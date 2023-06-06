import Foundation

enum DeviceType: Equatable, Hashable, Comparable {
    case iPhone(Int, Int)
    case iPad(Int, Int)
    case iPod(Int, Int)
    
    static let iPad11v1 = DeviceType.iPad(11, 1)
    static let iPad11v2 = DeviceType.iPad(11, 2)
    static let iPad11v3 = DeviceType.iPad(11, 3)
    static let iPad11v4 = DeviceType.iPad(11, 4)
    static let iPad11v6 = DeviceType.iPad(11, 6)
    static let iPad11v7 = DeviceType.iPad(11, 7)
    static let iPad12v1 = DeviceType.iPad(12, 1)
    static let iPad12v2 = DeviceType.iPad(12, 2)
    static let iPad13v1 = DeviceType.iPad(13, 1)
    static let iPad13v10 = DeviceType.iPad(13, 10)
    static let iPad13v11 = DeviceType.iPad(13, 11)
    static let iPad13v16 = DeviceType.iPad(13, 16)
    static let iPad13v17 = DeviceType.iPad(13, 17)
    static let iPad13v18 = DeviceType.iPad(13, 18)
    static let iPad13v19 = DeviceType.iPad(13, 19)
    static let iPad13v2 = DeviceType.iPad(13, 2)
    static let iPad13v4 = DeviceType.iPad(13, 4)
    static let iPad13v5 = DeviceType.iPad(13, 5)
    static let iPad13v6 = DeviceType.iPad(13, 6)
    static let iPad13v7 = DeviceType.iPad(13, 7)
    static let iPad13v8 = DeviceType.iPad(13, 8)
    static let iPad13v9 = DeviceType.iPad(13, 9)
    static let iPad14v1 = DeviceType.iPad(14, 1)
    static let iPad14v2 = DeviceType.iPad(14, 2)
    static let iPad14v3 = DeviceType.iPad(14, 3)
    static let iPad14v4 = DeviceType.iPad(14, 4)
    static let iPad14v5 = DeviceType.iPad(14, 5)
    static let iPad14v6 = DeviceType.iPad(14, 6)
    static let iPad2v1 = DeviceType.iPad(2, 1)
    static let iPad2v2 = DeviceType.iPad(2, 2)
    static let iPad2v3 = DeviceType.iPad(2, 3)
    static let iPad2v4 = DeviceType.iPad(2, 4)
    static let iPad2v5 = DeviceType.iPad(2, 5)
    static let iPad2v6 = DeviceType.iPad(2, 6)
    static let iPad2v7 = DeviceType.iPad(2, 7)
    static let iPad3v1 = DeviceType.iPad(3, 1)
    static let iPad3v2 = DeviceType.iPad(3, 2)
    static let iPad3v3 = DeviceType.iPad(3, 3)
    static let iPad3v4 = DeviceType.iPad(3, 4)
    static let iPad3v5 = DeviceType.iPad(3, 5)
    static let iPad3v6 = DeviceType.iPad(3, 6)
    static let iPad4v1 = DeviceType.iPad(4, 1)
    static let iPad4v2 = DeviceType.iPad(4, 2)
    static let iPad4v3 = DeviceType.iPad(4, 3)
    static let iPad4v4 = DeviceType.iPad(4, 4)
    static let iPad4v5 = DeviceType.iPad(4, 5)
    static let iPad4v6 = DeviceType.iPad(4, 6)
    static let iPad4v7 = DeviceType.iPad(4, 7)
    static let iPad4v8 = DeviceType.iPad(4, 8)
    static let iPad4v9 = DeviceType.iPad(4, 9)
    static let iPad5v1 = DeviceType.iPad(5, 1)
    static let iPad5v2 = DeviceType.iPad(5, 2)
    static let iPad5v3 = DeviceType.iPad(5, 3)
    static let iPad5v4 = DeviceType.iPad(5, 4)
    static let iPad6v11 = DeviceType.iPad(6, 11)
    static let iPad6v12 = DeviceType.iPad(6, 12)
    static let iPad6v3 = DeviceType.iPad(6, 3)
    static let iPad6v4 = DeviceType.iPad(6, 4)
    static let iPad6v7 = DeviceType.iPad(6, 7)
    static let iPad6v8 = DeviceType.iPad(6, 8)
    static let iPad7v1 = DeviceType.iPad(7, 1)
    static let iPad7v11 = DeviceType.iPad(7, 11)
    static let iPad7v12 = DeviceType.iPad(7, 12)
    static let iPad7v2 = DeviceType.iPad(7, 2)
    static let iPad7v3 = DeviceType.iPad(7, 3)
    static let iPad7v4 = DeviceType.iPad(7, 4)
    static let iPad7v5 = DeviceType.iPad(7, 5)
    static let iPad7v6 = DeviceType.iPad(7, 6)
    static let iPad8v1 = DeviceType.iPad(8, 1)
    static let iPad8v10 = DeviceType.iPad(8, 10)
    static let iPad8v11 = DeviceType.iPad(8, 11)
    static let iPad8v12 = DeviceType.iPad(8, 12)
    static let iPad8v2 = DeviceType.iPad(8, 2)
    static let iPad8v3 = DeviceType.iPad(8, 3)
    static let iPad8v4 = DeviceType.iPad(8, 4)
    static let iPad8v5 = DeviceType.iPad(8, 5)
    static let iPad8v6 = DeviceType.iPad(8, 6)
    static let iPad8v7 = DeviceType.iPad(8, 7)
    static let iPad8v8 = DeviceType.iPad(8, 8)
    static let iPad8v9 = DeviceType.iPad(8, 9)
    static let iPhone10v1 = DeviceType.iPhone(10, 1)
    static let iPhone10v2 = DeviceType.iPhone(10, 2)
    static let iPhone10v3 = DeviceType.iPhone(10, 3)
    static let iPhone10v4 = DeviceType.iPhone(10, 4)
    static let iPhone10v5 = DeviceType.iPhone(10, 5)
    static let iPhone10v6 = DeviceType.iPhone(10, 6)
    static let iPhone11v2 = DeviceType.iPhone(11, 2)
    static let iPhone11v4 = DeviceType.iPhone(11, 4)
    static let iPhone11v6 = DeviceType.iPhone(11, 6)
    static let iPhone11v8 = DeviceType.iPhone(11, 8)
    static let iPhone12v1 = DeviceType.iPhone(12, 1)
    static let iPhone12v3 = DeviceType.iPhone(12, 3)
    static let iPhone12v5 = DeviceType.iPhone(12, 5)
    static let iPhone12v8 = DeviceType.iPhone(12, 8)
    static let iPhone13v1 = DeviceType.iPhone(13, 1)
    static let iPhone13v2 = DeviceType.iPhone(13, 2)
    static let iPhone13v3 = DeviceType.iPhone(13, 3)
    static let iPhone13v4 = DeviceType.iPhone(13, 4)
    static let iPhone14v2 = DeviceType.iPhone(14, 2)
    static let iPhone14v3 = DeviceType.iPhone(14, 3)
    static let iPhone14v4 = DeviceType.iPhone(14, 4)
    static let iPhone14v5 = DeviceType.iPhone(14, 5)
    static let iPhone14v6 = DeviceType.iPhone(14, 6)
    static let iPhone14v7 = DeviceType.iPhone(14, 7)
    static let iPhone14v8 = DeviceType.iPhone(14, 8)
    static let iPhone15v2 = DeviceType.iPhone(15, 2)
    static let iPhone15v3 = DeviceType.iPhone(15, 3)
    static let iPhone4v1 = DeviceType.iPhone(4, 1)
    static let iPhone5v1 = DeviceType.iPhone(5, 1)
    static let iPhone5v2 = DeviceType.iPhone(5, 2)
    static let iPhone5v3 = DeviceType.iPhone(5, 3)
    static let iPhone5v4 = DeviceType.iPhone(5, 4)
    static let iPhone6v1 = DeviceType.iPhone(6, 1)
    static let iPhone6v2 = DeviceType.iPhone(6, 2)
    static let iPhone7v1 = DeviceType.iPhone(7, 1)
    static let iPhone7v2 = DeviceType.iPhone(7, 2)
    static let iPhone8v1 = DeviceType.iPhone(8, 1)
    static let iPhone8v2 = DeviceType.iPhone(8, 2)
    static let iPhone8v4 = DeviceType.iPhone(8, 4)
    static let iPhone9v1 = DeviceType.iPhone(9, 1)
    static let iPhone9v2 = DeviceType.iPhone(9, 2)
    static let iPhone9v3 = DeviceType.iPhone(9, 3)
    static let iPhone9v4 = DeviceType.iPhone(9, 4)
    static let iPod5v1 = DeviceType.iPod(5, 1)
    static let iPod7v1 = DeviceType.iPod(7, 1)
    static let iPod9v1 = DeviceType.iPod(9, 1)
    static let allTypes: [DeviceType] = [
        DeviceType.iPad11v1,
        DeviceType.iPad11v2,
        DeviceType.iPad11v3,
        DeviceType.iPad11v4,
        DeviceType.iPad11v6,
        DeviceType.iPad11v7,
        DeviceType.iPad12v1,
        DeviceType.iPad12v2,
        DeviceType.iPad13v1,
        DeviceType.iPad13v10,
        DeviceType.iPad13v11,
        DeviceType.iPad13v16,
        DeviceType.iPad13v17,
        DeviceType.iPad13v18,
        DeviceType.iPad13v19,
        DeviceType.iPad13v2,
        DeviceType.iPad13v4,
        DeviceType.iPad13v5,
        DeviceType.iPad13v6,
        DeviceType.iPad13v7,
        DeviceType.iPad13v8,
        DeviceType.iPad13v9,
        DeviceType.iPad14v1,
        DeviceType.iPad14v2,
        DeviceType.iPad14v3,
        DeviceType.iPad14v4,
        DeviceType.iPad14v5,
        DeviceType.iPad14v6,
        DeviceType.iPad2v1,
        DeviceType.iPad2v2,
        DeviceType.iPad2v3,
        DeviceType.iPad2v4,
        DeviceType.iPad2v5,
        DeviceType.iPad2v6,
        DeviceType.iPad2v7,
        DeviceType.iPad3v1,
        DeviceType.iPad3v2,
        DeviceType.iPad3v3,
        DeviceType.iPad3v4,
        DeviceType.iPad3v5,
        DeviceType.iPad3v6,
        DeviceType.iPad4v1,
        DeviceType.iPad4v2,
        DeviceType.iPad4v3,
        DeviceType.iPad4v4,
        DeviceType.iPad4v5,
        DeviceType.iPad4v6,
        DeviceType.iPad4v7,
        DeviceType.iPad4v8,
        DeviceType.iPad4v9,
        DeviceType.iPad5v1,
        DeviceType.iPad5v2,
        DeviceType.iPad5v3,
        DeviceType.iPad5v4,
        DeviceType.iPad6v11,
        DeviceType.iPad6v12,
        DeviceType.iPad6v3,
        DeviceType.iPad6v4,
        DeviceType.iPad6v7,
        DeviceType.iPad6v8,
        DeviceType.iPad7v1,
        DeviceType.iPad7v11,
        DeviceType.iPad7v12,
        DeviceType.iPad7v2,
        DeviceType.iPad7v3,
        DeviceType.iPad7v4,
        DeviceType.iPad7v5,
        DeviceType.iPad7v6,
        DeviceType.iPad8v1,
        DeviceType.iPad8v10,
        DeviceType.iPad8v11,
        DeviceType.iPad8v12,
        DeviceType.iPad8v2,
        DeviceType.iPad8v3,
        DeviceType.iPad8v4,
        DeviceType.iPad8v5,
        DeviceType.iPad8v6,
        DeviceType.iPad8v7,
        DeviceType.iPad8v8,
        DeviceType.iPad8v9,
        DeviceType.iPhone10v1,
        DeviceType.iPhone10v2,
        DeviceType.iPhone10v3,
        DeviceType.iPhone10v4,
        DeviceType.iPhone10v5,
        DeviceType.iPhone10v6,
        DeviceType.iPhone11v2,
        DeviceType.iPhone11v4,
        DeviceType.iPhone11v6,
        DeviceType.iPhone11v8,
        DeviceType.iPhone12v1,
        DeviceType.iPhone12v3,
        DeviceType.iPhone12v5,
        DeviceType.iPhone12v8,
        DeviceType.iPhone13v1,
        DeviceType.iPhone13v2,
        DeviceType.iPhone13v3,
        DeviceType.iPhone13v4,
        DeviceType.iPhone14v2,
        DeviceType.iPhone14v3,
        DeviceType.iPhone14v4,
        DeviceType.iPhone14v5,
        DeviceType.iPhone14v6,
        DeviceType.iPhone14v7,
        DeviceType.iPhone14v8,
        DeviceType.iPhone15v2,
        DeviceType.iPhone15v3,
        DeviceType.iPhone4v1,
        DeviceType.iPhone5v1,
        DeviceType.iPhone5v2,
        DeviceType.iPhone5v3,
        DeviceType.iPhone5v4,
        DeviceType.iPhone6v1,
        DeviceType.iPhone6v2,
        DeviceType.iPhone7v1,
        DeviceType.iPhone7v2,
        DeviceType.iPhone8v1,
        DeviceType.iPhone8v2,
        DeviceType.iPhone8v4,
        DeviceType.iPhone9v1,
        DeviceType.iPhone9v2,
        DeviceType.iPhone9v3,
        DeviceType.iPhone9v4,
        DeviceType.iPod5v1,
        DeviceType.iPod7v1,
        DeviceType.iPod9v1,
    ]
    
