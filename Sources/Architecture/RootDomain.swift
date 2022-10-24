import SwiftUI
import UIKit

#if canImport(ProximityReader)
import ProximityReader
#endif

@available(iOS 15.4, *)
typealias RootStore = Store<RootState, RootAction, RootEnvironment>

@available(iOS 15.4, *)
struct RootState: Equatable {
    enum WaitingWebView: Equatable {
        case needEnrollment(Navigation.Configuration.WebViewState),
             hasMissingInfo(Navigation.Configuration.WebViewState)

        var state: Navigation.Configuration.WebViewState {
            switch self {
            case let .needEnrollment(state), let .hasMissingInfo(state):
                return state
            }
        }
    }

    enum ReceiptInputVisibility: Equatable {
        enum VisibleState: Equatable {
            case idle, loading, success, failure
        }

        case visible(VisibleState)
        case hidden
    }

    enum InitialLoad: Equatable {
        case idle
        case loading(LoadingState)
        case finished

        mutating func transition(to state: InitialLoad) {
            guard self != .finished else { return }

            self = state
        }

        struct LoadingState: Equatable {
            static func login(isFailure: Bool = false) -> LoadingState {
                .init(message: "Logging in...", retryAction: .performLogin, isFailure: isFailure)
            }

            static func fetchingPaymentToken(isFailure: Bool = false) -> LoadingState {
                .init(message: "Fetching payment token...", retryAction: .fetchReaderToken(id: nil), isFailure: isFailure)
            }

            static func fetchingStatus(isFailure: Bool = false) -> LoadingState {
                .init(message: "Fetching status...", retryAction: .fetchStatus, isFailure: isFailure)
            }

            static func preparingReader(progress: Int, isFailure: Bool = false) -> LoadingState {
                .init(message: "Preparing card reader... \n\(progress)%", retryAction: .prepareTapToPay, isFailure: isFailure)
            }

            let message: String
            let retryAction: RootAction
            let isFailure: Bool
        }
    }

    var navigation: Navigation
    var initialLoad: InitialLoad = .idle
    var statusState = Loadable<Status, APIError>.initialLoad(.idle)
    var loginState = Loadable<LoginResponse, APIError>.initialLoad(.idle)
    var paymentTokenState = Loadable<PaymentTokenResponse, APIError>.initialLoad(.idle)
    var waitingWebView: WaitingWebView?
    var paymentSessionPreparation: PaymentSession.PreparationEvent?
    var paymentAmount = PaymentAmount()
    var tapToPayError: PaymentSession.ReadError?
    var isTransactionLoading = false
    var transactionResult: Result<TransactionResponse, APIError>?
    var emailInput = EmailInput()
    var receiptInputVisibility: ReceiptInputVisibility = .visible(.idle)
    var hasSentTransactionReceipt: Bool {
        (transactionResult?.success?.transaction?.lastReceiptEmail ??
            selectedTransaction?.lastReceiptEmail) != nil
    }

    var transactionsState = Loadable<[Transaction], APIError>.initialLoad(.idle)
    var selectedTransaction: Transaction?
    var cancelTransactionState = Loadable<Transaction, APIError>.initialLoad(.idle)
    var refundTransactionState = Loadable<Transaction, APIError>.initialLoad(.idle)
}

