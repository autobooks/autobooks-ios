import Foundation

final class Stubber {
    private(set) var stubs: Stubs

    init(stubs: Stubs) {
        self.stubs = stubs
    }
}

final class Stub {
    fileprivate struct Empty: Codable {}

    enum Payload {
        case response(statusCode: Int, data: Data, delay: DispatchTimeInterval? = nil)
        case networkError(URLError, delay: DispatchTimeInterval? = nil)
    }

    static func providing<T>(_ response: Response<T>, statusCode: Int, after delay: DispatchTimeInterval? = nil) -> Stub {
        Stub([.providing(response, statusCode: statusCode, after: delay)])
    }

    static func success<Value>(providing value: Value, after delay: DispatchTimeInterval? = nil) -> Stub where Value: Codable {
        Stub([.success(providing: value, after: delay)])
    }

    static func failure(id: String = "id",
                        date: Date = Date(),
                        error: ResponseError = .init(statusCode: 400,
                                                     description: "description",
                                                     presentableDescription: nil),
                        after delay: DispatchTimeInterval? = nil) -> Stub {
        Stub([.failure(id: id, date: date, error: error, after: delay)])
    }

    var lastRequest: URLRequest? {
        requests.last
    }

    private var payloads: [Payload]
    fileprivate let delay: DispatchTimeInterval?

    @Protected
    private(set) var requests: [URLRequest] = []

    init(_ payloads: [Payload], delay: DispatchTimeInterval? = nil) {
        self.payloads = payloads
        self.delay = delay
    }

    init(data: Data, statusCode: Int, delay: DispatchTimeInterval? = nil) {
        payloads = [.response(statusCode: statusCode, data: data, delay: delay)]
        self.delay = nil
    }

    fileprivate func complete(providing request: URLRequest) {
        $requests.write { $0.append(request) }
    }

    fileprivate func nextPayload() -> Payload {
        guard !payloads.isEmpty else { fatalError("Stub payloads should never be empty.") }

        if payloads.count == 1 {
            return payloads[0]
        } else {
            let payload = payloads.removeFirst()

            return payload
        }
    }
}

extension Stub: Equatable {
    static func ==(lhs: Stub, rhs: Stub) -> Bool {
        ObjectIdentifier(lhs) == ObjectIdentifier(rhs)
    }
}

extension Stub.Payload {
    static func providing<T>(_ response: Response<T>, statusCode: Int, after delay: DispatchTimeInterval? = nil) -> Stub.Payload {
        .response(statusCode: statusCode,
                  data: (try? JSONEncoder.autobooks.encode(response)) ?? Data("invalid stub".utf8),
                  delay: delay)
    }

    static func success<Value>(providing value: Value, after delay: DispatchTimeInterval? = nil) -> Stub.Payload where Value: Codable {
        let response = Response<Value>(id: "id", date: Date(), result: .success(value))

        return providing(response, statusCode: 200, after: delay)
    }

    static func failure(id: String = "id",
                        date: Date = Date(),
                        error: ResponseError = .init(statusCode: 400,
                                                     description: "description",
                                                     presentableDescription: nil),
                        after delay: DispatchTimeInterval? = nil) -> Stub.Payload {
        .providing(Response<Stub.Empty>(id: id,
                                        date: date,
                                        result: .failure(error)),
                   statusCode: error.statusCode,
                   after: delay)
    }
}

/// Type encapsulating a set of stubbed responses for Autobooks API calls.
///
/// - Note: You cannot create instances of this type. Instead, use one of the preconfigured instances available as
///         static values.
///
public struct Stubs: Equatable {
    private var stubs: [Resource.ID: Stub] = [:]

    var isEmpty: Bool {
        stubs.isEmpty
    }

    init(_ stubs: [Resource.ID: Stub]) {
        self.stubs = stubs
    }

    subscript(_ id: Resource.ID) -> Stub? {
        get { stubs[id] }
        set {
            if let newValue = newValue {
                stubs[id] = newValue
            } else {
                stubs.removeValue(forKey: id)
            }
        }
    }
}

final class StubProvider: URLProtocol {
    static var stubber: Stubber?

    override class func canInit(with task: URLSessionTask) -> Bool {
        guard let id = task.id else { return false }

        return stubber?.stubs[id] != nil
    }

    override class func canInit(with request: URLRequest) -> Bool {
        false
    }

    override class func canonicalRequest(for request: URLRequest) -> URLRequest { request }

    override var cachedResponse: CachedURLResponse? { nil }

    let stub: Stub

    init(stub: Stub, request: URLRequest, cachedResponse: CachedURLResponse?, client: URLProtocolClient?) {
        self.stub = stub

        super.init(request: request, cachedResponse: nil, client: client)
    }

