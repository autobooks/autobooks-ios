import SwiftUI

@available(iOS 16.0, *)
enum Postsale {
    struct State: Equatable {
        var details: TransactionDetails.State?
    }

    enum Action: Equatable {
        case retryTransaction
        case transactionDetails(TransactionDetails.Action)
    }

    static var reducer: Reducer<Postsale.State, Postsale.Action, TapToPay.Environment> {
        TransactionDetails.reducer
            .optional()
            .toParent(
                \.details,
                toChildAction: { action in
                    switch action {
                    case let .transactionDetails(details):
                        return details
                    default:
                        return nil
                    }
                },
                toParentAction: Action.transactionDetails,
                toChildEnvironment: { $0 }
            )
    }
}

@available(iOS 16.0, *)
struct PostsaleScreen: View {
    typealias ViewStore = Store<Postsale.State, Postsale.Action, TapToPay.Environment>

    @StateObject private var store: ViewStore

    init(store: ViewStore) {
        _store = StateObject(wrappedValue: store)
    }

    var body: some View {
        OptionalScoped(store: store.scope(state: \.details, action: Postsale.Action.transactionDetails)) { scopedStore in
            TransactionSummary(store: scopedStore, configuration: .success)
        } else: {
            failureMessageView
        }
    }

    private var failureMessageView: some View {
        MessageActionView(title: "Something Went Wrong",
                          message: "Please try again",
                          sourceDomain: .tapToPay,
                          action: .tryAgain {
                              store.send(.retryTransaction)
                          },
                          callUsAction: .callUs {
                              if let url = URL(string: "tel://8666173122") {
                                  UIApplication.shared.open(url)
                              }
                          })
    }
}

@available(iOS 15.0, *)
extension Transaction {
    struct UIElement: Identifiable {
        var id: String { label }

        let label: String
        let image: String
        let content: String
    }

    var uiElements: [UIElement] {
        var elements: [UIElement] = [
            .init(label: "Card", image: "creditcard", content: card.description),
            .init(label: "Paid on", image: "calendar", content: createdOn.formatted(date: .long, time: .omitted)),
        ]

        if let email = lastReceiptEmail {
            elements.append(.init(label: "Email", image: "envelope", content: email))
        }

        return elements
    }
}
