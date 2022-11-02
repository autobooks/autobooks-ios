@testable import Autobooks

import XCTest

@available(iOS 15.4, *)
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
                                               openURL: { _ in })
        let store = TapToPayStore(initialState: .init(navigation: .navigate([.loading])),
                                  reducer: TapToPay().reducer,
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
                                               openURL: { url in receivedURL = url })
        let store = TapToPayStore(initialState: .init(navigation: .navigate([.loading])),
                                  reducer: TapToPay().reducer,
                                  environment: environment)

        // When
        store.send(.openURL(sentURL))

        // Then
        XCTAssertEqual(receivedURL, sentURL)
    }

    func testThatTapToPayStoreProperlyMutatesAfterCallbackURL() {
        // This test leaves handleCallbackURL effects in flight.
        // Given
        let environment = TapToPay.Environment(api: .init(subscriptionKey: "subscriptionKey",
                                                          environment: .dev,
                                                          loginProvider: { "login" }),
                                               defaults: Defaults(),
                                               paymentSession: PaymentSession(),
                                               dismiss: {},
                                               openURL: { _ in })
        // Callback URL needs waitingWebView.
        let state = TapToPay.State(navigation: .navigate([.loading]),
                                   waitingWebView: .needEnrollment(.init(title: "Needs Enrollment",
                                                                         url: .paymentForm,
                                                                         callbackURL: .paymentForm)))
        let store = TapToPayStore(initialState: state,
                                  reducer: TapToPay().reducer,
                                  environment: environment)

        // When
        store.send(.handleCallbackURL(.paymentForm))

        // Then
        XCTAssertEqual(store.state.navigation, .navigate([.loading]))
        XCTAssertEqual(store.state.waitingWebView, nil)
    }
}
