import SwiftUI

@available(iOS 16.0, *)
struct TransactionDetailsScreen: View {
    typealias ViewStore = Store<TransactionDetails.State, TransactionDetails.Action, TapToPay.Environment>

    @StateObject private var store: ViewStore

    init(store: ViewStore) {
        _store = StateObject(wrappedValue: store)
    }

    var body: some View {
        TransactionSummary(store: store, configuration: .details)
            .onDisappear {
                store.send(.onDisappear)
            }
    }
}
