import Combine
import SwiftUI

@MainActor
@available(iOS 14.0, *)
final class Store<State: Equatable, Action, Environment>: ObservableObject {
    @Published var state: State
    @Published private var rawState: State
    private let reducer: Reducer<State, Action, Environment>
    private let environment: Environment

    init(initialState: State, reducer: Reducer<State, Action, Environment>, environment: Environment) {
        rawState = initialState
        state = initialState
        self.reducer = reducer
        self.environment = environment

        $rawState.removeDuplicates().assign(to: &$state)
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
        $state.map(toChildState).removeDuplicates().assign(to: &child.$rawState)

        return child
    }

    func send(_ action: Action) {
        let effect = reducer(&state, action, environment)
        effect?.perform { [unowned self] action in
            self.send(action)
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
        _ = await $state.values.first { !predicate($0) }
    }
}
