@testable import Autobooks
import XCTest

@available(iOS 16.0, *)
@MainActor
final class AutobooksAPITests: XCTestCase {
    func testThatAPICanPerformLogin() async {
        // Given
        let loginResponse = LoginResponse(status: .success(.init(accessToken: "accessToken",
                                                                 status: .enabled(.stub))),
                                          webFeatureURLs: .stub, tapToPayRates: .stub)
        let stub = Stub.success(providing: loginResponse)

        let api = AutobooksAPI(subscriptionKey: "subscriptionKey", responseProvider: .stubs(Stubs([.login: stub]))) {
            "session"
        }

        // When
        let result = await api.performLogin()

        // Then
        XCTAssertNotNil(stub.lastRequest?.subscriptionKey)
        XCTAssertNil(stub.lastRequest?.authorization)
        XCTAssertEqual(result, .success(loginResponse))
    }

    func testThatAPICanPerformFailedAndSuccessfulLogin() async {
        // Given
        let loginResponse = LoginResponse(status: .success(.init(accessToken: "accessToken",
                                                                 status: .enabled(.stub))),
                                          webFeatureURLs: .stub, tapToPayRates: .stub)
        let stub = Stub([.failure(), .success(providing: loginResponse)])

        let api = AutobooksAPI(subscriptionKey: "subscriptionKey", responseProvider: .stubs(Stubs([.login: stub]))) {
            "session"
        }

        // When
        let first = await api.performLogin()
        let second = await api.performLogin()

        // Then
        stub.requests.forEach { request in
            XCTAssertNotNil(stub.lastRequest?.subscriptionKey)
            XCTAssertNil(request.authorization)
        }
        XCTAssertTrue(first.isFailure)
        XCTAssertEqual(second, .success(loginResponse))
    }

    func testThatAPICanReturnErrorOnLogin() async {
        // Given
        let stub = Stub.failure()
        let api = AutobooksAPI(subscriptionKey: "subscriptionKey", responseProvider: .stubs(Stubs([.login: stub]))) {
            "session"
        }

        // When
        let result = await api.performLogin()

        // Then
        XCTAssertNotNil(stub.lastRequest?.subscriptionKey)
        XCTAssertNil(stub.lastRequest?.authorization)
        XCTAssertTrue(result.isFailure == true)
    }

    func testThatAPICanReturnNetworkErrorOnLogin() async {
        // Given
        let urlError = URLError(.notConnectedToInternet)
        let stub = Stub([.networkError(urlError)])
        let api = AutobooksAPI(subscriptionKey: "subscriptionKey", responseProvider: .stubs(Stubs([.login: stub]))) {
            "session"
        }

        // When
        let result = await api.performLogin()

        // Then
        XCTAssertNotNil(stub.lastRequest?.subscriptionKey)
        XCTAssertNil(stub.lastRequest?.authorization)
        XCTAssertEqual(result.failure?.networkErrorCode, urlError.code)
    }

    func testThatAPICanFetchStatus() async throws {
        // Given
        let session = "session"
        let status = Status.enabled(.stub)
        let loginResponse = LoginResponse(status: .success(.init(accessToken: session,
                                                                 status: .enabled(.stub))),
                                          webFeatureURLs: .stub, tapToPayRates: .stub)
        let loginStub = Stub.success(providing: loginResponse)
        let statusStub = Stub.success(providing: status)
        let api = AutobooksAPI(subscriptionKey: "subscriptionKey",
                               responseProvider: .stubs(Stubs([.login: loginStub, .status: statusStub]))) {
            session
        }

        // When
        _ = await api.performLogin()
        let result = await api.fetchStatus()

        // Then
        XCTAssertEqual(statusStub.lastRequest?.bearerToken, session)
        XCTAssertNotNil(statusStub.lastRequest?.subscriptionKey)
        XCTAssertEqual(result, .success(status))
    }

    func testThatAPICanReturnErrorOnStatus() async throws {
        // Given
        let session = "session"
        let loginResponse = LoginResponse(status: .success(.init(accessToken: session,
                                                                 status: .enabled(.stub))),
                                          webFeatureURLs: .stub, tapToPayRates: .stub)
        let loginStub = Stub.success(providing: loginResponse)
        let statusStub = Stub.failure()
        let api = AutobooksAPI(subscriptionKey: "subscriptionKey",
                               responseProvider: .stubs(Stubs([.login: loginStub, .status: statusStub]))) {
            session
        }

        // When
        _ = await api.performLogin()
        let result = await api.fetchStatus()

        // Then
        XCTAssertEqual(statusStub.lastRequest?.bearerToken, session)
        XCTAssertNotNil(statusStub.lastRequest?.subscriptionKey)
        XCTAssertTrue(result.isFailure)
    }

