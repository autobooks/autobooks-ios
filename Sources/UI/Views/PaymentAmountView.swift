import SwiftUI
import UIKit

@available(iOS 16.0, *)
struct PaymentAmountView: View {
    @Binding var amount: PaymentAmount
    @Binding var showValidity: Bool

    var body: some View {
        VStack(spacing: 0) {
            HStack(spacing: 4) {
                if showValidity, let message = amount.validity.message {
                    Image(systemName: "info.circle")
                    Text(message)
                }
            }
            .font(.caption)
            .foregroundColor(.red)
            .frame(height: 30, alignment: .bottom)
            .frame(maxWidth: .infinity)

            RepresentableControl(amount: _amount)
                .frame(maxWidth: .infinity)
        }
        .accessibilityRepresentation {
            if showValidity, let message = amount.validity.message {
                Text(message)
            }

            TextField("Amount", text: .constant(amount.formatted))
        }
        .onChange(of: amount) { newValue in
            if newValue.validity == .tooMuch {
                showValidity = true
            } else {
                showValidity = false
            }
        }
    }

    private struct RepresentableControl: UIViewRepresentable {
        @Binding var amount: PaymentAmount

        init(amount: Binding<PaymentAmount>) {
            _amount = amount
        }

        func makeUIView(context: Context) -> PaymentAmountControl {
            let view = PaymentAmountControl(frame: .zero)
            view.addAction(UIAction { [unowned view] _ in
                amount = PaymentAmount(view.amountState)
            }, for: .primaryActionTriggered)

            return view
        }

        func updateUIView(_ uiView: PaymentAmountControl, context: Context) {
            if amount.isInitialValue {
                uiView.reset()
            }
        }

        final class PaymentAmountControl: UIControl, UIKeyInput {
            // MARK: UITextInputTraits

            var keyboardType: UIKeyboardType = .decimalPad

            // MARK: UIResponder

            override var canBecomeFirstResponder: Bool { true }
            override var canResignFirstResponder: Bool { true }

            // MARK: UIView

            override var intrinsicContentSize: CGSize {
                CGSize(width: UIView.noIntrinsicMetric, height: amountLabel.intrinsicContentSize.height)
            }

            // MARK: Stored Values

            private let amountLabel: UILabel = {
                let label = UILabel(frame: .zero)
                label.textAlignment = .center
                label.translatesAutoresizingMaskIntoConstraints = false
                label.setContentCompressionResistancePriority(.defaultLow, for: .horizontal)
                label.adjustsFontForContentSizeCategory = true
                label.adjustsFontSizeToFitWidth = true
                label.minimumScaleFactor = 0.5

                return label
            }()

            var amountState = AmountState()

            override init(frame: CGRect) {
                super.init(frame: frame)

                setContentHuggingPriority(.defaultHigh, for: .vertical)

                addSubview(amountLabel)
                NSLayoutConstraint.activate([amountLabel.topAnchor.constraint(equalTo: topAnchor),
                                             amountLabel.bottomAnchor.constraint(equalTo: bottomAnchor),
                                             amountLabel.leadingAnchor.constraint(equalTo: leadingAnchor),
                                             amountLabel.trailingAnchor.constraint(equalTo: trailingAnchor),
                                             amountLabel.heightAnchor.constraint(equalTo: heightAnchor),
                                             amountLabel.widthAnchor.constraint(equalTo: widthAnchor)])
                amountLabel.attributedText = NSAttributedString(amountState.attributed)
            }

            override func becomeFirstResponder() -> Bool {
                super.becomeFirstResponder()

                return true
            }

            override func didMoveToWindow() {
                super.didMoveToWindow()

                _ = becomeFirstResponder()
            }

            func reset() {
                let emptyState = AmountState()
                guard amountState != emptyState else {
                    return
                }

                amountState = emptyState
                amountLabel.attributedText = NSAttributedString(amountState.attributed)
            }

            // MARK: UIKeyInput

            var hasText: Bool {
                amountLabel.text != nil
            }

            func insertText(_ text: String) {
                guard text.count == 1 else {
                    Log.sdk.debug("*** empty or long text")
                    return
                }

                guard let character = text.first else {
                    Log.sdk.debug("*** no character")
                    return
                }

                guard (character.isASCII && character.isWholeNumber) || character == "." else {
                    return
                }

                amountState.insert(character)
                if amountState.isOverInserted {
                    shakeText()
                }
                amountLabel.attributedText = NSAttributedString(amountState.attributed)

                sendActions(for: .primaryActionTriggered)
            }

            func deleteBackward() {
                amountState.delete()
                amountLabel.attributedText = NSAttributedString(amountState.attributed)

                sendActions(for: .primaryActionTriggered)
            }

            func shakeText() {
                let offset: CGFloat = 25
                let animator = UIViewPropertyAnimator(duration: 0.5, curve: .linear) {
                    self.amountLabel.transform = CGAffineTransform(translationX: offset, y: 0)
                }
                animator.addAnimations({
                    self.amountLabel.transform = CGAffineTransform(translationX: -offset, y: 0)
                }, delayFactor: 0.1)
                animator.addAnimations({
                    self.amountLabel.transform = CGAffineTransform(translationX: offset, y: 0)
                }, delayFactor: 0.2)
                animator.addAnimations({
                    self.amountLabel.transform = CGAffineTransform(translationX: -offset, y: 0)
                }, delayFactor: 0.3)
                animator.addAnimations({
                    self.amountLabel.transform = CGAffineTransform(translationX: offset, y: 0)
                }, delayFactor: 0.4)
                animator.addAnimations({
                    self.amountLabel.transform = .identity
                }, delayFactor: 0.5)
                animator.isInterruptible = true
                animator.startAnimation()
            }

