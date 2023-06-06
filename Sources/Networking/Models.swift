import Foundation

struct Response<Success: Codable> {
    let id: String
    let date: Date
    let result: Result<Success, ResponseError>
}

struct ResponseError: Error, Codable, Equatable {
    let statusCode: Int
    let description: String
    let presentableDescription: String?
}

extension Response: Equatable where Success: Equatable {}

extension Response: Decodable {
    enum ResponseResult: String, Codable {
        case success = "Success"
        case failure = "Failed"
    }

    enum CodingKeys: String, CodingKey {
        case id
        case date
        case result
        case data
    }

    init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: CodingKeys.self)
        self.id = try container.decode(String.self, forKey: .id)
        self.date = try container.decode(Date.self, forKey: .date)
        let result = try container.decode(ResponseResult.self, forKey: .result)
        switch result {
        case .success:
            self.result = try .success(container.decode(Success.self, forKey: .data))
        case .failure:
            self.result = try .failure(container.decode(ResponseError.self, forKey: .data))
        }
    }
}

extension Response: Encodable {
    func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: CodingKeys.self)
        try container.encode(id, forKey: .id)
        try container.encode(date, forKey: .date)
        switch result {
        case let .success(value):
            try container.encode(ResponseResult.success, forKey: .result)
            try container.encode(value, forKey: .data)
        case let .failure(value):
            try container.encode(ResponseResult.failure, forKey: .result)
            try container.encode(value, forKey: .data)
        }
    }
}

struct LoginRequest {
    let ssoPayload: String
}

extension LoginRequest: Encodable {}

struct LoginResponse: Equatable {
    let status: LoginStatus
    let webFeatureURLs: WebFeatureURLs
    let tapToPayRates: TapToPayRates?
}

extension LoginResponse {
    struct TapToPayRates: Codable, Equatable {
        let ttpFeeValue: Double?
        let ttpFeeCap: Double?
        let vtfFeeValue: Double?
        let vtfFeeCap: Double?
        
        enum CodingKeys: String, CodingKey {
            case ttpFeeValue
            case ttpFeeCap
            case vtfFeeValue
            case vtfFeeCap
        }
    }
}

extension LoginResponse {
    struct WebFeatureURLs: Codable, Equatable {
        let invoicing: URL
        let paymentForm: URL
        let virtualTerminal: URL?

        enum CodingKeys: String, CodingKey {
            case invoicing = "invoicingModuleUrl"
            case paymentForm = "paymentFormModuleUrl"
            case virtualTerminal = "virtualTerminalUrl"
        }
    }
}

extension LoginResponse {
    enum LoginStatus: Equatable {
        case needsEnrollment(NeedsEnrollment)
        case success(Success)

        var accessToken: String? {
            guard case let .success(value) = self else {
                return nil
            }

            return value.accessToken
        }
        
        var status: Status? {
            guard case let .success(value) = self else {
                return nil
            }
            return value.status
        }
        
        struct NeedsEnrollment: Codable, Equatable {
            let url: URL

            enum CodingKeys: String, CodingKey {
                case url = "webViewUrl"
            }
        }

        struct Success: Codable, Equatable {
            let accessToken: String
            let status: Status
        }
    }
}

extension LoginResponse: Codable {
    private enum URLCodingKeys: String, CodingKey {
        case webFeatureURLs = "moduleUrls"
    }
    
    private enum TapToPayRatesCodingKeys: String, CodingKey {
        case tapToPayRates
    }

    init(from decoder: Decoder) throws {
        self.status = try LoginResponse.LoginStatus(from: decoder)

        let webFeatureUrlContainer = try decoder.container(keyedBy: URLCodingKeys.self)
        self.webFeatureURLs = try webFeatureUrlContainer.decode(WebFeatureURLs.self, forKey: .webFeatureURLs)
        
        let tapToPayRatesContainer = try decoder.container(keyedBy: TapToPayRatesCodingKeys.self)
        self.tapToPayRates = try tapToPayRatesContainer.decode(TapToPayRates?.self, forKey: .tapToPayRates)
    }

