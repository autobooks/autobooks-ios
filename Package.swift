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
            checksum: "974f58d8d3dce5bb22fae3998a2044039f7e219922191a591ebb1659257b4a42"
        ),
        // Fiserv-only version that does NOT require triPOSMobileSDK
        .binaryTarget(
            name: "Autobooks-FiservOnly",
            url: "https://github.com/autobooks/autobooks-ios/raw/prerelease/2.3.6/ZippedFrameworks/Autobooks-FiservOnly.xcframework.zip",
            checksum: "0c06957f8039db4a1c32738fc616dd8d82fb1fae0cf4e9cfd3a7796533a5d2b5"
        ),
        // triPOS dependency for Autobooks
        .binaryTarget(
            name: "triPOSMobileSDK",
            url: "https://github.com/autobooks/autobooks-ios/raw/prerelease/2.3.6/ZippedFrameworks/triPOSMobileSDK.xcframework.zip",
            checksum: "6b48e54bdd602e7640db9751c518fd1f50f37726456c07aca18591c6df06d4c8"
        ),
    ]
)
