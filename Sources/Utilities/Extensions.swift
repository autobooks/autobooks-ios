import SwiftUI
import UIKit

@available(iOS 13.0, *)
extension Binding {
    func removeDuplicates(by isDuplicate: @escaping (Value, Value) -> Bool) -> Self {
        .init(get: { self.wrappedValue },
              set: { newValue, transaction in
                  guard !isDuplicate(self.wrappedValue, newValue) else {
                      return
                  }
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

extension Decimal {
    var dollars: String {
        if #available(iOS 15, *) {
            return formatted(.dollars)
        } else {
            return NumberFormatter.dollars.string(from: NSDecimalNumber(decimal: self))!
        }
    }
}

@available(iOS 15.0, *)
extension FormatStyle where Self == Decimal.FormatStyle.Currency {
    static var dollars: Decimal.FormatStyle.Currency {
        .currency(code: "usd")
    }
}

extension NumberFormatter {
    static let dollars: NumberFormatter = {
        let formatter = NumberFormatter()
        formatter.numberStyle = .currency
        formatter.currencyCode = "USD"

        return formatter
    }()
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
        guard case let .success(success) = self else {
            return nil
        }

        return success
    }

    var failure: Failure? {
        guard case let .failure(failure) = self else {
            return nil
        }

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

    var supportsTapToPay: Bool {
        if #available(iOS 16.0, *) {
            guard let deviceDescription = DeviceType(modelIdentifier)?.deviceDescription else {
                return false
            }
            
            return DeviceDescription.iPhoneXS.orLater.contains(deviceDescription)
        } else {
            return false
        }
    }
    
    var hasShortScreen: Bool {
        guard let deviceDescription = DeviceType(modelIdentifier)?.deviceDescription else {
            return false
        }
        
        return Set<DeviceDescription>(arrayLiteral:
            // 5.8 inch
            .iPhone14,
            .iPhone13Pro,
            .iPhone13,
            .iPhone13Mini,
            .iPhone12Pro,
            .iPhone12,
            .iPhone12Mini,
            .iPhone11Pro,
            .iPhoneXS,
            .iPhoneX,
                                      
            // 5.5 inch
            .iPhone8Plus,
            .iPhone7Plus,
            .iPhone6sPlus,
                                      
            // 4.7 inch
            .iPhoneSE3rdGeneration,
            .iPhoneSE2ndGeneration,
            .iPhone8,
            .iPhone7,
            .iPhone6s,
            .iPhone6,
                                      
            // 4 inch
            .iPhoneSE1stGeneration).contains(deviceDescription)
    }

    var supports13OrLater: Bool {
        guard let deviceDescription = DeviceType(modelIdentifier)?.deviceDescription else {
            return false
        }

        return Set<DeviceDescription>(arrayLiteral:
            .iPhone11, .iPhone11Pro, .iPhone11ProMax,
            .iPhoneXS, .iPhoneXSMax,
            .iPhoneXR,
            .iPhoneX,
            .iPhone8, .iPhone8Plus,
            .iPhone7, .iPhone7Plus,
            .iPhone6s, .iPhone6sPlus,
            .iPhoneSE1stGeneration, .iPhoneSE2ndGeneration,
            .iPodTouch7thGeneration).contains(deviceDescription)
    }
}
