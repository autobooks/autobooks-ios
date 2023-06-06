import SwiftUI

/// `View` which takes a `Store` scoped from some optional state.
///
/// - Note: This view is static, it does not react to content after initialization, so values should be non-nil. This is
///         useful for scoped presentations like navigations or sheets where the content shouldn't disappear when the
///         original value is niled out.
///
@available(iOS 14.0, *)
struct OptionalScoped<State: Equatable, Action, Environment, Content: View>: View {
    typealias ViewStore = Store<State?, Action, Environment>

    @StateObject private var store: ViewStore

    private let content: Content

    init<SomeContent, NoneContent>(
        store: ViewStore,
        @ViewBuilder then someContent: @escaping (Store<State, Action, Environment>) -> SomeContent,
        @ViewBuilder else noneContent: () -> NoneContent
    ) where Content == _ConditionalContent<SomeContent, NoneContent> {
        _store = StateObject(wrappedValue: store)

        let noneContent = noneContent()
        self.content = {
            if let state = store.state {
                return ViewBuilder.buildEither(first: someContent(store.scope(state: { $0 ?? state },
                                                                              action: { $0 },
                                                                              environment: { $0 })))
            } else {
                return ViewBuilder.buildEither(second: noneContent)
            }
        }()
    }

    init<SomeContent>(
        store: ViewStore,
        @ViewBuilder then someContent: @escaping (Store<State, Action, Environment>) -> SomeContent
    ) where Content == _ConditionalContent<SomeContent, UnwrappingFailureView> {
        self.init(store: store, then: someContent, else: UnwrappingFailureView.init)
    }

    var body: some View {
        content
    }
}

@available(iOS 13.0, *)
struct UnwrappingFailureView: View {
    var body: some View {
        Text("Unwrapping failed!")
            .frame(maxWidth: .infinity, maxHeight: .infinity)
            .background(Color.red)
    }
}