@available(iOS 15.4, *)
enum RootAction: Equatable {
    case start
    case performLogin
    case receiveLogin(Result<LoginResponse, APIError>)
    case fetchReaderToken(id: String?)
    case receiveReaderToken(Result<PaymentTokenResponse, APIError>)
    case fetchStatus
    case receiveStatus(Result<Status, APIError>)
    case prepareTapToPay
    case receiveTapToPayPreparationEvent(PaymentSession.PreparationEvent)
    case readerReady
    case paymentInput(PaymentAmount)
    case startTransaction
    case retryTransaction
    case tapToPayEvent(PaymentSession.ReadEvent)
    case tapToPayFailed(PaymentSession.ReadError)
    case tapToPayComplete(PaymentSession.ReadResult)
    case transactionComplete(Result<TransactionResponse, APIError>)
    case makeAnotherPayment
    case closeTapToPay
    case emailInput(EmailInput)
    case sendReceiptRequest
    case receiveReceiptResponse(Result<Transaction, APIError>)
    case hideReceiptInput
    case makeReceiptInputIdle
    case showTransactions
    case synchronizeNavigation(Navigation)
    case fetchTransactions
    case receiveTransactionsResponse(Result<[Transaction], APIError>)
    case cancelTransaction(id: String)
    case receiveCancelTransactionResponse(Result<Transaction, APIError>)
    case refundTransaction(id: String)
    case receiveRefundTransactionResponse(Result<Transaction, APIError>)
    case selectTransaction(Transaction)
    case resetSelectedTransaction
    case updateSelectedTransaction(Transaction)
    case openURL(URL)
    case handleCallbackURL(URL)
}

@available(iOS 15.4, *)
struct RootEnvironment {
    let api: AutobooksAPI
    let defaults: Defaults
    let paymentSession: PaymentSession
    let dismiss: () -> Void
    let openURL: (URL) -> Void
}

@available(iOS 15.4, *)
typealias RootReducer = Reducer<RootState, RootAction, RootEnvironment>

