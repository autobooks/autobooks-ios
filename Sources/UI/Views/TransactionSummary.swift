import SwiftUI

@available(iOS 16.0, *)
struct TransactionSummary: View {
    typealias ViewStore = Store<TransactionDetails.State, TransactionDetails.Action, TapToPay.Environment>

    enum Configuration {
        case success
        case details
    }

    @StateObject private var store: ViewStore

    private let configuration: Configuration

    private var transaction: Transaction {
        store.state.transaction
    }

    private var isStatusBannerVisible: Bool {
        configuration == .details && (transaction.status == .canceled || transaction.status == .refunded)
    }

    private var isDetailsTransactionCancellable: Bool {
        configuration == .details && transaction.status == .cancelable
    }

    private var isDetailsTransactionRefundable: Bool {
        configuration == .details && transaction.status == .refundable
    }

    private var isReceiptSendable: Bool {
        transaction.canRequestReceipt
    }

    init(store: ViewStore, configuration: Configuration) {
        _store = StateObject(wrappedValue: store)
        self.configuration = configuration
    }

    var body: some View {
        VStack(alignment: .leading, spacing: 0) {
            if isStatusBannerVisible {
                Spacer()
                    .frame(height: 8)

                Banner(transaction: store.state.transaction)
                    .lineLimit(1)
            }

            VStack(alignment: .leading, spacing: 0) {
                Spacer()
                    .frame(height: 40)

                AmountText(formattedAmount: transaction.formattedAmount)
                    .zIndex(1)

                Spacer()
                    .frame(height: 56)

                TransactionProperties(transaction: transaction)
                    .zIndex(1)

                if !UIDevice.current.hasShortScreen {
                    Spacer()
                        .frame(height: 56)
                }

                if isReceiptSendable {
                    ReceiptInput(store: store.scope(state: \.receipt, action: TransactionDetails.Action.receipt),
                                 configuration: configuration) {
                        store.send(.done)
                    }
                }

                Spacer()
                    .frame(height: 4)

                if isDetailsTransactionCancellable {
                    LoadableAlertButton(loadingState: store.onlyState.state.transactionUpdate,
                                        title: "Cancel Payment",
                                        loadingTitle: "Canceling...",
                                        successTitle: "Payment Canceled",
                                        failureTitle: "Cancellation Failed",
                                        alertTitle: "Confirm Cancellation",
                                        alertButtonTitle: "Cancel Payment",
                                        alertMessage: "This action can’t be undone.") {
                        store.send(.cancelTransaction, animation: .linear)
                    }
                } else if isDetailsTransactionRefundable {
                    LoadableAlertButton(loadingState: store.onlyState.state.transactionUpdate,
                                        title: "Refund Payment",
                                        loadingTitle: "Refunding...",
                                        successTitle: "Payment Refunded",
                                        failureTitle: "Refund Failed",
                                        alertTitle: "Confirm Full Refund",
                                        alertButtonTitle: "Refund Payment",
                                        alertMessage: "This action can’t be undone.") {
                        store.send(.refundTransaction, animation: .linear)
                    }
                }

                Spacer()
            }
            .padding(.horizontal, 32)
        }
    }
}

@available(iOS 16.0, *)
private struct AmountText: View {
    let formattedAmount: String

    var body: some View {
        Text(formattedAmount)
            .frame(maxWidth: .infinity, alignment: .leading)
            .minimumScaleFactor(0.5)
            .font(.system(size: 55, weight: .regular, design: .rounded))
    }
}

@available(iOS 16.0, *)
private struct TransactionProperties: View {
    let transaction: Transaction

    var body: some View {
        VStack(spacing: 12) {
            ForEach(transaction.uiElements) { element in
                HStack {
                    Label(element.label, systemImage: element.image)
                        .frame(width: 127, alignment: .topLeading)
                        .foregroundColor(.gray)
                        .font(.system(.subheadline))
                    Text(element.content)
                        .font(.system(.body))
                }
                .frame(maxWidth: .infinity, alignment: .leading)
                .accessibilityRepresentation {
                    Text("\(element.label) \(element.content)")
                }
            }
        }
        .frame(maxWidth: .infinity, alignment: .leading)
        .background(Color(uiColor: .systemBackground))
    }
}

@available(iOS 16.0, *)
private struct ReceiptInput: View {
    typealias ViewStore = Store<Receipt.State, Receipt.Action, TapToPay.Environment>

    @StateObject private var store: ViewStore

    @State private var showValidation = false
    @State private var isPresentingRefundAlert = false

    private let configuration: TransactionSummary.Configuration
    private let onDone: () -> Void

    init(store: ViewStore, configuration: TransactionSummary.Configuration, onDone: @escaping () -> Void) {
        _store = StateObject(wrappedValue: store)
        self.configuration = configuration
        self.onDone = onDone
    }

    var body: some View {
        input
            .onChange(of: store.state.input) { _ in
                showValidation = false
            }
    }

    @ViewBuilder
    private var input: some View {
        switch store.state.inputVisibility {
        case let .visible(visibility):
            VStack {
                VStack(spacing: 4) {
                    VStack {
                        if showValidation, !store.state.input.isValid {
                            ErrorText("Enter a valid email address")
                        }
                    }
                    .frame(height: 18)

                    EmailTextField(input: Binding(get: { store.state.input },
                                                  set: { store.send(.emailInput($0)) }))
                        .disabled(visibility != .idle)
                }

                Button {
                    if store.state.input.isValid {
                        store.send(.sendReceiptRequest(store.state.transactionID), animation: .linear)
                    } else {
                        showValidation = true
                    }
                } label: {
                    switch visibility {
                    case .idle:
                        if store.state.hasSentTransactionReceipt {
                            Text("Send Another Receipt")
                        } else {
                            Text("Send a Receipt")
                        }
                    case .loading:
                        Text("Sending...")
                    case .success:
                        HStack {
                            Text("Receipt Sent")
                            Image(systemName: "checkmark")
                        }
                    case .failure:
                        HStack {
                            Text("Failed to Send Receipt")
                            Image(systemName: "xmark")
                        }
                    }
                }
                .buttonStyle(.secondary(isFailure: visibility == .failure))
                .disabled(visibility != .idle)

                if configuration == .success {
                    Button {
                        store.send(.hideReceiptInput, animation: .linear)
                    } label: {
                        Text("Skip")
                    }
                    .buttonStyle(.tertiary)
                    .disabled(visibility != .idle)
                }
            }
            .transition(.move(edge: .top).combined(with: .opacity))
        case .hidden:
            Button("Done") {
                onDone()
            }
            .padding(.top, 16)
            .buttonStyle(.action)
            .transition(.move(edge: .bottom).combined(with: .opacity))
        }
    }
}