            @available(*, unavailable)
            required init?(coder: NSCoder) {
                fatalError("init(coder:) has not been implemented")
            }
        }
    }
}

struct PaymentAmount: Equatable {
    let decimal: Decimal
    let formatted: String
    let validity: PaymentValidity
    let isValid: Bool

    var isInitialValue: Bool {
        decimal == 0 && formatted == "$0" && validity == .lessThanOne && !isValid
    }
}

@available(iOS 16.0, *)
extension PaymentAmount {
    init(_ amountState: AmountState) {
        self.decimal = amountState.decimal
        self.formatted = amountState.formatted
        self.validity = amountState.validity
        self.isValid = amountState.isValid
    }

    init() {
        self.decimal = 0
        self.formatted = "$0"
        self.validity = .lessThanOne
        self.isValid = false
    }
}

enum PaymentValidity: Equatable {
    case valid
    case lessThanOne
    case missingCents
    case tooMuch

    var message: String? {
        switch self {
        case .valid:
            return nil
        case .lessThanOne:
            return "Please enter at least $1"
        case .missingCents:
            return "Please enter the full amount"
        case .tooMuch:
            return "You can't enter more than $9,999,999.99"
        }
    }
}

@available(iOS 16.0, *)
struct AmountState: Equatable {
    enum Action {
        case insert
        case delete
        case overInsert
    }

    private static let font: UIFont = {
        let systemFont = UIFont.monospacedDigitSystemFont(ofSize: 55, weight: .regular)
        let descriptor = systemFont.fontDescriptor.withDesign(.rounded)
        let font = UIFont(descriptor: descriptor!, size: 55)
        let metrics = UIFontMetrics(forTextStyle: .largeTitle)

        return metrics.scaledFont(for: font)
    }()

    private(set) var decimal: Decimal = 0
    private(set) var formatted = "$0"
    private(set) var attributed: AttributedString
    private(set) var validity: PaymentValidity = .lessThanOne
    private(set) var isOverInserted = false
    var isValid: Bool {
        validity == .valid || validity == .tooMuch
    }

    private var dollars = ""
    private var cents = ""
    private var isInDecimal = false
    private let maxDollarLength = 7
    private let maxAmount: Decimal = .init(string: "9999999.99")!

    init() {
        var attributes = AttributeContainer()
        attributes.font = AmountState.font
        attributes.foregroundColor = .tertiaryLabel
        self.attributed = AttributedString("$0", attributes: attributes)
    }

    mutating func insert(_ character: Character) {
        if character == "." {
            if isInDecimal || dollars.isEmpty {
                updateState(for: .insert)
            } else {
                isInDecimal = true
                updateState(for: .insert)
            }
        } else if character.isASCII, character.isWholeNumber {
            if isInDecimal {
                if cents.count < 2 {
                    cents.append(character)
                    updateState(for: .insert)
                } else {
                    updateState(for: .overInsert)
                }
            } else {
                if dollars.count < maxDollarLength {
                    #if !DEBUG
                    if dollars.isEmpty, character == "0" {
                        return // Ignore leading 0.
                    }
                    #endif

                    dollars.append(character)
                    updateState(for: .insert)
                } else {
                    updateState(for: .overInsert)
                }
            }
        }
    }

    mutating func delete() {
        if isInDecimal {
            if cents.isEmpty {
                isInDecimal = false
                updateState(for: .delete)
            } else {
                cents.removeLast()
                updateState(for: .delete)
            }
        } else {
            if dollars.isEmpty {
                return // Ignore additional deletions.
            } else {
                dollars.removeLast()
                updateState(for: .delete)
            }
        }
    }

    private mutating func updateState(for action: Action) {
        isOverInserted = (action == .overInsert)
        updateOutputs()
        updateAttributedString()
        calculateValidity(for: action)
    }

    private mutating func updateOutputs() {
        let dollarsToFormat = (dollars.isEmpty) ? "0" : dollars
        let centsToFormat = (cents.isEmpty && !isInDecimal) ? "." : ".\(cents)"
        decimal = Decimal(string: "\(dollarsToFormat)\(centsToFormat)") ?? 0
        formatted = decimal.formatted(.dollars.precision(.fractionLength(isInDecimal ? 2 : 0)))
    }

    private mutating func updateAttributedString() {
        var attributedString = AttributedString(formatted)
        attributedString.font = AmountState.font

        if let decimalRange = attributedString.range(of: ".") {
            attributedString[..<decimalRange.lowerBound].foregroundColor = .label

            let decimalIndex = decimalRange.upperBound
            if cents.isEmpty {
                attributedString[decimalRange].foregroundColor = .label
                attributedString[decimalIndex...].foregroundColor = .tertiaryLabel
            } else {
                let filledCentsRange = decimalIndex..<attributedString.index(decimalIndex, offsetByCharacters: cents.count - 1)

                attributedString[filledCentsRange].foregroundColor = .label
                attributedString[attributedString.index(afterCharacter: filledCentsRange.upperBound)...].foregroundColor = .tertiaryLabel
            }
        } else {
            if dollars.isEmpty {
                attributedString.foregroundColor = .tertiaryLabel
            } else {
                attributedString.foregroundColor = .label
            }
        }

        attributed = attributedString
    }

    mutating func calculateValidity(for action: Action) {
        if isInDecimal {
            if cents.count == 2 {
                if action == .overInsert {
                    validity = decimal > maxAmount ? .tooMuch : .valid
                } else {
                    validity = .valid
                }
            } else {
                validity = .missingCents
            }
        } else {
            if dollars.isEmpty {
                validity = .lessThanOne
            } else {
                if action == .overInsert {
                    validity = .tooMuch
                } else {
                    validity = .valid
                }
            }
        }
    }
}
