import Foundation

@available(iOS 13.0, *)
@dynamicMemberLookup
struct Request {
    let environment: Autobooks.BackendEnvironment
    let resource: Resource

    var urlRequest: URLRequest {
        get throws {
            var request = URLRequest(url: environment.url.appendingPathComponent(resource.path))
            request.httpMethod = resource.method
            try resource.encodeParameters(into: &request)

            return request
        }
    }

    subscript<T>(dynamicMember dynamicMember: KeyPath<Resource, T>) -> T {
        resource[keyPath: dynamicMember]
    }
}

enum Resource {
    case login(LoginRequest)
    case paymentToken(PaymentTokenRequest)
    case receipt(ReceiptRequest)
    case status
    case transaction(TransactionRequest)
    case transactions
    case cancelTransaction(String)
    case refundTransaction(String)

    var id: ID {
        switch self {
        case .login: return .login
        case .paymentToken: return .paymentToken
        case .receipt: return .receipt
        case .status: return .status
        case .transaction: return .transaction
        case .transactions: return .transactions
        case .cancelTransaction: return .cancelTransaction
        case .refundTransaction: return .refundTransaction
        }
    }

    var isAuthenticated: Bool {
        switch self {
        case .login: return false
        case .paymentToken, .receipt, .status, .transaction, .transactions, .cancelTransaction, .refundTransaction: return true
        }
    }

    var method: String {
        switch self {
        case .paymentToken, .status, .transactions: return "GET"
        case .login, .receipt, .transaction, .cancelTransaction, .refundTransaction: return "POST"
        }
    }

    var path: String {
        switch self {
        case .login: return "login"
        case .paymentToken: return "payment-card-reader-token"
        case let .receipt(request):
            return "payment-request/\(request.transactionID)/receipt"
        case .status: return "status"
        case .transaction: return "transaction"
        case .transactions: return "transactions"
        case let .cancelTransaction(id): return "payment-request/\(id)/cancel"
        case let .refundTransaction(id): return "payment-request/\(id)/refund"
        }
    }

    func encodeParameters(into request: inout URLRequest) throws {
        switch self {
        case .status, .transactions, .cancelTransaction, .refundTransaction: break
        case let .login(parameters):
            request.httpBody = try JSONEncoder.autobooks.encode(parameters)
        case let .paymentToken(parameters):
            guard let id = parameters.cardReaderID else { return }

            var components = URLComponents(url: request.url!, resolvingAgainstBaseURL: false)
            components?.queryItems = [URLQueryItem(name: PaymentTokenRequest.CodingKeys.cardReaderID.rawValue, value: id)]
            request.url = components?.url
        case let .receipt(parameters):
            request.httpBody = try JSONEncoder.autobooks.encode(parameters)
        case let .transaction(parameters):
            request.httpBody = try JSONEncoder.autobooks.encode(parameters)
        }
    }

    enum ID: String, Hashable {
        case login, paymentToken, receipt, status, transaction, transactions, cancelTransaction, refundTransaction
    }
}

extension JSONEncoder {
    static var autobooks: JSONEncoder {
        let encoder = JSONEncoder()
        encoder.dateEncodingStrategy = .custom { date, encoder in
            var container = encoder.singleValueContainer()
            try container.encode(ISO8601DateFormatter.autobooks.string(from: date))
        }

        return encoder
    }
}

extension ISO8601DateFormatter {
    static let autobooks: ISO8601DateFormatter = {
        let formatter = ISO8601DateFormatter()
        formatter.formatOptions.insert(.withFractionalSeconds)

        return formatter
    }()
}

extension JSONDecoder {
    enum DateDecodingError: Error {
        case decodeFailed(String)
    }

    static var autobooks: JSONDecoder {
        let decoder = JSONDecoder()
        decoder.dateDecodingStrategy = .custom { decoder in
            let container = try decoder.singleValueContainer()
            let string = try container.decode(String.self)

            guard let date = ISO8601DateFormatter.autobooks.date(from: string) else {
                throw DateDecodingError.decodeFailed(string)
            }

            return date
        }

        return decoder
    }
}
