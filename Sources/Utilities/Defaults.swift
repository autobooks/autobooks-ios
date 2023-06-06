import Foundation

final class Defaults {
    enum Key: String {
        case isPreviouslyLaunched
        case isPreviouslyOnboarded
    }

    private let userDefaults = UserDefaults.standard
    private let keyPrefix = "co.autobooks.tapToPay."

    var isPreviouslyLaunched: Bool {
        get { bool(for: .isPreviouslyLaunched) }
        set { userDefaults.set(newValue, forKey: prefixedKey(for: .isPreviouslyLaunched)) }
    }

    var isPreviouslyOnboarded: Bool {
        get { bool(for: .isPreviouslyOnboarded) }
        set { userDefaults.set(newValue, forKey: prefixedKey(for: .isPreviouslyOnboarded)) }
    }

    private func prefixedKey(for key: Key) -> String {
        "\(keyPrefix)\(key.rawValue)"
    }

    private func bool(for key: Key) -> Bool {
        userDefaults.bool(forKey: prefixedKey(for: key))
    }
}
