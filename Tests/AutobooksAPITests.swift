@testable import Autobooks

import XCTest

@available(iOS 15.4, *)
@MainActor
final class AutobooksAPITests: XCTestCase {
    func testThatAPICanPerformLogin() async {
        // Given
        let loginResponse = LoginResponse(status: .success(.init(accessToken: "accessToken",
                                                                 status: .enabled)),
                                          invoicingURL: .invoicing,
                                          paymentFormURL: .paymentForm)
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
                                                                 status: .enabled)),
                                          invoicingURL: .invoicing,
                                          paymentFormURL: .paymentForm)
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
        let status = Status.enabled
        let loginResponse = LoginResponse(status: .success(.init(accessToken: session,
                                                                 status: .enabled)),
                                          invoicingURL: .invoicing,
                                          paymentFormURL: .paymentForm)
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
                                                                 status: .enabled)),
                                          invoicingURL: .invoicing,
                                          paymentFormURL: .paymentForm)
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

    func testThatAPICanFetchReaderToken() async throws {
        // Given
        let session = "session"
        let token = "token"
        let readerID = "readerID"
        let loginResponse = LoginResponse(status: .success(.init(accessToken: session,
                                                                 status: .enabled)),
                                          invoicingURL: .invoicing,
                                          paymentFormURL: .paymentForm)
        let loginStub = Stub.success(providing: loginResponse)
        let tokenResponse = PaymentTokenResponse(token: token)
        let tokenStub = Stub.success(providing: tokenResponse)
        let api = AutobooksAPI(subscriptionKey: "subscriptionKey",
                               responseProvider: .stubs(Stubs([.login: loginStub, .paymentToken: tokenStub]))) {
            session
        }

        // When
        _ = await api.performLogin()
        let result = await api.fetchPaymentToken(forReaderID: readerID)

        // Then
        XCTAssertEqual(tokenStub.lastRequest?.bearerToken, session)
        XCTAssertNotNil(tokenStub.lastRequest?.subscriptionKey)
        XCTAssertEqual(result.success?.token, token)
        XCTAssertEqual(tokenStub.lastRequest?.url?.query, "cardReaderId=\(readerID)")
    }

    func testThatAPICanErrorReaderToken() async throws {
        // Given
        let session = "session"
        let readerID = "readerID"
        let loginResponse = LoginResponse(status: .success(.init(accessToken: session,
                                                                 status: .enabled)),
                                          invoicingURL: .invoicing,
                                          paymentFormURL: .paymentForm)
        let loginStub = Stub.success(providing: loginResponse)
        let tokenStub = Stub.failure()
        let api = AutobooksAPI(subscriptionKey: "subscriptionKey",
                               responseProvider: .stubs(Stubs([.login: loginStub, .paymentToken: tokenStub]))) {
            session
        }

        // When
        _ = await api.performLogin()
        let result = await api.fetchPaymentToken(forReaderID: readerID)

        // Then
        XCTAssertEqual(tokenStub.lastRequest?.bearerToken, session)
        XCTAssertNotNil(tokenStub.lastRequest?.subscriptionKey)
        XCTAssertTrue(result.isFailure)
        XCTAssertEqual(tokenStub.lastRequest?.url?.query, "cardReaderId=\(readerID)")
    }

    func testThatAPICanPerformTransaction() async throws {
        // Given
        let session = "session"
        let loginResponse = LoginResponse(status: .success(.init(accessToken: session,
                                                                 status: .enabled)),
                                          invoicingURL: .invoicing,
                                          paymentFormURL: .paymentForm)
        let loginStub = Stub.success(providing: loginResponse)
        let transactionResponse = TransactionResponse(result: .success(.stub))
        let transactionStub = Stub.success(providing: transactionResponse)
        let api = AutobooksAPI(subscriptionKey: "subscriptionKey",
                               responseProvider: .stubs(Stubs([.login: loginStub, .transaction: transactionStub]))) {
            session
        }

        // When
        _ = await api.performLogin()
        let result = await api.performTransaction(.init(cardReaderBlob: "blob"))

        // Then
        XCTAssertEqual(transactionStub.lastRequest?.bearerToken, session)
        XCTAssertNotNil(transactionStub.lastRequest?.subscriptionKey)
        XCTAssertTrue(result.isSuccess)
    }

    func testThatAPICanReturnErrorOnTransaction() async throws {
        // Given
        let session = "session"
        let loginResponse = LoginResponse(status: .success(.init(accessToken: session,
                                                                 status: .enabled)),
                                          invoicingURL: .invoicing,
                                          paymentFormURL: .paymentForm)
        let loginStub = Stub.success(providing: loginResponse)
        let transactionStub = Stub.failure()
        let api = AutobooksAPI(subscriptionKey: "subscriptionKey",
                               responseProvider: .stubs(Stubs([.login: loginStub, .transaction: transactionStub]))) {
            session
        }

        // When
        _ = await api.performLogin()
        let result = await api.performTransaction(.init(cardReaderBlob: "blob"))

        // Then
        XCTAssertEqual(transactionStub.lastRequest?.bearerToken, session)
        XCTAssertNotNil(transactionStub.lastRequest?.subscriptionKey)
        XCTAssertTrue(result.isFailure)
    }

    func testThatAPICanRequestReceipt() async {
        // Given
        let bearerToken = "bearerToken"
        let transactionID = "transactionID"
        let loginResponse = LoginResponse(status: .success(.init(accessToken: bearerToken,
                                                                 status: .enabled)),
                                          invoicingURL: .invoicing,
                                          paymentFormURL: .paymentForm)
        let loginStub = Stub.success(providing: loginResponse)
        let receiptResponse = Transaction.stub
        let receiptStub = Stub.success(providing: receiptResponse)
        let api = AutobooksAPI(subscriptionKey: "subscriptionKey",
                               responseProvider: .stubs(Stubs([.login: loginStub, .receipt: receiptStub]))) {
            "login"
        }

        // When
        _ = await api.performLogin()
        let result = await api.requestReceipt(forTransactionID: transactionID, email: "some@email.com")

        // Then
        XCTAssertEqual(receiptStub.lastRequest?.bearerToken, bearerToken)
        XCTAssertNotNil(receiptStub.lastRequest?.subscriptionKey)
        XCTAssertTrue(receiptStub.lastRequest?.url?.path.contains(transactionID) == true)
        XCTAssertTrue(result.isSuccess)
    }
}

extension APIError {
    fileprivate var networkErrorCode: URLError.Code? {
        guard case let .network(error) = self else { return nil }

        return error.code
    }
}
