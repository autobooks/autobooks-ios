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
            checksum: "6b586624b9c6b8895cd1ed7a0b8251c931b5609a5819d531cc3183e388ebcbcf"
        ),
        // Fiserv-only version that does NOT require triPOSMobileSDK
        .binaryTarget(
            name: "Autobooks-FiservOnly",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.4/ZippedFrameworks/Autobooks-FiservOnly.xcframework.zip",
            checksum: "5b283b68385cca7a15bfd5f7326090c885c819eb5d770fdb71ee60d095d7fa29"
        ),
        // triPOS dependency for Autobooks
        .binaryTarget(
            name: "triPOSMobileSDK",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.4/ZippedFrameworks/triPOSMobileSDK.xcframework.zip",
            checksum: "01d5dd031a35611c99b9430a2df207176e41ba75badd5ca256be79ae1285b4a3"
        ),
    ]
)
