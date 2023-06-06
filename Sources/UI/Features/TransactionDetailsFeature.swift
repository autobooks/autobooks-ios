@available(iOS 16.0, *)
enum TransactionDetails {
    enum Source {
        case postsale
        case transactionDetails
    }

    struct State: Equatable {
        let source: Source
        var receipt: Receipt.State
        var transaction: Transaction
        var transactionUpdate: Loadable<Transaction, APIError> = .initialLoad(.idle)

        init(source: Source, transaction: Transaction) {
            self.source = source
            self.receipt = Receipt.State(transactionID: transaction.uuid,
                                         hasSentTransactionReceipt: transaction.lastReceiptEmail != nil,
                                         canSendMultipleReceipts: source == .transactionDetails)
            self.transaction = transaction
        }
    }

    enum Action: Equatable {
        case cancelTransaction
        case done
        case onDisappear
        case receiveTransactionUpdate(Result<Transaction, APIError>)
        case receipt(Receipt.Action)
        case refundTransaction
        case resetTransactionToIdle
        case updateTransaction(Transaction)
    }

    static var reducer: Reducer<TransactionDetails.State, TransactionDetails.Action, TapToPay.Environment> {
        .combine([
            Receipt.reducer.toParent(\.receipt,
                                     toChildAction: { action in
                                         switch action {
                                         case let .receipt(childAction):
                                             return childAction
                                         default:
                                             return nil
                                         }
                                     },
                                     toParentAction: Action.receipt,
                                     toChildEnvironment: { $0 }),
            Reducer { state, action, environment in
                switch action {
                case .cancelTransaction:
                    state.transactionUpdate.refreshStarted()

                    return .run { [id = state.transaction.id] send in
                        await send(.receiveTransactionUpdate(environment.api.cancelTransaction(id)), animation: .linear)
                    }
                case .done,
                     .onDisappear:
                    // Handled by parent.
                    return nil
                case let .receiveTransactionUpdate(.success(transaction)):
                    state.transactionUpdate.update(to: transaction)

                    // Delay transaction update to give success view time to display.
                    return .run(after: 1) { send in
                        send(.updateTransaction(transaction), animation: .linear)
                    }
                case let .receiveTransactionUpdate(.failure(error)):
                    state.transactionUpdate.update(to: error)

                    // Delay transaction update to give failure view time to show before dismissing.
                    return .run(after: 2) { send in
                        send(.resetTransactionToIdle, animation: .linear)
                    }
                case let .receipt(.receiveReceiptResponse(.success(transaction))):
                    state.transaction = transaction
                    state.receipt.hasSentTransactionReceipt = transaction.lastReceiptEmail != nil

                    return nil
                case .receipt:
                    // Handled by Receipt.reducer.
                    return nil
                case .refundTransaction:
                    state.transactionUpdate.refreshStarted()

                    return .run { [id = state.transaction.id] send in
                        await send(.receiveTransactionUpdate(environment.api.refundTransaction(id)), animation: .linear)
                    }
                case .resetTransactionToIdle:
                    state.transactionUpdate = .initialLoad(.idle)

                    return nil
                case let .updateTransaction(transaction):
                    state.transaction = transaction
                    state.receipt.hasSentTransactionReceipt = transaction.lastReceiptEmail != nil

                    return nil
                }
            },
        ])
    }
}
