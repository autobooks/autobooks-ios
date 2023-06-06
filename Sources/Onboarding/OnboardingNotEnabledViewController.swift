import SwiftUI
import UIKit

final class OnboardingNotEnabledViewController: UIViewController {
    @IBOutlet var titleLabel: UILabel!
    @IBOutlet var subtitleLabel: UILabel!
    @IBOutlet var contactButton: UIButton!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        titleLabel.font = UIFont.preferredFont(forTextStyle: .title1).bold

        let captionFont = UIFont.preferredFont(forTextStyle: .caption1)

        let centerAlignment = NSMutableParagraphStyle()
        centerAlignment.alignment = .center
        
        let contactButtonAttributedTitle = [
            NSAttributedString(string: "If you have questions, call us toll-free at\n", attributes: [
                .font: captionFont,
                .foregroundColor: UIColor.secondaryLabel,
                .paragraphStyle: centerAlignment,
            ]),
            NSAttributedString(string: "(866) 617-3122", attributes: [
                .font: captionFont,
                .foregroundColor: view.tintColor ?? UIColor.systemBlue,
                .paragraphStyle: centerAlignment,
            ]),
            NSAttributedString(string: " for assistance.", attributes: [
                .font: captionFont,
                .foregroundColor: UIColor.secondaryLabel,
                .paragraphStyle: centerAlignment,
            ]),
        ].reduce(NSMutableAttributedString()) { output, currentPiece in
            output.append(currentPiece)
            return output
        }
        
        contactButton.setAttributedTitle(contactButtonAttributedTitle, for: .normal)
    }
    
    @IBAction func didTapContactButton(_ sender: UIButton) {
        let contactURL = URL(string: "tel://8666173122")!
        UIApplication.shared.open(contactURL)
    }
}

struct NotEnabledScreen: UIViewControllerRepresentable {
    typealias UIViewControllerType = OnboardingNotEnabledViewController

    func makeUIViewController(context: Context) -> OnboardingNotEnabledViewController {
        let storyboard = UIStoryboard(name: "Onboarding", bundle: Bundle(for: OnboardingNotEnabledViewController.self))
        return storyboard.instantiateViewController(withIdentifier: "OnboardingNotEnabledViewController") as! OnboardingNotEnabledViewController
    }
    
    func updateUIViewController(_ uiViewController: OnboardingNotEnabledViewController, context: Context) {}
}
