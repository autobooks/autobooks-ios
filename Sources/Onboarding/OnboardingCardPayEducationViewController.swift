import SwiftUI

final class OnboardingCardPayEducationViewController: OnboardingEducationViewController {}

struct OnboardingCardPayEducationView: UIViewControllerRepresentable {
    typealias UIViewControllerType = OnboardingCardPayEducationViewController

    func makeUIViewController(context: Context) -> OnboardingCardPayEducationViewController {
        let storyboard = UIStoryboard(name: "Onboarding", bundle: Bundle(for: OnboardingCardPayEducationViewController.self))
        return storyboard.instantiateViewController(withIdentifier: "OnboardingCardPayEducationViewController") as! OnboardingCardPayEducationViewController
    }
    
    func updateUIViewController(_ uiViewController: OnboardingCardPayEducationViewController, context: Context) {}
}
