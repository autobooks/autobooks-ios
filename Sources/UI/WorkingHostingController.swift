import SwiftUI
import UIKit

@available(iOS 13.0, *)
/// `UIViewController` subclass which embeds a `UIHostingController` to work around various bugs in navigation bar
/// appearance.
class WorkingHostingController<RootView: View>: UIViewController {
    private let hostingController: UIHostingController<RootView>

    init(rootView: RootView) {
        self.hostingController = UIHostingController(rootView: rootView)

        super.init(nibName: nil, bundle: nil)
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        view.backgroundColor = .systemBackground

        hostingController.view.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(hostingController.view)

        NSLayoutConstraint.activate([
            view.safeAreaLayoutGuide.topAnchor.constraint(equalTo: hostingController.view.topAnchor),
            view.safeAreaLayoutGuide.bottomAnchor.constraint(equalTo: hostingController.view.bottomAnchor),
            view.safeAreaLayoutGuide.leadingAnchor.constraint(equalTo: hostingController.view.leadingAnchor),
            view.safeAreaLayoutGuide.trailingAnchor.constraint(equalTo: hostingController.view.trailingAnchor),
        ])

        addChild(hostingController)
        hostingController.didMove(toParent: self)
    }

    @available(*, unavailable)
    @MainActor dynamic required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
}
