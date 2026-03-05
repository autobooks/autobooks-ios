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
            url: "https://github.com/autobooks/autobooks-ios/raw/prerelease/2.3.6/ZippedFrameworks/Autobooks.xcframework.zip",
            checksum: "22e307734b79246e1218836ffa3989ddb69f4aee648be70113229f09e3dcc4cb"
        ),
        // Fiserv-only version that does NOT require triPOSMobileSDK
        .binaryTarget(
            name: "Autobooks-FiservOnly",
            url: "https://github.com/autobooks/autobooks-ios/raw/prerelease/2.3.6/ZippedFrameworks/Autobooks-FiservOnly.xcframework.zip",
            checksum: "fcb814430dea25403070fc95809779c1614c4b47929848929684e6025320d0f9"
        ),
        // triPOS dependency for Autobooks
        .binaryTarget(
            name: "triPOSMobileSDK",
            url: "https://github.com/autobooks/autobooks-ios/raw/prerelease/2.3.6/ZippedFrameworks/triPOSMobileSDK.xcframework.zip",
            checksum: "17a753369e2ebec1b6909831a0912f9a5e9606dbe10fe3f9279877bc77b1c2fa"
        ),
    ]
)
