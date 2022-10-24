import SwiftUI

@available(iOS 15.0.0, *)
struct Banner: View {
    enum Style {
        case canceled(Date)
        case refunded(Date)
        case custom(String)
    }

    let style: Style

    private var message: String {
        switch style {
        case let .canceled(date):
            return "This payment was canceled on \(date.formatted(date: .abbreviated, time: .omitted))"
        case let .refunded(date):
            return "This payment was refunded on \(date.formatted(date: .abbreviated, time: .omitted))"
        case let .custom(text):
            return text
        }
    }

    var body: some View {
        HStack(spacing: 4) {
            Image(systemName: "info.circle")

            Text(message)
        }
        .font(.subheadline)
        .frame(maxWidth: .infinity, minHeight: 53, alignment: .leading)
        .padding(.horizontal, 32)
        .background(Color(.systemGroupedBackground))
    }
}

@available(iOS 15.0.0, *)
extension Banner {
    init?(transaction: Transaction) {
        switch transaction.status {
        case .canceled: style = .canceled(transaction.date)
        case .refunded: style = .refunded(transaction.date)
        default: return nil
        }
    }
}