    var deviceDescription: DeviceDescription? {
        switch self {
        case .iPad13v10,
             .iPad13v11,
             .iPad13v8,
             .iPad13v9:
            return .iPadPro129Inch5thGeneration
        case .iPad13v16,
             .iPad13v17:
            return .iPadAir5thGeneration
        case .iPad13v4,
             .iPad13v5,
             .iPad13v6,
             .iPad13v7:
            return .iPadPro11Inch3rdGeneration
        case .iPad11v1,
             .iPad11v2:
            return .iPadMini5thGeneration
        case .iPad11v3,
             .iPad11v4:
            return .iPadAir3rdGeneration
        case .iPad11v6,
             .iPad11v7:
            return .iPad8thGeneration
        case .iPhone11v2:
            return .iPhoneXS
        case .iPhone11v4,
             .iPhone11v6:
            return .iPhoneXSMax
        case .iPhone11v8:
            return .iPhoneXR
        case .iPad12v1,
             .iPad12v2:
            return .iPad9thGeneration
        case .iPhone12v1:
            return .iPhone11
        case .iPhone12v3:
            return .iPhone11Pro
        case .iPhone12v5:
            return .iPhone11ProMax
        case .iPhone12v8:
            return .iPhoneSE2ndGeneration
        case .iPad13v1,
             .iPad13v2:
            return .iPadAir4thGeneration
        case .iPad13v18,
             .iPad13v19:
            return .iPad10thGeneration
        case .iPhone13v1:
            return .iPhone12Mini
        case .iPhone13v2:
            return .iPhone12
        case .iPhone13v3:
            return .iPhone12Pro
        case .iPhone13v4:
            return .iPhone12ProMax
        case .iPad14v1,
             .iPad14v2:
            return .iPadMini6thGeneration
        case .iPhone14v2:
            return .iPhone13Pro
        case .iPhone14v3:
            return .iPhone13ProMax
        case .iPhone14v4:
            return .iPhone13Mini
        case .iPhone14v5:
            return .iPhone13
        case .iPhone14v6:
            return .iPhoneSE3rdGeneration
        case .iPhone14v7:
            return .iPhone14
        case .iPhone14v8:
            return .iPhone14Plus
        case .iPad14v3,
             .iPad14v4:
            return .iPadPro11Inch4thGeneration
        case .iPad14v5,
             .iPad14v6:
            return .iPadPro129Inch6thGeneration
        case .iPad6v11,
             .iPad6v12:
            return .iPad5thGeneration
        case .iPhone8v1:
            return .iPhone6s
        case .iPhone8v2:
            return .iPhone6sPlus
        case .iPhone8v4:
            return .iPhoneSE1stGeneration
        case .iPad6v3,
             .iPad6v4:
            return .iPadPro97Inch
        case .iPad6v7,
             .iPad6v8:
            return .iPadPro129Inch
        case .iPad7v1,
             .iPad7v2:
            return .iPadPro129Inch2ndGeneration
        case .iPad7v3,
             .iPad7v4:
            return .iPadPro105Inch
        case .iPad7v11,
             .iPad7v12:
            return .iPad7thGeneration
        case .iPad7v5,
             .iPad7v6:
            return .iPad6thGeneration
        case .iPhone9v1,
             .iPhone9v3:
            return .iPhone7
        case .iPhone9v2,
             .iPhone9v4:
            return .iPhone7Plus
        case .iPod9v1:
            return .iPodTouch7thGeneration
        case .iPad8v1,
             .iPad8v2,
             .iPad8v3,
             .iPad8v4:
            return .iPadPro11Inch
        case .iPad8v10,
             .iPad8v9:
            return .iPadPro11Inch2ndGeneration
        case .iPad8v11,
             .iPad8v12:
            return .iPadPro129Inch4thGeneration
        case .iPad8v5,
             .iPad8v6,
             .iPad8v7,
             .iPad8v8:
            return .iPadPro129Inch3rdGeneration
        case .iPhone10v1,
             .iPhone10v4:
            return .iPhone8
        case .iPhone10v2,
             .iPhone10v5:
            return .iPhone8Plus
        case .iPhone10v3,
             .iPhone10v6:
            return .iPhoneX
        case .iPhone15v2:
            return .iPhone14Pro
        case .iPhone15v3:
            return .iPhone14ProMax
        case .iPad2v1,
             .iPad2v2,
             .iPad2v3,
             .iPad2v4:
            return .iPad2
        case .iPhone4v1:
            return .iPhone4s
        case .iPad2v5,
             .iPad2v6,
             .iPad2v7:
            return .iPadMini
        case .iPod5v1:
            return .iPodTouch
        case .iPad3v1,
             .iPad3v2,
             .iPad3v3:
            return .iPad3rdGeneration
        case .iPad3v4,
             .iPad3v5,
             .iPad3v6:
            return .iPad4thGeneration
        case .iPad4v1,
             .iPad4v2,
             .iPad4v3:
            return .iPadAir
        case .iPad4v4,
             .iPad4v5,
             .iPad4v6:
            return .iPadMini2
        case .iPad4v7,
             .iPad4v8,
             .iPad4v9:
            return .iPadMini3
        case .iPhone6v1,
             .iPhone6v2:
            return .iPhone5s
        case .iPad5v1,
             .iPad5v2:
            return .iPadMini4
        case .iPhone7v1:
            return .iPhone6Plus
        case .iPhone7v2:
            return .iPhone6
        case .iPod7v1:
            return .iPodTouch6thGeneration
        case .iPad5v3,
             .iPad5v4:
            return .iPadAir2
        case .iPhone5v1,
             .iPhone5v2:
            return .iPhone5
        case .iPhone5v3,
             .iPhone5v4:
            return .iPhone5c
        default:
            return nil
        }
    }

