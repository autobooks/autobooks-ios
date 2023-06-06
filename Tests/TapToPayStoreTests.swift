@testable import Autobooks
import XCTest

@available(iOS 16.0, *)
@MainActor
final class TapToPayDomainTests: XCTestCase {
    func testThatTapToPayStoreCallsDismissProvider() {
        // Given
        var dismissCalled = false
        let environment = TapToPay.Environment(api: .init(subscriptionKey: "subscriptionKey",
                                                          environment: .dev,
                                                          loginProvider: { "login" }),
                                               defaults: Defaults(),
                                               paymentSession: PaymentSession(),
                                               dismiss: { dismissCalled = true },
                                               openURL: { _ in }, triPOS: TriPOS(device: .simulated, mode: .certification))
        let store = TapToPayStore(initialState: .init(navigation: .navigate([.loading])),
                                  reducer: TapToPay.reducer,
                                  environment: environment)

        // When
        store.send(.closeTapToPay)

        // Then
        XCTAssertTrue(dismissCalled)
    }

    func testThatTapToPayStoreCallsOpenURLHandler() {
        // Given
        let sentURL = URL.paymentForm
        var receivedURL: URL?
        let environment = TapToPay.Environment(api: .init(subscriptionKey: "subscriptionKey",
                                                          environment: .dev,
                                                          loginProvider: { "login" }),
                                               defaults: Defaults(),
                                               paymentSession: PaymentSession(),
                                               dismiss: {},
                                               openURL: { url in receivedURL = url }, triPOS: TriPOS(device: .simulated, mode: .certification))
        let store = TapToPayStore(initialState: .init(navigation: .navigate([.loading])),
                                  reducer: TapToPay.reducer,
                                  environment: environment)

        // When
        store.send(.openURL(sentURL))

        // Then
        XCTAssertEqual(receivedURL, sentURL)
    }
}
