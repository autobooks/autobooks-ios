import Combine
import SwiftUI
import UIKit

@available(iOS 15.4, *)
final class TapToPayFlowController: UINavigationController {
    private let store: TapToPayStore
    private var observationToken: Cancellable?
    private var configuration: Autobooks.Configuration

    var currentNavigationConfigurations: [Navigation.Configuration] {
        viewControllers.compactMap { ($0 as? NavigationRepresentable)?.configuration }
    }

    init(store: TapToPayStore, configuration: Autobooks.Configuration) {
        self.store = store
        self.configuration = configuration

        super.init(nibName: nil, bundle: nil)

        delegate = self

        observationToken = store.$state
            .map(\.navigation)
            .removeDuplicates()
            .sink { [unowned self] navigation in
                handleNavigation(navigation)
            }
    }

    func handleNavigation(_ navigation: Navigation) {
        guard !navigation.configurations.isEmpty else { print("*** Navigation was empty, ignoring."); return }

        // Prevents duplicate navigations regardless of type.
        guard navigation.configurations != currentNavigationConfigurations else { return }

        if let lastConfiguration = navigation.configurations.last,
           case .postsale = lastConfiguration,
           presentedViewController == nil {
            let controller = lastConfiguration.screenController(using: store, configuration: configuration)
            let navigationController = UINavigationController(rootViewController: controller)
            navigationController.navigationBar.prefersLargeTitles = true
            navigationController.presentationController?.delegate = self

            present(navigationController, animated: true)
        } else {
            let animated = presentedViewController == nil

            if presentedViewController != nil {
                presentedViewController?.dismiss(animated: true)
            }

            switch navigation {
            case let .navigate(configurations):
                performNavigationDifferences(from: configurations, animated: animated)
            case let .reset(configurations):
                let controllers = configurations.map { navConfiguration -> UIViewController in
                    let controller = navConfiguration.screenController(using: store, configuration: configuration)
                    configureNavigation(for: controller, in: navConfiguration)

                    return controller
                }

                setViewControllers(controllers, animated: animated)
            }
        }
    }

    private func performNavigationDifferences(from configurations: [Navigation.Configuration], animated: Bool) {
        // For each configuration, grab the existing controller or create a new one.
        let controllers = configurations.map { navConfiguration -> UIViewController in
            let existingController = viewControllers
                .first { ($0 as? NavigationRepresentable)?.configuration == navConfiguration }
            let controller = existingController ?? navConfiguration.screenController(using: store, configuration: configuration)
            configureNavigation(for: controller, in: navConfiguration)

            return controller
        }

        setViewControllers(controllers, animated: animated)
    }

