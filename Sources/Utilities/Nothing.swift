struct Nothing: Hashable {}

extension Result where Success == Nothing {
    static var success: Result<Nothing, Failure> {
        .success(.init())
    }
}
