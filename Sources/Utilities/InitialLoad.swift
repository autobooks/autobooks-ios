enum InitialLoad<Action>: Equatable where Action: Equatable {
    case idle
    case loading(LoadingState<Action>)
    case finished

    mutating func transition(to state: InitialLoad) {
        guard self != .finished else { return }

        self = state
    }

    struct LoadingState<Action>: Equatable where Action: Equatable {
        let message: String
        let retryAction: Action
        let isFailure: Bool
    }
}

@available(iOS 15.4, *)
extension InitialLoad.LoadingState where Action == TapToPay.Action {
    static func login(isFailure: Bool = false) -> Self {
        .init(message: "Logging in...", retryAction: .performLogin, isFailure: isFailure)
    }

    static func fetchingPaymentToken(isFailure: Bool = false) -> Self {
        .init(message: "Fetching payment token...", retryAction: .fetchReaderToken(id: nil), isFailure: isFailure)
    }

    static func fetchingStatus(isFailure: Bool = false) -> Self {
        .init(message: "Fetching status...", retryAction: .fetchStatus, isFailure: isFailure)
    }

    static func preparingReader(progress: Int, isFailure: Bool = false) -> Self {
        .init(message: "Preparing card reader... \n\(progress)%", retryAction: .prepareTapToPay, isFailure: isFailure)
    }
}

@available(iOS 14.0, *)
extension InitialLoad.LoadingState where Action == WebFeature.Action {
    static func login(isFailure: Bool = false) -> Self {
        .init(message: "Logging in...", retryAction: .performLogin, isFailure: isFailure)
    }
}
