import Combine
import SwiftUI
import UIKit
import WebKit

@available(iOS 14.0, *)
final class WebFeatureFlowController: UINavigationController {
    private let store: WebFeatureStore
    private let configuration: Autobooks.WebFeatureConfiguration
    private lazy var closeButton: UIBarButtonItem = .init(title: "Close",
                                                          style: .done,
                                                          target: self,
                                                          action: #selector(closeWebFeature))

    private var storeObservation: AnyCancellable?

    init(store: WebFeatureStore, configuration: Autobooks.WebFeatureConfiguration) {
        self.store = store
        self.configuration = configuration

        let loadingScreen = LoadingScreen<WebFeature.Action>(store: store.scope(
            state: { parentState in
                .init(initialLoad: parentState.initialLoad)
            },
            action: { childAction in
                childAction.action
            },
            environment: { _ in
                .init()
            }
        ))
        .environment(\.primaryColor, Color(configuration.sdkConfiguration.primaryColor))

        let loadingController = WorkingHostingController(rootView: loadingScreen)

        super.init(rootViewController: loadingController)

        addCloseButton(to: loadingController)

        storeObservation = store.$state
            .map(\.navigation)
            .compactMap { navigation in
                if case let .feature(url) = navigation.last {
                    return url
                } else {
                    return nil
                }
            }
            .sink { [unowned self] url in
                self.pushWebView(to: url)
            }
    }

    func pushWebView(to url: URL) {
        let webView = WebView(initialURL: url)
            .environment(\.primaryColor, Color(configuration.sdkConfiguration.primaryColor))
        let controller = WorkingHostingController(rootView: webView)

        addCloseButton(to: controller)
        controller.navigationItem.title = configuration.title

        pushViewController(controller, animated: true)
    }

    func addCloseButton(to controller: UIViewController) {
        controller.navigationItem.leftBarButtonItem = closeButton
    }

    @objc
    private func closeWebFeature() {
        store.send(.dismiss)
    }

    @available(*, unavailable)
    @MainActor dynamic required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
