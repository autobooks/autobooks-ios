@testable import Autobooks

import XCTest

@available(iOS 15.4, *)
final class AutobooksTests: XCTestCase {
    func testThatReaderCanBeCreated() {
        // Given
        let reader = PaymentCardReader()

        // When, Then
        XCTAssertNotNil(reader)
    }
}
