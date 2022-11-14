import SwiftUI
import WebKit

@available(iOS 14.0, *)
struct WebView: View {
    enum LoadingState: Equatable {
        case initialLoad(Load)
        case loaded(Load)

        enum Load: Equatable {
            case idle
            case loadingStarted
            case loading(progress: Double)
            case error
        }

        var isLoading: Bool {
            switch self {
            case .initialLoad(.loading), .loaded(.loading):
                return true
            default:
                return false
            }
        }

        var isError: Bool {
            switch self {
            case .initialLoad(.error), .loaded(.error):
                return true
            default:
                return false
            }
        }

        var progress: Double? {
            switch self {
            case let .initialLoad(.loading(progress)),
                 let .loaded(.loading(progress)):
                return progress
            default:
                return nil
            }
        }

        var isInitialLoadFailure: Bool {
            switch self {
            case .initialLoad(.error):
                return true
            default:
                return false
            }
        }

        mutating func startLoading() {
            switch self {
            case .initialLoad(.idle):
                self = .initialLoad(.loadingStarted)
            case .loaded(.idle):
                self = .loaded(.loadingStarted)
            default:
                break
            }
        }

        mutating func updateProgress(_ progress: Double) {
            switch self {
            case .initialLoad(.loadingStarted), .loaded(.loadingStarted), .initialLoad(.loading), .loaded(.loading):
                self = .initialLoad(.loading(progress: progress))
            default:
                break
            }
        }

        mutating func updateToError() {
            switch self {
            case .initialLoad:
                self = .initialLoad(.error)
            case .loaded:
                self = .loaded(.error)
            }
        }

        mutating func finishLoading() {
            switch self {
            case .initialLoad:
                self = .initialLoad(.idle)
            case .loaded:
                self = .loaded(.idle)
            }
        }
    }

    @State private var state: LoadingState = .initialLoad(.idle)

    let initialURL: URL

    var body: some View {
        if state.isInitialLoadFailure {
            MessageActionView(title: "Something went wrong",
                              message: "Try again or check back later",
                              sourceDomain: .webFeature,
                              action: .tryAgain {
                                  state = .initialLoad(.idle)
                              })
        } else {
            WrappedWebView(initialURL: initialURL, state: $state)
                .frame(maxWidth: .infinity, maxHeight: .infinity)
                .overlay(progressOverlay, alignment: .top)
        }
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
                var policy: WKNavigationActionPolicy = .allow

                if navigationAction.navigationType == .linkActivated, let url = navigationAction.request.url {
                    policy = .cancel
                    UIApplication.shared.open(url)
                }

                if observations.isEmpty {
                    observations = [
                        webView.observe(\.estimatedProgress) { [unowned self] webView, _ in
                            state.updateProgress(webView.estimatedProgress)
                        }
                    ]
                }

                decisionHandler(policy)
            }

            func webView(_ webView: WKWebView, didCommit navigation: WKNavigation!) {
                state.startLoading()
            }

            func webView(_ webView: WKWebView, didFinish navigation: WKNavigation!) {
                state.finishLoading()
            }

            func webView(_ webView: WKWebView, didFail navigation: WKNavigation!, withError error: Error) {
                state.updateToError()
            }

            func webView(_ webView: WKWebView, didFailProvisionalNavigation navigation: WKNavigation!, withError error: Error) {
                state.updateToError()
            }
        }
    }
}
