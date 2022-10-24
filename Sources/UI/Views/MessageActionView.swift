import SwiftUI

@available(iOS 15.4, *)
struct MessageActionView: View {
    struct Action {
        static func tryAgain(_ action: RootAction) -> Action {
            .init(title: "Try Again", action: action)
        }

        static var start: Action {
            .init(title: "Get Started", action: .start)
        }

        let title: String
        let action: RootAction
    }

    @StateObject private var store: RootStore

    let title: String
    let message: String
    let action: Action?

    init(store: RootStore, title: String, message: String, action: Action?) {
        _store = StateObject(wrappedValue: store)
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
            .accessibilityRepresentation {
                Text("\(title). \(message).")
            }

            Spacer()

            if let action = action {
                Button {
                    store.send(action.action)
                } label: {
                    Text(action.title)
                }
                .buttonStyle(.action)
            }
        }
        .padding(32)
    }
}
