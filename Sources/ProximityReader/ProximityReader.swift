import Foundation
import UIKit

// #if !canImport(ProximityReader)

@available(iOS 15.4, *)
class PaymentCardReader {
    struct Options {
        var vasMerchants: [VASRequest.Merchant] = []
    }

    struct Token: RawRepresentable, Hashable {
        let rawValue: String

        init(rawValue: String) {
            self.rawValue = rawValue
        }
    }

    enum UpdateEvent {
        case notReady
        case progress(Int)
    }

    static var isSupported: Bool {
        UIDevice.current.supportsTapToPay
    }

    // TODO: Generate from ObjectIdentifier?
    let id = UUID().uuidString

    var readerIdentifier: String {
        get async throws { "id" }
    }

    // MARK: - Testing APIs

    typealias PreparationClosure = () throws -> Void

    private var preparationFailures: [PreparationClosure] = [{
        throw PaymentCardReaderError.serviceConnectionError
    },
    {}]

    func nextPreparationFailure() -> PreparationClosure {
        guard !preparationFailures.isEmpty else { fatalError("preparationFailures is empty.") }

        if preparationFailures.count > 1 {
            let failure = preparationFailures.removeFirst()
            return failure
        } else {
            return preparationFailures[0]
        }
    }

    // MARK: -

    func linkAccount(using token: PaymentCardReader.Token) async throws {
        print("*** Linking account.")
        try? await Task.sleep(nanoseconds: 100 * NSEC_PER_MSEC)
    }

    func prepare(using token: PaymentCardReader.Token,
                 updateHandler: ((PaymentCardReader.UpdateEvent) -> Void)?) async throws -> PaymentCardReaderSession {
        if let updateHandler = updateHandler {
            updateHandler(.notReady)
            updateHandler(.progress(0))
            for completion in stride(from: 10, through: 100, by: 10) {
                try? await Task.sleep(nanoseconds: 100 * NSEC_PER_MSEC)
                updateHandler(.progress(completion))
//                if completion > 60 {
//                    try nextPreparationFailure()()
//                }
            }
        }

        return .init()
    }
}

@available(iOS 15.4, *)
enum PaymentCardReaderError: Error, Equatable {
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

@available(iOS 15.4, *)
class PaymentCardReaderSession {
    enum Event: Hashable {
        case readyForTap
        case cardDetected
        case removeCard
        case completed
        case retry
        case readCancelled
        case readNotCompleted

        var name: String { String(describing: self) }
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

        var errorName: String { String(describing: self) }
    }

    let id: String = UUID().uuidString

    enum Payload {
        case event(Event)
        case sessionError(ReadError)
    }

    private var payloadSequences: [[Payload]] = [
        // [.event(.readyForTap), .event(.cardDetected), .event(.removeCard), .sessionError(.cardReadFailed)],
        [.event(.readyForTap), .event(.cardDetected), .event(.removeCard), .event(.completed)]
    ]

    func nextPayloadSequence() -> [Payload] {
        guard !payloadSequences.isEmpty else { fatalError("payloadSequence is empty.") }

        if payloadSequences.count > 1 {
            let failure = payloadSequences.removeFirst()
            return failure
        } else {
            return payloadSequences[0]
        }
    }

    func readPaymentCard(_ request: PaymentCardTransactionRequest,
                         eventHandler: ((PaymentCardReaderSession.Event) -> Void)? = nil) async throws -> PaymentCardReadResult {
        for payload in nextPayloadSequence() {
            switch payload {
            case let .event(event):
                try? await Task.sleep(nanoseconds: 100 * NSEC_PER_MSEC)
                eventHandler?(event)
            case let .sessionError(readError):
                throw readError
            }
        }

        return .init(id: UUID().uuidString, generalCardData: "generalCardData", paymentCardData: "paymentCardData")
    }

    func readPaymentCard(_ request: PaymentCardVerificationRequest,
                         eventHandler: ((PaymentCardReaderSession.Event) -> Void)? = nil) async throws -> PaymentCardReadResult {
        .init(id: UUID().uuidString, generalCardData: "generalCardData", paymentCardData: "paymentCardData")
    }

    func cancelRead() async throws -> Bool {
        true
    }
}

@available(iOS 15.4, *)
struct PaymentCardTransactionRequest {
    enum TransactionType: Hashable {
        case purchase
        case refund
    }

    let amount: Decimal
    let currencyCode: String
    let type: PaymentCardTransactionRequest.TransactionType

    init(amount: Decimal, currencyCode: String, for type: PaymentCardTransactionRequest.TransactionType = .purchase) {
        self.amount = amount
        self.currencyCode = currencyCode
        self.type = type
    }
}

@available(iOS 15.4, *)
struct PaymentCardVerificationRequest {
    enum Reason: Hashable {
        case lookUp
        case saveCard
        case openTab
        case other
    }

    let currencyCode: String
    let verificationReason: PaymentCardVerificationRequest.Reason

    init(currencyCode: String, for reason: PaymentCardVerificationRequest.Reason = .other) {
        self.currencyCode = currencyCode
        verificationReason = reason
    }
}

@available(iOS 15.4, *)
struct PaymentCardReadResult: Equatable, Identifiable {
    let id: String
    let generalCardData: String?
    let paymentCardData: String?

    init(id: String, generalCardData: String?, paymentCardData: String?) {
        self.id = id
        self.generalCardData = generalCardData
        self.paymentCardData = paymentCardData
    }
}

@available(iOS 15.4, *)
class VASRequest {
    struct Merchant: Identifiable {
        let id: String
        var localizedName: String
        let url: URL?
        let shouldSendURLOnly: Bool

        init(id: String, url: URL? = nil, shouldSendURLOnly: Bool = false, localizedName: String? = nil) {
            self.id = id
            self.localizedName = localizedName ?? "Localized Name"
            self.url = url
            self.shouldSendURLOnly = shouldSendURLOnly
        }
    }

    let localizedVASType: String
    let vasMerchants: [Merchant]

    init(vasMerchants: [VASRequest.Merchant] = [], localizedVASType: String = "") {
        self.localizedVASType = localizedVASType
        self.vasMerchants = vasMerchants
    }
}

// #endif
