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
            checksum: "ac595de42d0fef550faece6ac863eeed3a8ea668373b012d15bdfad8c8a780a5"
        ),
        // Fiserv-only version that does NOT require triPOSMobileSDK
        .binaryTarget(
            name: "Autobooks-FiservOnly",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.4/ZippedFrameworks/Autobooks-FiservOnly.xcframework.zip",
            checksum: "e257c7340d0c941311a6eaf27931489677a7e39af15c5530c153108a129b1bdc"
        ),
        // triPOS dependency for Autobooks
        .binaryTarget(
            name: "triPOSMobileSDK",
            url: "https://github.com/autobooks/autobooks-ios/raw/2.3.4/ZippedFrameworks/triPOSMobileSDK.xcframework.zip",
            checksum: "b8e519c56068cef94f9683fbd269ec421cb458b00016678e40b3750c069add41"
        ),
    ]
)