    static func < (lhs: Self, rhs: Self) -> Bool {
        switch (lhs, rhs) {
        case let (.iPhone(majorA, minorA), .iPhone(majorB, minorB)):
            return majorA < majorB && minorA < minorB
        case let (.iPad(majorA, minorA), .iPad(majorB, minorB)):
            return majorA < majorB && minorA < minorB
        case let (.iPod(majorA, minorA), .iPod(majorB, minorB)):
            return majorA < majorB && minorA < minorB
        default:
            return false
        }
    }

    static func <= (lhs: Self, rhs: Self) -> Bool {
        switch (lhs, rhs) {
        case let (.iPhone(majorA, minorA), .iPhone(majorB, minorB)):
            return majorA <= majorB && minorA <= minorB
        case let (.iPad(majorA, minorA), .iPad(majorB, minorB)):
            return majorA <= majorB && minorA <= minorB
        case let (.iPod(majorA, minorA), .iPod(majorB, minorB)):
            return majorA <= majorB && minorA <= minorB
        default:
            return false
        }
    }

    static func > (lhs: Self, rhs: Self) -> Bool {
        switch (lhs, rhs) {
        case let (.iPhone(majorA, minorA), .iPhone(majorB, minorB)):
            return majorA <= majorB && minorA <= minorB
        case let (.iPad(majorA, minorA), .iPad(majorB, minorB)):
            return majorA <= majorB && minorA <= minorB
        case let (.iPod(majorA, minorA), .iPod(majorB, minorB)):
            return majorA <= majorB && minorA <= minorB
        default:
            return false
        }
    }

