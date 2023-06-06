import SwiftUI

@available(iOS 16.0, *)
struct ErrorText: View {
    let message: String

    init(_ message: String) {
        self.message = message
    }

    var body: some View {
        HStack {
            Image(systemName: "info.circle")
            Text(message)
        }
        .font(.system(.footnote))
        .foregroundColor(.red)
        .frame(maxWidth: .infinity, alignment: .leading)
        .accessibilityRepresentation {
            Text(message)
        }
    }
}
