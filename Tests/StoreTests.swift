@testable import Autobooks
import Combine
import XCTest

@available(iOS 15.0, *)
@MainActor
final class StoreTests: XCTestCase {
    struct State: Equatable {
        var ints: [Int] = []
        var isLoading = false
        var seenChildStates: [ChildState] = []
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
        case updateStringAsync(String)
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

    var reducer: Reducer<State, Action, Environment> {
        .combine([
            childReducer.toParent(\.childState,
                                  toChildAction: { action in
                                      switch action {
                                      case let .child(action):
                                          return action
                                      default:
                                          return nil
                                      }
                                  },
                                  toParentAction: Action.child,
                                  toChildEnvironment: { $0 }),
            Reducer { state, action, environment in
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
                case .child:
                    state.seenChildStates.append(state.childState)

                    return nil
                }
            },
        ])
    }

    let childReducer: Reducer<ChildState, ChildAction, Environment> = .init { state, action, _ in
        switch action {
        case let .updateString(string):
            state.someString = string

            return nil
        case let .updateStringAsync(string):
            return .action(.updateString(string))
        case .toggleLoading:
            state.isLoading.toggle()

            return nil
        }
    }

    private var tokens: Set<AnyCancellable> = []

    func testThatStoreCanProcessSyncEffects() async {
        // Given
        let store = Store(initialState: State(), reducer: reducer, environment: Environment())
        let newValue = 1

        // When
        let waiter = Task { () -> [Int] in
            var values: [Int] = []
            for await value in store.statePublisher.values.map(\.ints) {
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
            for await value in store.statePublisher.values.map(\.ints).filter({ !$0.isEmpty }) {
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
            for await value in store.statePublisher.values {
                guard !value.isLoading else {
                    continue
                }

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
        let child = store.scope(state: \.childState, action: Action.child, environment: { $0 })
        let newString = "newString"

        // When
        let waiter = Task { () -> [ChildState] in
            var values: [ChildState] = []
            for await value in child.statePublisher.values {
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

    func testThatStoreObjectWillChangeIsFiredOnMutation() {
        // Given
        let store = Store(initialState: State(), reducer: reducer, environment: Environment())
        let didReceiveWillChange = expectation(description: "did receive willChange")
        var willChangeValue: Bool?
        var afterSendValue: Bool?

        // Then
        store.objectWillChange.sink { _ in
            willChangeValue = store.state.isLoading
            didReceiveWillChange.fulfill()
        }
        .store(in: &tokens)
        store.send(.child(.toggleLoading))
        afterSendValue = store.state.childState.isLoading

        waitForExpectations(timeout: 1)

        XCTAssertTrue(willChangeValue == false)
        XCTAssertTrue(afterSendValue == true)
    }

    func testThatScopedStoreObjectWillChangeIsFiredOnParentMutation() {
        // Given
        let store = Store(initialState: State(), reducer: reducer, environment: Environment())
        let child = store.scope(state: { $0 })
        let didReceiveWillChange = expectation(description: "did receive willChange")
        var willChangeValue: Bool?
        var afterSendValue: Bool?

        // Then
        child.objectWillChange.sink { _ in
            willChangeValue = child.state.isLoading
            didReceiveWillChange.fulfill()
        }
        .store(in: &tokens)
        store.send(.child(.toggleLoading))
        afterSendValue = child.state.childState.isLoading

        waitForExpectations(timeout: 1)

        XCTAssertTrue(willChangeValue == false)
        XCTAssertTrue(afterSendValue == true)
    }

    func testThatScopedStoresReceiveAllState() {
        // Given
        let parent = Store(initialState: State(), reducer: reducer, environment: Environment())
        let child = parent.scope(state: { $0 })
        let didReceiveString = expectation(description: "did receive string")
        didReceiveString.expectedFulfillmentCount = 8
        let strings = ["first", "second", "third"]
        let output = ["string"] + strings
        var parentStrings: [String] = []
        var childStrings: [String] = []

        // When
        parent.statePublisher.map(\.childState.someString).sink { string in
            parentStrings.append(string)
            didReceiveString.fulfill()
        }
        .store(in: &tokens)

        child.statePublisher.map(\.childState.someString).sink { string in
            childStrings.append(string)
            didReceiveString.fulfill()
        }
        .store(in: &tokens)

        for string in strings {
            child.send(.child(.updateString(string)))
        }

        waitForExpectations(timeout: 1)

        // Then
        XCTAssertEqual(parentStrings, output)
        XCTAssertEqual(childStrings, output)
    }

    func testThatScopedStoresReceiveScopedState() {
        // Given
        let parent = Store(initialState: State(), reducer: reducer, environment: Environment())
        let child = parent.scope(state: \.childState, action: Action.child)
        let didReceiveString = expectation(description: "did receive string")
        didReceiveString.expectedFulfillmentCount = 8
        let strings = ["first", "second", "third"]
        let output = ["string"] + strings
        var parentStrings: [String] = []
        var childStrings: [String] = []

        // When
        parent.statePublisher.map(\.childState.someString).sink { string in
            parentStrings.append(string)
            didReceiveString.fulfill()
        }
        .store(in: &tokens)

        child.statePublisher.map(\.someString).sink { string in
            childStrings.append(string)
            didReceiveString.fulfill()
        }
        .store(in: &tokens)

        for string in strings {
            child.send(.updateString(string))
        }

        waitForExpectations(timeout: 1)

        // Then
        XCTAssertEqual(parentStrings, output)
        XCTAssertEqual(childStrings, output)
        XCTAssertEqual(parent.state.seenChildStates.map(\.someString), strings)
    }

    func testThatScopedStoresReceiveScopedStateFromEffects() {
        // Given
        let parent = Store(initialState: State(), reducer: reducer, environment: Environment())
        let child = parent.scope(state: \.childState, action: Action.child)
        let didReceiveString = expectation(description: "did receive string")
        didReceiveString.expectedFulfillmentCount = 11
        let strings = ["first", "second", "third"]
        let output = ["string"] + strings
        var parentStrings: [String] = []
        var childStrings: [String] = []

        // When
        parent.statePublisher.map(\.childState.someString).sink { string in
            parentStrings.append(string)
            didReceiveString.fulfill()
        }
        .store(in: &tokens)

        child.statePublisher.map(\.someString).sink { string in
            childStrings.append(string)
            didReceiveString.fulfill()
        }
        .store(in: &tokens)

        for string in strings {
            child.send(.updateStringAsync(string))
        }

        waitForExpectations(timeout: 1)

        // Then
        let expected = ["string", "string", "first", "first", "second", "second", "third"]
        XCTAssertEqual(parentStrings, expected)
        XCTAssertEqual(childStrings, output)
        XCTAssertEqual(parent.state.seenChildStates.map(\.someString), Array(expected.dropFirst()))
    }

    func testThatChildStoresSeeActionsFromParent() async {
        // Given
        let store = Store(initialState: State(), reducer: reducer, environment: Environment())
        let child = store.scope(state: \.childState, action: Action.child, environment: { $0 })
        let newString = "newString"

        // When
        let waiter = Task { () -> [ChildState] in
            var values: [ChildState] = []
            for await value in child.statePublisher.values {
                values.append(value)
                break
            }
            return values
        }

        store.send(.child(.updateString(newString)))
        let values = await waiter.value

        // Then
        XCTAssertEqual(values, [.init(isLoading: false, someString: newString)])
    }

    func testThatScopedStoresAreNotUpdatedForUnscopedState() async {
        // Given
        let store = Store(initialState: State(), reducer: reducer, environment: Environment())
        let childStore = store.scope(state: \.childState, action: Action.child, environment: { $0 })
        let newInt = 1

        // When
        let parentWaiter = Task { () -> [Int] in
            var ints: [Int] = []
            for await value in store.statePublisher.values.map(\.ints) {
                ints = value
                break
            }

            return ints
        }

        let childWaiter = Task { () -> [ChildState] in
            var values: [ChildState] = []
            for await value in childStore.statePublisher.values {
                values.append(value)
                break
            }
            return values
        }

        store.send(.append(1))
        async let childValues = childWaiter.value
        async let parentValues = parentWaiter.value

        let (child, parent) = await (childValues, parentValues)

        // Then
        XCTAssertEqual(parent, [newInt])
        XCTAssertEqual(child, [.init(isLoading: false, someString: "string")])
    }
}
