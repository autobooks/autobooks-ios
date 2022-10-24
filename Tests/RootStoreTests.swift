@testable import Autobooks

import XCTest

@available(iOS 15.4, *)
@MainActor
final class RootStoreTests: XCTestCase {
    func testThatRootStoreCallsDismissProvider() {
        // Given
        var dismissCalled = false
        let environment = RootEnvironment(api: .init(subscriptionKey: "subscriptionKey",
                                                     environment: .dev,
                                                     loginProvider: { "login" }),
                                          defaults: Defaults(),
                                          paymentSession: PaymentSession(),
                                          dismiss: { dismissCalled = true },
                                          openURL: { _ in })
        let store = RootStore(initialState: .init(navigation: .navigate([.loading])),
                              reducer: RootReducer.default,
                              environment: environment)

        // When
        store.send(.closeTapToPay)

        // Then
        XCTAssertTrue(dismissCalled)
    }
}
