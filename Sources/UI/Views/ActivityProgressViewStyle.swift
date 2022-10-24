import SwiftUI

@available(iOS 15.4, *)
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

@available(iOS 15.4, *)
extension ProgressViewStyle where Self == ActivityProgressViewStyle {
    static func activity(style: UIActivityIndicatorView.Style, color: UIColor) -> ActivityProgressViewStyle {
        ActivityProgressViewStyle(style: style, color: color)
    }
}
