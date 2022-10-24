import SwiftUI
import UIKit

/// The Autobooks namespace.
public enum Autobooks {
    /// Configuration of various Autobooks features, including primary color, backend environment, response provider,
    /// and fallback behavior.
    public struct Configuration {
        /// Default Autobooks SDK configuration.
        ///
        /// Current Defaults:
        ///  * `environment` = `.staging`
        ///  * `primaryColor` = `.blue`
        ///  * `responseProvider` = `.hybrid(.successes)`
        ///  * `shouldFallBackToPaymentForm` = `false`
        ///
        public static let `default` = Configuration(environment: .staging,
                                                    primaryColor: .blue,
                                                    responseProvider: .hybrid(.successes),
                                                    shouldFallBackToPaymentForm: false)

        /// `BackendEnvironment` to use for network requests.
        public let environment: BackendEnvironment

        /// `UIColor` used for primary fills in various views.
        ///
        /// - Note: If your app supports dark mode, ensure this color also supports light and dark variants.
        ///
        public let primaryColor: UIColor

        /// `ResponseProvider` to use for network requests.
        public let responseProvider: ResponseProvider

        /// Determines whether the SDK will fall back on the Payment Form when the device doesn't support Tap to Pay.
        ///
        /// - Note: Has no effect until Tap to Pay is fully integrated.
        ///
        public let shouldFallBackToPaymentForm: Bool

        /// Create an instance.
        public init(environment: BackendEnvironment,
                    primaryColor: UIColor,
                    responseProvider: ResponseProvider,
                    shouldFallBackToPaymentForm: Bool) {
            self.environment = environment
            self.primaryColor = primaryColor
            self.responseProvider = responseProvider
            self.shouldFallBackToPaymentForm = shouldFallBackToPaymentForm
        }
    }

    /// Autobooks environment to which API calls will be made.
    ///
    /// - Note: Access to environments other than the default requires coordination with Autobooks.
    ///
    public enum BackendEnvironment {
        case dev, staging, production

        var url: URL {
            switch self {
            case .dev:
                return URL(string: "https://dev-apim.autobooks.co/ttp/v1")!
            case .staging:
                return URL(string: "https://staging-apim.autobooks.co/ttp/v1")!
            case .production:
                return URL(string: "https://apim.autobooks.co/ttp/v1")!
            }
        }
    }

    /// Type determining where Autobooks API responses will come from.
    public enum ResponseProvider: Equatable {
        /// Use the provided `BackendEnvironment` with mocked login endpoint, normal endpoints for the rest.
        case backendMocked
        /// Use the provided `BackendEnvironment` for login, provided stubs for the rest.
        case hybrid(Stubs)
        /// Use the provided `BackendEnvironment` for all API calls.
        case live
        /// Use provided local stubs for all calls. No traffic should go over the network with this setting.
        case stubs(Stubs)
    }

    /// Current version of the Autobooks SDK.
    public static let version = "0.1.0"

    private static var handleURL: ((URL) -> Void)?

