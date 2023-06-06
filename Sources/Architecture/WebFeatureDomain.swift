import Foundation

@available(iOS 14.0, *)
typealias WebFeatureStore = Store<WebFeature.State, WebFeature.Action, WebFeature.Environment>

@available(iOS 14.0, *)
struct WebFeature {
    let feature: AB.WebFeatureConfiguration

    enum Navigation: Equatable {
        case login
        case feature(URL)
    }

    struct State: Equatable {
        var initialLoad: InitialLoad<Action> = .idle
        var navigation: [Navigation] = [.login]
    }

    enum Action: Equatable {
        case dismiss
        case performLogin
        case receiveLogin(Result<LoginResponse, APIError>)
    }

    struct Environment {
        let api: AutobooksAPI
        let dismiss: () -> Void
    }

    var reducer: Reducer<State, Action, Environment> {
        .init { state, action, environment in
            switch action {
            case .dismiss:
                environment.dismiss()

                return nil
            case .performLogin:
                state.initialLoad.transition(to: .loading(.login()))

                return .run { send in
                    await send(.receiveLogin(environment.api.performLogin()))
                }
            case let .receiveLogin(.success(response)):
                state.initialLoad.transition(to: .finished)

                switch feature.kind {
                case .paymentForm:
                    state.navigation.append(.feature(response.webFeatureURLs.paymentForm))
                case .invoicing:
                    state.navigation.append(.feature(response.webFeatureURLs.invoicing))
                }

                return nil
            case .receiveLogin(.failure):
                state.initialLoad.transition(to: .loading(.login(isFailure: true)))

                return nil
            }
        }
    }
}
