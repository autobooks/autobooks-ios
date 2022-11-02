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

    let title: String
    let message: String
    let action: Action?

    init(title: String, message: String, action: Action?) {
        self.title = title
        self.message = message
        self.action = action
    }

    var body: some View {
        VStack {
            Spacer()
                .frame(height: 36)

            if let image = UIImage(named: "tapToPayIcon", in: .resources, compatibleWith: nil) {
                Image(uiImage: image)
                    .accessibilityHidden(true)
            }

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
        }
        .padding(32)
    }
}
