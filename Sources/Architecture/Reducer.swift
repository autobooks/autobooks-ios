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

    @MainActor
    func callAsFunction(_ state: inout State, _ action: Action, _ environment: Environment) -> Effect<Action>? {
        reducerClosure(&state, action, environment)
    }

    /// When the `DEBUG` compilation condition is active, adds a higher-order reducer which prints incoming actions.
    func debug() -> Self {
        #if DEBUG
        Self { state, action, environment in
            print("*** Action: \(action)")

            return self(&state, action, environment)
        }
        #else
        self
        #endif
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
