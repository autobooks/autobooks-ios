import Foundation

// #if canImport(ProximityReader)
// import ProximityReader
// #endif

@available(iOS 16.0, *)
@MainActor
final class PaymentSession {
    enum State {
        case idle
        case preparing
        case ready
    }

    enum PreparationEvent {
        case notReady
        case progress(Int)
        case error(PaymentCardReaderError)
        case ready

        var error: PaymentCardReaderError? {
            guard case let .error(error) = self else {
                return nil
            }

            return error
        }

        var isPreparing: Bool {
            self != .ready
        }

        var isReady: Bool {
            self == .ready
        }

        var progress: Int {
            guard case let .progress(value) = self else {
                return self == .ready ? 100 : 0
            }

            return value
        }
    }

    enum ReaderError: Error, Equatable {
        case accountAlreadyLinked
        case accountLinkingCancelled
        case accountLinkingFailed
        case accountLinkingRequiresiCloudSignIn
        case accountNotLinked
        case backgroundRequestNotAllowed
        case deviceBanned(Date?)
        case emptyReaderToken
        case invalidMerchant
        case invalidReaderToken(String?)
        case merchantBlocked
        case modelNotSupported
        case networkAuthenticationError
        case networkError
        case notAllowed
        case notReady
        case osVersionNotSupported
        case passcodeDisabled
        case prepareExpired
        case prepareFailed(String?)
        case readerBusy
        case readerMemoryFull
        case serviceConnectionError
        case tokenExpired
        case unsupported

        var errorName: String {
            String(describing: self)
        }
    }

    enum ReadEvent {
        case readyForTap
        case cardDetected
        case readCancelled
        case readNotCompleted
        case pinEntry
        case removeCard
        case readCompleted // Maps to Event.completed
        case retrying // Maps to Event.retry
        case error(PaymentSession.ReadError)
        case complete(PaymentSession.ReadResult)
    }

    enum ReadError: Error, Equatable {
        case readNotAllowed
        case readFromBackgroundError
        case readerServiceConnectionError
        case readerServiceError
        case noReaderSession
        case readerSessionExpired
        case readerTokenExpired
        case readerSessionNetworkError
        case readerSessionAuthenticationError
        case readerSessionBusy
        case readCancelled
        case invalidAmount
        case invalidCurrencyCode
        case nfcDisabled
        case readNotAllowedDuringCall
        case passcodeDisabled
        case cardReadFailed
        case vasReadFail
        case paymentReadFailed
        case paymentCardDeclined
        case invalidVASMerchants(String?)
        case invalidVASRequestParameters(String?)
        @available(iOS 16.0, *)
        case pinEntryFailed
        @available(iOS 16.0, *)
        case pinTokenInvalid
        @available(iOS 16.0, *)
        case pinEntryTimeout
        @available(iOS 16.0, *)
        case pinCancelled
        @available(iOS 16.0, *)
        case pinNotAllowed
        case unknown

        var errorName: String {
            String(describing: self)
        }
    }

    @dynamicMemberLookup
    struct ReadResult: Identifiable {
        var id: String { result.id }

        private let result: PaymentCardReadResult

        init(_ result: PaymentCardReadResult) {
            self.result = result
        }

        subscript<T>(dynamicMember dynamicMember: KeyPath<PaymentCardReadResult, T>) -> T {
            result[keyPath: dynamicMember]
        }
    }

    nonisolated static var isSupported: Bool {
        PaymentCardReader.isSupported
    }

    private let reader: PaymentCardReader
    private var session: PaymentCardReaderSession?

    init(reader: PaymentCardReader = PaymentCardReader()) {
        self.reader = reader
    }

    func prepare() -> AsyncStream<PreparationEvent> {
        AsyncStream { continuation in
            // Can be removed once refactored on top of triPOS.
            let token = PaymentCardReader.Token(rawValue: "fakeToken")

            Task {
                do {
                    session = try await reader.prepare(using: token) { event in
                        switch event {
                        case .notReady:
                            continuation.yield(.notReady)
                        case let .progress(value):
                            continuation.yield(.progress(value))
//                        #if canImport(ProximityReader)
//                        @unknown default:
//                            print("Unknown default: \(event)")
//                        #endif
                        }
                    }
                    continuation.yield(.ready)
                } catch let error as PaymentCardReaderError {
                    if case .accountNotLinked = error {
                        do {
                            try await reader.linkAccount(using: token)
                            session = try await reader.prepare(using: token) { event in
                                switch event {
                                case .notReady:
                                    continuation.yield(.notReady)
                                case let .progress(value):
                                    continuation.yield(.progress(value))
//                                #if canImport(ProximityReader)
//                                @unknown default:
//                                    print("Unknown default: \(event)")
//                                #endif
                                }
                            }
                            continuation.yield(.ready)
                        } catch let error as PaymentCardReaderError {
                            Log.proximityReader.error("*** Preparation failed: \(error)")
                            continuation.yield(.error(error))
                        } catch {
                            Log.proximityReader.error("Inner reader received other error: \(error)")
                        }
                    } else {
                        Log.proximityReader.error("*** Preparation failed: \(error)")
                        continuation.yield(.error(error))
                    }
                } catch {
                    Log.proximityReader.error("Reader received other error: \(error)")
                }

                continuation.finish()
            }
        }
    }

