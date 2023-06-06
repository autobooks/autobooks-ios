import SwiftUI
import UIKit

class OnboardingEducationViewController: UIViewController {
    @IBOutlet var titleLabel: UILabel!
    @IBOutlet var imageView: UIImageView!
    @IBOutlet var instructionsLabels: [UILabel]!

    override func viewDidLoad() {
        super.viewDidLoad()
        
        navigationController?.navigationBar.backIndicatorImage = UIImage()
        
        titleLabel.font = UIFont.preferredFont(forTextStyle: .title1).bold

        let instructionsLabelParagraphStyle = NSMutableParagraphStyle()
        instructionsLabelParagraphStyle.headIndent = 20

        for instructionsLabel in instructionsLabels {
            instructionsLabel.attributedText = NSAttributedString(string: instructionsLabel.text ?? "", attributes: [.paragraphStyle: instructionsLabelParagraphStyle])
        }
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        titleLabel.layer.isHidden = true
        imageView.layer.isHidden = true

        for instructionsLabel in instructionsLabels {
            instructionsLabel.layer.isHidden = true
        }

        navigationController?.setNavigationBarHidden(false, animated: false)
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        // MARK: Animation timing

        let now = CACurrentMediaTime()
        let titleTransitionBeginTime = now
        let imageTransitionBeginTime = now + 0.2
        let instructionTransitionBeginTime = now + 0.4

        // MARK: titleLabel animations

        let titleSlideTransition = CABasicAnimation(keyPath: "position.x")
        titleSlideTransition.fromValue = titleLabel.layer.position.x - 40
        titleSlideTransition.toValue = titleLabel.layer.position.x
        titleSlideTransition.duration = 0.4
        titleSlideTransition.beginTime = titleTransitionBeginTime
        titleSlideTransition.fillMode = .backwards
        titleSlideTransition.timingFunction = CAMediaTimingFunction(name: .easeOut)

        let titleFadeTransition = CABasicAnimation(keyPath: "opacity")
        titleFadeTransition.fromValue = 0
        titleFadeTransition.toValue = 1
        titleFadeTransition.duration = 0.4
        titleFadeTransition.beginTime = titleTransitionBeginTime
        titleFadeTransition.fillMode = .backwards
        titleFadeTransition.timingFunction = CAMediaTimingFunction(name: .easeOut)

        titleLabel.layer.isHidden = false
        titleLabel.layer.add(titleSlideTransition, forKey: nil)
        titleLabel.layer.add(titleFadeTransition, forKey: nil)
        
        // MARK: imageView animations

        let imageAnimation = CABasicAnimation(keyPath: "opacity")
        imageAnimation.fromValue = 0
        imageAnimation.toValue = 1
        imageAnimation.duration = 0.4
        imageAnimation.fillMode = .backwards
        imageAnimation.beginTime = imageTransitionBeginTime
        imageAnimation.timingFunction = CAMediaTimingFunction(name: .easeOut)

        imageView.layer.isHidden = false
        imageView.layer.add(imageAnimation, forKey: nil)
        
        // MARK: instructionLabel animations

        for (instructionLabelIndex, instructionLabel) in instructionsLabels.enumerated() {
            let offset: CFTimeInterval = instructionTransitionBeginTime + (CFTimeInterval(instructionLabelIndex) * 0.1)
            
            let instructionSlideTransition = CABasicAnimation(keyPath: "position.y")
            instructionSlideTransition.fromValue = instructionLabel.layer.position.y + 20
            instructionSlideTransition.toValue = instructionLabel.layer.position.y
            instructionSlideTransition.duration = 0.4
            instructionSlideTransition.beginTime = offset
            instructionSlideTransition.fillMode = .backwards
            instructionSlideTransition.timingFunction = CAMediaTimingFunction(name: .easeOut)
            
            let instructionFadeTransition = CABasicAnimation(keyPath: "opacity")
            instructionFadeTransition.fromValue = 0
            instructionFadeTransition.toValue = 1
            instructionFadeTransition.duration = 0.4
            instructionFadeTransition.beginTime = offset
            instructionFadeTransition.fillMode = .backwards
            instructionFadeTransition.timingFunction = CAMediaTimingFunction(name: .easeOut)

            instructionLabel.layer.isHidden = false
            instructionLabel.layer.add(instructionSlideTransition, forKey: nil)
            instructionLabel.layer.add(instructionFadeTransition, forKey: nil)
        }
    }
}
