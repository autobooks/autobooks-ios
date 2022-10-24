import SwiftUI
import WebKit

@available(iOS 13.0, *)
struct WebView: View {
    let initialURL: URL

    var body: some View {
        WrappedWebView(initialURL: initialURL)
    }

    private struct WrappedWebView: UIViewRepresentable {
        let initialURL: URL

        func makeUIView(context: Context) -> WKWebView {
            let webView = WKWebView(frame: .zero, configuration: .init())
            webView.load(.init(url: initialURL))
            webView.navigationDelegate = context.coordinator

            return webView
        }

        func makeCoordinator() -> Coordinator {
            Coordinator()
        }

        func updateUIView(_ uiView: WKWebView, context: Context) {}

        final class Coordinator: NSObject, WKNavigationDelegate {
            func webView(_ webView: WKWebView, didFinish navigation: WKNavigation!) {
                print("*** WKWebView finished loading \(webView.url?.absoluteString ?? "Nothing")")
            }
        }
    }
}
