import SwiftUI

@available(iOS 16.0, *)
struct EmailTextField: View {
    @Binding var input: EmailInput

    var body: some View {
        HStack(spacing: 4) {
            TextField("Add Email...", text: $input
                .bidirectionalMap(toOutput: \.email,
                                  fromOutput: EmailInput.init)
                .removeDuplicates(by: ==))
                .disableAutocorrection(true)
                .keyboardType(.emailAddress)
                .textInputAutocapitalization(.never)

            if !input.email.isEmpty {
                Button {
                    input = EmailInput()
                } label: {
                    Image(systemName: "xmark.circle.fill")
                        .foregroundColor(.gray)
                }
                .accessibilityLabel("Clear Email")
            }
        }
        .frame(maxWidth: .infinity)
        .frame(height: 44)
        .font(.system(.body))
        .overlay(Divider().background(Color(uiColor: .opaqueSeparator)), alignment: .bottom)
    }
}

struct EmailInput: Equatable {
    var email = ""
    var isValid = false
}

extension EmailInput {
    init(email: String) {
        self.email = email
        let emailRegex = #"^\S+@\S+\.\S+$"#
        let result = email.range(of: emailRegex, options: .regularExpression)
        self.isValid = result != nil
    }
}
