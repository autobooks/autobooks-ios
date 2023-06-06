import SceneKit
import SwiftUI

final class OnboardingWaitForTTPSetupViewController: OnboardingWaitViewController {
    @IBOutlet var checkmarkView: OnboardingCheckmarkView!
    @IBOutlet var scnView: SCNView!

    var scene: SCNScene!
    
    var confettiParticleSystem: SCNParticleSystem? {
        scene.rootNode.childNodes.first?.particleSystems?.first
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        guard let url = Bundle(for: OnboardingWaitForTTPSetupViewController.self).url(forResource: "Confetti", withExtension: "scn", subdirectory: "Onboarding.scnassets"),
              let scene = try? SCNScene(url: url),
              #available(iOS 16.0, *) else {
            return
        }
        
        let notificationEvent = TapToPay.Action.firstTimeReaderReady
        let notificationName = Notification.Name(rawValue: String(describing: notificationEvent))
        NotificationCenter.default.addObserver(self, selector: #selector(didReceiveNotificationOfReaderReady), name: notificationName, object: nil)

        self.scene = scene

        confettiParticleSystem?.birthRate = 0
        confettiParticleSystem?.particleColor = .systemBlue
        confettiParticleSystem?.particleColorVariation = SCNVector4(0.25, 0, 0, 0)
        scene.background.contents = UIColor.clear

        let cameraNode = SCNNode()
        let camera = SCNCamera()
        camera.usesOrthographicProjection = true

        cameraNode.camera = camera
        cameraNode.position = SCNVector3(x: 0, y: 0, z: 15)
        scene.rootNode.addChildNode(cameraNode)
        
        let lightNode = SCNNode()
        lightNode.light = SCNLight()
        lightNode.light!.type = .omni
        lightNode.position = SCNVector3(x: 0, y: 10, z: 10)
        scene.rootNode.addChildNode(lightNode)
        
        let ambientLightNode = SCNNode()
        ambientLightNode.light = SCNLight()
        ambientLightNode.light!.type = .ambient
        ambientLightNode.light!.color = UIColor.darkGray
        scene.rootNode.addChildNode(ambientLightNode)
        
        scnView.scene = scene
        scnView.backgroundColor = UIColor.clear
        scnView.showsStatistics = false
        scnView.allowsCameraControl = false
    }
    
    @objc private func didReceiveNotificationOfReaderReady(_ sender: Notification) {
        let now = CACurrentMediaTime()
        let titleLabelTransitionBeginTime = now
        let progressViewAnimationBeginTime = now + 0.2
        let pleaseWaitLabelAnimationBeginTime = now + 0.4
        let checkmarkViewAnimationBeginTime = now + 0.6

        let titleLabelTransition = CATransition()
        titleLabelTransition.type = .push
        titleLabelTransition.duration = 0.4
        titleLabelTransition.beginTime = titleLabelTransitionBeginTime
        titleLabelTransition.timingFunction = CAMediaTimingFunction(name: .easeOut)
        titleLabel.text = "Tap to Pay for iPhone\nis ready."
        titleLabel.layer.add(titleLabelTransition, forKey: nil)

        let progressViewAnimation = CABasicAnimation(keyPath: "opacity")
        progressViewAnimation.fromValue = 1
        progressViewAnimation.toValue = 0
        progressViewAnimation.duration = 0.4
        progressViewAnimation.fillMode = .forwards
        progressViewAnimation.isRemovedOnCompletion = false
        progressViewAnimation.beginTime = progressViewAnimationBeginTime
        progressViewAnimation.timingFunction = CAMediaTimingFunction(name: .easeOut)
        progressView.layer.add(progressViewAnimation, forKey: nil)

        let pleaseWaitLabelAnimation = CABasicAnimation(keyPath: "opacity")
        pleaseWaitLabelAnimation.fromValue = 1
        pleaseWaitLabelAnimation.toValue = 0
        pleaseWaitLabelAnimation.duration = 0.4
        pleaseWaitLabelAnimation.fillMode = .forwards
        pleaseWaitLabelAnimation.isRemovedOnCompletion = false
        pleaseWaitLabelAnimation.beginTime = pleaseWaitLabelAnimationBeginTime
        pleaseWaitLabelAnimation.timingFunction = CAMediaTimingFunction(name: .easeOut)
        pleaseWaitLabel.layer.add(pleaseWaitLabelAnimation, forKey: nil)

        checkmarkView.layer.opacity = 1
        checkmarkView.animate(at: checkmarkViewAnimationBeginTime)
        
        confettiParticleSystem?.birthRate = 64
    }
}

struct OnboardingWaitForTTPSetupView: UIViewControllerRepresentable {
    typealias UIViewControllerType = OnboardingWaitForTTPSetupViewController
    
    func makeUIViewController(context: Context) -> OnboardingWaitForTTPSetupViewController {
        let storyboard = UIStoryboard(name: "Onboarding", bundle: Bundle(for: OnboardingWaitForTTPSetupViewController.self))
        return storyboard.instantiateViewController(withIdentifier: "OnboardingWaitForTTPSetupViewController") as! OnboardingWaitForTTPSetupViewController
    }
    
    func updateUIViewController(_ uiViewController: OnboardingWaitForTTPSetupViewController, context: Context) {}
}
