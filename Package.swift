// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "Autobooks",
    platforms: [.iOS(.v14)],
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
            url: "https://github.com/autobooks/autobooks-ios/raw/1.12.1/ZippedFrameworks/Autobooks.xcframework.zip",
            checksum: "e6c17936604f9913b74a1a154208f3d3cec02d722dad833615c2211e8f69965e"
        ),
        // Fiserv-only version that does NOT require triPOSMobileSDK
        .binaryTarget(
            name: "Autobooks-FiservOnly",
            url: "https://github.com/autobooks/autobooks-ios/raw/1.12.1/ZippedFrameworks/Autobooks-FiservOnly.xcframework.zip",
            checksum: "3e0f6c6ac595aeb27caeb0db558f58bf788125a348fdc97853854d98344e276c"
        ),
        // triPOS dependency for Autobooks
        .binaryTarget(
            name: "triPOSMobileSDK",
            url: "https://github.com/autobooks/autobooks-ios/raw/1.12.1/ZippedFrameworks/triPOSMobileSDK.xcframework.zip",
            checksum: "b221e6b05bf75f5fa928149c5b691316ab4c1cdd55d158d747eec7a0095b72b0"
        )
    ]
)