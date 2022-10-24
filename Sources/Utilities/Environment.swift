import SwiftUI

@available(iOS 13.0, *)
private struct PrimaryColorKey: EnvironmentKey {
    static let defaultValue = Color.blue
}

@available(iOS 13.0, *)
extension EnvironmentValues {
    var primaryColor: Color {
        get { self[PrimaryColorKey.self] }
        set { self[PrimaryColorKey.self] = newValue }
    }
}
