import SwiftUI

@available(iOS 15.4, *)
struct PostsaleScreen: View {
    @StateObject private var store: RootStore

    init(store: RootStore) {
        _store = StateObject(wrappedValue: store)
    }

    var body: some View {
        TransactionSummary(store: store, transaction: \.transactionResult?.success?.transaction, configuration: .success)
    }
}

@available(iOS 15.0, *)
extension Transaction {
    struct UIElement: Identifiable {
        var id: String { label }

        let label: String
        let image: String
        let content: String
    }

    var uiElements: [UIElement] {
        var elements: [UIElement] = [.init(label: "Paid by", image: "person.circle", content: name),
                                     .init(label: "Card", image: "creditcard", content: cardDescription),
                                     .init(label: "Paid on", image: "calendar", content: date.formatted(date: .long, time: .omitted))]

        if let email = lastReceiptEmail {
            elements.append(.init(label: "Email", image: "envelope", content: email))
        }

        return elements
    }
}