    func encode(to encoder: Encoder) throws {
        try status.encode(to: encoder)

        var webFeatureURLsContainer = encoder.container(keyedBy: URLCodingKeys.self)
        try webFeatureURLsContainer.encode(webFeatureURLs, forKey: .webFeatureURLs)
        
        var tapToPayRatesContainer = encoder.container(keyedBy: TapToPayRatesCodingKeys.self)
        try tapToPayRatesContainer.encode(tapToPayRates, forKey: .tapToPayRates)
    }
}

extension LoginResponse.LoginStatus: Codable {
    private enum Kind: String, Codable {
        case success = "LoginSuccess"
        case needsEnrollment = "NeedsEnrollment"
    }

    fileprivate enum CodingKeys: String, CodingKey {
        case loginStatus
        case login
    }

    init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: CodingKeys.self)
        let kind = try container.decode(Kind.self, forKey: .loginStatus)
        switch kind {
        case .needsEnrollment:
            self = try .needsEnrollment(container.decode(NeedsEnrollment.self, forKey: .login))
        case .success:
            self = try .success(container.decode(Success.self, forKey: .login))
        }
    }

    func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: CodingKeys.self)
        switch self {
        case let .needsEnrollment(value):
            try container.encode(Kind.needsEnrollment, forKey: .loginStatus)
            try container.encode(value, forKey: .login)
        case let .success(value):
            try container.encode(Kind.success, forKey: .loginStatus)
            try container.encode(value, forKey: .login)
        }
    }
}

enum Status: Equatable {
    case hasMissingInfo(HasMissingInfo)
    case merchantPendingApprovalForTapToPay(MerchantPendingApprovalForTapToPay)
    case paymentEnablementRequested(PaymentEnablementRequested)
    case enabled(Enabled)
    case notEnabled(NotEnabled)
    
    var merchantCredentials: MerchantCredentials? {
        guard case let .enabled(value) = self else {
            return nil
        }
        return value.merchantCredentials
    }
    
    struct HasMissingInfo: Codable, Equatable {
        let url: URL

        enum CodingKeys: String, CodingKey {
            case url = "webViewUrl"
        }
    }
    
    struct Enabled: Codable, Equatable {
        let merchantCredentials: MerchantCredentials
    }

    struct NotEnabled: Codable, Equatable {
        let presentableDescription: String
    }
    
    struct MerchantPendingApprovalForTapToPay: Codable, Equatable {
        let presentableDescription: String
    }
    
    struct PaymentEnablementRequested: Codable, Equatable {
        let presentableDescription: String
    }
}

struct MerchantCredentials: Codable, Equatable {
    let accountToken: String
    let accountId: String
    let acceptorId: String
    let applicationId: String
    let applicationVersion: String
    let applicationName: String
}

extension Status: Codable {
    enum Kind: String, Codable {
        case hasMissingInfo = "HasMissingInfo"
        case paymentEnablementRequested = "PaymentEnablementRequested"
        case merchantPendingApprovalForTapToPay = "MerchantPendingApprovalForTapToPay"
        case notEnabled = "NotEnabled"
        case enabled = "Enabled"
    }

    enum CodingKeys: String, CodingKey {
        case kind
        case status
    }

