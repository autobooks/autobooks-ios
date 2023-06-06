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
        case .idle,
             .finished:
            EmptyView()
        case let .loading(state):
            VStack(spacing: 100) {
                Spacer()
              
                if state.isFailure {
                    MessageActionView(title: "Something Went Wrong",
                                      message: "Try again or check back later",
                                      sourceDomain: .tapToPay,
                                      action: nil,
                                      callUsAction: .callUs {
                                          if let url = URL(string: "tel://8666173122") {
                                              UIApplication.shared.open(url)
                                          }
                                      })
                } else {
                    if let image = UIImage(named: "tapToPayIcon", in: .resources, compatibleWith: nil) {
                        Image(uiImage: image)
                            .accessibilityHidden(true)
                    }
                    Text("Loading Tap to Pay")
                        .font(.title)
                        .bold()
                    VStack {
                        ProgressView(value: Double(state.progress ?? 5), total: 100)
                            .progressViewStyle(.linear)
                            .animation(.default)
                            .padding(20)
                        Spacer()
                    }
                }
            }
            .frame(maxWidth: .infinity, maxHeight: .infinity, alignment: .center)
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
