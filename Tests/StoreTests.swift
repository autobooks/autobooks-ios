@testable import Autobooks

import Combine
import XCTest

@available(iOS 15.4, *)
@MainActor
final class StoreTests: XCTestCase {
    struct State: Equatable {
        var ints: [Int] = []
        var isLoading = false
        var childState = ChildState()
    }

    struct ChildState: Equatable {
        var isLoading = false
        var someString = "string"
    }

    enum Action {
        case appendAsync(Int)
        case append(Int)
        case appendMany
        case appendComplete
        case child(ChildAction)
    }

    enum ChildAction {
        case updateString(String)
        case toggleLoading
    }

    struct Environment {
        var intStream: AsyncStream<Int> {
            AsyncStream<Int> { continuation in
                continuation.yield(1)
                continuation.yield(2)
                continuation.finish()
            }
        }
    }

    let reducer = Reducer<State, Action, Environment> { state, action, environment in
        switch action {
        case let .appendAsync(value):
            return .action(.append(value))
        case let .append(value):
            state.ints.append(value)
            return nil
        case .appendMany:
            state.isLoading = true
            return .run { send in
                for await value in environment.intStream {
                    send(.append(value))
                }
                send(.appendComplete)
            }
        case .appendComplete:
            state.isLoading = false
            return nil
        case let .child(.updateString(string)):
            state.childState.someString = string
            return nil
        case .child(.toggleLoading):
            state.childState.isLoading.toggle()
            return nil
        }
    }

    func testThatStoreCanProcessSyncEffects() async {
        // Given
        let store = Store(initialState: State(), reducer: reducer, environment: Environment())
        let newValue = 1

        // When
        let waiter = Task { () -> [Int] in
            var values: [Int] = []
            for await value in store.$state.values.map(\.ints) {
                values = value
                break
            }
            return values
        }
        store.send(.append(newValue))
        let values = await waiter.value

        // Then
        XCTAssertEqual(values, [newValue])
    }

    func testThatStoreCanProcessAsyncEffects() async {
        // Given
        let store = Store(initialState: State(), reducer: reducer, environment: Environment())
        let newValue = 1

        // When
        let waiter = Task { () -> [Int] in
            var values: [Int] = []
            for await value in store.$state.values.map(\.ints).filter({ !$0.isEmpty }) {
                values = value
                break
            }
            return values
        }
        store.send(.appendAsync(newValue))
        let values = await waiter.value

        // Then
        XCTAssertEqual(values, [newValue])
    }

    func testThatStoreCanProcessStreamedEffects() async {
        // Given
        let store = Store(initialState: State(), reducer: reducer, environment: Environment())

        // When
        let waiter = Task { () -> [Int] in
            var values: [Int] = []
            for await value in store.$state.values {
                guard !value.isLoading else { continue }

                values = value.ints
                break
            }
            return values
        }
        store.send(.appendMany)
        let values = await waiter.value

        // Then
        XCTAssertEqual(values, [1, 2])
    }

    func testThatStoreCanScopeToChildForSyncEffects() async {
        // Given
        let store = Store(initialState: State(), reducer: reducer, environment: Environment())
        let child = store.scope(state: \.childState, action: Action.child)
        let newString = "newString"

        // When
        let waiter = Task { () -> [ChildState] in
            var values: [ChildState] = []
            for await value in child.$state.values {
                values.append(value)
                break
            }
            return values
        }
        child.send(.updateString(newString))
        let values = await waiter.value

        // Then
        XCTAssertEqual(values, [.init(isLoading: false, someString: newString)])
    }
}
