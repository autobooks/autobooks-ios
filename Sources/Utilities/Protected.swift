import Foundation

final class UnfairLock {
    private let unfairLock: os_unfair_lock_t

    init() {
        unfairLock = .allocate(capacity: 1)
        unfairLock.initialize(to: os_unfair_lock())
    }

    deinit {
        unfairLock.deinitialize(count: 1)
        unfairLock.deallocate()
    }

    fileprivate func lock() {
        os_unfair_lock_lock(unfairLock)
    }

    private func unlock() {
        os_unfair_lock_unlock(unfairLock)
    }

    /// Executes a closure returning a value while acquiring the lock.
    ///
    /// - Parameter closure: The closure to run.
    ///
    /// - Returns:           The value the closure generated.
    func around<T>(_ closure: () throws -> T) rethrows -> T {
        lock(); defer { unlock() }
        return try closure()
    }

    /// Execute a closure while acquiring the lock.
    ///
    /// - Parameter closure: The closure to run.
    func around(_ closure: () throws -> Void) rethrows {
        lock(); defer { unlock() }
        try closure()
    }
}

/// A thread-safe wrapper around a value.
@propertyWrapper
@dynamicMemberLookup
final class Protected<T> {
    private let lock = UnfairLock()
    private var value: T

    init(_ value: T) {
        self.value = value
    }

    /// The contained value. Unsafe for anything more than direct read or write.
    var wrappedValue: T {
        get { lock.around { value } }
        set { lock.around { value = newValue } }
    }

    var projectedValue: Protected<T> { self }

    init(wrappedValue: T) {
        value = wrappedValue
    }

    /// Synchronously read or transform the contained value.
    ///
    /// - Parameter closure: The closure to execute.
    ///
    /// - Returns:           The return value of the closure passed.
    func read<U>(_ closure: (T) throws -> U) rethrows -> U {
        try lock.around { try closure(self.value) }
    }

    /// Synchronously modify the protected value.
    ///
    /// - Parameter closure: The closure to execute.
    ///
    /// - Returns:           The modified value.
    @discardableResult
    func write<U>(_ closure: (inout T) throws -> U) rethrows -> U {
        try lock.around { try closure(&self.value) }
    }

    subscript<Property>(dynamicMember keyPath: WritableKeyPath<T, Property>) -> Property {
        get { lock.around { value[keyPath: keyPath] } }
        set { lock.around { value[keyPath: keyPath] = newValue } }
    }

    subscript<Property>(dynamicMember keyPath: KeyPath<T, Property>) -> Property {
        lock.around { value[keyPath: keyPath] }
    }
}
