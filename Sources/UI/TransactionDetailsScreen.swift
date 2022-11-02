import SwiftUI

@available(iOS 15.4, *)
struct TransactionDetailsScreen: View {
    @StateObject private var store: TapToPayStore

    init(store: TapToPayStore) {
        _store = StateObject(wrappedValue: store)
    }

    var body: some View {
        TransactionSummary(store: store, transaction: \.selectedTransaction, configuration: .details)
            .onDisappear {
                store.send(.resetSelectedTransaction)
            }
    }
}
