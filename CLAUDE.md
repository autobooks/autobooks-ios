# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Overview

This is the **Autobooks iOS SDK distribution repository**. It distributes pre-built xcframeworks for integrating Autobooks payment features (including Tap to Pay on iPhone) into iOS apps. This is not a source code repository—it contains binary frameworks only.

## Distribution Methods

- **CocoaPods**: via `Autobooks.podspec`
- **Swift Package Manager**: via `Package.swift`
- **Manual install**: drag xcframeworks from `Frameworks/` directory

## Framework Variants

| Framework | Description | Simulator Architectures |
|-----------|-------------|------------------------|
| `Autobooks.xcframework` | Full SDK with Worldpay support (requires triPOSMobileSDK) | x86_64 only |
| `Autobooks-FiservOnly.xcframework` | Smaller SDK without Worldpay | arm64 + x86_64 |
| `Autobooks-Standalone.xcframework` | Standalone variant | x86_64 only |

## Common Commands

### Prepare frameworks for SPM distribution
```bash
./zip.sh
```
This zips all xcframeworks and computes Swift package checksums, outputting to `ZippedFrameworks/`.

### Update version
1. Update version in `Autobooks.podspec`
2. Update URLs and checksums in `Package.swift` (after running `zip.sh`)
3. Tag the release

## Key Files

- `Frameworks/` - Pre-built xcframeworks for manual installation
- `ZippedFrameworks/` - Zipped frameworks with checksums for SPM binary targets
- `Autobooks.podspec` - CocoaPods specification (current version: 2.0.4)
- `Package.swift` - Swift Package Manager manifest

## Requirements

- iOS 16.7+ deployment target (as of 2.3.0)
- Swift 5
- For Tap to Pay: iOS 17.0+, physical iPhone XS or later, Tap to Pay entitlement
