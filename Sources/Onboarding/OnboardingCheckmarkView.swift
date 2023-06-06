import UIKit

class OnboardingCheckmarkView: UIView {
    // MARK: - Initialization

    init() {
        super.init(frame: CGRect(x: 0, y: 0, width: 30, height: 30))
        commonInit()
    }

    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
        commonInit()
    }

    // MARK: - Setup Layers

    let checkmarkShapeLayer = CAShapeLayer()
    
    private func commonInit() {
        // Colors
        let fillColor = UIColor.clear
        let strokeColor = UIColor.systemBlue

        // Paths
        let checkmarkPath = CGMutablePath()
        checkmarkPath.move(to: CGPoint(x: 0.4, y: 16.379999))
        checkmarkPath.addLine(to: CGPoint(x: 11.15, y: 30.27))
        checkmarkPath.addLine(to: CGPoint(x: 11.15, y: 30.27))
        checkmarkPath.addLine(to: CGPoint(x: 30.09, y: 0.27))

        checkmarkShapeLayer.name = "Onboarding Success Checkmark"
        checkmarkShapeLayer.bounds = CGRect(x: 0, y: 0, width: 53, height: 53)
        checkmarkShapeLayer.position = CGPoint(x: 0, y: 0)
        checkmarkShapeLayer.anchorPoint = CGPoint(x: 0, y: 0)
        checkmarkShapeLayer.contentsGravity = .center
        checkmarkShapeLayer.shadowOffset = CGSize(width: 0, height: 1)
        checkmarkShapeLayer.allowsEdgeAntialiasing = true
        checkmarkShapeLayer.allowsGroupOpacity = true
        checkmarkShapeLayer.fillMode = .forwards

        checkmarkShapeLayer.path = checkmarkPath
        checkmarkShapeLayer.fillColor = fillColor.cgColor
        checkmarkShapeLayer.strokeColor = strokeColor.cgColor
        checkmarkShapeLayer.lineCap = .round
        checkmarkShapeLayer.lineJoin = .round
        checkmarkShapeLayer.lineWidth = 5
        checkmarkShapeLayer.strokeEnd = 0

        layer.addSublayer(checkmarkShapeLayer)
    }
    
    func animate(at beginTime: CFTimeInterval = 0) {
        let strokeEndAnimation = CABasicAnimation()
        strokeEndAnimation.beginTime = layer.convertTime(CACurrentMediaTime(), from: nil) + 0.000001
        strokeEndAnimation.duration = 0.25
        strokeEndAnimation.fillMode = .forwards
        strokeEndAnimation.isRemovedOnCompletion = false
        strokeEndAnimation.timingFunction = CAMediaTimingFunction(name: .easeIn)
        strokeEndAnimation.beginTime = beginTime
        strokeEndAnimation.keyPath = "strokeEnd"
        strokeEndAnimation.toValue = 1

        checkmarkShapeLayer.add(strokeEndAnimation, forKey: "strokeEndAnimation")
    }
}
