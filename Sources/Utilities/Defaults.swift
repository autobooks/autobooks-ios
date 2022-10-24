import Foundation

final class Defaults {
    enum Key: String {
        case isPreviouslyLaunched
    }

    private let userDefaults = UserDefaults(suiteName: "co.autobooks.tapToPay")!
    private let keyPrefix = "co.autobooks.tapToPay."

    var isPreviouslyLaunched: Bool {
        get { bool(for: .isPreviouslyLaunched) }
        set { userDefaults.set(newValue, forKey: prefixedKey(for: .isPreviouslyLaunched)) }
    }

    private func prefixedKey(for key: Key) -> String {
        "\(keyPrefix)\(key.rawValue)"
    }

    private func bool(for key: Key) -> Bool {
        userDefaults.bool(forKey: prefixedKey(for: key))
    }
}
