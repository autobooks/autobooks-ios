import SwiftUI

@available(iOS 16.0, *)
struct WebViewScreen: View {
    let store: TapToPayStore
    let state: Navigation.Configuration.WebViewState

    var body: some View {
        VStack {
            WebView(initialURL: state.url)
        }
        .frame(maxWidth: .infinity, maxHeight: .infinity)
    }
}
