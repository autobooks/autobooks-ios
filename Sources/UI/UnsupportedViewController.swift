import SwiftUI
import UIKit

final class UnsupportedViewController: UIViewController {
    private var imageView = UIImageView()
    private var titleLabel = UILabel()
    private var messageLabel = UILabel()

    var labels: (title: String, message: String) {
        if UIDevice.current.supportsTapToPay { // iPhone XS or later.
            return (title: "Your iOS version isn't supported",
                    message: "You can't use the card reader until you update it")
        } else {
            return (title: "Your device isn't supported",
                    message: "This feature can only be used on an iPhone XS or newer")
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        navigationItem.leftBarButtonItem = UIBarButtonItem(title: "Close", style: .done, target: self, action: #selector(dismissView))

        if #available(iOS 13, *) {
            view.backgroundColor = .systemBackground
        } else {
            view.backgroundColor = .white
        }

        let image = UIImage(named: "tapToPayIcon", in: .resources, compatibleWith: nil)
        imageView = UIImageView(image: image)
        if #available(iOS 13, *) {
            imageView.tintColor = .label
        } else {
            imageView.tintColor = .black
        }
        imageView.accessibilityElementsHidden = true

        imageView.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(imageView)

        let labels = labels
        titleLabel.translatesAutoresizingMaskIntoConstraints = false
        titleLabel.text = labels.title
        titleLabel.textAlignment = .center
        titleLabel.numberOfLines = 0
        titleLabel.font = UIFont.boldSystemFont(ofSize: 30)
        view.addSubview(titleLabel)

        messageLabel.translatesAutoresizingMaskIntoConstraints = false
        messageLabel.text = labels.message
        messageLabel.textAlignment = .center
        messageLabel.numberOfLines = 0
        messageLabel.font = UIFont.systemFont(ofSize: 16)
        view.addSubview(messageLabel)

        applyConstraints()
    }

    func applyConstraints() {
        NSLayoutConstraint.activate([imageView.centerXAnchor.constraint(equalTo: view.centerXAnchor),
                                     imageView.topAnchor.constraint(equalTo: view.safeAreaLayoutGuide.topAnchor, constant: 36),
                                     imageView.widthAnchor.constraint(equalToConstant: 95),
                                     imageView.heightAnchor.constraint(equalToConstant: 56),

                                     titleLabel.centerXAnchor.constraint(equalTo: view.centerXAnchor),
                                     titleLabel.topAnchor.constraint(equalTo: imageView.bottomAnchor, constant: 100),
                                     titleLabel.leadingAnchor.constraint(equalTo: view.leadingAnchor, constant: 10),
                                     titleLabel.trailingAnchor.constraint(equalTo: view.trailingAnchor, constant: -10),

                                     messageLabel.centerXAnchor.constraint(equalTo: view.centerXAnchor),
                                     messageLabel.topAnchor.constraint(equalTo: titleLabel.bottomAnchor, constant: 48),
                                     messageLabel.leadingAnchor.constraint(equalTo: view.leadingAnchor, constant: 10),
                                     messageLabel.trailingAnchor.constraint(equalTo: view.trailingAnchor, constant: -10)])
    }

    @objc func dismissView(sender: UIButton) {
        dismiss(animated: true)
    }
}
