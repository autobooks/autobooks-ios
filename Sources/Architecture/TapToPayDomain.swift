import SwiftUI
import UIKit

#if canImport(ProximityReader)
import ProximityReader
#endif

@available(iOS 16.0, *)
typealias TapToPayStore = Store<TapToPay.State, TapToPay.Action, TapToPay.Environment>

@available(iOS 16.0, *)
enum TapToPay {
    struct State: Equatable {
        enum WaitingWebView: Equatable {
            case needEnrollment(Navigation.Configuration.WebViewState)
            case hasMissingInfo(Navigation.Configuration.WebViewState)

            var state: Navigation.Configuration.WebViewState {
                switch self {
                case let .needEnrollment(state),
                     let .hasMissingInfo(state):
                    return state
                }
            }
        }

        var navigation: Navigation
        var initialLoad: InitialLoad<Action> = .idle
        var statusState = Loadable<Status, APIError>.initialLoad(.idle)
        var loginState = Loadable<LoginResponse, APIError>.initialLoad(.idle)
        var waitingWebView: WaitingWebView?
        var paymentSessionPreparation: PaymentSession.PreparationEvent?
        var paymentAmount = PaymentAmount()
        var tapToPayError: PaymentSession.ReadError?
        var isTransactionLoading = false
        var postsaleState: Postsale.State?
        var transactionResult: Result<Transaction, APIError>?
        var transactionsState = Loadable<[Transaction], APIError>.initialLoad(.idle)
        var selectedTransaction: TransactionDetails.State?
        var useExpressApi: Bool = false
    }

    enum Action: Equatable {
        case start
        case performLogin
        case receiveLogin(Result<LoginResponse, APIError>)
        case fetchStatus
        case receiveStatus(Result<Status, APIError>)
        case setupTriPOS
        case receiveTriPOS(Result<Nothing, APIError>)
        case performSaleComplete(Result<VTPSale, APIError>)
        case prepareTapToPay
        case receiveTapToPayPreparationEvent(PaymentSession.PreparationEvent)
        case readerReady
        case firstTimeReaderReady
        case paymentInput(PaymentAmount)
        case startTransaction
        case startExpressTransaction
        case retryTransaction
        case tapToPayEvent(PaymentSession.ReadEvent)
        case tapToPayFailed(PaymentSession.ReadError)
        case tapToPayComplete(PaymentSession.ReadResult)
        case transactionComplete(Result<Transaction, APIError>)
        case makeAnotherPayment
        case closeTapToPay
        case postsale(Postsale.Action)
        case showTransactions
        case synchronizeNavigation(Navigation)
        case fetchTransactions
        case receiveTransactionsResponse(Result<[Transaction], APIError>)
        case selectTransaction(Transaction)
        case transactionDetails(TransactionDetails.Action)
        case openURL(URL)
        case toggleExpressApi(Bool)
        case openVirtualTerminal
        case cardEducation
        case phoneEducation
        case firstTimeSetup
    }

    struct Environment {
        let api: AutobooksAPI
        let defaults: Defaults
        let paymentSession: PaymentSession
        let dismiss: () -> Void
        let openURL: (URL) -> Void
        let triPOS: TriPOS
    }