    func read(amount: Decimal) -> AsyncStream<ReadEvent> {
        AsyncStream { continuation in
            Task {
                guard let session else {
                    continuation.finish()
                    return
                } // TODO: State error.

                do {
                    let result = try await session.readPaymentCard(.init(amount: amount,
                                                                         currencyCode: "USD")) { event in
                        switch event {
                        case .readyForTap:
                            continuation.yield(.readyForTap)
                        case .cardDetected:
                            continuation.yield(.cardDetected)
                        case .removeCard:
                            continuation.yield(.removeCard)
                        case .completed:
                            continuation.yield(.readCompleted)
                        case .retry:
                            continuation.yield(.retrying)
                        case .readCancelled:
                            continuation.yield(.readCancelled)
                        case .readNotCompleted:
                            continuation.yield(.readNotCompleted)
//                        #if canImport(ProximityReader)
//                        @unknown default:
//                            break
//                        #endif
                        }
                    }

                    continuation.yield(.complete(.init(result)))
                } catch let error as PaymentCardReaderSession.ReadError {
                    continuation.yield(.error(.init(error)))
                } catch {}

                continuation.finish()
            }
        }
    }
}

@available(iOS 16.0, *)
extension PaymentSession.ReadError {
    init(_ underlyingReadError: PaymentCardReaderSession.ReadError) {
        switch underlyingReadError {
        case .readNotAllowed:
            self = .readNotAllowed
        case .readFromBackgroundError:
            self = .readFromBackgroundError
        case .readerServiceConnectionError:
            self = .readerServiceConnectionError
        case .readerServiceError:
            self = .readerServiceError
        case .noReaderSession:
            self = .noReaderSession
        case .readerSessionExpired:
            self = .readerSessionExpired
        case .readerTokenExpired:
            self = .readerTokenExpired
        case .readerSessionNetworkError:
            self = .readerSessionNetworkError
        case .readerSessionAuthenticationError:
            self = .readerSessionAuthenticationError
        case .readerSessionBusy:
            self = .readerSessionBusy
        case .readCancelled:
            self = .readCancelled
        case .invalidAmount:
            self = .invalidAmount
        case .invalidCurrencyCode:
            self = .invalidCurrencyCode
        case .nfcDisabled:
            self = .nfcDisabled
        case .readNotAllowedDuringCall:
            self = .readNotAllowedDuringCall
        case .passcodeDisabled:
            self = .passcodeDisabled
        case .cardReadFailed:
            self = .cardReadFailed
        case .vasReadFail:
            self = .vasReadFail
        case .paymentReadFailed:
            self = .paymentReadFailed
        case .paymentCardDeclined:
            self = .paymentCardDeclined
        case let .invalidVASMerchants(merchants):
            self = .invalidVASMerchants(merchants)
        case let .invalidVASRequestParameters(parameters):
            self = .invalidVASRequestParameters(parameters)
        default:
            switch underlyingReadError {
            case .pinEntryFailed:
                self = .pinEntryFailed
            case .pinTokenInvalid:
                self = .pinTokenInvalid
            case .pinEntryTimeout:
                self = .pinEntryTimeout
            case .pinCancelled:
                self = .pinCancelled
            case .pinNotAllowed:
                self = .pinNotAllowed
            default:
                self = .unknown
            }
        }
    }
}

#if canImport(ProximityReader)

@available(iOS 16.0, *)
extension PaymentSession.PreparationEvent: Equatable {
    static func == (lhs: PaymentSession.PreparationEvent, rhs: PaymentSession.PreparationEvent) -> Bool {
        switch (lhs, rhs) {
        case (.notReady, .notReady),
             (.ready, .ready):
            return true
        case let (.progress(lProgress), .progress(rProgress)):
            return lProgress == rProgress
        case let (.error(lError), .error(rError)):
            return lError == rError
        default:
            return false
        }
    }
}

@available(iOS 16.0, *)
extension PaymentSession.ReadEvent: Equatable {
    static func == (lhs: PaymentSession.ReadEvent, rhs: PaymentSession.ReadEvent) -> Bool {
        switch (lhs, rhs) {
        case (.readyForTap, .readyForTap),
             (.cardDetected, .cardDetected),
             (.readCancelled, .readCancelled),
             (.readNotCompleted, .readNotCompleted),
             (.pinEntry, .pinEntry),
             (.removeCard, .removeCard),
             (.readCompleted, .readCompleted),
             (.retrying, .retrying):
            return true
        case let (.error(lError), .error(rError)):
            return lError == rError
        case let (.complete(lResult), .complete(rResult)):
            return lResult.id == rResult.id
        default:
            return false
        }
    }
}

@available(iOS 16.0, *)
extension PaymentSession.ReadResult: Equatable {
    static func == (lhs: PaymentSession.ReadResult, rhs: PaymentSession.ReadResult) -> Bool {
        lhs.id == rhs.id
    }
}

#else

@available(iOS 16.0, *)
extension PaymentSession.PreparationEvent: Equatable {}
@available(iOS 16.0, *)
extension PaymentSession.ReadEvent: Equatable {}
@available(iOS 16.0, *)
extension PaymentSession.ReadResult: Equatable {}

#endif