    static func >= (lhs: Self, rhs: Self) -> Bool {
        switch (lhs, rhs) {
        case let (.iPhone(majorA, minorA), .iPhone(majorB, minorB)):
            return majorA >= majorB && minorA >= minorB
        case let (.iPad(majorA, minorA), .iPad(majorB, minorB)):
            return majorA >= majorB && minorA >= minorB
        case let (.iPod(majorA, minorA), .iPod(majorB, minorB)):
            return majorA >= majorB && minorA >= minorB
        default:
            return false
        }
    }
}

enum DeviceDescription: Equatable, Hashable, CustomStringConvertible {
    case iPad10thGeneration
    case iPad3rdGeneration
    case iPad4thGeneration
    case iPad5thGeneration
    case iPad6thGeneration
    case iPad7thGeneration
    case iPad8thGeneration
    case iPad9thGeneration
    case iPad2
    case iPadAir
    case iPadAir3rdGeneration
    case iPadAir4thGeneration
    case iPadAir5thGeneration
    case iPadAir2
    case iPadPro105Inch
    case iPadPro11Inch
    case iPadPro11Inch2ndGeneration
    case iPadPro11Inch3rdGeneration
    case iPadPro11Inch4thGeneration
    case iPadPro129Inch
    case iPadPro129Inch2ndGeneration
    case iPadPro129Inch3rdGeneration
    case iPadPro129Inch4thGeneration
    case iPadPro129Inch5thGeneration
    case iPadPro129Inch6thGeneration
    case iPadPro97Inch
    case iPadMini
    case iPadMini5thGeneration
    case iPadMini6thGeneration
    case iPadMini2
    case iPadMini3
    case iPadMini4
    case iPhone11
    case iPhone11Pro
    case iPhone11ProMax
    case iPhone12
    case iPhone12Pro
    case iPhone12ProMax
    case iPhone12Mini
    case iPhone13
    case iPhone13Pro
    case iPhone13ProMax
    case iPhone13Mini
    case iPhone14
    case iPhone14Plus
    case iPhone14Pro
    case iPhone14ProMax
    case iPhone4s
    case iPhone5
    case iPhone5c
    case iPhone5s
    case iPhone6
    case iPhone6Plus
    case iPhone6s
    case iPhone6sPlus
    case iPhone7
    case iPhone7Plus
    case iPhone8
    case iPhone8Plus
    case iPhoneSE1stGeneration
    case iPhoneSE2ndGeneration
    case iPhoneSE3rdGeneration
    case iPhoneX
    case iPhoneXR
    case iPhoneXS
    case iPhoneXSMax
    case iPodTouch
    case iPodTouch6thGeneration
    case iPodTouch7thGeneration
    
