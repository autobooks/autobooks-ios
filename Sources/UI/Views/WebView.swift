import SwiftUI
import WebKit

@available(iOS 14.0, *)
struct WebView: View {
    private enum LoadingState {
        case idle
        case loading(progress: Double?)

        var isLoading: Bool {
            guard case .loading = self else { return false }

            return true
        }

        var progress: Double? {
            guard case let .loading(progress) = self else { return nil }

            return progress
        }
    }

    @State private var state: LoadingState = .loading(progress: nil)

    let initialURL: URL

    var body: some View {
        WrappedWebView(initialURL: initialURL, state: $state)
            .frame(maxWidth: .infinity, maxHeight: .infinity)
            .overlay(progressOverlay, alignment: .top)
    }

    @ViewBuilder
    var progressOverlay: some View {
        if state.isLoading {
            ProgressView("", value: state.progress, total: 1.0)
                .progressViewStyle(.workingLinear)
        }
    }

    private struct WrappedWebView: UIViewRepresentable {
        @Binding var state: LoadingState

        let initialURL: URL

        init(initialURL: URL, state: Binding<LoadingState>) {
            self.initialURL = initialURL
            _state = state
        }

        func makeUIView(context: Context) -> WKWebView {
            let configuration = WKWebViewConfiguration()
            configuration.websiteDataStore = .nonPersistent()
            let webView = WKWebView(frame: .zero, configuration: configuration)
            webView.navigationDelegate = context.coordinator
            webView.load(.init(url: initialURL))

            return webView
        }

        func makeCoordinator() -> Coordinator {
            Coordinator(state: $state)
        }

        func updateUIView(_ uiView: WKWebView, context: Context) {}

        final class Coordinator: NSObject, WKNavigationDelegate {
            @Binding var state: LoadingState
            var observations: [NSKeyValueObservation] = []

            init(state: Binding<LoadingState>) {
                _state = state
            }

            func webView(_ webView: WKWebView, decidePolicyFor navigationAction: WKNavigationAction, decisionHandler: @escaping (WKNavigationActionPolicy) -> Void) {
                defer { decisionHandler(.allow) }

                guard observations.isEmpty else { return }

                observations = [
                    webView.observe(\.estimatedProgress) { [unowned self] webView, _ in
                        state = (webView.isLoading) ? .loading(progress: webView.estimatedProgress) : .idle
                    },
                    webView.observe(\.isLoading) { [unowned self] webView, _ in
                        if !webView.isLoading {
                            withAnimation {
                                state = .idle
                            }
                        }
                    }
                ]
            }
        }
    }
}
