import SwiftUI

/// Reducer signature when expressed as a closure.
@available(iOS 13.0, *)
typealias ReducerClosure<State, Action, Environment> = @MainActor (inout State, Action, Environment) -> Effect<Action>?

/// Type which reduces state and actions into mutations and optional effects.
@available(iOS 13.0, *)
struct Reducer<State, Action, Environment> {
    /// Combine multiple `Reducer`s into a single instance.
    ///
    /// - Parameter reducers: `Reducer`s to combine. They are performed in the provided order.
    ///
    /// - Returns: The `Reducer`.
    ///
    static func combine(_ reducers: [Self]) -> Self {
        Self { state, action, environment in
            .merge(reducers.map { $0(&state, action, environment) })
        }
    }

    private let reducerClosure: ReducerClosure<State, Action, Environment>

    init(_ reducerClosure: @escaping ReducerClosure<State, Action, Environment>) {
        self.reducerClosure = reducerClosure
    }

    func toParent<ParentState, ParentAction, ParentEnvironment>(
        _ childStatePath: WritableKeyPath<ParentState, State>,
        toChildAction: @escaping (ParentAction) -> Action?,
        toParentAction: @escaping (Action) -> ParentAction,
        toChildEnvironment: @escaping (ParentEnvironment) -> Environment
    ) -> Reducer<ParentState, ParentAction, ParentEnvironment> {
        .init { parentState, parentAction, parentEnvironment in
            guard let childAction = toChildAction(parentAction) else {
                return nil
            }

            var childState = parentState[keyPath: childStatePath]

            let childEffect = self(&childState, childAction, toChildEnvironment(parentEnvironment))
            parentState[keyPath: childStatePath] = childState

            return childEffect.map { effect in
                Effect { parentSender in
                    effect.perform { childAction in
                        parentSender(toParentAction(childAction))
                    }
                }
            }
        }
    }

    func optional() -> Reducer<State?, Action, Environment> {
        .init { state, action, environment in
            guard state != nil else {
                Log.sdk.debug("*** Attempted to operate on nil state from optional() reducer.")
                return nil
            }

            return self(&state!, action, environment)
        }
    }

    @MainActor
    func callAsFunction(_ state: inout State, _ action: Action, _ environment: Environment) -> Effect<Action>? {
        reducerClosure(&state, action, environment)
    }

    /// Adds a higher-order reducer which logs incoming actions and posts some actions as Notifications.
    func logAndPostNotifications() -> Self {
        Self { state, action, environment in
            Log.sdk.debug("*** Action: \(String(describing: action))")
            
            let notificationName = Notification.Name(String(describing: action))
            let notification = Notification(name: notificationName)
            NotificationCenter.default.post(notification)

            return self(&state, action, environment)
        }
    }
}

/// Type encapsulating a unit of work which later returns an action back into a reducer.
@available(iOS 13.0, *)
@MainActor
final class Effect<Action> {
    typealias Operation = @MainActor (Sender<Action>) -> Void

    /// Perform an `Action` without other work.
    ///
    /// - Parameter action: `Action` to be performed.
    ///
    /// - Returns: The `Effect`.
    ///
    static func action(_ action: Action) -> Effect<Action> {
        Effect { send in
            send(action)
        }
    }

    /// Perform async work while sending actions.
    ///
    /// - Parameter operation: Async work to be performed with a provided `Sender`.
    ///
    /// - Returns: The `Effect`.
    ///
    static func run(_ operation: @escaping (Sender<Action>) async -> Void) -> Effect<Action> {
        Effect { send in
            Task {
                await operation(send)
            }
        }
    }

    static func run(after seconds: Double, operation: @escaping (Sender<Action>) async -> Void) -> Effect<Action> {
        Effect { send in
            Task {
                try? await Task.sleep(nanoseconds: UInt64(seconds * Double(NSEC_PER_SEC)))
                await operation(send)
            }
        }
    }

    /// Merge multiple `Effect`s into a single instance.
    ///
    /// - Parameter effects: `Effect`s to be merged. They are performed in the provided order.
    ///
    /// - Returns: The `Effect`.
    static func merge(_ effects: [Effect<Action>?]) -> Effect<Action> {
        Effect { send in
            for effect in effects {
                effect?.perform { action in
                    send(action)
                }
            }
        }
    }

    private let operation: Operation

    init(operation: @escaping Operation) {
        self.operation = operation
    }

    /// Performs the captured operation using the provided closure.
    func perform(_ sender: @escaping (Action) -> Void) {
        operation(Sender(send: sender))
    }
}

/// Type encapsulating a connection between an action and a receiver. Allows the sending of multiple actions through the
/// same connection.
@available(iOS 13.0, *)
@MainActor
struct Sender<Action> {
    let send: (Action) -> Void

    func callAsFunction(_ action: Action) {
        send(action)
    }

    func callAsFunction(_ action: Action, animation: Animation?) {
        withAnimation(animation) {
            self(action)
        }
    }
}
