import SwiftUI

@available(iOS 15.4, *)
struct PresaleScreen: View {
    @StateObject private var store: RootStore
    @State private var showValidity = false

    init(store: RootStore) {
        _store = StateObject(wrappedValue: store)
    }

    var body: some View {
        VStack(spacing: 0) {
            Spacer()
                .frame(height: 100)

            PaymentAmountView(amount: Binding {
                store.state.paymentAmount
            } set: {
                store.send(.paymentInput($0))
            }, showValidity: $showValidity)

            Divider()
                .background(Color(uiColor: .opaqueSeparator))

            Spacer()
                .frame(height: 24)

            Button {
                if store.state.paymentAmount.isValid {
                    store.send(.startTransaction)
                } else {
                    showValidity = true
                }
            } label: {
                HStack(spacing: 4) {
                    waveImage
                    Text("Charge")
                }
                .font(.system(.body).weight(.bold))
            }
            .buttonStyle(.action)

            Spacer()
        }
        .padding(.horizontal, 16)
    }

    var waveImage: Image {
        Image(systemName: "wave.3.right.circle.fill")
    }
}
