import Foundation

@available(iOS 16.0, *)
enum Receipt {
    enum InputVisibility: Equatable {
        enum VisibleState: Equatable {
            case idle
            case loading
            case success
            case failure
        }

        case visible(VisibleState)
        case hidden
    }

    struct State: Equatable {
        let transactionID: UUID
        var hasSentTransactionReceipt = false
        var input = EmailInput()
        var inputVisibility: InputVisibility = .visible(.idle)
        let canSendMultipleReceipts: Bool
    }

    enum Action: Equatable {
        case emailInput(EmailInput)
        case sendReceiptRequest(UUID)
        case receiveReceiptResponse(Result<Transaction, APIError>)
        case hideReceiptInput
        case makeReceiptInputIdle
    }

    static var reducer: Reducer<Receipt.State, Receipt.Action, TapToPay.Environment> {
        Reducer { state, action, environment in
            switch action {
            case let .emailInput(input):
                state.input = input

                return nil
            case let .sendReceiptRequest(transactionID):
                state.inputVisibility = .visible(.loading)

                return .run { [email = state.input.email] send in
                    await send(.receiveReceiptResponse(environment.api.requestReceipt(forTransactionID: transactionID,
                                                                                      email: email)),
                               animation: .default)
                }
            
            // Parent handles updating the actual displayed transaction.
            case .receiveReceiptResponse(.success):
                state.input = EmailInput()
                state.inputVisibility = .visible(.success)

                let action: Action = (state.canSendMultipleReceipts) ? .makeReceiptInputIdle : .hideReceiptInput

                return .run(after: 2) { send in
                    send(action, animation: .linear)
                }
            case .receiveReceiptResponse(.failure):
                state.inputVisibility = .visible(.failure)

                return .run(after: 2) { send in
                    send(.makeReceiptInputIdle)
                }
            case .hideReceiptInput:
                state.input = EmailInput()
                state.inputVisibility = .hidden

                return nil
            case .makeReceiptInputIdle:
                state.inputVisibility = .visible(.idle)

                return nil
            }
        }
    }
}
