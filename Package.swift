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
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.5/ZippedFrameworks/Autobooks.xcframework.zip",
            checksum: "215629ce2b47cdec9ed0325525c269b13f0ea204821f81a2f97b4d1d39eb9ae5"
        ),
        // Fiserv-only version that does NOT require triPOSMobileSDK
        .binaryTarget(
            name: "Autobooks-FiservOnly",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.5/ZippedFrameworks/Autobooks-FiservOnly.xcframework.zip",
            checksum: "a8d71e80c8096cfd7a8babb45cf248de2ef52960b5e0e518c037d6fe641cd897"
        ),
        // triPOS dependency for Autobooks
        .binaryTarget(
            name: "triPOSMobileSDK",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.5/ZippedFrameworks/triPOSMobileSDK.xcframework.zip",
            checksum: "b75521de3457bb498d3195b26bc1838180a9607c673560ddd6ceacc9113dda6c"
        ),
    ]
)
