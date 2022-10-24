import SwiftUI

@available(iOS 15.0, *)
struct ActionButtonStyle: ButtonStyle {
    func makeBody(configuration: Configuration) -> some View {
        ActionButton(configuration: configuration)
    }

    private struct ActionButton: View {
        @Environment(\.isEnabled) var isEnabled
        @Environment(\.primaryColor) var primaryColor

        let configuration: ButtonStyleConfiguration

        var body: some View {
            configuration.label
                .frame(maxWidth: .infinity)
                .padding(.horizontal, 16)
                .frame(minHeight: 50)
                .background(backgroundColor)
                .cornerRadius(14)
                .foregroundColor(.white)
        }

        var backgroundColor: Color {
            if isEnabled {
                return configuration.isPressed ? primaryColor.opacity(0.75) : primaryColor
            } else {
                return Color.gray
            }
        }
    }
}

@available(iOS 15.0, *)
extension ButtonStyle where Self == ActionButtonStyle {
    static var action: ActionButtonStyle {
        ActionButtonStyle()
    }
}

@available(iOS 15.0, *)
struct SecondaryButtonStyle: ButtonStyle {
    let isFailure: Bool

    func makeBody(configuration: Configuration) -> some View {
        SecondaryButton(configuration: configuration, isFailure: isFailure)
    }

    private struct SecondaryButton: View {
        @Environment(\.isEnabled) var isEnabled
        @Environment(\.primaryColor) var primaryColor

        let configuration: ButtonStyleConfiguration
        let isFailure: Bool

        var body: some View {
            configuration.label
                .frame(maxWidth: .infinity)
                .frame(minHeight: 50)
                .background(backgroundColor)
                .cornerRadius(14)
                .foregroundColor(foregroundColor)
                .font(.system(.body).weight(.bold))
        }

        var foregroundColor: Color {
            isFailure ? .red : primaryColor
        }

        var backgroundColor: Color {
            if isFailure {
                return .red.opacity(0.15)
            } else {
                if isEnabled {
                    return configuration.isPressed ? primaryColor.opacity(0.3) : primaryColor.opacity(0.15)
                } else {
                    return primaryColor.opacity(0.15)
                }
            }
        }
    }
}

@available(iOS 15.0, *)
extension ButtonStyle where Self == SecondaryButtonStyle {
    static var secondary: SecondaryButtonStyle {
        SecondaryButtonStyle(isFailure: false)
    }

    static func secondary(isFailure: Bool) -> SecondaryButtonStyle {
        SecondaryButtonStyle(isFailure: isFailure)
    }
}

@available(iOS 15.0, *)
struct TertiaryButtonStyle: ButtonStyle {
    let color: Color?
    let disabledColor: Color?

    init(color: Color? = nil, disabledColor: Color? = .gray) {
        self.color = color
        self.disabledColor = disabledColor
    }

    func makeBody(configuration: Configuration) -> some View {
        TertiaryButton(configuration: configuration, color: color, disabledColor: disabledColor)
    }

    private struct TertiaryButton: View {
        @Environment(\.isEnabled) var isEnabled
        @Environment(\.primaryColor) var primaryColor

        let configuration: ButtonStyleConfiguration
        let color: Color?
        let disabledColor: Color?

        var body: some View {
            configuration.label
                .frame(maxWidth: .infinity)
                .frame(minHeight: 50)
                .background()
                .cornerRadius(14)
                .foregroundColor(foregroundColor)
                .font(.system(.body).weight(.bold))
        }

        var foregroundColor: Color {
            if isEnabled {
                return configuration.isPressed ? enabledForegroundColor.opacity(0.5) : enabledForegroundColor
            } else {
                return disabledColor ?? enabledForegroundColor
            }
        }

        var enabledForegroundColor: Color {
            color ?? primaryColor
        }
    }
}

@available(iOS 15.0, *)
extension ButtonStyle where Self == TertiaryButtonStyle {
    static var tertiary: TertiaryButtonStyle {
        TertiaryButtonStyle()
    }

    static func tertiary(color: Color, disabledColor: Color? = .gray) -> TertiaryButtonStyle {
        TertiaryButtonStyle(color: color, disabledColor: disabledColor)
    }
}