    func testThatAPICanPerformCreateTransaction() async throws {
        // Given
        let session = "session"
        let uuid = UUID()
        let referenceNumber = "1234"
        let ticketNumber = "5678"
        let loginResponse = LoginResponse(status: .success(.init(accessToken: session,
                                                                 status: .enabled(.stub))),
                                          webFeatureURLs: .stub, tapToPayRates: .stub)
        let loginStub = Stub.success(providing: loginResponse)
        let createResponse = CreateTransactionResponse(uuid: uuid,
                                                       referenceNumber: referenceNumber,
                                                       ticketNumber: ticketNumber)
        let createStub = Stub.success(providing: createResponse)
        let api = AutobooksAPI(subscriptionKey: "subscriptionKey",
                               responseProvider: .stubs(Stubs([.login: loginStub, .createTransaction: createStub]))) {
            session
        }

        // When
        _ = await api.performLogin()
        let result = await api.createTransaction(for: 1, type: .sale)

        // Then
        XCTAssertEqual(createStub.lastRequest?.bearerToken, session)
        XCTAssertNotNil(createStub.lastRequest?.subscriptionKey)
        XCTAssertEqual(result.success, .init(uuid: uuid, referenceNumber: referenceNumber, ticketNumber: ticketNumber))
        XCTAssertTrue(result.isSuccess)
    }

    func testThatAPICanReturnErrorOnCreateTransaction() async throws {
        // Given
        let session = "session"
        let loginResponse = LoginResponse(status: .success(.init(accessToken: session,
                                                                 status: .enabled(.stub))),
                                          webFeatureURLs: .stub, tapToPayRates: .stub)
        let loginStub = Stub.success(providing: loginResponse)
        let createStub = Stub.failure()
        let api = AutobooksAPI(subscriptionKey: "subscriptionKey",
                               responseProvider: .stubs(Stubs([.login: loginStub, .createTransaction: createStub]))) {
            session
        }

        // When
        _ = await api.performLogin()
        let result = await api.createTransaction(for: 1, type: .sale)

        // Then
        XCTAssertEqual(createStub.lastRequest?.bearerToken, session)
        XCTAssertNotNil(createStub.lastRequest?.subscriptionKey)
        XCTAssertTrue(result.isFailure)
    }

    func testThatAPICanPerformSyncTransaction() async throws {
        // Given
        let session = "session"
        let uuid = UUID()
        let loginResponse = LoginResponse(status: .success(.init(accessToken: session,
                                                                 status: .enabled(.stub))),
                                          webFeatureURLs: .stub, tapToPayRates: .stub)
        let loginStub = Stub.success(providing: loginResponse)
        let syncResponse = Transaction.random(uuid: uuid)
        let syncStub = Stub.success(providing: syncResponse)
        let api = AutobooksAPI(subscriptionKey: "subscriptionKey",
                               responseProvider: .stubs(Stubs([.login: loginStub, .syncTransaction: syncStub]))) {
            session
        }

        // When
        _ = await api.performLogin()
        let result = await api.syncTransaction(uuid, transactionID: "transactionID")

        // Then
        XCTAssertEqual(syncStub.lastRequest?.bearerToken, session)
        XCTAssertNotNil(syncStub.lastRequest?.subscriptionKey)
        XCTAssertEqual(result.success?.uuid, syncResponse.uuid)
        XCTAssertTrue(result.isSuccess)
    }

    func testThatAPICanReturnErrorOnSyncTransaction() async throws {
        // Given
        let session = "session"
        let loginResponse = LoginResponse(status: .success(.init(accessToken: session,
                                                                 status: .enabled(.stub))),
                                          webFeatureURLs: .stub, tapToPayRates: .stub)
        let loginStub = Stub.success(providing: loginResponse)
        let syncStub = Stub.failure()
        let api = AutobooksAPI(subscriptionKey: "subscriptionKey",
                               responseProvider: .stubs(Stubs([.login: loginStub, .syncTransaction: syncStub]))) {
            session
        }

        // When
        _ = await api.performLogin()
        let result = await api.syncTransaction(UUID(), transactionID: "transactionID")

        // Then
        XCTAssertEqual(syncStub.lastRequest?.bearerToken, session)
        XCTAssertNotNil(syncStub.lastRequest?.subscriptionKey)
        XCTAssertTrue(result.isFailure)
    }

    func testThatAPICanRequestReceipt() async {
        // Given
        let bearerToken = "bearerToken"
        let uuid = UUID()
        let loginResponse = LoginResponse(status: .success(.init(accessToken: bearerToken,
                                                                 status: .enabled(.stub))),
                                          webFeatureURLs: .stub, tapToPayRates: .stub)
        let loginStub = Stub.success(providing: loginResponse)
        let receiptResponse = Transaction.random(uuid: uuid)
        let receiptStub = Stub.success(providing: receiptResponse)
        let api = AutobooksAPI(subscriptionKey: "subscriptionKey",
                               responseProvider: .stubs(Stubs([.login: loginStub, .receipt: receiptStub]))) {
            "login"
        }

        // When
        _ = await api.performLogin()
        let result = await api.requestReceipt(forTransactionID: uuid, email: "some@email.com")

        // Then
        XCTAssertEqual(receiptStub.lastRequest?.bearerToken, bearerToken)
        XCTAssertNotNil(receiptStub.lastRequest?.subscriptionKey)
        XCTAssertTrue(receiptStub.lastRequest?.url?.path.contains(uuid.uuidString) == true)
        XCTAssertTrue(result.isSuccess)
    }
}

private extension APIError {
    var networkErrorCode: URLError.Code? {
        guard case let .network(error) = self else {
            return nil
        }

        return error.code
    }
}