    init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: CodingKeys.self)
        let kind = try container.decode(Kind.self, forKey: .kind)
        switch kind {
        case .hasMissingInfo:
            self = try .hasMissingInfo(container.decode(HasMissingInfo.self, forKey: .status))
        case .notEnabled:
            self = try .notEnabled(container.decode(NotEnabled.self, forKey: .status))
        case .enabled:
            self = try .enabled(container.decode(Enabled.self, forKey: .status))
        case .paymentEnablementRequested:
            self = try .paymentEnablementRequested(container.decode(PaymentEnablementRequested.self, forKey: .status))
        case .merchantPendingApprovalForTapToPay:
            self = try .merchantPendingApprovalForTapToPay(container.decode(MerchantPendingApprovalForTapToPay.self, forKey: .status))
        }
    }

    func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: CodingKeys.self)
        switch self {
        case let .hasMissingInfo(value):
            try container.encode(Kind.hasMissingInfo, forKey: .kind)
            try container.encode(value, forKey: .status)
        case let .enabled(value):
            try container.encode(Kind.enabled, forKey: .kind)
            try container.encode(value, forKey: .status)
        case let .notEnabled(value):
            try container.encode(Kind.notEnabled, forKey: .kind)
            try container.encode(value, forKey: .status)
        case let .merchantPendingApprovalForTapToPay(value):
            try container.encode(Kind.merchantPendingApprovalForTapToPay, forKey: .kind)
            try container.encode(value, forKey: .status)
        case let .paymentEnablementRequested(value):
            try container.encode(Kind.paymentEnablementRequested, forKey: .kind)
            try container.encode(value, forKey: .status)
        }
    }
}

struct CreateTransactionRequest: Codable, Equatable {
    let amount: Decimal
    let type: Transaction.TransactionType
}

struct CreateTransactionResponse: Equatable {
    let uuid: UUID
    let referenceNumber: String
    let ticketNumber: String

    enum CodingKeys: String, CodingKey {
        case uuid
        case referenceNumber
        case ticketNumber
    }
}

extension CreateTransactionResponse: Encodable {
    func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: CodingKeys.self)
        try container.encode(uuid, forKey: .uuid)
        try container.encode(Int(referenceNumber)!, forKey: .referenceNumber)
        try container.encode(Int(ticketNumber)!, forKey: .ticketNumber)
    }
}

extension CreateTransactionResponse: Decodable {
    init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: CodingKeys.self)
        self.uuid = try container.decode(UUID.self, forKey: .uuid)
        self.referenceNumber = try "\(container.decode(Int.self, forKey: .referenceNumber))"
        self.ticketNumber = try "\(container.decode(Int.self, forKey: .ticketNumber))"
    }
}

struct SyncTransactionRequest: Encodable {
    let uuid: UUID
    let transactionID: String

    enum CodingKeys: String, CodingKey {
        case uuid
        case transactionID = "transactionId"
    }
}

struct Transaction: Equatable {
    let uuid: UUID
    let createdOn: Date
    let formattedAmount: String
    let type: TransactionType
    let status: Status
    let receiptRecipients: [ReceiptRecipient]
    let card: Card
    let associatedTransactionRequestDate: Date?
    let canRequestReceipt: Bool

    var lastReceiptEmail: String? {
        receiptRecipients.last?.email
    }
    
    struct Card: Encodable, Equatable, CustomStringConvertible {
        let payerName: String
        let logo: String
        let type: String
        let lastFour: String
        
        var description: String {
            "\(logo) *\(lastFour)"
        }
    }

    enum Status: String, Codable, Equatable, CaseIterable {
        case cancelable = "Cancelable"
        case refundable = "Refundable"
        case final = "Final"
        case canceled = "Canceled"
        case refunded = "Refunded"
        case declined = "Declined"
        case unknown = "Unknown"
    }

    enum TransactionType: String, Codable, Equatable {
        case refund = "Refund"
        case sale = "Sale"
        case cancel = "Cancel"
        case fallbackSale = "FallbackSale"
    }

    // Generated by quicktype.io
    struct Raw: Codable {
        let created: Date
        let formattedAmount: String
        let type: TransactionType
        let status: String
        let card: Card
        let receiptRecipients: [ReceiptRecipient]
        let uuid: UUID
        let associatedTransactionRequestDate: Date?
        let canRequestReceipt: Bool
    }
}

extension Transaction.Card: Decodable {
    init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: CodingKeys.self)
        self.payerName = try (container.decodeIfPresent(String.self, forKey: .payerName)) ?? "No Name"
        self.logo = try (container.decodeIfPresent(String.self, forKey: .logo)) ?? "No Logo"
        self.type = try (container.decodeIfPresent(String.self, forKey: .type)) ?? "No Type"
        self.lastFour = try (container.decodeIfPresent(String.self, forKey: .lastFour)) ?? "No Four"
    }
}

