import SwiftUI

@available(iOS 16.0, *)
struct PresaleScreen: View {
    @StateObject private var store: TapToPayStore
    @State private var showValidity = false

    init(store: TapToPayStore) {
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
                    if store.state.useExpressApi {
                        store.send(.startExpressTransaction)
                    } else {
                        Analytics.shared.log(.tappedCharge(store.state.paymentAmount.decimal))
                        store.send(.startTransaction)
                    }
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
            
            Button("Manual Card Entry") {
                store.send(.openVirtualTerminal)
            }
            .font(.system(.body).weight(.bold))
            .frame(height: 50)

            Spacer()
        }
        .padding(.horizontal, 16)
    }

    var waveImage: Image {
        Image(systemName: "wave.3.right.circle.fill")
    }
}
