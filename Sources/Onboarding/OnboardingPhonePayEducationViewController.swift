import SwiftUI

final class OnboardingPhonePayEducationViewController: OnboardingEducationViewController {}

struct OnboardingPhonePayEducationView: UIViewControllerRepresentable {
    typealias UIViewControllerType = OnboardingPhonePayEducationViewController

    func makeUIViewController(context: Context) -> OnboardingPhonePayEducationViewController {
        let storyboard = UIStoryboard(name: "Onboarding", bundle: Bundle(for: OnboardingPhonePayEducationViewController.self))
        return storyboard.instantiateViewController(withIdentifier: "OnboardingPhonePayEducationViewController") as! OnboardingPhonePayEducationViewController
    }
    
    func updateUIViewController(_ uiViewController: OnboardingPhonePayEducationViewController, context: Context) {}
}
