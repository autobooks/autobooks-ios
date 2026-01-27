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
            checksum: "c76f01a19652501a603d8e0ac1fe16b76b238b11f043424a9f412b0a17ee0d12"
        ),
        // Fiserv-only version that does NOT require triPOSMobileSDK
        .binaryTarget(
            name: "Autobooks-FiservOnly",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.4/ZippedFrameworks/Autobooks-FiservOnly.xcframework.zip",
            checksum: "d91de6790b331b86ab18678ca2fb8379163b947ac33060952b9125a528a14441"
        ),
        // triPOS dependency for Autobooks
        .binaryTarget(
            name: "triPOSMobileSDK",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.4/ZippedFrameworks/triPOSMobileSDK.xcframework.zip",
            checksum: "03175ee68d3a9a70a166b2787bc56f47a621dbe14457da463ec74fd07a6f4fc6"
        ),
    ]
)
