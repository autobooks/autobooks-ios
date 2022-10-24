@testable import Autobooks

import XCTest

@available(iOS 15.4, *)
final class AmountStateTests: XCTestCase {
    func testThatInputOverMaximumDollarsIsIgnored() {
        // Given
        var state = AmountState()

        // When
        for int in 1...8 {
            state.insert(Character("\(int)"))
        }

        // Then
        XCTAssertEqual(state.decimal, 1_234_567)
        XCTAssertEqual(state.formatted, "$1,234,567")
        XCTAssertTrue(state.isValid)
    }

    func testThatEqualInsertsAndDeletsReturnToZero() {
        // Given
        var state = AmountState()

        // When
        for int in 1...7 {
            state.insert(Character("\(int)"))
            state.delete()
        }

        // Then
        XCTAssertEqual(state.decimal, 0)
        XCTAssertEqual(state.formatted, "$0")
        XCTAssertFalse(state.isValid)
    }

    func testThatInitialZeroIsIgnored() {
        // Given
        var state = AmountState()

        // When
        for int in 0...7 {
            state.insert(Character("\(int)"))
        }

        // Then
        XCTAssertEqual(state.decimal, 1_234_567)
        XCTAssertEqual(state.formatted, "$1,234,567")
        XCTAssertTrue(state.isValid)
    }

    func testThatDecimalInsertionIsInitiallyInvalid() {
        // Given
        var state = AmountState()

        // When
        state.insert("1")
        state.insert(".")

        // Then
        XCTAssertEqual(state.decimal, 1)
        XCTAssertEqual(state.formatted, "$1.00")
        XCTAssertFalse(state.isValid)
    }

    func testThatInsertingAndDeletingADecimalReturnsToNoDecimal() {
        // Given
        var state = AmountState()

        // When
        state.insert("1")
        state.insert(".")
        state.delete()

        // Then
        XCTAssertEqual(state.decimal, 1)
        XCTAssertEqual(state.formatted, "$1")
        XCTAssertTrue(state.isValid)
    }

    func testThatInsertingDecimalAndTwoCentsIsValid() {
        // Given
        var state = AmountState()

        // When
        state.insert("1")
        state.insert(".")
        state.insert("0")
        state.insert("0")

        // Then
        XCTAssertEqual(state.decimal, 1)
        XCTAssertEqual(state.formatted, "$1.00")
        XCTAssertTrue(state.isValid)
    }

    func testThatInsertingDecimalAndOneCentIsNotValid() {
        // Given
        var state = AmountState()

        // When
        state.insert("1")
        state.insert(".")
        state.insert("0")

        // Then
        XCTAssertEqual(state.decimal, 1)
        XCTAssertEqual(state.formatted, "$1.00")
        XCTAssertFalse(state.isValid)
    }
}
