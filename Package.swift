// swift-tools-version:6.0
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
            url: "https://github.com/autobooks/autobooks-ios/raw/2.4.0/ZippedFrameworks/Autobooks.xcframework.zip",
            checksum: "4001b839f9e58c9a51f7ceaf7805bbae871f73759b6a1c5a6c69fe17645ee035"
        ),
        // Fiserv-only version that does NOT require triPOSMobileSDK
        .binaryTarget(
            name: "Autobooks-FiservOnly",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.4.0/ZippedFrameworks/Autobooks-FiservOnly.xcframework.zip",
            checksum: "1a9ed42cb2b7deb44be82665a9f930907fc30cacbf8b0d18e0d08068a2dc662e"
        ),
        // triPOS dependency for Autobooks
        .binaryTarget(
            name: "triPOSMobileSDK",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.4.0/ZippedFrameworks/triPOSMobileSDK.xcframework.zip",
            checksum: "43d360198eba5d2506e03d3ac85d9e9c575ceeb9c51b2ddbdf90e53d1d394c50"
        ),
    ]
)
