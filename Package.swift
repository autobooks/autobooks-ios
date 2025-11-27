// swift-tools-version:5.9
import PackageDescription

let package = Package(
    name: "Autobooks",
    platforms: [.iOS(.v16)],
    products: [
        .library(
            name: "Autobooks",
            targets: ["Autobooks", "triPOSMobileSDK"]
        ),
        .library(
            name: "Autobooks-FiservOnly",
            targets: ["Autobooks-FiservOnly"]
        ),
    ],
    targets: [
        // Main Autobooks SDK that requires triPOSMobileSDK
        .binaryTarget(
            name: "Autobooks",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.3/ZippedFrameworks/Autobooks.xcframework.zip",
            checksum: "b676ec48158cdced156655cd65fcfa13943e55e046a820774247e1440b28e5ea"
        ),
        // Fiserv-only version that does NOT require triPOSMobileSDK
        .binaryTarget(
            name: "Autobooks-FiservOnly",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.3/ZippedFrameworks/Autobooks-FiservOnly.xcframework.zip",
            checksum: "4fdcdc7ba85f7cbd5c6bc41e36e6fd9bec1b48e5c54dba0de0b591250073dc91"
        ),
        // triPOS dependency for Autobooks
        .binaryTarget(
            name: "triPOSMobileSDK",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.3/ZippedFrameworks/triPOSMobileSDK.xcframework.zip",
            checksum: "4803af65e09a9a91b38a18f53abd64d5b6571c03c53db24f03dfbe85fc3d47bd"
        ),
    ]
)