    convenience init(task: URLSessionTask, cachedResponse: CachedURLResponse?, client: URLProtocolClient?) {
        let stub = task.id.flatMap { StubProvider.stubber?.stubs[$0] }

        self.init(stub: stub!, request: task.currentRequest!, cachedResponse: nil, client: client)
    }

    override func startLoading() {
        switch stub.nextPayload() {
        case let .response(statusCode, data, delay):
            let response = HTTPURLResponse(url: request.url!,
                                           statusCode: statusCode,
                                           httpVersion: "1.1",
                                           headerFields: ["Content-Type": "application/json"])
            if let delay = delay ?? stub.delay {
                onCurrentRunLoop(after: delay) { [self] in
                    success(providing: response!, data: data)
                }
            } else {
                success(providing: response!, data: data)
            }
        case let .networkError(error, delay):
            if let delay = delay ?? stub.delay {
                onCurrentRunLoop(after: delay) { [self] in
                    failure(providing: error)
                }
            } else {
                failure(providing: error)
            }
        }
    }

    override func stopLoading() {
        // Nothing for now.
    }

    private func success(providing response: HTTPURLResponse, data: Data) {
        client?.urlProtocol(self, didReceive: response, cacheStoragePolicy: .notAllowed)
        client?.urlProtocol(self, didLoad: data)

        client?.urlProtocolDidFinishLoading(self)
        stub.complete(providing: request)
    }

    private func failure(providing error: URLError) {
        client?.urlProtocol(self, didFailWithError: error)
        client?.urlProtocolDidFinishLoading(self)
        stub.complete(providing: request)
    }

    private func onCurrentRunLoop(after delay: DispatchTimeInterval, perform closure: @escaping () -> Void) {
        let currentRunLoop = CFRunLoopGetCurrent()
        DispatchQueue.global().asyncAfter(deadline: .now() + delay) { [currentRunLoop] in
            CFRunLoopPerformBlock(currentRunLoop, CFRunLoopMode.defaultMode.rawValue) {
                closure()
            }
            CFRunLoopWakeUp(currentRunLoop)
        }
    }
}

extension Stubs {
    /// All requests succeed.
    public static var successes: Stubs {
        let statusResponse = Status.enabled
        let enabledResponse = LoginResponse(status: .success(.init(accessToken: "accessToken", status: .enabled)))
        let paymentTokenResponse = PaymentTokenResponse(token: "paymentToken")

        let transaction = Transaction.stub
        let transactionResponse = TransactionResponse(result: .success(transaction))
        let receiptResponse = Transaction(transactionID: transaction.transactionID,
                                          name: transaction.name,
                                          cardDescription: transaction.cardDescription,
                                          date: transaction.date,
                                          total: transaction.total,
                                          lastReceiptEmail: "some@email.com",
                                          status: .final)
        let transactionsResponse: [Transaction] = [.stub, .stub, .stub, .stub, .stub, .stub, .stub, .stub]
            .sorted { $0.date > $1.date }
        let cancelTransactionResponse = Transaction(transactionID: transaction.transactionID,
                                                    name: transaction.name,
                                                    cardDescription: transaction.cardDescription,
                                                    date: transaction.date,
                                                    total: transaction.total,
                                                    lastReceiptEmail: "some@email.com",
                                                    status: .canceled)
        let refundTransactionResponse = Transaction(transactionID: transaction.transactionID,
                                                    name: transaction.name,
                                                    cardDescription: transaction.cardDescription,
                                                    date: transaction.date,
                                                    total: transaction.total,
                                                    lastReceiptEmail: "refund@email.com",
                                                    status: .refunded)
        let stubs = Stubs([.login: .success(providing: enabledResponse, after: .seconds(1)),
                           .paymentToken: .success(providing: paymentTokenResponse, after: .seconds(1)),
                           .status: .success(providing: statusResponse, after: .seconds(1)),
                           .transaction: .success(providing: transactionResponse, after: .seconds(1)),
                           .receipt: .success(providing: receiptResponse, after: .seconds(1)),
                           .transactions: .success(providing: transactionsResponse, after: .seconds(1)),
                           .cancelTransaction: .success(providing: cancelTransactionResponse, after: .seconds(1)),
                           .refundTransaction: .success(providing: refundTransactionResponse, after: .seconds(1))])

        return stubs
    }

