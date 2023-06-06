//
//  URL.swift
//  Autobooks
//
//  Created by Joshua Eckstein on 5/30/23.
//

import Foundation

internal extension URL {
    var withoutQueries: URL {
        var components = URLComponents(string: absoluteString)
        components?.query = nil
        return components?.url ?? self
    }
}
