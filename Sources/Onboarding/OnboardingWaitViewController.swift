import SceneKit
import SwiftUI
import UIKit

class OnboardingWaitViewController: UIViewController {
    @IBOutlet var titleLabel: UILabel!
    @IBOutlet var pleaseWaitLabel: UILabel!
    @IBOutlet var progressView: UIProgressView!

    private var timerLink: CADisplayLink!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        titleLabel.font = UIFont.preferredFont(forTextStyle: .title1).bold
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        
        titleLabel.layer.isHidden = true
        pleaseWaitLabel.layer.isHidden = true

        navigationController?.setNavigationBarHidden(false, animated: false)
    }
    
    var startDate: CFTimeInterval!
    var endDate: CFTimeInterval!

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        let now = CACurrentMediaTime()

        // MARK: titleLabel animations

        let titleSlideTransition = CABasicAnimation(keyPath: "position.x")
        titleSlideTransition.fromValue = titleLabel.layer.position.x - 40
        titleSlideTransition.toValue = titleLabel.layer.position.x
        titleSlideTransition.duration = 0.4
        titleSlideTransition.beginTime = now
        titleSlideTransition.fillMode = .backwards
        titleSlideTransition.timingFunction = CAMediaTimingFunction(name: .easeOut)

        let titleFadeTransition = CABasicAnimation(keyPath: "opacity")
        titleFadeTransition.fromValue = 0
        titleFadeTransition.toValue = 1
        titleFadeTransition.duration = 0.4
        titleFadeTransition.beginTime = now
        titleFadeTransition.fillMode = .backwards
        titleFadeTransition.timingFunction = CAMediaTimingFunction(name: .easeOut)
        
        titleLabel.layer.isHidden = false
        titleLabel.layer.add(titleSlideTransition, forKey: nil)
        titleLabel.layer.add(titleFadeTransition, forKey: nil)
        
        // MARK: imageView animations

        let pleaseWaitLabelFadeAnimation = CABasicAnimation(keyPath: "opacity")
        pleaseWaitLabelFadeAnimation.fromValue = 0
        pleaseWaitLabelFadeAnimation.toValue = 1
        pleaseWaitLabelFadeAnimation.duration = 0.4
        pleaseWaitLabelFadeAnimation.fillMode = .backwards
        pleaseWaitLabelFadeAnimation.beginTime = now + 0.2
        pleaseWaitLabelFadeAnimation.timingFunction = CAMediaTimingFunction(name: .easeOut)

        pleaseWaitLabel.layer.isHidden = false
        pleaseWaitLabel.layer.add(pleaseWaitLabelFadeAnimation, forKey: nil)
        
        // MARK: CADisplayLink for progressView

        startDate = CACurrentMediaTime()
        endDate = startDate + 30
        
        timerLink = CADisplayLink(target: self, selector: #selector(updateProgressView))
        timerLink.add(to: .current, forMode: .common)
    }
    
    @objc func updateProgressView() {
        let position = timerLink.targetTimestamp - startDate
        let duration = endDate - startDate
        progressView.setProgress(Float(position / duration), animated: false)
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)

        timerLink.invalidate()
    }
}