    /// Start the Autobooks Tap to Pay feature or fall back to the Payment Form on unsupported devices, if configured.
    ///
    /// - Parameters:
    ///   - subscriptionKey: Autobooks subscription key.
    ///   - configuration:   `Configuration` value to be used. `.default` by default.
    ///   - loginProvider:   Async closure return the SSO payload as a `String`. This closure may be called multiple
    ///                      times to get the latest value and is used to renew authorization while the session is
    ///                      active.
    public static func startTapToPay(subscriptionKey: String,
                                     configuration: Configuration = .default,
                                     loginProvider: @escaping @Sendable () async throws -> String) {
        if #available(iOS 15.4, *), PaymentSession.isSupported {
            // Trampoline into the main actor, as we can't mark the Autobooks type @MainActor due to availability.
            Task { @MainActor in
                presentTapToPayController(subscriptionKey: subscriptionKey,
                                          configuration: configuration,
                                          loginProvider: loginProvider)
            }
        } else {
            let rootController: UIViewController

            // When the device supports tap to pay, don't fallback despite the configuration so we can tell the user to
            // update their OS.
            if configuration.shouldFallBackToPaymentForm, !UIDevice.current.supportsTapToPay {
                rootController = WebFeatureViewController(feature: .paymentForm)
            } else {
                rootController = UnsupportedViewController()
            }

            present(rootController, configuration: configuration)
        }
    }

    @available(iOS 15.4, *)
    @MainActor
    private static func presentTapToPayController(subscriptionKey: String,
                                                  configuration: Configuration,
                                                  loginProvider: @escaping @Sendable () async throws -> String) {
        let api = AutobooksAPI(subscriptionKey: subscriptionKey,
                               environment: configuration.environment,
                               responseProvider: configuration.responseProvider,
                               loginProvider: loginProvider)
        let environment = RootEnvironment(
            api: api,
            defaults: Defaults(),
            paymentSession: PaymentSession(),
            dismiss: {
                UIApplication.shared.activeRootViewController?.dismiss(animated: true)
            },
            openURL: { url in
                UIApplication.shared.open(url)
            })
        let isPreviouslyLaunched = environment.defaults.isPreviouslyLaunched
        let navigation: Navigation = isPreviouslyLaunched ? .navigate([.loading]) : .navigate([.start])
        let store = Store(initialState: RootState(navigation: navigation),
                          reducer: RootReducer.default.debug(),
                          environment: environment)
        if isPreviouslyLaunched {
            store.send(.performLogin, animation: .default)
        }
        handleURL = { [weak store] url in store?.send(.handleCallbackURL(url)) }

        present(SupportedFlowController(store: store, configuration: configuration), configuration: configuration)
    }

    /// Start the Autobooks Payment Form feature.
    ///
    /// - Parameters:
    ///   - loginToken:    Autobooks SSO payload as a `String`, used to initialize the web feature.
    ///   - configuration: `Configuration` value to be used. `.default` by default.
    ///
    public static func startPaymentForm(loginToken: String,
                                        configuration: Configuration = .default) {
        startWebFeature(.paymentForm, loginToken: loginToken, configuration: configuration)
    }

    /// Start the Autobooks Invoicing feature.
    ///
    /// - Parameters:
    ///   - loginToken:    Autobooks SSO payload as a `String`, used to initialize the web feature.
    ///   - configuration: `Configuration` value to be used. `.default` by default.
    ///
    public static func startInvoicing(loginToken: String,
                                      configuration: Configuration = .default) {
        startWebFeature(.invoicing, loginToken: loginToken, configuration: configuration)
    }

    /// Passes a callback `URL` to the Autobooks SDK to handle as part of the Enrollment or More Info web flows.
    ///
    /// - Note: The scheme of this `URL` is provided by your Autobooks account and must be registered by the app using
    ///         this SDK.
    ///
    /// - Parameter url: Callback `URL` received by the application.
    ///
    public static func handle(url: URL) {
        handleURL?(url)
    }

    /// Stops the current Autobooks feature session and dismisses back to the app.
    public static func stop() {
        UIApplication.shared.activeRootViewController?.dismiss(animated: true)
    }

    #if DEBUG
    /// Resets stored Autobooks SDK state.
    public static func reset() {
        let defaults = Defaults()
        defaults.isPreviouslyLaunched = false
    }
    #endif

    private static func startWebFeature(_ feature: WebFeature,
                                        loginToken: String,
                                        configuration: Configuration) {
        let controller = WebFeatureViewController(feature: feature)
        present(controller, configuration: configuration, transparentNavigationBar: false)
    }

    private static func present(_ controller: UIViewController,
                                configuration: Configuration,
                                transparentNavigationBar: Bool = true) {
        let navigationController: UINavigationController

        if let controller = controller as? UINavigationController {
            navigationController = controller
        } else {
            navigationController = UINavigationController(rootViewController: controller)
        }

        navigationController.modalPresentationStyle = .fullScreen
        navigationController.customizeNavigationBarAppearance(primaryColor: configuration.primaryColor,
                                                              isTransparent: transparentNavigationBar)
        UIApplication.shared.activeRootViewController?.present(navigationController, animated: true)
    }

    enum WebFeature {
        case paymentForm, invoicing

        var url: URL {
            .init(string: "https://www.autobooks.co")!
        }

        var title: String {
            switch self {
            case .paymentForm:
                return "Payments"
            case .invoicing:
                return "Invoicing"
            }
        }
    }
}
