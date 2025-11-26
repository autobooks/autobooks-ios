// swift-tools-version:5.9
import PackageDescription

let package = Package(
    name: "Autobooks",
    platforms: [.iOS("16.7")],
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
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.0/ZippedFrameworks/Autobooks.xcframework.zip",
            checksum: "5a4396ddcec9cdf1c6bc4311dc3636df352f1e669dfce87f4b44e54ed6ab7079"
        ),
        // Fiserv-only version that does NOT require triPOSMobileSDK
        .binaryTarget(
            name: "Autobooks-FiservOnly",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.0/ZippedFrameworks/Autobooks-FiservOnly.xcframework.zip",
            checksum: "5fe11afd36c31cc560db9fc811e6cefe3a8b4fe6fa22c01c9fa1cc35fea9c06b"
        ),
        // triPOS dependency for Autobooks
        .binaryTarget(
            name: "triPOSMobileSDK",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.0/ZippedFrameworks/triPOSMobileSDK.xcframework.zip",
            checksum: "6e526e7efdead15b7ce15be2a9aaaf78d55889cb856e09be98603c4d71afce3f"
        ),
    ]
)