    static var reducer: Reducer<State, Action, Environment> {
        .combine([
            Postsale.reducer
                .optional()
                .toParent(\.postsaleState,
                          toChildAction: { parentAction in
                              switch parentAction {
                              case let .postsale(action):
                                  return action
                              default:
                                  return nil
                              }
                          },
                          toParentAction: Action.postsale,
                          toChildEnvironment: { $0 }),
            TransactionDetails.reducer
                .optional()
                .toParent(\.selectedTransaction,
                          toChildAction: { parentAction in
                              switch parentAction {
                              case let .transactionDetails(action):
                                  return action
                              default:
                                  return nil
                              }
                          },
                          toParentAction: Action.transactionDetails,
                          toChildEnvironment: { $0 }),
            .init { state, action, environment in
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
                                                                                 url: value.url)

                        let navigation: Navigation = .navigate([.webview(webViewState)])
                        
                        if state.navigation != navigation {
                            state.navigation = .navigate([.webview(webViewState)])
                            state.waitingWebView = .needEnrollment(webViewState)
                        }
                        
                        return .run { send in
                            try? await Task.sleep(nanoseconds: UInt64(3 * Double(NSEC_PER_SEC)))
                            send(.performLogin)
                        }

                    case let .success(value):
                        switch value.status {
                        case let .hasMissingInfo(value):
                            let webViewState = Navigation.Configuration.WebViewState(title: "Has Missing Info",
                                                                                     url: value.url)
                            
                            let navigation: Navigation = .navigate([.webview(webViewState)])

                            if state.navigation != navigation {
                                state.navigation = .navigate([.webview(webViewState)])
                                state.waitingWebView = .needEnrollment(webViewState)
                            }

                            return .run { send in
                                try? await Task.sleep(nanoseconds: UInt64(3 * Double(NSEC_PER_SEC)))
                                send(.performLogin)
                            }

                        case .enabled:
                            if environment.defaults.isPreviouslyOnboarded {
                                if state.useExpressApi {
                                    state.navigation = .navigate([.presale])
                                    state.initialLoad.transition(to: .finished)
                                } else {
                                    return .run { send in
                                        send(.setupTriPOS, animation: .default)
                                    }
                                }
                            } else {
                                state.navigation = .navigate([.cardEducation])
                                state.initialLoad.transition(to: .finished)
                            }
                        case .notEnabled:
                            state.navigation = .navigate([.notEnabled])
                            state.initialLoad.transition(to: .finished)

                            return nil
                        case .paymentEnablementRequested,
                             .merchantPendingApprovalForTapToPay:
                            state.navigation = .navigate([.waiting])
                            state.initialLoad.transition(to: .finished)

                            return .run { send in
                                try? await Task.sleep(nanoseconds: UInt64(3 * Double(NSEC_PER_SEC)))
                                send(.performLogin)
                            }
                        }
                    }
                    
                    return nil
                case let .receiveLogin(.failure(error)):
                    state.loginState.update(to: error)
                    state.initialLoad.transition(to: .loading(.login(isFailure: true)))

                    return nil
                case .setupTriPOS:
                    state.initialLoad.transition(to: .loading(.startTriPOS()))

                    let merchantCredentials = state.loginState.value.flatMap { loginResponse in
                        loginResponse.status.status?.merchantCredentials
                    }

                    // Once we can use merchant credentials we wouldn't want to go here if we didn't have merchant credentials
                    return .run { send in
                        await send(.receiveTriPOS(environment.triPOS.start(merchantCredentials: merchantCredentials ?? nil)))
                    }
                case .receiveTriPOS(.success):
                    return .run { send in
                        send(.prepareTapToPay)
                    }

                case .receiveTriPOS(.failure):
                    state.initialLoad.transition(to: .loading(.startTriPOS(isFailure: true)))
                    
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
                                                                                 url: value.url)
                        state.navigation = .navigate([.webview(webViewState)])
                        state.waitingWebView = .hasMissingInfo(webViewState)

                        return nil
                    case .enabled:
                        return .run { send in
                            send(.setupTriPOS, animation: .default)
                        }
                    case .notEnabled:
                        state.navigation = .navigate([.notEnabled])

                        return nil
                    case .merchantPendingApprovalForTapToPay,
                         .paymentEnablementRequested:
                        state.navigation = .navigate([.waiting])
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
                                if environment.defaults.isPreviouslyOnboarded {
                                    send(.readerReady)
                                } else {
                                    send(.firstTimeReaderReady)
                                }
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
                case .firstTimeReaderReady:
                    environment.defaults.isPreviouslyOnboarded = true
                    return .run { send in
                        try? await Task.sleep(nanoseconds: UInt64(5 * Double(NSEC_PER_SEC)))
                        send(.readerReady)
                    }
                
                case .readerReady:
                    state.navigation = .navigate([.presale])
                    state.initialLoad.transition(to: .finished)

                    return nil
                case let .paymentInput(value):
                    state.paymentAmount = value

                    return nil
                case let .toggleExpressApi(shouldUseExpressApi):
                    state.useExpressApi = shouldUseExpressApi

                    return nil
                case .startExpressTransaction:
                    state.navigation = .navigate([.presale, .tapToPay])
                    
                    let merchantCredentials = state.loginState.value.flatMap { loginResponse in
                        loginResponse.status.status.flatMap { statusRes in
                            statusRes.merchantCredentials
                        }
                    }
                    
                    return .run { [amount = state.paymentAmount] send in
                        let result: Result<VTPSale, APIError> = await environment.api.createTransaction(for: amount.decimal, type: .sale)
                            .flatMap { createResponse in
                                let transaction: Result<VTPSale, APIError> = try! await ExpressAPI().performTransaction(for: amount.decimal, merchantCredentials: merchantCredentials!, ticketNumber: createResponse.ticketNumber, referenceNumber: createResponse.referenceNumber).flatMap { expressTransaction in
                                    .success(VTPSale(uuid: createResponse.uuid, transactionID: expressTransaction.TransactionID))
                                }
                                return transaction
                            }
                        send(.performSaleComplete(result))
                    }
                case .startTransaction:
                    state.navigation = .navigate([.presale, .tapToPay])
                    
                    return .run { [amount = state.paymentAmount] send in
                        let result: Result<VTPSale, APIError> =
                            await environment.api.createTransaction(for: amount.decimal, type: .sale)
                                .flatMap { createResponse in
                                    await environment.triPOS.performSale(of: amount, ticketNumber: createResponse.ticketNumber, referenceNumber: createResponse.referenceNumber, uuid: createResponse.uuid)
                                }
                        send(.performSaleComplete(result))
                    }
                case let .performSaleComplete(result):
                    return .run { send in
                        let result = await result.flatMap { createResponse in
                            await environment.api.syncTransaction(createResponse.uuid, transactionID: createResponse.transactionID)
                        }
                        send(.transactionComplete(result))
                    }
                    
                case .retryTransaction:
                    state.navigation = .navigate([.presale])

                    return nil
                // Tap to Pay events not called, update or remove when it's known whether triPOS will expose the events.
                case .tapToPayEvent:
                    return nil
                case let .tapToPayFailed(error):
                    state.tapToPayError = error

                    return nil
                case .tapToPayComplete:
                    state.isTransactionLoading = true

                    return .run { send in
                        await send(.transactionComplete(environment.api.syncTransaction(UUID(), transactionID: "transactionID")))
                    }
                case let .transactionComplete(result):
                    state.transactionResult = result
                    let details = result.success.map {
                        TransactionDetails.State(source: .postsale, transaction: $0)
                    }
                    state.postsaleState = Postsale.State(details: details)
                    state.isTransactionLoading = false

                    state.navigation = .navigate([.presale, .tapToPay, .postsale(result.isSuccess)])
                    
                    return nil
                case .makeAnotherPayment:
                    state.navigation = .navigate([.presale])
                    state.paymentAmount = PaymentAmount()
                    state.transactionResult = nil
                    state.postsaleState = nil

                    return nil
                case .closeTapToPay:
                    environment.dismiss()

                    return nil
                case .postsale(.transactionDetails(.done)):
                    return .action(.makeAnotherPayment)
                case .postsale(.retryTransaction):
                    return .action(.retryTransaction)
                case .postsale:
                    // Handled by Postsale.reducer
                    return nil
                case let .openURL(url):
                    environment.openURL(url)

                    return nil
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
                    state.selectedTransaction = .init(source: .transactionDetails, transaction: transaction)
                    state.navigation = .navigate([.presale, .transactions, .transactionDetails])

                    return nil
                case .transactionDetails(.onDisappear):
                    state.selectedTransaction = nil

                    return nil
                case .transactionDetails:
                    // Handled by TransactionDetails.reducer
                    return nil
                case .openVirtualTerminal:
                    guard let virtualTerminalURL = state.loginState.value?.webFeatureURLs.virtualTerminal else {
                        return nil
                    }
                    
                    let virtualTerminalState = Navigation.Configuration.VirtualTerminalState(url: virtualTerminalURL)
                    
                    state.navigation = .navigate([.virtualTerminal(virtualTerminalState)])
                    return nil
                case .cardEducation:
                    state.navigation = .navigate([.cardEducation])
                    return nil
                case .phoneEducation:
                    state.navigation = .navigate([.phoneEducation])
                    return nil
                case .firstTimeSetup:
                    state.navigation = .navigate([.firstTimeSetup])
                    return .run { send in
                        send(.setupTriPOS, animation: .default)
                    }
                }
            },
        ])
    }
}

@available(iOS 16.0, *)
enum TapToPayError {
    case api(APIError)
    case reader(PaymentSession.ReaderError)
    case session(PaymentSession.ReadError)
}

@available(iOS 16.0, *)
extension TapToPayError: Equatable {}
