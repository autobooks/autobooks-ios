import SwiftUI

final class OnboardingWaitForPaymentEnablementViewController: OnboardingWaitViewController {}

@available(iOS 16.0, *)
struct OnboardingWaitForPaymentEnablementView: UIViewControllerRepresentable {
    let store: TapToPayStore

    typealias UIViewControllerType = OnboardingWaitForPaymentEnablementViewController

    func makeUIViewController(context: Context) -> OnboardingWaitForPaymentEnablementViewController {
        let storyboard = UIStoryboard(name: "Onboarding", bundle: Bundle(for: OnboardingWaitForPaymentEnablementViewController.self))
        return storyboard.instantiateViewController(withIdentifier: "OnboardingWaitForPaymentEnablementViewController") as! OnboardingWaitForPaymentEnablementViewController
    }
    
    func updateUIViewController(_ uiViewController: OnboardingWaitForPaymentEnablementViewController, context: Context) {}
}
