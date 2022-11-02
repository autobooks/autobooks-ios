import SwiftUI

@available(iOS 15.4, *)
struct StartingScreen: View {
    @StateObject private var store: TapToPayStore

    init(store: TapToPayStore) {
        _store = StateObject(wrappedValue: store)
    }

    var body: some View {
        MessageActionView(title: "Tap to Pay on iPhone has to be set up on this device.",
                          message: "This will take a few minutes.",
                          action: .start {
                              store.send(.start)
                          })
    }
}
