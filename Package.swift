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
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.1/ZippedFrameworks/Autobooks.xcframework.zip",
            checksum: "db9993aff9f7c14dbe6a193bff4a43aca3f9de4275e4c95cd32e1daf45e4329d"
        ),
        // Fiserv-only version that does NOT require triPOSMobileSDK
        .binaryTarget(
            name: "Autobooks-FiservOnly",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.1/ZippedFrameworks/Autobooks-FiservOnly.xcframework.zip",
            checksum: "e78d1df6e90f7b063bdac281239a6e2c1ff9ab837eaeb33db12fabc5eb7e50b7"
        ),
        // triPOS dependency for Autobooks
        .binaryTarget(
            name: "triPOSMobileSDK",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.1/ZippedFrameworks/triPOSMobileSDK.xcframework.zip",
            checksum: "6e526e7efdead15b7ce15be2a9aaaf78d55889cb856e09be98603c4d71afce3f"
        ),
    ]
)
