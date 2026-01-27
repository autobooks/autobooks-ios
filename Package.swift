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
            checksum: "37ebecf04a8b2d2c78b929e4be659672c80ca8ec0d6a8676365efd931206b682"
        ),
        // Fiserv-only version that does NOT require triPOSMobileSDK
        .binaryTarget(
            name: "Autobooks-FiservOnly",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.4/ZippedFrameworks/Autobooks-FiservOnly.xcframework.zip",
            checksum: "b3f466a2fe5c79ae658ea93308054b94d1639981dd929d2dd586f2e4a32694c6"
        ),
        // triPOS dependency for Autobooks
        .binaryTarget(
            name: "triPOSMobileSDK",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.4/ZippedFrameworks/triPOSMobileSDK.xcframework.zip",
            checksum: "76eb88e0c324ddc0f69481e86c562448eea94754f3eaccf79be343962951e2fa"
        ),
    ]
)