@available(iOS 15.4, *)
extension RootReducer {
    static var `default`: RootReducer {
        Self { state, action, environment in
            switch action {
            case .start:
                environment.defaults.isPreviouslyLaunched = true
                state.navigation = .navigate([.loading])

                return .action(.performLogin)
            case .performLogin:
                state.loginState.refreshStarted()
                state.initialLoad.transition(to: .loading(.login()))

                return .run { send in
                    await send(.receiveLogin(environment.api.performLogin()))
                }
            case let .receiveLogin(.success(response)):
                state.loginState.update(to: response)

                switch response.status {
                case let .needsEnrollment(value):
                    let webViewState = Navigation.Configuration.WebViewState(title: "Needs Enrollment",
                                                                             url: value.url,
                                                                             callbackURL: value.callbackURL)
                    state.navigation = .navigate([.webview(webViewState)])
                    state.waitingWebView = .needEnrollment(webViewState)
                case let .success(value):
                    switch value.status {
                    case let .hasMissingInfo(value):
                        let webViewState = Navigation.Configuration.WebViewState(title: "Has Missing Info",
                                                                                 url: value.url,
                                                                                 callbackURL: value.callbackURL)
                        state.navigation = .navigate([.webview(webViewState)])
                        state.waitingWebView = .hasMissingInfo(webViewState)
                    case .enabled:
                        return .run { send in
                            send(.fetchReaderToken(id: nil), animation: .default)
                        }
                    case .notEnabled:
                        state.navigation = .navigate([.notEnabled])
                        state.initialLoad.transition(to: .finished)
                    }
                }

                return nil
            case let .receiveLogin(.failure(error)):
                state.loginState.update(to: error)
                state.initialLoad.transition(to: .loading(.login(isFailure: true)))

                return nil
            case let .fetchReaderToken(id):
                state.paymentTokenState.refreshStarted()
                state.initialLoad.transition(to: .loading(.fetchingPaymentToken()))

                return .run { send in
                    await send(.receiveReaderToken(environment.api.fetchPaymentToken(forReaderID: id)),
                               animation: .default)
                }
            case let .receiveReaderToken(.success(value)):
                state.paymentTokenState.update(to: value)
                environment.paymentSession.acceptToken(value.token)

                return .action(.prepareTapToPay)
            case let .receiveReaderToken(.failure(error)):
                state.paymentTokenState.update(to: error)
                state.initialLoad.transition(to: .loading(.fetchingPaymentToken(isFailure: true)))

                return nil
            case .fetchStatus:
                state.navigation = .navigate([.loading])
                state.initialLoad.transition(to: .loading(.fetchingStatus()))

                return .run { send in
                    await send(.receiveStatus(environment.api.fetchStatus()), animation: .default)
                }
            case let .receiveStatus(.success(status)):
                state.statusState.update(to: status)

                switch status {
                case let .hasMissingInfo(value):
                    let webViewState = Navigation.Configuration.WebViewState(title: "Has Missing Info",
                                                                             url: value.url,
                                                                             callbackURL: value.callbackURL)
                    state.navigation = .navigate([.webview(webViewState)])
                    state.waitingWebView = .hasMissingInfo(webViewState)

                    return nil
                case .enabled:
                    return .action(.fetchReaderToken(id: nil))
                case .notEnabled:
                    state.navigation = .navigate([.notEnabled])

                    return nil
                }
            case let .receiveStatus(.failure(error)):
                state.statusState.update(to: error)
                state.initialLoad.transition(to: .loading(.fetchingStatus(isFailure: true)))

                return nil
            case .prepareTapToPay:
                return .run { send in
                    for await event in environment.paymentSession.prepare() {
                        send(.receiveTapToPayPreparationEvent(event))

                        if event == .ready {
                            send(.readerReady)
                        }
                    }
                }
            case let .receiveTapToPayPreparationEvent(event):
                state.paymentSessionPreparation = event
                switch event {
                case .progress:
                    state.initialLoad.transition(to: .loading(.preparingReader(progress: event.progress)))
                case .error:
                    state.initialLoad.transition(to: .loading(.preparingReader(progress: event.progress,
                                                                               isFailure: true)))
                default:
                    break
                }

                return nil
            case .readerReady:
                state.navigation = .navigate([.presale])
                state.initialLoad.transition(to: .finished)

                return nil
            case let .paymentInput(value):
                state.paymentAmount = value

                return nil
            case .startTransaction:
                state.navigation = .navigate([.presale, .tapToPay])

                return .run { [amount = state.paymentAmount] send in
                    for await event in environment.paymentSession.read(amount: amount.decimal) {
                        switch event {
                        case let .error(error):
                            send(.tapToPayFailed(error))
                        case let .complete(result):
                            send(.tapToPayComplete(result))
                        default:
                            send(.tapToPayEvent(event))
                        }
                    }
                }
            case .retryTransaction:
                state.navigation = .navigate([.presale])

                return nil
            case .tapToPayEvent:
                return nil
            case let .tapToPayFailed(error):
                state.tapToPayError = error

                return nil
            case let .tapToPayComplete(result):
                state.isTransactionLoading = true

                return .run { send in
                    await send(.transactionComplete(environment.api.performTransaction(.init(cardReaderBlob: result.paymentCardData!))))
                }
            case let .transactionComplete(result):
                state.transactionResult = result
                state.isTransactionLoading = false

                state.navigation = .navigate([.presale, .tapToPay, .postsale])

                return nil
            case .makeAnotherPayment:
                state.navigation = .navigate([.presale])
                state.paymentAmount = PaymentAmount()
                state.receiptInputVisibility = .visible(.idle)
                state.transactionResult = nil

                return nil
            case .closeTapToPay:
                environment.dismiss()

                return nil
            case let .emailInput(value):
                state.emailInput = value

                return nil
            case .sendReceiptRequest:
                state.receiptInputVisibility = .visible(.loading)

                return .run { [email = state.emailInput.email] send in
                    await send(.receiveReceiptResponse(environment.api.requestReceipt(forTransactionID: "someID",
                                                                                      email: email)), animation: .default)
                }
            case let .receiveReceiptResponse(.success(value)):
                state.emailInput = EmailInput()
                state.receiptInputVisibility = .visible(.success)

                let action: RootAction
                if state.selectedTransaction != nil {
                    state.selectedTransaction = value
                    action = .makeReceiptInputIdle
                } else {
                    state.transactionResult = .success(.init(result: .success(value)))
                    action = .hideReceiptInput
                }

                return .run { send in
                    try? await Task.sleep(nanoseconds: 2 * NSEC_PER_SEC)

                    send(action, animation: .linear)
                }
            case .receiveReceiptResponse(.failure):
                state.receiptInputVisibility = .visible(.failure)

                return .run { send in
                    try? await Task.sleep(nanoseconds: 2 * NSEC_PER_SEC)

                    send(.makeReceiptInputIdle)
                }
            case .hideReceiptInput:
                state.emailInput = EmailInput()
                state.receiptInputVisibility = .hidden

                return nil
            case .makeReceiptInputIdle:
                state.receiptInputVisibility = .visible(.idle)

                return nil
            case let .openURL(url):
                environment.openURL(url)

                return nil
            case let .handleCallbackURL(url):
                guard let waitingWebView = state.waitingWebView else {
                    print("*** callback received without waiting webview")
                    return nil
                }

                guard url == waitingWebView.state.callbackURL else { print("*** callbackURL didn't match"); return nil }

                state.navigation = .navigate([.loading])
                state.waitingWebView = nil

                let action: RootAction
                switch waitingWebView {
                case .needEnrollment:
                    action = .performLogin
                case .hasMissingInfo:
                    action = .fetchStatus
                }

                return .action(action)
            case .showTransactions:
                state.navigation = .navigate([.presale, .transactions])

                return .action(.fetchTransactions)
            case let .synchronizeNavigation(navigation):
                if state.selectedTransaction != nil, !navigation.configurations.contains(.transactionDetails) {
                    state.selectedTransaction = nil
                }
                state.navigation = navigation

                return nil
            case .fetchTransactions:
                state.transactionsState.refreshStarted()

                return .run { send in
                    await send(.receiveTransactionsResponse(environment.api.fetchTransactions()))
                }
            case let .receiveTransactionsResponse(result):
                state.transactionsState.update(to: result)

                return nil
            case let .selectTransaction(transaction):
                state.selectedTransaction = transaction
                state.navigation = .navigate([.presale, .transactions, .transactionDetails])

                return nil
            case .resetSelectedTransaction:
                state.selectedTransaction = nil
                state.cancelTransactionState = .initialLoad(.idle)
                state.refundTransactionState = .initialLoad(.idle)

                return nil
            case let .cancelTransaction(id):
                state.cancelTransactionState.refreshStarted()

                return .run { send in
                    await send(.receiveCancelTransactionResponse(environment.api.cancelTransaction(id)),
                               animation: .linear)
                }
            case let .receiveCancelTransactionResponse(result):
                state.cancelTransactionState.update(to: result)

                guard case let .success(transaction) = result else { return nil }

                return .run { send in
                    try? await Task.sleep(nanoseconds: 1 * NSEC_PER_SEC)
                    send(.updateSelectedTransaction(transaction), animation: .linear)
                }
            case let .refundTransaction(id):
                state.refundTransactionState.refreshStarted()

                return .run { send in
                    await send(.receiveRefundTransactionResponse(environment.api.refundTransaction(id)),
                               animation: .linear)
                }
            case let .receiveRefundTransactionResponse(result):
                state.refundTransactionState.update(to: result)

                guard case let .success(transaction) = result else { return nil }

                return .run { send in
                    try? await Task.sleep(nanoseconds: 1 * NSEC_PER_SEC)
                    send(.updateSelectedTransaction(transaction), animation: .linear)
                }

            case let .updateSelectedTransaction(transaction):
                state.selectedTransaction = transaction
                return nil
            }
        }
    }
}

@available(iOS 15.4, *)
enum AppError {
    case api(APIError)
    case reader(PaymentSession.ReaderError)
    case session(PaymentSession.ReadError)
}

@available(iOS 15.4, *)
extension AppError: Equatable {
    static func ==(lhs: Self, rhs: Self) -> Bool {
        switch (lhs, rhs) {
        case let (.api(right), .api(left)):
            return right == left
        case let (.session(right), .session(left)):
            return right == left
        default:
            return false
        }
    }
}
