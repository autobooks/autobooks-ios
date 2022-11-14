import SwiftUI

@available(iOS 14.0, *)
struct MessageActionView: View {
    struct Action {
        static func tryAgain(_ action: @escaping () -> Void) -> Action {
            .init(title: "Try Again", action: action)
        }

        static func start(_ action: @escaping () -> Void) -> Action {
            .init(title: "Get Started", action: action)
        }

        let title: String
        let action: () -> Void

        func callAsFunction() {
            action()
        }
    }

    enum SourceDomain {
        case tapToPay, webFeature
    }

    private struct MessageIcon: View {
        let domain: SourceDomain

        var body: some View {
            switch domain {
            case .tapToPay:
                if let image = UIImage(named: "tapToPayIcon", in: .resources, compatibleWith: nil) {
                    Image(uiImage: image)
                        .accessibilityHidden(true)
                }
            case .webFeature:
                Image(systemName: "exclamationmark.triangle")
                    .font(.system(size: 72))
                    .accessibilityHidden(true)
            }
        }
    }

    let title: String
    let message: String
    let sourceDomain: SourceDomain
    let action: Action?
    let secondaryAction: Action?

    init(title: String, message: String, sourceDomain: SourceDomain = .tapToPay, action: Action?, secondaryAction: Action? = nil) {
        self.title = title
        self.message = message
        self.sourceDomain = sourceDomain
        self.action = action
        self.secondaryAction = secondaryAction
    }

    var body: some View {
        VStack {
            Spacer()
                .frame(height: 36)

            MessageIcon(domain: sourceDomain)

            Spacer()
                .frame(height: 93)

            VStack(spacing: 56) {
                Text(title)
                    .font(.largeTitle.weight(.bold))
                    .multilineTextAlignment(.center)

                Text(message)
                    .font(.title2)
                    .multilineTextAlignment(.center)
            }
            .accessibilityElement(children: .combine)

            Spacer()

            if let action = action {
                Button {
                    action()
                } label: {
                    Text(action.title)
                }
                .buttonStyle(.action)
            }

            if let secondaryAction = secondaryAction {
                Button {
                    secondaryAction()
                } label: {
                    Text(secondaryAction.title)
                }
                .buttonStyle(.secondary)
            }
        }
        .padding(32)
    }
}