    var deviceTypes: Set<DeviceType> {
        switch self {
        case .iPadPro129Inch5thGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad13v10, .iPad13v11, .iPad13v8, .iPad13v9)
        case .iPadAir5thGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad13v16, .iPad13v17)
        case .iPadPro11Inch3rdGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad13v4, .iPad13v5, .iPad13v6, .iPad13v7)
        case .iPadMini5thGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad11v1, .iPad11v2)
        case .iPadAir3rdGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad11v3, .iPad11v4)
        case .iPad8thGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad11v6, .iPad11v7)
        case .iPhoneXS:
            return Set<DeviceType>(arrayLiteral: .iPhone11v2)
        case .iPhoneXSMax:
            return Set<DeviceType>(arrayLiteral: .iPhone11v4, .iPhone11v6)
        case .iPhoneXR:
            return Set<DeviceType>(arrayLiteral: .iPhone11v8)
        case .iPad9thGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad12v1, .iPad12v2)
        case .iPhone11:
            return Set<DeviceType>(arrayLiteral: .iPhone12v1)
        case .iPhone11Pro:
            return Set<DeviceType>(arrayLiteral: .iPhone12v3)
        case .iPhone11ProMax:
            return Set<DeviceType>(arrayLiteral: .iPhone12v5)
        case .iPhoneSE2ndGeneration:
            return Set<DeviceType>(arrayLiteral: .iPhone12v8)
        case .iPadAir4thGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad13v1, .iPad13v2)
        case .iPad10thGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad13v18, .iPad13v19)
        case .iPhone12Mini:
            return Set<DeviceType>(arrayLiteral: .iPhone13v1)
        case .iPhone12:
            return Set<DeviceType>(arrayLiteral: .iPhone13v2)
        case .iPhone12Pro:
            return Set<DeviceType>(arrayLiteral: .iPhone13v3)
        case .iPhone12ProMax:
            return Set<DeviceType>(arrayLiteral: .iPhone13v4)
        case .iPadMini6thGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad14v1, .iPad14v2)
        case .iPhone13Pro:
            return Set<DeviceType>(arrayLiteral: .iPhone14v2)
        case .iPhone13ProMax:
            return Set<DeviceType>(arrayLiteral: .iPhone14v3)
        case .iPhone13Mini:
            return Set<DeviceType>(arrayLiteral: .iPhone14v4)
        case .iPhone13:
            return Set<DeviceType>(arrayLiteral: .iPhone14v5)
        case .iPhoneSE3rdGeneration:
            return Set<DeviceType>(arrayLiteral: .iPhone14v6)
        case .iPhone14:
            return Set<DeviceType>(arrayLiteral: .iPhone14v7)
        case .iPhone14Plus:
            return Set<DeviceType>(arrayLiteral: .iPhone14v8)
        case .iPadPro11Inch4thGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad14v3, .iPad14v3, .iPad14v4, .iPad14v4)
        case .iPadPro129Inch6thGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad14v5, .iPad14v5, .iPad14v6, .iPad14v6)
        case .iPad5thGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad6v11, .iPad6v11, .iPad6v12, .iPad6v12)
        case .iPhone6s:
            return Set<DeviceType>(arrayLiteral: .iPhone8v1, .iPhone8v1)
        case .iPhone6sPlus:
            return Set<DeviceType>(arrayLiteral: .iPhone8v2, .iPhone8v2)
        case .iPhoneSE1stGeneration:
            return Set<DeviceType>(arrayLiteral: .iPhone8v4, .iPhone8v4)
        case .iPadPro97Inch:
            return Set<DeviceType>(arrayLiteral: .iPad6v3, .iPad6v4)
        case .iPadPro129Inch:
            return Set<DeviceType>(arrayLiteral: .iPad6v7, .iPad6v8)
        case .iPadPro129Inch2ndGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad7v1, .iPad7v2)
        case .iPadPro105Inch:
            return Set<DeviceType>(arrayLiteral: .iPad7v3, .iPad7v4)
        case .iPad7thGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad7v11, .iPad7v12)
        case .iPad6thGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad7v5, .iPad7v6)
        case .iPhone7:
            return Set<DeviceType>(arrayLiteral: .iPhone9v1, .iPhone9v3)
        case .iPhone7Plus:
            return Set<DeviceType>(arrayLiteral: .iPhone9v2, .iPhone9v4)
        case .iPodTouch7thGeneration:
            return Set<DeviceType>(arrayLiteral: .iPod9v1)
        case .iPadPro11Inch:
            return Set<DeviceType>(arrayLiteral: .iPad8v1, .iPad8v2, .iPad8v3, .iPad8v4)
        case .iPadPro11Inch2ndGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad8v10, .iPad8v9)
        case .iPadPro129Inch4thGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad8v11, .iPad8v12)
        case .iPadPro129Inch3rdGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad8v5, .iPad8v6, .iPad8v7, .iPad8v8)
        case .iPhone8:
            return Set<DeviceType>(arrayLiteral: .iPhone10v1, .iPhone10v4)
        case .iPhone8Plus:
            return Set<DeviceType>(arrayLiteral: .iPhone10v2, .iPhone10v5)
        case .iPhoneX:
            return Set<DeviceType>(arrayLiteral: .iPhone10v3, .iPhone10v6)
        case .iPhone14Pro:
            return Set<DeviceType>(arrayLiteral: .iPhone15v2)
        case .iPhone14ProMax:
            return Set<DeviceType>(arrayLiteral: .iPhone15v3)
        case .iPad2:
            return Set<DeviceType>(arrayLiteral: .iPad2v1, .iPad2v2, .iPad2v3, .iPad2v4)
        case .iPhone4s:
            return Set<DeviceType>(arrayLiteral: .iPhone4v1)
        case .iPadMini:
            return Set<DeviceType>(arrayLiteral: .iPad2v5, .iPad2v6, .iPad2v7)
        case .iPodTouch:
            return Set<DeviceType>(arrayLiteral: .iPod5v1)
        case .iPad3rdGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad3v1, .iPad3v2, .iPad3v3)
        case .iPad4thGeneration:
            return Set<DeviceType>(arrayLiteral: .iPad3v4, .iPad3v5, .iPad3v6)
        case .iPadAir:
            return Set<DeviceType>(arrayLiteral: .iPad4v1, .iPad4v2, .iPad4v3)
        case .iPadMini2:
            return Set<DeviceType>(arrayLiteral: .iPad4v4, .iPad4v5, .iPad4v6)
        case .iPadMini3:
            return Set<DeviceType>(arrayLiteral: .iPad4v7, .iPad4v8, .iPad4v9)
        case .iPhone5s:
            return Set<DeviceType>(arrayLiteral: .iPhone6v1, .iPhone6v2)
        case .iPadMini4:
            return Set<DeviceType>(arrayLiteral: .iPad5v1, .iPad5v2)
        case .iPhone6Plus:
            return Set<DeviceType>(arrayLiteral: .iPhone7v1)
        case .iPhone6:
            return Set<DeviceType>(arrayLiteral: .iPhone7v2)
        case .iPodTouch6thGeneration:
            return Set<DeviceType>(arrayLiteral: .iPod7v1)
        case .iPadAir2:
            return Set<DeviceType>(arrayLiteral: .iPad5v3, .iPad5v4)
        case .iPhone5:
            return Set<DeviceType>(arrayLiteral: .iPhone5v1, .iPhone5v2)
        case .iPhone5c:
            return Set<DeviceType>(arrayLiteral: .iPhone5v3, .iPhone5v4)
        }
    }
    
    var description: String {
        switch self {
        case .iPadPro129Inch5thGeneration:
            return "iPad Pro (12.9-inch) (5th generation)"
        case .iPadAir5thGeneration:
            return "iPad Air (5th generation)"
        case .iPadPro11Inch3rdGeneration:
            return "iPad Pro (11-inch) (3rd generation)"
        case .iPadMini5thGeneration:
            return "iPad mini (5th generation)"
        case .iPadAir3rdGeneration:
            return "iPad Air (3rd generation)"
        case .iPad8thGeneration:
            return "iPad (8th generation)"
        case .iPhoneXS:
            return "iPhone XS"
        case .iPhoneXSMax:
            return "iPhone XS Max"
        case .iPhoneXR:
            return "iPhone XR"
        case .iPad9thGeneration:
            return "iPad (9th generation)"
        case .iPhone11:
            return "iPhone 11"
        case .iPhone11Pro:
            return "iPhone 11 Pro"
        case .iPhone11ProMax:
            return "iPhone 11 Pro Max"
        case .iPhoneSE2ndGeneration:
            return "iPhone SE (2nd generation)"
        case .iPadAir4thGeneration:
            return "iPad Air (4th generation)"
        case .iPad10thGeneration:
            return "iPad (10th generation)"
        case .iPhone12Mini:
            return "iPhone 12 mini"
        case .iPhone12:
            return "iPhone 12"
        case .iPhone12Pro:
            return "iPhone 12 Pro"
        case .iPhone12ProMax:
            return "iPhone 12 Pro Max"
        case .iPadMini6thGeneration:
            return "iPad mini (6th generation)"
        case .iPhone13Pro:
            return "iPhone 13 Pro"
        case .iPhone13ProMax:
            return "iPhone 13 Pro Max"
        case .iPhone13Mini:
            return "iPhone 13 mini"
        case .iPhone13:
            return "iPhone 13"
        case .iPhoneSE3rdGeneration:
            return "iPhone SE (3rd generation)"
        case .iPhone14:
            return "iPhone 14"
        case .iPhone14Plus:
            return "iPhone 14 Plus"
        case .iPadPro11Inch4thGeneration:
            return "iPad Pro (11-inch) (4th generation)"
        case .iPadPro129Inch6thGeneration:
            return "iPad Pro (12.9-inch) (6th generation)"
        case .iPad5thGeneration:
            return "iPad (5th generation)"
        case .iPhone6s:
            return "iPhone 6s"
        case .iPhone6sPlus:
            return "iPhone 6s Plus"
        case .iPhoneSE1stGeneration:
            return "iPhone SE (1st generation)"
        case .iPadPro97Inch:
            return "iPad Pro (9.7-inch)"
        case .iPadPro129Inch:
            return "iPad Pro (12.9-inch)"
        case .iPadPro129Inch2ndGeneration:
            return "iPad Pro (12.9-inch) (2nd generation)"
        case .iPadPro105Inch:
            return "iPad Pro (10.5-inch)"
        case .iPad7thGeneration:
            return "iPad (7th generation)"
        case .iPad6thGeneration:
            return "iPad (6th generation)"
        case .iPhone7:
            return "iPhone 7"
        case .iPhone7Plus:
            return "iPhone 7 Plus"
        case .iPodTouch7thGeneration:
            return "iPod touch (7th generation)"
        case .iPadPro11Inch:
            return "iPad Pro (11-inch)"
        case .iPadPro11Inch2ndGeneration:
            return "iPad Pro (11-inch) (2nd generation)"
        case .iPadPro129Inch4thGeneration:
            return "iPad Pro (12.9-inch) (4th generation)"
        case .iPadPro129Inch3rdGeneration:
            return "iPad Pro (12.9-inch) (3rd generation)"
        case .iPhone8:
            return "iPhone 8"
        case .iPhone8Plus:
            return "iPhone 8 Plus"
        case .iPhoneX:
            return "iPhone X"
        case .iPhone14Pro:
            return "iPhone 14 Pro"
        case .iPhone14ProMax:
            return "iPhone 14 Pro Max"
        case .iPad2:
            return "iPad 2"
        case .iPhone4s:
            return "iPhone 4S"
        case .iPadMini:
            return "iPad mini"
        case .iPodTouch:
            return "iPod touch"
        case .iPad3rdGeneration:
            return "iPad (3rd generation)"
        case .iPad4thGeneration:
            return "iPad (4th generation)"
        case .iPadAir:
            return "iPad Air"
        case .iPadMini2:
            return "iPad mini 2"
        case .iPadMini3:
            return "iPad mini 3"
        case .iPhone5s:
            return "iPhone 5s"
        case .iPadMini4:
            return "iPad mini 4"
        case .iPhone6Plus:
            return "iPhone 6 Plus"
        case .iPhone6:
            return "iPhone 6"
        case .iPodTouch6thGeneration:
            return "iPod touch (6th generation)"
        case .iPadAir2:
            return "iPad Air 2"
        case .iPhone5:
            return "iPhone 5"
        case .iPhone5c:
            return "iPhone 5c"
        }
    }
}

