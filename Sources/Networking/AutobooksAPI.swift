import Foundation

@available(iOS 13.0, *)
final class AutobooksAPI {
    private let session: URLSession
    private let environment: AB.BackendEnvironment
    private let responseProvider: AB.ResponseProvider
    private let loginProvider: @Sendable () async throws -> String

    private var bearerToken: String?

    init(subscriptionKey: String,
         environment: AB.BackendEnvironment = .dev,
         responseProvider: AB.ResponseProvider = .stubs(.successes),
         loginProvider: @escaping @Sendable () async throws -> String) {
        let configuration = URLSessionConfiguration.default
        let jsonMIMEType = "application/json"
        configuration.accept = jsonMIMEType
        configuration.contentType = jsonMIMEType
        let version = ProcessInfo.processInfo.operatingSystemVersion
        let versionString = "\(version.majorVersion).\(version.minorVersion).\(version.patchVersion)"
        configuration.userAgent = "AutobooksSDK/\(AB.version) iOS/\(versionString)"
        configuration.subscriptionKey = subscriptionKey

        switch responseProvider {
        case var .stubs(stubs) where !stubs.isEmpty,
             var .hybrid(stubs) where !stubs.isEmpty:
            if case .hybrid = responseProvider {
                // Login is real in hybrid case.
                stubs[.login] = nil
            }

            StubProvider.stubber = Stubber(stubs: stubs)
            URLProtocol.registerClass(StubProvider.self)
            configuration.protocolClasses?.insert(StubProvider.self, at: 0)
        default:
            break
        }

        self.session = URLSession(configuration: configuration)
        self.environment = environment
        self.responseProvider = responseProvider
        self.loginProvider = loginProvider
    }

    deinit {
        StubProvider.stubber = nil
        URLProtocol.unregisterClass(StubProvider.self)
    }

    func performLogin() async -> Result<LoginResponse, APIError> {
        await Result {
            try await loginProvider()
        }
        .mapError(APIError.loginProvider)
        .flatMap { loginToken in
            await perform(.login(LoginRequest(ssoPayload: loginToken)))
        }
        .then {
            bearerToken = $0.success?.status.accessToken
        }
    }

    func fetchStatus() async -> Result<Status, APIError> {
        await perform(.status)
    }

    func createTransaction(for amount: Decimal, type: Transaction.TransactionType) async -> Result<CreateTransactionResponse, APIError> {
        await perform(.createTransaction(.init(amount: amount, type: type)))
    }

    func syncTransaction(_ uuid: UUID, transactionID: String) async -> Result<Transaction, APIError> {
        await perform(.syncTransaction(.init(uuid: uuid, transactionID: transactionID)))
    }

    func requestReceipt(forTransactionID transactionID: UUID, email: String) async -> Result<Transaction, APIError> {
        await perform(.receipt(.init(uuid: transactionID, email: email)))
    }

    func fetchTransactions() async -> Result<[Transaction], APIError> {
        await perform(.transactions)
    }

    func cancelTransaction(_ uuid: UUID) async -> Result<Transaction, APIError> {
        await perform(.cancelTransaction(uuid))
    }

    func refundTransaction(_ uuid: UUID) async -> Result<Transaction, APIError> {
        await perform(.refundTransaction(uuid))
    }

    private func perform<Success: Codable>(_ resource: Resource, decoding type: Success.Type = Success.self) async -> Result<Success, APIError> {
        let request = Request(environment: environment, resource: resource)

        return await Result { () async throws -> Response<Success> in
            var urlRequest = try request.urlRequest

            if request.isAuthenticated {
                guard let sessionToken = bearerToken else {
                    throw APIError.missingSessionToken
                }

                urlRequest.bearerToken = sessionToken
            }

            if responseProvider == .backendMocked, request.id == .login {
                urlRequest.url?.appendPathComponent("mock")
            }

            let (data, _) = try await session.data(for: urlRequest, id: request.id)

            return try JSONDecoder.autobooks.decode(Response<Success>.self, from: data)
        }
        .mapError(APIError.init)
        .extractingResponseError()
    }
}

