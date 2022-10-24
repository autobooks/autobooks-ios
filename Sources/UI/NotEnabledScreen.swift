import SwiftUI

@available(iOS 15.4, *)
struct NotEnabledScreen: View {
    let store: RootStore

    var body: some View {
        MessageActionView(store: store,
                          title: "Payment isn't enabled yet",
                          message: "You will receive an email once you're approved. Check back later.",
                          action: nil)
    }
}