extension Transaction: Encodable {
    func encode(to encoder: Encoder) throws {
        let rawStatus: String
        switch status {
        case .cancelable:
            rawStatus = "Pending"
        case .refundable:
            rawStatus = "Approved"
        case .final:
            rawStatus = "Settled"
        case .canceled:
            rawStatus = "Voided"
        case .refunded:
            rawStatus = "Returned"
        case .declined:
            rawStatus = "Declined"
        case .unknown:
            rawStatus = "Unknown"
        }

        let rawTransaction = Raw(created: createdOn,
                                 formattedAmount: formattedAmount,
                                 type: type,
                                 status: rawStatus,
                                 card: card,
                                 receiptRecipients: receiptRecipients,
                                 uuid: uuid,
                                 associatedTransactionRequestDate: associatedTransactionRequestDate,
                                 canRequestReceipt: canRequestReceipt)

        try rawTransaction.encode(to: encoder)
    }
}

extension Transaction: Decodable {
    init(from decoder: Decoder) throws {
        let rawTransaction = try Raw(from: decoder)
        self.createdOn = rawTransaction.created
        self.formattedAmount = rawTransaction.formattedAmount
        self.card = rawTransaction.card
        self.receiptRecipients = rawTransaction.receiptRecipients
        self.uuid = rawTransaction.uuid
        self.type = rawTransaction.type
        self.associatedTransactionRequestDate = rawTransaction.associatedTransactionRequestDate
        self.canRequestReceipt = rawTransaction.canRequestReceipt

        // Parse our Status from the raw status.
        switch rawTransaction.status {
        case "Canceled":
            self.status = .canceled
        case "Cancelable":
            self.status = .cancelable
        case "Declined":
            self.status = .declined
        case "Voided":
            self.status = .canceled
        case "Refunded":
            self.status = .refunded
        case "Refundable":
            self.status = .refundable
        case "Settled":
            self.status = .final
        default:
            Log.sdk.warning("*** Received unhandled RawTransaction.Status: \(rawTransaction.status), marking as .final.")
            self.status = .final
        }
    }
}

struct ReceiptRecipient: Codable, Equatable {
    let email: String
}

extension Transaction {
    static func random(uuid: UUID = UUID()) -> Transaction {
        .init(uuid: uuid,
              createdOn: Date(timeIntervalSince1970: Date().timeIntervalSince1970 - Double(Int.random(in: 0...(3600 * 92)))),
              formattedAmount: Decimal(Double.random(in: 1...200)).dollars,
              type: .sale,
              status: Status.allCases.randomElement()!,
              receiptRecipients: [],
              card: .init(payerName: "Otto Books",
                          logo: "Visa",
                          type: "Credit",
                          lastFour: "1234"),
              associatedTransactionRequestDate: nil,
              canRequestReceipt: true)
    }
}

extension Transaction: Identifiable {
    var id: UUID { uuid }
}

struct ReceiptRequest {
    let uuid: UUID
    let email: String
}

extension ReceiptRequest: Encodable {
    enum CodingKeys: String, CodingKey {
        case email = "EmailAddress"
    }
}

struct VTPSale: Equatable {
    let uuid: UUID
    let transactionID: String
}

struct ExpressTransaction {
    var ExpressResponseMessage: String = ""
    var ExpressTransactionDate: String = ""
    var ExpressTransactionTime: String = ""
    var card = Card()
    var TransactionID: String = ""
    var ApprovalNumber: String = ""
    var ReferenceNumber: String = ""
    var ProcessorName: String = ""
    var ApprovedAmount: String = ""
    var NetworkTransactionID: String = ""
    var RetrievalReferenceNumber: String = ""
    var SystemTraceAuditNumber: String = ""
}

struct Card {
    var ExpirationMonth: String = ""
    var ExpirationYear: String = ""
    var CardLogo: String = ""
    var CardNumberMasked: String = ""
    var BIN: String = ""
}
