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
        case success = "Success", failure = "Failed"
    }

    enum CodingKeys: String, CodingKey {
        case id, date, result, data
    }

    init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: CodingKeys.self)
        id = try container.decode(String.self, forKey: .id)
        date = try container.decode(Date.self, forKey: .date)
        let result = try container.decode(ResponseResult.self, forKey: .result)
        switch result {
        case .success:
            self.result = .success(try container.decode(Success.self, forKey: .data))
        case .failure:
            self.result = .failure(try container.decode(ResponseError.self, forKey: .data))
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
}

extension LoginResponse {
    enum LoginStatus: Equatable {
        case needsEnrollment(NeedsEnrollment)
        case success(Success)

        var accessToken: String? {
            guard case let .success(value) = self else { return nil }

            return value.accessToken
        }

        struct NeedsEnrollment: Codable, Equatable {
            let callbackURL: URL
            let url: URL

            enum CodingKeys: String, CodingKey {
                case callbackURL = "callbackUrl", url = "webViewUrl"
            }
        }

        struct Success: Codable, Equatable {
            let accessToken: String
            let status: Status
        }
    }
}

extension LoginResponse: Codable {
    init(from decoder: Decoder) throws {
        status = try LoginResponse.LoginStatus(from: decoder)
    }

    func encode(to encoder: Encoder) throws {
        try status.encode(to: encoder)
    }
}

extension LoginResponse.LoginStatus: Codable {
    private enum Kind: String, Codable {
        case success = "LoginSuccess", needsEnrollment = "NeedsEnrollment"
    }

    fileprivate enum CodingKeys: String, CodingKey {
        case loginStatus, login
    }

    init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: CodingKeys.self)
        let kind = try container.decode(Kind.self, forKey: .loginStatus)
        switch kind {
        case .needsEnrollment:
            self = .needsEnrollment(try container.decode(NeedsEnrollment.self, forKey: .login))
        case .success:
            self = .success(try container.decode(Success.self, forKey: .login))
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

struct PaymentTokenRequest {
    let cardReaderID: String?

    enum CodingKeys: String, CodingKey {
        case cardReaderID = "cardReaderId"
    }
}

struct PaymentTokenResponse: Codable, Equatable {
    let token: String

    enum CodingKeys: String, CodingKey {
        case token = "paymentCardToken"
    }
}

enum Status: Equatable {
    case hasMissingInfo(HasMissingInfo)
    case enabled
    case notEnabled(NotEnabled)

    struct HasMissingInfo: Codable, Equatable {
        let callbackURL: URL
        let url: URL

        enum CodingKeys: String, CodingKey {
            case callbackURL = "callbackUrl", url = "webViewUrl"
        }
    }

    struct NotEnabled: Codable, Equatable {
        let presentableDescription: String
    }
}

extension Status: Codable {
    enum Kind: String, Codable {
        case hasMissingInfo = "HasMissingInfo", notEnabled = "NotEnabled", enabled = "Enabled"
    }

    enum CodingKeys: String, CodingKey {
        case kind, status
    }

    init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: CodingKeys.self)
        let kind = try container.decode(Kind.self, forKey: .kind)
        switch kind {
        case .hasMissingInfo:
            self = .hasMissingInfo(try container.decode(HasMissingInfo.self, forKey: .status))
        case .notEnabled:
            self = .notEnabled(try container.decode(NotEnabled.self, forKey: .status))
        case .enabled:
            self = .enabled
        }
    }

    func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: CodingKeys.self)
        switch self {
        case let .hasMissingInfo(value):
            try container.encode(Kind.hasMissingInfo, forKey: .kind)
            try container.encode(value, forKey: .status)
        case .enabled:
            try container.encode(Kind.enabled, forKey: .kind)
        case let .notEnabled(value):
            try container.encode(Kind.notEnabled, forKey: .kind)
            try container.encode(value, forKey: .status)
        }
    }
}

struct TransactionRequest: Encodable {
    let cardReaderBlob: String
}

struct TransactionResponse: Equatable {
    let result: Result
    var transaction: Transaction? {
        guard case let .success(transaction) = result else { return nil }

        return transaction
    }

    enum Result: Codable, Equatable {
        case success(Transaction)
        case failure(Failure)
    }

    struct Failure: Codable, Equatable {
        let message: String
    }
}

struct Transaction: Codable, Equatable {
    let transactionID: String
    let name: String
    let cardDescription: String
    let date: Date
    let total: String
    let lastReceiptEmail: String?
    let status: Status

    enum Status: String, Codable, Equatable, CaseIterable {
        case cancelable = "Cancelable", refundable = "Refundable", final = "Final", canceled = "Canceled", refunded = "Refunded"
    }
}

extension Transaction {
    static var stub: Transaction {
        .init(transactionID: UUID().uuidString,
              name: "Otto Books",
              cardDescription: "Visa *4354",
              date: Date(timeIntervalSince1970: Date().timeIntervalSince1970 - Double(Int.random(in: 0...(3600 * 92)))),
              total: "$125.45",
              lastReceiptEmail: nil,
              status: Status.allCases.randomElement()!)
    }
}

extension Transaction: Identifiable {
    var id: String { transactionID }
}

extension TransactionResponse: Codable {
    enum CodingKeys: String, CodingKey {
        case result, value
    }

    enum ResultKey: String, Codable {
        case success, failure
    }

    init(from decoder: Decoder) throws {
        let container = try decoder.container(keyedBy: CodingKeys.self)
        let result = try container.decode(ResultKey.self, forKey: .result)
        switch result {
        case .success:
            self.result = .success(try container.decode(Transaction.self, forKey: .value))
        case .failure:
            self.result = .failure(try container.decode(Failure.self, forKey: .value))
        }
    }

    func encode(to encoder: Encoder) throws {
        var container = encoder.container(keyedBy: CodingKeys.self)
        switch result {
        case let .success(value):
            try container.encode(ResultKey.success, forKey: .result)
            try container.encode(value, forKey: .value)
        case let .failure(value):
            try container.encode(ResultKey.failure, forKey: .result)
            try container.encode(value, forKey: .value)
        }
    }
}

struct ReceiptRequest {
    let transactionID: String
    let email: String
}

extension ReceiptRequest: Encodable {
    enum CodingKeys: String, CodingKey {
        case email
    }
}
