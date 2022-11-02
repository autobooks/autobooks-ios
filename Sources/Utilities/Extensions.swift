import SwiftUI
import UIKit

@available(iOS 13.0, *)
extension Binding {
    func removeDuplicates(by isDuplicate: @escaping (Value, Value) -> Bool) -> Self {
        .init(get: { self.wrappedValue },
              set: { newValue, transaction in
                  guard !isDuplicate(self.wrappedValue, newValue) else { return }
                  self.transaction(transaction).wrappedValue = newValue
              })
    }

    func bidirectionalMap<Output>(toOutput: @escaping (Value) -> Output,
                                  fromOutput: @escaping (Output) -> Value) -> Binding<Output> {
        Binding<Output> {
            toOutput(wrappedValue)
        } set: { newValue, transaction in
            self.transaction(transaction).wrappedValue = fromOutput(newValue)
        }
    }
}

extension Bundle {
    static var resources: Bundle {
        #if SWIFT_PACKAGE
        return module
        #else
        final class Finder {}
        return Bundle(for: Finder.self)
        #endif
    }
}

extension Result {
    var isFailure: Bool {
        !isSuccess
    }

    var isSuccess: Bool {
        if case .success = self {
            return true
        } else {
            return false
        }
    }

    var success: Success? {
        guard case let .success(success) = self else { return nil }

        return success
    }

    var failure: Failure? {
        guard case let .failure(failure) = self else { return nil }

        return failure
    }

    @available(iOS 13.0, *)
    init(_ work: () async throws -> Success) async where Failure == Error {
        do {
            let value = try await work()
            self = .success(value)
        } catch {
            self = .failure(error)
        }
    }

    @available(iOS 13.0, *)
    func flatMap<NewSuccess>(_ transform: (Success) async -> Result<NewSuccess, Failure>) async -> Result<NewSuccess, Failure> {
        switch self {
        case let .success(value):
            return await transform(value)
        case let .failure(error):
            return .failure(error)
        }
    }

    @available(iOS 13.0, *)
    func then(perform: (Self) async -> Void) async -> Self {
        await perform(self)

        return self
    }

    func extractingResponseError<Value>() -> Result<Value, APIError> where Success == Response<Value>, Failure == APIError {
        flatMap { success in
            switch success.result {
            case let .success(value):
                return .success(value)
            case let .failure(error):
                return .failure(.response(error))
            }
        }
    }
}

extension UIApplication {
    var activeRootViewController: UIViewController? {
        if #available(iOS 15.0, *) {
            return connectedScenes
                .compactMap { $0 as? UIWindowScene }
                .first { $0.activationState == .foregroundActive }?
                .keyWindow?
                .rootViewController
        } else if #available(iOS 13.0, *) {
            return connectedScenes
                .compactMap { $0 as? UIWindowScene }
                .first { $0.activationState == .foregroundActive }?
                .windows
                .first { $0.isKeyWindow }?
                .rootViewController
        } else {
            return keyWindow?.rootViewController
        }
    }
}

extension UIDevice {
    var modelIdentifier: String {
        if let identifier = ProcessInfo().environment["SIMULATOR_MODEL_IDENTIFIER"] {
            return identifier
        } else {
            var systemInfo = utsname()
            uname(&systemInfo)
            return withUnsafePointer(to: &systemInfo.machine) {
                $0.withMemoryRebound(to: CChar.self, capacity: 1) { pointer in
                    String(validatingUTF8: pointer) ?? "Unable to parse identifier."
                }
            }
        }
    }

    var modelNumber: Int {
        Int(modelIdentifier.drop { !$0.isNumber }.prefix { $0.isNumber }) ?? 0
    }

    var minorModelNumber: Int {
        Int(modelIdentifier.drop { $0 != "," }.prefix { $0.isNumber }) ?? 0
    }

    var supportsTapToPay: Bool {
        if #available(iOS 15.4, *),
           userInterfaceIdiom == .phone,
           modelNumber >= 11,
           !(modelNumber == 11 && minorModelNumber == 8) { // iPhone XR doesn't support Tap to Pay.
            return true
        } else {
            return false
        }
    }

    var supports13OrLater: Bool {
        if userInterfaceIdiom == .phone, modelNumber >= 8 {
            return true
        } else {
            return false
        }
    }
}
