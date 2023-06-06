enum Loadable<Value, Error: Swift.Error> {
    case initialLoad(InitialLoad<Error>)
    case loaded(Loaded<Value, Error>)

    enum InitialLoad<Error> {
        case idle
        case loading(currentError: Error?)
        case failed(Error)
    }
}

extension Loadable: Equatable where Value: Equatable, Error: Equatable {}
extension Loadable.InitialLoad: Equatable where Error: Equatable {}

extension Loadable {
    var isIdle: Bool {
        guard case .initialLoad(.idle) = self else {
            return false
        }

        return true
    }

    var isRefreshing: Bool {
        switch self {
        case .initialLoad(.loading):
            return true
        case .initialLoad(.idle),
             .initialLoad(.failed):
            return false
        case let .loaded(loadedValue):
            return loadedValue.isRefreshing
        }
    }

    var value: Value? {
        guard case let .loaded(value) = self else {
            return nil
        }

        return value.value
    }

    var error: Error? {
        switch self {
        case .initialLoad(.idle):
            return nil
        case let .initialLoad(.failed(error as Error?)),
             let .initialLoad(.loading(error)):
            return error
        case let .loaded(loadedValue):
            return loadedValue.error
        }
    }

    mutating func refreshStarted() {
        switch self {
        case .initialLoad(.idle):
            self = .initialLoad(.loading(currentError: nil))
        case let .initialLoad(.loading(error)):
            self = .initialLoad(.loading(currentError: error))
        case let .initialLoad(.failed(error)):
            self = .initialLoad(.loading(currentError: error))
        case var .loaded(value):
            value.refreshStarted()
            self = .loaded(value)
        }
    }

    mutating func update(to result: Result<Value, Error>) {
        switch self {
        case .initialLoad:
            switch result {
            case let .success(value):
                self = .loaded(.loaded(value))
            case let .failure(error):
                self = .initialLoad(.failed(error))
            }
        case var .loaded(value):
            value.update(to: result)
            self = .loaded(value)
        }
    }

    mutating func update(to newValue: Value) {
        update(to: .success(newValue))
    }

    mutating func update(to newError: Error) {
        update(to: .failure(newError))
    }
}

@dynamicMemberLookup
enum Loaded<Value, Error: Swift.Error> {
    case loaded(Value)
    case failed(Error, previousValue: Value)
    case refreshing(currentValue: Value)

    subscript<T>(dynamicMember dynamicMember: KeyPath<Value, T>) -> T {
        value[keyPath: dynamicMember]
    }
}

extension Loaded: Equatable where Value: Equatable, Error: Equatable {}

extension Loaded {
    var isRefreshing: Bool {
        guard case .refreshing = self else {
            return false
        }

        return true
    }

    var value: Value {
        switch self {
        case let .loaded(value),
             let .failed(_, value),
             let .refreshing(value):
            return value
        }
    }

    var error: Error? {
        guard case let .failed(error, _) = self else {
            return nil
        }

        return error
    }

    mutating func refreshStarted() {
        self = .refreshing(currentValue: value)
    }

    mutating func update(to result: Result<Value, Error>) {
        switch (result, self) {
        case let (.success(value), .loaded),
             let (.success(value), .failed),
             let (.success(value), .refreshing):
            self = .loaded(value)
        case let (.failure(error), .loaded(value)),
             (let .failure(error), let .failed(_, value)),
             let (.failure(error), .refreshing(value)):
            self = .failed(error, previousValue: value)
        }
    }

    mutating func update(to newValue: Value) {
        update(to: .success(newValue))
    }

    mutating func update(to newError: Error) {
        update(to: .failure(newError))
    }
}
