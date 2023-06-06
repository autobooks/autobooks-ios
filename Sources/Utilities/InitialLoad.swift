enum InitialLoad<Action>: Equatable where Action: Equatable {
    case idle
    case loading(LoadingState<Action>)
    case finished

    mutating func transition(to state: InitialLoad) {
        guard self != .finished else {
            return
        }

        self = state
    }

    struct LoadingState<Action>: Equatable where Action: Equatable {
        let message: String
        let retryAction: Action
        let isFailure: Bool
        let progress: Int? // Add this line
    }
}

@available(iOS 16.0, *)
extension InitialLoad.LoadingState where Action == TapToPay.Action {
    static func login(isFailure: Bool = false) -> Self {
        .init(message: "Logging in...", retryAction: .performLogin, isFailure: isFailure, progress: nil)
    }

    static func fetchingStatus(isFailure: Bool = false) -> Self {
        .init(message: "Fetching status...", retryAction: .fetchStatus, isFailure: isFailure, progress: nil)
    }

    static func preparingReader(progress: Int, isFailure: Bool = false) -> Self {
        .init(message: "Preparing card reader... \n\(progress)%", retryAction: .prepareTapToPay, isFailure: isFailure, progress: progress)
    }

    static func startTriPOS(isFailure: Bool = false) -> Self {
        .init(message: "Setting up...", retryAction: .setupTriPOS, isFailure: isFailure, progress: nil)
    }
}

@available(iOS 14.0, *)
extension InitialLoad.LoadingState where Action == WebFeature.Action {
    static func login(isFailure: Bool = false) -> Self {
        .init(message: "Logging in...", retryAction: .performLogin, isFailure: isFailure, progress: nil)
    }
}
