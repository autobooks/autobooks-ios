import SwiftUI

@available(iOS 14.0, *)
struct LoadingScreen<Action: Equatable>: View {
    typealias ViewStore = Store<ViewState, ViewAction, ViewEnvironment>

    struct ViewState: Equatable {
        var initialLoad: InitialLoad<Action>
    }

    enum ViewAction: Equatable {
        case performParentAction(Action)

        var action: Action {
            switch self {
            case let .performParentAction(action):
                return action
            }
        }
    }

    struct ViewEnvironment {}

    @StateObject private var store: ViewStore

    init(store: ViewStore) {
        _store = StateObject(wrappedValue: store)
    }

    var body: some View {
        switch store.state.initialLoad {
        case .idle, .finished:
            EmptyView()
        case let .loading(state):
            if state.isFailure {
                MessageActionView(title: "Something went wrong",
                                  message: "Try again or check back later",
                                  action: .tryAgain {
                                      store.send(.performParentAction(state.retryAction))
                                  })
            } else {
                ProgressView {
                    text(for: state.message)
                }
                .progressViewStyle(.activity(style: .large, color: .label))
                .foregroundColor(.init(.label))
                .font(.system(.body).monospacedDigit())
                .frame(maxWidth: .infinity, maxHeight: .infinity)
            }
        }
    }

    @ViewBuilder
    private func text(for message: String) -> some View {
        #if swift(>=5.7)
        if #available(iOS 16, *) {
            olderText(for: message)
                .lineLimit(2, reservesSpace: true)
        } else {
            olderText(for: message)
        }
        #else
        olderText(for: message)
        #endif
    }

    private func olderText(for message: String) -> some View {
        Text(message)
            .multilineTextAlignment(.center)
            .id(message) // Make each value unique so SwiftUI < iOS 16 doesn't animate the frame.
    }
}
