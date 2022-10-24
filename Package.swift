// swift-tools-version: 5.6

import PackageDescription

let package = Package(name: "Autobooks",
                      platforms: [.iOS(.v12)],
                      products: [.library(name: "Autobooks",
                                          targets: ["Autobooks"])],
                      dependencies: [],
                      targets: [.target(name: "Autobooks",
                                        path: "Sources",
                                        resources: [.process("Resources")]),
                                .testTarget(name: "AutobooksTests",
                                            dependencies: ["Autobooks"],
                                            path: "Tests")])
