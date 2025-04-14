// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "Autobooks",
    platforms: [.iOS(.v15)],
    products: [
        .library(
            name: "Autobooks",
            targets: ["Autobooks", "triPOSMobileSDK"]
        ),
        .library(
            name: "Autobooks-FiservOnly",
            targets: ["Autobooks-FiservOnly"]
        )
    ],
    targets: [
        // Main Autobooks SDK that requires triPOSMobileSDK
        .binaryTarget(
            name: "Autobooks",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.0.0/ZippedFrameworks/Autobooks.xcframework.zip",
            checksum: "1a07c7176bfc94b93b47643a8083848a6dc0792a07e09872833fd8fbca74ce75"
        ),
        // Fiserv-only version that does NOT require triPOSMobileSDK
        .binaryTarget(
            name: "Autobooks-FiservOnly",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.0.0/ZippedFrameworks/Autobooks-FiservOnly.xcframework.zip",
            checksum: "364bf0758a94c3c1b2e52f75d209dd073bfe58beaf8771e4ecb0bd90699f1bc2"
        ),
        // triPOS dependency for Autobooks
        .binaryTarget(
            name: "triPOSMobileSDK",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.0.0/ZippedFrameworks/triPOSMobileSDK.xcframework.zip",
            checksum: "5d6236920f610cd3aadd2c8a45e65f5c278d05769936ba12fcc5a59929c8fac2"
        )
    ]
)