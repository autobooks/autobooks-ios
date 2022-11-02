import SwiftUI

@available(iOS 14.0, *)
struct ActivityProgressViewStyle: ProgressViewStyle {
    let style: UIActivityIndicatorView.Style
    let color: UIColor

    func makeBody(configuration: Configuration) -> some View {
        VStack {
            ActivityIndicator(style: style, color: color)
            configuration.label
        }
    }

    private struct ActivityIndicator: UIViewRepresentable {
        let style: UIActivityIndicatorView.Style
        let color: UIColor

        func makeUIView(context: Context) -> UIActivityIndicatorView {
            let view = UIActivityIndicatorView(style: style)
            view.startAnimating()
            view.color = color

            return view
        }

        func updateUIView(_ uiView: UIActivityIndicatorView, context: Context) {}
    }
}

@available(iOS 14.0, *)
extension ProgressViewStyle where Self == ActivityProgressViewStyle {
    static func activity(style: UIActivityIndicatorView.Style, color: UIColor) -> ActivityProgressViewStyle {
        ActivityProgressViewStyle(style: style, color: color)
    }
}

@available(iOS 14.0, *)
struct WorkingLinearProgressViewStyle: ProgressViewStyle {
    func makeBody(configuration: Configuration) -> some View {
        WrappedLinearProgressView(progress: Binding(get: { configuration.fractionCompleted },
                                                    set: { _ in }))
    }

    private struct WrappedLinearProgressView: UIViewRepresentable {
        @Environment(\.primaryColor) var primaryColor

        @Binding var progress: Double?

        func makeUIView(context: Context) -> UIProgressView {
            let view = UIProgressView(progressViewStyle: .bar)
            view.progressTintColor = UIColor(primaryColor)

            return view
        }

        func updateUIView(_ uiView: UIProgressView, context: Context) {
            uiView.setProgress(Float(progress ?? 0), animated: true)
        }
    }
}

@available(iOS 14.0, *)
extension ProgressViewStyle where Self == WorkingLinearProgressViewStyle {
    static var workingLinear: WorkingLinearProgressViewStyle {
        WorkingLinearProgressViewStyle()
    }
}