    private func configureNavigation(for viewController: UIViewController, in configuration: Navigation.Configuration) {
        if configuration.showCloseButton, viewController.navigationItem.leftBarButtonItem == nil {
            viewController.navigationItem.leftBarButtonItem = UIBarButtonItem(title: "Close",
                                                                              style: .done,
                                                                              target: self,
                                                                              action: #selector(closeTapToPay))
        }

        if configuration == .presale, viewController.navigationItem.rightBarButtonItem == nil {
            viewController.navigationItem.rightBarButtonItem = UIBarButtonItem(title: "Transactions",
                                                                               style: .plain,
                                                                               target: self,
                                                                               action: #selector(showTransactions))
        }
    }

    @objc private func closeTapToPay() {
        let alert = UIAlertController(title: "Close Tap to Pay?", message: "You can navigate back at any time", preferredStyle: .alert)
        let ok = UIAlertAction(title: "OK", style: .default, handler: { _ in
            self.store.send(.closeTapToPay)
        })
        let cancel = UIAlertAction(title: "Cancel", style: .cancel) { _ in
        }
        alert.addAction(ok)
        alert.addAction(cancel)

        present(alert, animated: false)
    }

    @objc private func showTransactions() {
        store.send(.showTransactions)
    }

    @available(*, unavailable)
    @MainActor dynamic required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}

@available(iOS 15.4, *)
extension TapToPayFlowController: UIAdaptivePresentationControllerDelegate {
    func presentationControllerShouldDismiss(_ presentationController: UIPresentationController) -> Bool {
        !(store.state.receiptInputVisibility == .visible(.loading))
    }

    func presentationControllerDidDismiss(_ presentationController: UIPresentationController) {
        presentationController.delegate = nil
        store.send(.makeAnotherPayment)
    }
}

@available(iOS 15.4, *)
extension TapToPayFlowController: UINavigationControllerDelegate {
    func navigationController(_ navigationController: UINavigationController, didShow viewController: UIViewController, animated: Bool) {
        // If our navigation state is out of sync with the current controllers the user has manually navigated or swiped back.
        // Bring the states back into sync by synchronizing with the RootState.
        guard currentNavigationConfigurations.count < store.state.navigation.configurations.count else { return }

        // If we're navigating back from the transaction details screen, refresh the transactions.
        if store.state.navigation.configurations.last == .transactionDetails {
            store.send(.fetchTransactions)
        }

        store.send(.synchronizeNavigation(.navigate(currentNavigationConfigurations)))
    }
}

@available(iOS 15.4, *)
enum Navigation: Equatable {
    case navigate([Configuration])
    case reset([Configuration])

    var configurations: [Configuration] {
        switch self {
        case let .navigate(configurations), let .reset(configurations):
            return configurations
        }
    }

    enum Configuration: Equatable {
        case start, loading, webview(WebViewState),
             notEnabled, presale, tapToPay, postsale(Bool),
             transactions, transactionDetails

        struct WebViewState: Equatable {
            let title: String
            let url: URL
            let callbackURL: URL
        }

        var showCloseButton: Bool {
            switch self {
            case .transactions, .transactionDetails:
                return false
            default:
                return true
            }
        }

        var title: String? {
            switch self {
            case .start, .loading, .webview, .tapToPay, .notEnabled:
                return nil
            case .presale:
                return "New Payment"
            case let .postsale(isSuccess):
                return isSuccess ? "Payment Successful" : nil
            case .transactions:
                return "Transactions"
            case .transactionDetails:
                return "Payment Details"
            }
        }

        var titleDisplayMode: UINavigationItem.LargeTitleDisplayMode {
            switch self {
            case .start, .loading, .webview, .tapToPay, .notEnabled:
                return .never
            case .presale, .postsale, .transactions, .transactionDetails:
                return .always
            }
        }

        @MainActor
        func screenController(using store: TapToPayStore, configuration: Autobooks.Configuration) -> UIViewController {
            ScreenViewController(configuration: self) {
                Group {
                    switch self {
                    case .start:
                        StartingScreen(store: store)
                    case .loading:
                        LoadingScreen(
                            store: store.scope(
                                state: { parentState in
                                    .init(initialLoad: parentState.initialLoad)
                                },
                                action: { childAction in
                                    childAction.action
                                },
                                environment: { _ in .init() }
                            )
                        )
                    case let .webview(state):
                        WebViewScreen(store: store, state: state)
                    case .notEnabled:
                        NotEnabledScreen()
                    case .presale:
                        PresaleScreen(store: store)
                    case .tapToPay:
                        TapToPayScreen(store: store)
                    case .postsale:
                        PostsaleScreen(store: store)
                    case .transactions:
                        TransactionsScreen(store: store)
                    case .transactionDetails:
                        TransactionDetailsScreen(store: store)
                    }
                }
                .environment(\.primaryColor, Color(configuration.primaryColor))
            }
        }
    }
}

@available(iOS 15.4, *)
private final class ScreenViewController<Screen: View>: WorkingHostingController<Screen>, NavigationRepresentable {
    override var navigationItem: UINavigationItem {
        let item = super.navigationItem
        item.title = configuration.title
        item.largeTitleDisplayMode = configuration.titleDisplayMode

        if configuration.showCloseButton {
            item.backBarButtonItem = nil
            item.hidesBackButton = true
        }

        return item
    }

    let configuration: Navigation.Configuration

    init(configuration: Navigation.Configuration, @ViewBuilder screen: () -> Screen) {
        self.configuration = configuration

        super.init(rootView: screen())
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)

        navigationController?.navigationBar.prefersLargeTitles = configuration.titleDisplayMode == .always
    }

    @available(*, unavailable)
    @MainActor dynamic required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}

@available(iOS 15.4, *)
protocol NavigationRepresentable {
    var configuration: Navigation.Configuration { get }
}

extension UINavigationController {
    func customizeNavigationBarAppearance(primaryColor: UIColor, isTransparent: Bool = true) {
        navigationBar.tintColor = primaryColor

        guard #available(iOS 13, *) else { return }

        let customAppearance = UINavigationBarAppearance()

        if isTransparent {
            customAppearance.configureWithTransparentBackground()
        } else {
            customAppearance.configureWithDefaultBackground()
        }

        let barButtonItemAppearance = UIBarButtonItemAppearance(style: .plain)
        barButtonItemAppearance.normal.titleTextAttributes = [.foregroundColor: primaryColor]
        barButtonItemAppearance.disabled.titleTextAttributes = [.foregroundColor: primaryColor]
        barButtonItemAppearance.highlighted.titleTextAttributes = [.foregroundColor: primaryColor]
        barButtonItemAppearance.focused.titleTextAttributes = [.foregroundColor: primaryColor]

        customAppearance.buttonAppearance = barButtonItemAppearance
        customAppearance.backButtonAppearance = barButtonItemAppearance
        customAppearance.doneButtonAppearance = barButtonItemAppearance

        navigationBar.scrollEdgeAppearance = customAppearance
        navigationBar.compactAppearance = customAppearance
        navigationBar.standardAppearance = customAppearance

        if #available(iOS 15.0, *) {
            navigationBar.compactScrollEdgeAppearance = customAppearance
        }
    }
}
