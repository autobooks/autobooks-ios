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

    static func providing(_ response: Response<some Any>, statusCode: Int, after delay: DispatchTimeInterval? = nil) -> Stub {
        Stub([.providing(response, statusCode: statusCode, after: delay)])
    }

    static func success(providing value: some Codable, after delay: DispatchTimeInterval? = nil) -> Stub {
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

    init(_ payloads: [Payload], delay: DispatchTimeInterval? = .seconds(1)) {
        self.payloads = payloads
        self.delay = delay
    }

    init(data: Data, statusCode: Int, delay: DispatchTimeInterval? = nil) {
        self.payloads = [.response(statusCode: statusCode, data: data, delay: delay)]
        self.delay = nil
    }

    fileprivate func complete(providing request: URLRequest) {
        $requests.write { $0.append(request) }
    }

    fileprivate func nextPayload() -> Payload {
        guard !payloads.isEmpty else {
            fatalError("Stub payloads should never be empty.")
        }

        if payloads.count == 1 {
            return payloads[0]
        } else {
            let payload = payloads.removeFirst()

            return payload
        }
    }
}

extension Stub: Equatable {
    static func == (lhs: Stub, rhs: Stub) -> Bool {
        ObjectIdentifier(lhs) == ObjectIdentifier(rhs)
    }
}

extension Stub.Payload {
    static func providing(_ response: Response<some Any>,
                          statusCode: Int,
                          after delay: DispatchTimeInterval? = .seconds(1)) -> Stub.Payload {
        .response(statusCode: statusCode,
                  data: (try? JSONEncoder.autobooks.encode(response)) ?? Data("invalid stub".utf8),
                  delay: delay)
    }

    static func success<Value>(providing value: Value,
                               after delay: DispatchTimeInterval? = .seconds(1)) -> Stub.Payload where Value: Codable {
        let response = Response<Value>(id: "id", date: Date(), result: .success(value))

        return providing(response, statusCode: 200, after: delay)
    }

    static func failure(id: String = "id",
                        date: Date = Date(),
                        error: ResponseError = .init(statusCode: 400,
                                                     description: "description",
                                                     presentableDescription: nil),
                        after delay: DispatchTimeInterval? = .seconds(1)) -> Stub.Payload {
        .providing(Response<Stub.Empty>(id: id,
                                        date: date,
                                        result: .failure(error)),
                   statusCode: error.statusCode,
                   after: delay)
    }
}