extension DeviceDescription {
    var orLater: Set<DeviceDescription> {
        guard let minimumDeviceType = deviceTypes.min() else {
            return Set<DeviceDescription>()
        }

        let minimumDeviceTypes = DeviceType.allTypes.filter { $0 >= minimumDeviceType }
        return Set<DeviceDescription>(minimumDeviceTypes.compactMap(\.deviceDescription))
    }
}

// @available(iOS 16.0, *)
// extension DeviceType {
//    static let regularExpression = /\A(iPhone|iPad|iPod)(\d{1,2})\,(\d{1,2})\z/
//
//    init?(_ string: String) {
//        guard let output = string.firstMatch(of: DeviceType.regularExpression)?.output,
//              let major = Int(output.2),
//              let minor = Int(output.3) else {
//            return nil
//        }
//
//        switch output.1 {
//        case "iPhone":
//            self = DeviceType.iPhone(major, minor)
//        case "iPad":
//            self = DeviceType.iPad(major, minor)
//        case "iPod":
//            self = DeviceType.iPod(major, minor)
//        default:
//            return nil
//        }
//    }
// }

extension DeviceType {
    static let regularExpressionPattern = "\\A(iPhone|iPad|iPod)(\\d{1,2})\\,(\\d{1,2})\\z"

    init?(_ string: String) {
        guard let regularExpression = try? NSRegularExpression(pattern: DeviceType.regularExpressionPattern, options: []) else {
            return nil
        }
        
        let matches = regularExpression.matches(in: string, range: NSMakeRange(0, string.count))
        
        guard matches.count == 1,
              let match = matches.first,
              match.numberOfRanges == 4 else {
            return nil
        }
        
        guard let modelRange = Range(match.range(at: 1), in: string),
              let majorRange = Range(match.range(at: 2), in: string),
              let minorRange = Range(match.range(at: 3), in: string) else {
            return nil
        }
        
        let model = string[modelRange]

        guard let major = Int(string[majorRange]),
              let minor = Int(string[minorRange]) else {
            return nil
        }

        switch model {
        case "iPhone":
            self = DeviceType.iPhone(major, minor)
        case "iPad":
            self = DeviceType.iPad(major, minor)
        case "iPod":
            self = DeviceType.iPod(major, minor)
        default:
            return nil
        }
    }
}
