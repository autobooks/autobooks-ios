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
            url: "https://github.com/autobooks/autobooks-ios/raw/2.0.4/ZippedFrameworks/Autobooks.xcframework.zip",
            checksum: "6efa5a2605dbcf2ba441d938707c431acb132b283309836821e82ea7e1744a40"
        ),
        // Fiserv-only version that does NOT require triPOSMobileSDK
        .binaryTarget(
            name: "Autobooks-FiservOnly",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.0.4/ZippedFrameworks/Autobooks-FiservOnly.xcframework.zip",
            checksum: "3bf658950ee580a071a523961f56fed0e043d5187216b623807960ffc0ea53e8"
        ),
        // triPOS dependency for Autobooks
        .binaryTarget(
            name: "triPOSMobileSDK",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.0.4/ZippedFrameworks/triPOSMobileSDK.xcframework.zip",
            checksum: "6e526e7efdead15b7ce15be2a9aaaf78d55889cb856e09be98603c4d71afce3f"
        )
    ]
)