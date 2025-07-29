// swift-tools-version:5.5
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
            url: "https://github.com/autobooks/autobooks-ios/raw/2.0.2/ZippedFrameworks/Autobooks.xcframework.zip",
            checksum: "e90a5c5a5aaedc000cafad2c234f069d1f30cffab1ef49157a0d27ac874bbb10"
        ),
        // Fiserv-only version that does NOT require triPOSMobileSDK
        .binaryTarget(
            name: "Autobooks-FiservOnly",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.0.2/ZippedFrameworks/Autobooks-FiservOnly.xcframework.zip",
            checksum: "bf20a9b9172c61408cf837578f2e19115f6b5e4d73ec11bb3f9575305652aa93"
        ),
        // triPOS dependency for Autobooks
        .binaryTarget(
            name: "triPOSMobileSDK",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.0.2/ZippedFrameworks/triPOSMobileSDK.xcframework.zip",
            checksum: "c9ee95e2d4bcd97d89a835f759a815dc8c8ca5b5188453238025bc6b540a3498"
        )
    ]
)