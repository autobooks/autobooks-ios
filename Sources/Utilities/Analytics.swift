import Foundation

@_implementationOnly import Segment

struct Analytics {
    private let segment: Segment.Analytics = {
        let configuration = Segment.Configuration(writeKey: "vYjeT92L3lbWkU0eRhKYa7RNkYGBeeBB")
            .trackApplicationLifecycleEvents(true)
            .flushInterval(10)
            .flushAt(1)

        return Segment.Analytics(configuration: configuration)
    }()
    
    static let shared = Analytics()
    
    enum Event: CustomStringConvertible {
        case visitedTransactions
        case tappedCharge(Decimal)

        var description: String {
            switch self {
            case .visitedTransactions:
                return "[Tap To Pay] Visited Transactions List"
            case .tappedCharge:
                return "[Tap To Pay] Tapped Charge"
            }
        }
    }
    
    func log(_ event: Event) {
        switch event {
        case let .tappedCharge(amount):
            segment.track(name: event.description, properties: ["Amount": amount])
        default:
            segment.track(name: event.description)
        }
    }
}
