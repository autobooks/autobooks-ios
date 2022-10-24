import SwiftUI

@available(iOS 15.4, *)
struct LoadableButton<Value, Error: Swift.Error>: View {
    let action: () -> Void
    let loadingState: Loadable<Value, Error>
    let title: String
    let loadingTitle: String
    let successTitle: String
    let failureTitle: String?

    init(loadingState: Loadable<Value, Error>, title: String, loadingTitle: String, successTitle: String, failureTitle: String? = nil, action: @escaping () -> Void) {
        self.action = action
        self.loadingState = loadingState
        self.title = title
        self.loadingTitle = loadingTitle
        self.successTitle = successTitle
        self.failureTitle = failureTitle
    }

    var body: some View {
        Button {
            action()
        } label: {
            switch loadingState {
            case .initialLoad(.idle):
                Text(title)
            case .initialLoad(.loading):
                Text(loadingTitle)
            case .loaded:
                HStack {
                    Text(successTitle)
                    Image(systemName: "checkmark")
                }
            case .initialLoad(.failed):
                Text(failureTitle ?? title)
            }
        }
        .disabled(!loadingState.isIdle)
    }
}

@available(iOS 15.4, *)
struct LoadableAlertButton<Success, Failure: Error>: View {
    @State private var isPresenting: Bool = false

    let loadingState: Loadable<Success, Failure>
    let title: String
    let loadingTitle: String
    let successTitle: String
    let failureTitle: String?
    let alertTitle: String
    let alertButtonTitle: String
    let alertMessage: String
    let alertAction: () -> Void

    init(loadingState: Loadable<Success, Failure>,
         title: String,
         loadingTitle: String,
         successTitle: String,
         failureTitle: String? = nil,
         alertTitle: String,
         alertButtonTitle: String,
         alertMessage: String,
         alertAction: @escaping () -> Void) {
        self.loadingState = loadingState
        self.title = title
        self.loadingTitle = loadingTitle
        self.successTitle = successTitle
        self.failureTitle = failureTitle
        self.alertTitle = alertTitle
        self.alertButtonTitle = alertButtonTitle
        self.alertMessage = alertMessage
        self.alertAction = alertAction
    }

    var body: some View {
        LoadableButton(loadingState: loadingState,
                       title: title,
                       loadingTitle: loadingTitle,
                       successTitle: successTitle,
                       failureTitle: failureTitle) {
            isPresenting = true
        }
        .buttonStyle(.tertiary(color: .red, disabledColor: nil))
        .alert(alertTitle, isPresented: $isPresenting) {
            Button(alertButtonTitle, role: .destructive, action: alertAction)
        } message: {
            Text(alertMessage)
        }
    }
}
