import SwiftUI

@available(iOS 15.4, *)
struct TransactionSummary: View {
    enum Configuration {
        case success, details
    }

    @StateObject private var store: TapToPayStore

    private let transaction: KeyPath<TapToPay.State, Transaction?>
    private let configuration: Configuration

    init(store: TapToPayStore, transaction: KeyPath<TapToPay.State, Transaction?>, configuration: Configuration) {
        _store = StateObject(wrappedValue: store)
        self.transaction = transaction
        self.configuration = configuration
    }

    var body: some View {
        if let transaction = store.state[keyPath: transaction] {
            VStack(alignment: .leading, spacing: 0) {
                if store.state.selectedTransaction?.status == .canceled || store.state.selectedTransaction?.status == .refunded {
                    Spacer()
                        .frame(height: 8)

                    Banner(transaction: transaction)
                        .lineLimit(1)
                }

                VStack(alignment: .leading, spacing: 0) {
                    Spacer()
                        .frame(height: 40)

                    AmountText(formattedAmount: transaction.total)
                        .zIndex(1)

                    Spacer()
                        .frame(height: 56)

                    TransactionProperties(transaction: transaction)
                        .zIndex(1)

                    Spacer()
                        .frame(height: 56)

                    ReceiptInput(store: store, configuration: configuration)

                    Spacer()
                        .frame(height: 4)

                    if store.state.selectedTransaction?.status == .cancelable {
                        LoadableAlertButton(loadingState: store.state.cancelTransactionState,
                                            title: "Cancel Payment",
                                            loadingTitle: "Canceling...",
                                            successTitle: "Payment Canceled",
                                            alertTitle: "Confirm Cancelation",
                                            alertButtonTitle: "Cancel Payment",
                                            alertMessage: """
                                            This action can’t be undone. \
                                            Your customer will receive a cancelation receipt \
                                            to the email on file, if one exists.
                                            """) {
                            guard let transaction = store.state.selectedTransaction else { return }
                            store.send(.cancelTransaction(id: transaction.id), animation: .linear)
                        }
                    }

                    if store.state.selectedTransaction?.status == .refundable {
                        LoadableAlertButton(loadingState: store.state.refundTransactionState,
                                            title: "Refund Payment",
                                            loadingTitle: "Refunding...",
                                            successTitle: "Payment Refunded",
                                            alertTitle: "Confirm Full Refund",
                                            alertButtonTitle: "Refund Payment",
                                            alertMessage: """
                                            This action can’t be undone. \
                                            Your customer will receive a refund receipt \
                                            to the email on file, if one exists.
                                            """) {
                            guard let transaction = store.state.selectedTransaction else { return }
                            store.send(.refundTransaction(id: transaction.id), animation: .linear)
                        }
                    }

                    Spacer()
                }
                .padding(.horizontal, 32)
            }
        } else {
            // Transition to empty when we don't have a transaction, as it likely means we're in the middle of dismissal.
            EmptyView()
        }
    }
}

@available(iOS 15.4, *)
struct AmountText: View {
    let formattedAmount: String

    var body: some View {
        Text(formattedAmount)
            .frame(maxWidth: .infinity, alignment: .leading)
            .minimumScaleFactor(0.5)
            .font(.system(size: 55, weight: .regular, design: .rounded))
    }
}

@available(iOS 15.4, *)
struct TransactionProperties: View {
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

@available(iOS 15.4, *)
struct ReceiptInput: View {
    @StateObject private var store: TapToPayStore
    @State private var showValidation = false
    @State private var isPresentingRefundAlert = false

    private let configuration: TransactionSummary.Configuration

    init(store: TapToPayStore, configuration: TransactionSummary.Configuration) {
        _store = StateObject(wrappedValue: store)
        self.configuration = configuration
    }

    var body: some View {
        input
            .onChange(of: store.state.emailInput) { _ in
                showValidation = false
            }
    }

    @ViewBuilder
    private var input: some View {
        switch store.state.receiptInputVisibility {
        case let .visible(visibility):
            VStack {
                VStack(spacing: 4) {
                    VStack {
                        if showValidation && !store.state.emailInput.isValid {
                            ErrorText("Enter a valid email address")
                        }
                    }
                    .frame(height: 18)

                    EmailTextField(input: Binding(get: { store.state.emailInput },
                                                  set: { store.send(.emailInput($0)) }))
                        .disabled(visibility != .idle)
                }

                Button {
                    if store.state.emailInput.isValid {
                        store.send(.sendReceiptRequest, animation: .linear)
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
                store.send(.makeAnotherPayment)
            }
            .buttonStyle(.action)
            .transition(.move(edge: .bottom).combined(with: .opacity))
        }
    }
}
