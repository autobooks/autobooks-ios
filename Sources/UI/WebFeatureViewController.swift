import UIKit
import WebKit

final class WebFeatureViewController: UIViewController {
    private let feature: Autobooks.WebFeature

    init(feature: Autobooks.WebFeature) {
        self.feature = feature

        super.init(nibName: nil, bundle: nil)
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        navigationItem.title = feature.title
        navigationItem.leftBarButtonItem = UIBarButtonItem(title: "Close",
                                                           style: .done,
                                                           target: self,
                                                           action: #selector(dismissView))

        if #available(iOS 13.0, *) {
            view.backgroundColor = .systemBackground
        } else {
            view.backgroundColor = .white
        }

        let configuration = WKWebViewConfiguration()
        configuration.websiteDataStore = .nonPersistent()
        let webView = WKWebView(frame: .zero, configuration: configuration)
        webView.translatesAutoresizingMaskIntoConstraints = false

        view.addSubview(webView)
        NSLayoutConstraint.activate([
            webView.leadingAnchor.constraint(equalTo: view.leadingAnchor),
            webView.trailingAnchor.constraint(equalTo: view.trailingAnchor),
            webView.topAnchor.constraint(equalTo: view.topAnchor),
            webView.bottomAnchor.constraint(equalTo: view.bottomAnchor)
        ])

        webView.load(.init(url: feature.url))
    }

    @objc
    private func dismissView() {
        dismiss(animated: true)
    }

    @available(*, unavailable)
    @MainActor dynamic required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