/// Type encapsulating a set of stubbed responses for Autobooks API calls.
///
/// - Note: You cannot create instances of this type. Instead, use one of the preconfigured static values.
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
            if let newValue {
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
        guard let id = task.id else {
            return false
        }

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

public extension Stubs {
    /// All requests succeed.
    static var successes: Stubs {
        let statusResponse = Status.enabled(.stub)
        let enabledResponse = LoginResponse(status: .success(.stub), webFeatureURLs: .stub, tapToPayRates: .stub)
        let uuid = UUID()
        let createTransactionResponse = CreateTransactionResponse(uuid: uuid,
                                                                  referenceNumber: "1234",
                                                                  ticketNumber: "1234")
        let transaction = Transaction.random(uuid: uuid)
        let receiptResponse = Transaction(uuid: transaction.uuid,
                                          createdOn: transaction.createdOn,
                                          formattedAmount: transaction.formattedAmount,
                                          type: transaction.type,
                                          status: transaction.status,
                                          receiptRecipients: [.init(email: "some@email.com")],
                                          card: transaction.card,
                                          associatedTransactionRequestDate: transaction.associatedTransactionRequestDate,
                                          canRequestReceipt: transaction.canRequestReceipt)
        let transactionsResponse: [Transaction] = [
            .random(), .random(), .random(), .random(), .random(), .random(), .random(), .random(),
        ]
        .sorted { $0.createdOn > $1.createdOn }
        let cancelTransactionResponse = Transaction(uuid: transaction.uuid,
                                                    createdOn: transaction.createdOn,
                                                    formattedAmount: transaction.formattedAmount,
                                                    type: transaction.type,
                                                    status: .canceled,
                                                    receiptRecipients: [],
                                                    card: transaction.card,
                                                    associatedTransactionRequestDate: transaction.associatedTransactionRequestDate,
                                                    canRequestReceipt: transaction.canRequestReceipt)
        let refundTransactionResponse = Transaction(uuid: transaction.uuid,
                                                    createdOn: transaction.createdOn,
                                                    formattedAmount: transaction.formattedAmount,
                                                    type: transaction.type,
                                                    status: .refunded,
                                                    receiptRecipients: [],
                                                    card: transaction.card,
                                                    associatedTransactionRequestDate: transaction.associatedTransactionRequestDate,
                                                    canRequestReceipt: transaction.canRequestReceipt)
        let stubs = Stubs([
            .login: .success(providing: enabledResponse),
            .status: .success(providing: statusResponse),
            .createTransaction: .success(providing: createTransactionResponse),
            .syncTransaction: .success(providing: transaction),
            .receipt: .success(providing: receiptResponse),
            .transactions: .success(providing: transactionsResponse),
            .cancelTransaction: .success(providing: cancelTransactionResponse),
            .refundTransaction: .success(providing: refundTransactionResponse),
        ])

        return stubs
    }

    /// All requests fail once before succeeding.
    static var failures: Stubs {
        let statusResponse = Status.enabled(.stub)
        let enabledResponse = LoginResponse(status: .success(.stub),
                                            webFeatureURLs: .stub, tapToPayRates: .stub)
        let uuid = UUID()
        let createTransactionResponse = CreateTransactionResponse(uuid: uuid,
                                                                  referenceNumber: "1234",
                                                                  ticketNumber: "1234")
        let transaction = Transaction.random(uuid: uuid)
        let receiptResponse = Transaction(uuid: transaction.uuid,
                                          createdOn: transaction.createdOn,
                                          formattedAmount: transaction.formattedAmount,
                                          type: transaction.type,
                                          status: transaction.status,
                                          receiptRecipients: [.init(email: "some@email.com")],
                                          card: transaction.card,
                                          associatedTransactionRequestDate: transaction.associatedTransactionRequestDate,
                                          canRequestReceipt: transaction.canRequestReceipt)
        let transactionsResponse: [Transaction] = [
            .random(), .random(), .random(), .random(), .random(), .random(), .random(), .random(),
        ]
        .sorted { $0.createdOn > $1.createdOn }
        let cancelTransactionResponse = Transaction(uuid: transaction.uuid,
                                                    createdOn: transaction.createdOn,
                                                    formattedAmount: transaction.formattedAmount,
                                                    type: transaction.type,
                                                    status: .canceled,
                                                    receiptRecipients: [],
                                                    card: transaction.card,
                                                    associatedTransactionRequestDate: transaction.associatedTransactionRequestDate,
                                                    canRequestReceipt: transaction.canRequestReceipt)
        
        let refundTransactionResponse = Transaction(uuid: transaction.uuid,
                                                    createdOn: transaction.createdOn,
                                                    formattedAmount: transaction.formattedAmount,
                                                    type: transaction.type,
                                                    status: .refunded,
                                                    receiptRecipients: [],
                                                    card: transaction.card,
                                                    associatedTransactionRequestDate: transaction.associatedTransactionRequestDate,
                                                    canRequestReceipt: transaction.canRequestReceipt)
        
        let stubs = Stubs([
            .login: Stub([.failure(), .success(providing: enabledResponse)]),
            .status: Stub([.failure(), .success(providing: statusResponse)]),
            .createTransaction: Stub([.failure(), .success(providing: createTransactionResponse)]),
            .syncTransaction: Stub([.failure(), .success(providing: transaction)]),
            .receipt: Stub([.failure(), .success(providing: receiptResponse)]),
            .transactions: Stub([.failure(), .success(providing: transactionsResponse)]),
            .cancelTransaction: Stub([.failure(), .success(providing: cancelTransactionResponse)]),
            .refundTransaction: Stub([.failure(), .success(providing: refundTransactionResponse)]),
        ])

        return stubs
    }

    /// All requests succeed, but the web prompts are triggered on login.
    static func webPrompts(loadedWebURL: URL, needsEnrollmentCallback: URL, hasMissingInfoCallback: URL) -> Stubs {
        let statusResponse = Status.enabled(.stub)
        let needsEnrollmentResponse = LoginResponse(status: .needsEnrollment(.init(url: loadedWebURL)),
                                                    webFeatureURLs: .stub, tapToPayRates: .stub)
        let hasMissingInfoResponse = LoginResponse(status: .success(.init(accessToken: "accessToken",
                                                                          status: .hasMissingInfo(.init(url: loadedWebURL)))),
                                                   webFeatureURLs: .stub, tapToPayRates: .stub)
        let enabledResponse = LoginResponse(status: .success(.stub), webFeatureURLs: .stub, tapToPayRates: .stub)
        let uuid = UUID()
        let createTransactionResponse = CreateTransactionResponse(uuid: uuid,
                                                                  referenceNumber: "1234",
                                                                  ticketNumber: "1234")
        let transaction = Transaction.random(uuid: uuid)
        let receiptResponse = Transaction(uuid: transaction.uuid,
                                          createdOn: transaction.createdOn,
                                          formattedAmount: transaction.formattedAmount,
                                          type: transaction.type,
                                          status: transaction.status,
                                          receiptRecipients: [.init(email: "some@email.com")],
                                          card: transaction.card,
                                          associatedTransactionRequestDate: transaction.associatedTransactionRequestDate,
                                          canRequestReceipt: transaction.canRequestReceipt)
        
        let transactionsResponse: [Transaction] = [
            .random(), .random(), .random(), .random(), .random(), .random(), .random(), .random(),
        ]
        .sorted { $0.createdOn > $1.createdOn }
        let cancelTransactionResponse = Transaction(uuid: transaction.uuid,
                                                    createdOn: transaction.createdOn,
                                                    formattedAmount: transaction.formattedAmount,
                                                    type: transaction.type,
                                                    status: .canceled,
                                                    receiptRecipients: [],
                                                    card: transaction.card,
                                                    associatedTransactionRequestDate: transaction.associatedTransactionRequestDate,
                                                    canRequestReceipt: transaction.canRequestReceipt)
        
        let refundTransactionResponse = Transaction(uuid: transaction.uuid,
                                                    createdOn: transaction.createdOn,
                                                    formattedAmount: transaction.formattedAmount,
                                                    type: transaction.type,
                                                    status: .refunded,
                                                    receiptRecipients: [],
                                                    card: transaction.card,
                                                    associatedTransactionRequestDate: transaction.associatedTransactionRequestDate,
                                                    canRequestReceipt: transaction.canRequestReceipt)
        
        let stubs = Stubs([
            .login: Stub([.success(providing: needsEnrollmentResponse),
                          .success(providing: hasMissingInfoResponse),
                          .success(providing: enabledResponse)]),
            .status: Stub([.failure(), .success(providing: statusResponse)]),
            .createTransaction: Stub([.failure(), .success(providing: createTransactionResponse)]),
            .syncTransaction: Stub([.failure(), .success(providing: transaction)]),
            .receipt: Stub([.failure(), .success(providing: receiptResponse)]),
            .transactions: Stub([.failure(), .success(providing: transactionsResponse)]),
            .cancelTransaction: Stub([.failure(), .success(providing: cancelTransactionResponse)]),
            .refundTransaction: Stub([.failure(), .success(providing: refundTransactionResponse)]),
        ])

        return stubs
    }
}

extension Status.Enabled {
    static let stub = Self(merchantCredentials: .init(accountToken: "079701FC1CBBEACDC0353ADFD246B965965C19C69BE2BC2B102DBCD524A78301A2AC6D01", accountId: "1045826", acceptorId: "364801436", applicationId: "14643", applicationVersion: "1.0.0", applicationName: "Autobooks"))
}

extension LoginResponse.LoginStatus.Success {
    static let stub = Self(accessToken: "accessToken", status: .enabled(.stub))
}

extension LoginResponse.WebFeatureURLs {
    static let stub = Self(invoicing: .invoicing, paymentForm: .paymentForm, virtualTerminal: .virtualTerminal)
}

extension LoginResponse.TapToPayRates {
    static let stub = Self(ttpFeeValue: 0.0275, ttpFeeCap: nil, vtfFeeValue: 0.0289, vtfFeeCap: nil)
}

extension URL {
    static let paymentForm = URL(string: "https://app.autobooks.co/payment-form/default?launchmode=PaymentForm&viewmode=PaymentForm")!
    static let invoicing = URL(string: "https://app.autobooks.co/invoicing/invoices?launchmode=CreateInvoice&viewmode=Invoicing")!
    static let virtualTerminal = URL(string: "https://app.autobooks.co/virtual-terminal/")!
}
