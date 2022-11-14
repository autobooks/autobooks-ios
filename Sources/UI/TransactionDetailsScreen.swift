import SwiftUI

@available(iOS 15.4, *)
struct TransactionDetailsScreen: View {
    @StateObject private var store: TapToPayStore

    init(store: TapToPayStore) {
        _store = StateObject(wrappedValue: store)
    }

    var body: some View {
        if let transaction = store.state.selectedTransaction {
            TransactionSummary(store: store, transaction: transaction, configuration: .details)
                .onDisappear {
                    store.send(.resetSelectedTransaction)
                }
        } else {
            EmptyView()
        }
    }
}
