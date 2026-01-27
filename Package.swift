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
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.4/ZippedFrameworks/Autobooks.xcframework.zip",
            checksum: "dcc7e670177d98cc13dd9651ac852f9ee85ab164868b00f2be85d43b2130ecac"
        ),
        // Fiserv-only version that does NOT require triPOSMobileSDK
        .binaryTarget(
            name: "Autobooks-FiservOnly",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.4/ZippedFrameworks/Autobooks-FiservOnly.xcframework.zip",
            checksum: "7a30c747b08aec258d409d0fbf4f0616586e89759583b76ae78e16e0ad3e1d9b"
        ),
        // triPOS dependency for Autobooks
        .binaryTarget(
            name: "triPOSMobileSDK",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.4/ZippedFrameworks/triPOSMobileSDK.xcframework.zip",
            checksum: "e9debc67a8893a488e475b76913e3824cb9748bc4c7bf08f438d1edb1ce4b83f"
        ),
    ]
)
