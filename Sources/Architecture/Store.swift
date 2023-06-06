import Combine
import SwiftUI

@MainActor
@available(iOS 14.0, *)
final class Store<State: Equatable, Action, Environment>: ObservableObject {
    private let stateSubject: CurrentValueSubject<State, Never>
    private let reducer: Reducer<State, Action, Environment>
    private let environment: Environment

    private var parentCancellable: AnyCancellable?
    private var mutationCancellable: AnyCancellable?
    private var debugTokens: [AnyCancellable] = []

    private(set) lazy var statePublisher: AnyPublisher<State, Never> = stateSubject
        // Have to remove duplicates, otherwise children emit twice.
        .removeDuplicates()
        .eraseToAnyPublisher()

    var state: State {
        stateSubject.value
    }

    var onlyState: Store<State, Never, Environment> {
        nonisolated
        func absurd<T>(_ never: Never) -> T {}
        return scope(state: { $0 }, action: absurd, environment: { $0 })
    }

    init(initialState: State, reducer: Reducer<State, Action, Environment>, environment: Environment) {
        self.stateSubject = CurrentValueSubject(initialState)
        self.reducer = reducer
        self.environment = environment
    }

    func debug(prefix: String = "") -> Self {
        debugTokens.append(statePublisher.sink { value in
            Log.sdk.debug("*** \(prefix) \(Self.self) updated to \(String(describing: value))")
        })

        return self
    }

    func scope<ChildState: Equatable, ChildAction, ChildEnvironment>(
        state toChildState: @escaping (State) -> ChildState,
        action fromChildAction: @escaping (ChildAction) -> Action,
        environment toChildEnvironment: (Environment) -> ChildEnvironment
    ) -> Store<ChildState, ChildAction, ChildEnvironment> {
        let childReducer = Reducer<ChildState, ChildAction, ChildEnvironment> { [self] childState, childAction, _ in
            send(fromChildAction(childAction))
            childState = toChildState(state)

            return nil
        }
        let child = Store<ChildState, ChildAction, ChildEnvironment>(initialState: toChildState(state),
                                                                     reducer: childReducer,
                                                                     environment: toChildEnvironment(environment))
        let token = statePublisher
            .map(toChildState)
            .removeDuplicates()
            .sink { [weak child] state in
                child?.objectWillChange.send()
                child?.stateSubject.value = state
            }
        child.parentCancellable = token

        return child
    }

    func scope<ChildState: Equatable, ChildAction>(
        state toChildState: @escaping (State) -> ChildState,
        action fromChildAction: @escaping (ChildAction) -> Action
    ) -> Store<ChildState, ChildAction, Environment> {
        scope(state: toChildState, action: fromChildAction, environment: { $0 })
    }

    func scope<ChildState: Equatable>(
        state toChildState: @escaping (State) -> ChildState
    ) -> Store<ChildState, Action, Environment> {
        scope(state: toChildState, action: { $0 }, environment: { $0 })
    }

    func send(_ action: Action) {
        objectWillChange.send()
        let effect = reducer(&stateSubject.value, action, environment)
        effect?.perform { [unowned self] action in
            send(action)
        }
    }

    func send(_ action: Action, animation: Animation?) {
        withAnimation(animation) {
            send(action)
        }
    }

    @available(iOS 15.0, *)
    func send(_ action: Action, while predicate: @escaping (State) -> Bool) async {
        send(action)
        await yield(while: predicate)
    }

    @available(iOS 15.0, *)
    func send(_ action: Action, animation: Animation?, while predicate: @escaping (State) -> Bool) async {
        send(action, animation: animation)
        await yield(while: predicate)
    }

    @available(iOS 15.0, *)
    func yield(while predicate: @escaping (State) -> Bool) async {
        _ = await statePublisher.values.first { !predicate($0) }
    }
}
