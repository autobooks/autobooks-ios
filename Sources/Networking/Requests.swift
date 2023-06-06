import Foundation

@available(iOS 13.0, *)
@dynamicMemberLookup
struct Request {
    let environment: AB.BackendEnvironment
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
    case receipt(ReceiptRequest)
    case status
    case createTransaction(CreateTransactionRequest)
    case syncTransaction(SyncTransactionRequest)
    case transactions
    case cancelTransaction(UUID)
    case refundTransaction(UUID)

    var id: ID {
        switch self {
        case .login:
            return .login
        case .receipt:
            return .receipt
        case .status:
            return .status
        case .createTransaction:
            return .createTransaction
        case .syncTransaction:
            return .syncTransaction
        case .transactions:
            return .transactions
        case .cancelTransaction:
            return .cancelTransaction
        case .refundTransaction:
            return .refundTransaction
        }
    }

    var isAuthenticated: Bool {
        switch self {
        case .login:
            return false
        case .receipt,
             .status,
             .createTransaction,
             .syncTransaction,
             .transactions,
             .cancelTransaction,
             .refundTransaction:
            return true
        }
    }

    var method: String {
        switch self {
        case .status,
             .transactions: return "GET"
        case .login,
             .receipt,
             .createTransaction: return "POST"
        case .syncTransaction,
             .cancelTransaction,
             .refundTransaction: return "PUT"
        }
    }

    var path: String {
        switch self {
        case .login:
            return "login"
        case let .receipt(request):
            return "transactions/\(request.uuid.uuidString)/receipt"
        case .status:
            return "status"
        case .createTransaction:
            return "transactions"
        case let .syncTransaction(request):
            return "transactions/\(request.uuid.uuidString)"
        case .transactions:
            return "transactions"
        case let .cancelTransaction(id):
            return "transactions/\(id.uuidString)/cancel"
        case let .refundTransaction(id):
            return "transactions/\(id.uuidString)/refund"
        }
    }

    func encodeParameters(into request: inout URLRequest) throws {
        switch self {
        case .status,
             .transactions,
             .cancelTransaction,
             .refundTransaction: break
        case let .createTransaction(parameters):
            request.httpBody = try JSONEncoder.autobooks.encode(parameters)
        case let .login(parameters):
            request.httpBody = try JSONEncoder.autobooks.encode(parameters)
        case let .receipt(parameters):
            request.httpBody = try JSONEncoder.autobooks.encode(parameters)
        case let .syncTransaction(parameters):
            request.httpBody = try JSONEncoder.autobooks.encode(parameters)
        }
    }

    enum ID: String, Hashable {
        case login
        case receipt
        case status
        case createTransaction
        case syncTransaction
        case transactions
        case cancelTransaction
        case refundTransaction
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

extension DateFormatter {
    static let autobooks: DateFormatter = {
        let formatter = DateFormatter()
        formatter.dateFormat = "yyyy-MM-dd'T'HH:mm:ss.SSSSSSS"
        formatter.locale = Locale(identifier: "en_US_POSIX")
        #if swift(>=5.7)
        if #available(iOS 16.0, *) {
            formatter.timeZone = .gmt
        } else {
            formatter.timeZone = TimeZone(identifier: "GMT")
        }
        #else
        formatter.timeZone = TimeZone(identifier: "GMT")
        #endif

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

            guard let date = ISO8601DateFormatter.autobooks.date(from: string) ??
                DateFormatter.autobooks.date(from: string) else {
                throw DateDecodingError.decodeFailed(string)
            }

            return date
        }

        return decoder
    }
}