    /// All requests fail once before succeeding.
    public static var failures: Stubs {
        let statusResponse = Status.enabled
        let enabledResponse = LoginResponse(status: .success(.init(accessToken: "accessToken", status: .enabled)))
        let paymentTokenResponse = PaymentTokenResponse(token: "paymentToken")

        let transaction = Transaction.stub
        let transactionResponse = TransactionResponse(result: .success(transaction))
        let receiptResponse = Transaction(transactionID: transaction.transactionID,
                                          name: transaction.name,
                                          cardDescription: transaction.cardDescription,
                                          date: transaction.date,
                                          total: transaction.total,
                                          lastReceiptEmail: "some@email.com",
                                          status: .cancelable)
        let transactionsResponse: [Transaction] = [.stub, .stub, .stub, .stub, .stub, .stub, .stub, .stub]
            .sorted { $0.date > $1.date }
        let cancelTransactionResponse = Transaction(transactionID: transaction.transactionID,
                                                    name: transaction.name,
                                                    cardDescription: transaction.cardDescription,
                                                    date: transaction.date,
                                                    total: transaction.total,
                                                    lastReceiptEmail: "some@email.com",
                                                    status: .canceled)
        let refundTransactionResponse = Transaction(transactionID: transaction.transactionID,
                                                    name: transaction.name,
                                                    cardDescription: transaction.cardDescription,
                                                    date: transaction.date,
                                                    total: transaction.total,
                                                    lastReceiptEmail: "refund@email.com",
                                                    status: .refundable)
        let stubs = Stubs([.login: Stub([.failure(), .success(providing: enabledResponse)], delay: .seconds(1)),
                           .paymentToken: Stub([.failure(), .success(providing: paymentTokenResponse)], delay: .seconds(1)),
                           .status: Stub([.failure(), .success(providing: statusResponse)], delay: .seconds(1)),
                           .transaction: Stub([.failure(), .success(providing: transactionResponse)], delay: .seconds(1)),
                           .receipt: Stub([.failure(), .success(providing: receiptResponse)], delay: .seconds(1)),
                           .transactions: Stub([.failure(), .success(providing: transactionsResponse)], delay: .seconds(1)),
                           .cancelTransaction: Stub([.failure(), .success(providing: cancelTransactionResponse, after: .seconds(1))]),
                           .refundTransaction: Stub([.failure(), .success(providing: refundTransactionResponse)], delay: .seconds(1))])

        return stubs
    }

    /// All requests succeed, but the web prompts are triggered on login.
    public static func webPrompts(loadedWebURL: URL, needsEnrollmentCallback: URL, hasMissingInfoCallback: URL) -> Stubs {
        let statusResponse = Status.enabled
        let needsEnrollmentResponse = LoginResponse(status: .needsEnrollment(.init(callbackURL: needsEnrollmentCallback,
                                                                                   url: loadedWebURL)))
        let hasMissingInfoResponse = LoginResponse(status: .success(.init(accessToken: "accessToken",
                                                                          status: .hasMissingInfo(.init(callbackURL: hasMissingInfoCallback,
                                                                                                        url: loadedWebURL)))))
        let enabledResponse = LoginResponse(status: .success(.init(accessToken: "accessToken", status: .enabled)))
        let paymentTokenResponse = PaymentTokenResponse(token: "paymentToken")
        let transaction = Transaction.stub
        let transactionResponse = TransactionResponse(result: .success(transaction))
        let receiptResponse = Transaction(transactionID: transaction.transactionID,
                                          name: transaction.name,
                                          cardDescription: transaction.cardDescription,
                                          date: transaction.date,
                                          total: transaction.total,
                                          lastReceiptEmail: "some@email.com",
                                          status: .refundable)
        let transactionsResponse: [Transaction] = [.stub, .stub, .stub, .stub, .stub, .stub, .stub, .stub]
            .sorted { $0.date > $1.date }
        let cancelTransactionResponse = Transaction(transactionID: transaction.transactionID,
                                                    name: transaction.name,
                                                    cardDescription: transaction.cardDescription,
                                                    date: transaction.date,
                                                    total: transaction.total,
                                                    lastReceiptEmail: "some@email.com",
                                                    status: .canceled)
        let refundTransactionResponse = Transaction(transactionID: transaction.transactionID,
                                                    name: transaction.name,
                                                    cardDescription: transaction.cardDescription,
                                                    date: transaction.date,
                                                    total: transaction.total,
                                                    lastReceiptEmail: "refund@email.com",
                                                    status: .refunded)
        let stubs = Stubs([
            .login: Stub([.success(providing: needsEnrollmentResponse, after: .seconds(1)),
                          .success(providing: hasMissingInfoResponse, after: .seconds(1)),
                          .success(providing: enabledResponse, after: .seconds(1))]),
            .paymentToken: .success(providing: paymentTokenResponse, after: .seconds(1)),
            .status: .success(providing: statusResponse, after: .seconds(1)),
            .transaction: .success(providing: transactionResponse, after: .seconds(1)),
            .receipt: .success(providing: receiptResponse, after: .seconds(1)),
            .transactions: .success(providing: transactionsResponse, after: .seconds(1)),
            .cancelTransaction: .success(providing: cancelTransactionResponse, after: .seconds(1)),
            .refundTransaction: .success(providing: refundTransactionResponse, after: .seconds(1))
        ])

        return stubs
    }
}
