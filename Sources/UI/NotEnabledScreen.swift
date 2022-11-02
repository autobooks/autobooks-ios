import SwiftUI

@available(iOS 15.4, *)
struct NotEnabledScreen: View {
    var body: some View {
        MessageActionView(title: "Payment isn't enabled yet",
                          message: "You will receive an email once you're approved. Check back later.",
                          action: nil)
    }
}
