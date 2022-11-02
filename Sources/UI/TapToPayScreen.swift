import SwiftUI

@available(iOS 15.4, *)
struct TapToPayScreen: View {
    @StateObject private var store: TapToPayStore

    init(store: TapToPayStore) {
        _store = StateObject(wrappedValue: store)
    }

    var body: some View {
        VStack {
            if let error = store.state.tapToPayError {
                Text("Tap to Pay failed with error \(error.errorName)")
                Button("Try Again") {
                    store.send(.retryTransaction)
                }
            } else {
                Text("Tap to Pay in progress...")

                if store.state.isTransactionLoading {
                    ProgressView()
                        .progressViewStyle(.circular)
                }
            }
        }
    }
}