enum APIError: Error {
    case decoding(DecodingError)
    case encoding(EncodingError)
    case loginProvider(Error)
    case missingSessionToken
    case network(URLError)
    case response(ResponseError)
    case unknown(Error)
    case triPOS(TriPOSError)
}

extension APIError {
    init(_ error: Error) {
        switch error {
        case let error as APIError:
            self = error
        case let error as EncodingError:
            self = .encoding(error)
        case let error as URLError:
            self = .network(error)
        case let error as DecodingError:
            self = .decoding(error)
        case let error as TriPOSError:
            self = .triPOS(error)
        default:
            self = .unknown(error)
        }
    }
}

extension APIError: Equatable {
    static func == (lhs: Self, rhs: Self) -> Bool {
        switch (lhs, rhs) {
        case (.missingSessionToken, .missingSessionToken): return true
        case let (.encoding(left), .encoding(right)):
            return (left as NSError) == (right as NSError)
        case let (.decoding(left), .decoding(right)):
            return (left as NSError) == (right as NSError)
        case let (.triPOS(left), .triPOS(right)): return left == right
        case let (.network(left), .network(right)): return left == right
        case let (.loginProvider(left), .loginProvider(right)),
             let (.unknown(left), .unknown(right)):
            return left.localizedDescription == right.localizedDescription
        default:
            return false
        }
    }
}

@available(iOS 13.0, *)
extension URLSession {
    struct MalformedCompletion: Error {}

    func data(for urlRequest: URLRequest, id: Resource.ID) async throws -> (Data, HTTPURLResponse) {
        try await withCheckedThrowingContinuation { continuation in
            let task = dataTask(with: urlRequest) { data, response, error in
                switch (data, response, error) {
                case let (_, _, error?):
                    continuation.resume(with: .failure(error))
                case let (data?, response?, _):
                    continuation.resume(with: .success((data, response as! HTTPURLResponse)))
                default:
                    continuation.resume(with: .failure(MalformedCompletion()))
                }
            }
            task.taskDescription = id.rawValue
            task.resume()
        }
    }
}

enum Header: String {
    case accept = "Accept"
    case authorization = "Authorization"
    case contentType = "Content-Type"
    case subscriptionKey = "Ocp-Apim-Subscription-Key"
    case userAgent = "User-Agent"
}

extension URLRequest {
    var authorization: String? {
        get { self[header: .authorization] }
        set { self[header: .authorization] = newValue }
    }

    var bearerToken: String? {
        get { (authorization?.drop { $0 != " " }.dropFirst()).map(String.init) }
        set {
            if let newValue {
                authorization = "Bearer \(newValue)"
            } else {
                authorization = nil
            }
        }
    }

    var subscriptionKey: String? {
        get { self[header: .subscriptionKey] }
        set { self[header: .subscriptionKey] = newValue }
    }

    subscript(header header: Header) -> String? {
        get {
            allHTTPHeaderFields?[header.rawValue]
        }
        set {
            allHTTPHeaderFields?[header.rawValue] = newValue
        }
    }
}

extension URLSessionConfiguration {
    var accept: String? {
        get { self[header: .accept] }
        set { self[header: .accept] = newValue }
    }

    var contentType: String? {
        get { self[header: .contentType] }
        set { self[header: .contentType] = newValue }
    }

    var subscriptionKey: String? {
        get { self[header: .subscriptionKey] }
        set { self[header: .subscriptionKey] = newValue }
    }

    var userAgent: String? {
        get { self[header: .userAgent] }
        set { self[header: .userAgent] = newValue }
    }

    subscript(header header: Header) -> String? {
        get {
            httpAdditionalHeaders?[header.rawValue] as? String
        }
        set {
            var headers = httpAdditionalHeaders ?? [:]
            headers[header.rawValue] = newValue
            httpAdditionalHeaders = headers
        }
    }
}

extension URLSessionTask {
    var id: Resource.ID? {
        taskDescription.flatMap(Resource.ID.init)
    }
}
