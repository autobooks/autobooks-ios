import SwiftUI

@available(iOS 15.4, *)
struct WebViewScreen: View {
    let store: TapToPayStore
    let state: Navigation.Configuration.WebViewState

    var body: some View {
        VStack {
            Text(state.title)
            Button("Close") {
                store.send(.openURL(state.callbackURL))
            }
        }
        .frame(maxWidth: .infinity, maxHeight: .infinity)
    }
}
