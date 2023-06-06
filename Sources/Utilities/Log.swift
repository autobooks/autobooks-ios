//
//  Log.swift
//  Autobooks
//
//  Created by Joshua Eckstein on 5/15/23.
//

import Foundation
import OSLog

typealias Log = os.Logger

internal extension os.Logger {
    private static var subsystem = Bundle.main.bundleIdentifier!

    static let triPOS = Logger(subsystem: subsystem, category: "TriPOS")
    static let proximityReader = Logger(subsystem: subsystem, category: "ProximityReader")
    static let sdk = Logger(subsystem: subsystem, category: "SDK")
    
    static func logEntries(since offset: CFTimeInterval) -> [String] {
        if #available(iOS 15.0, *) {
            guard let logStore = try? OSLogStore(scope: .currentProcessIdentifier) else {
                return ["OSLogStore(scope:) could not initialize."]
            }

            let timeAgo = logStore.position(date: Date().addingTimeInterval(offset))
            guard let logEntries = try? logStore.getEntries(at: timeAgo) else {
                return ["OSLogStore.getEntries did not return logs for the past \(-offset) seconds."]
            }
            
            return logEntries
                .compactMap { $0 as? OSLogEntryLog }
                .filter {
                    $0.subsystem == Log.subsystem || $0.subsystem.isEmpty
                }
                .map { entry in
                    if entry.subsystem.isEmpty {
                        return "[\(entry.level.rawValue)] \(entry.date): \(entry.composedMessage)"
                    } else {
                        return "[\(entry.level.rawValue)] \(entry.date): \(entry.subsystem).\(entry.category): \(entry.composedMessage)"
                    }
                }
        } else {
            return ["OSLogStore.getEntries is not available pre-iOS 15."]
        }
    }
}
