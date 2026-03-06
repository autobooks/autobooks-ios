# Changelog

All notable changes to the Autobooks iOS SDK.

## [2.3.6-RC2] - 2026-03-06
Rebuilt with Xcode 16.4 (Swift 6.1.2). Same source as RC1.

## [2.3.6-RC1] - 2026-03-05
- Fix VTP singleton double-deinit race when reinvoking `makeTapToPayController()`
- Handle VTP "already initialized" (error 26) gracefully on reinvocation
- Fix `disableDuplicateDetection` permanently stuck after first `makeTapToPayController()` call
- Remove `EXCLUDED_ARCHS` for arm64 simulator builds
- Updated triPOS to v5.2.2

## [2.3.5] - 2026-02-25
- Updated triPOS SDK to v5.2.2 (from v4.x) to investigate double-deinit race
- Disabled triPOS card input retries to fix cancel re-presentation bug
- Added UI automation test suite and unit tests

## [2.3.4] - 2026-01-26
- Fixed a bug that presented users with an error when canceling a transaction midstream

## [2.3.3] - 2025-11-26
- Rebuilt frameworks with Xcode 16.4 for partner compatibility
- No code changes from 2.3.2 -- build tooling only

## [2.3.2] - 2025-11-26
- Fixed triPOSMobileSDK checksum in Package.swift for SPM
- No code changes from 2.3.1 -- packaging fix only

## [2.3.1] - 2025-11-26
- Lowered minimum deployment target from iOS 16.7 to iOS 16.0

## [2.3.0] - 2025-11-26
- Updated Fiserv SDK and Tap to Pay dependencies
- Fixed double navigation headers in web-based SDK content
- Minimum SDK requirement: iOS 16.7 (lowered to 16.0 in 2.3.1)
- swift-tools-version bumped from 5.5 to 5.9

## [2.0.4] - 2025-08-04
- `makeTapToPayController()` now globally disables duplicate instance detection

## [2.0.3] - 2025-07-29
- Fixed swift-tools-version regression: 5.3 -> 5.5 (2.0.2 reverted the 2.0.1 fix)
- No framework binary changes -- Package.swift only

## [2.0.2] - 2025-07-21
- Added arm64 simulator slice (changed `ios-x86_64-simulator` to `ios-arm64_x86_64-simulator`)
- swift-tools-version reverted to 5.3 (regression, fixed in 2.0.3)

## [2.0.1] - 2025-04-28
- Fixed swift-tools-version: 5.3 -> 5.5 on 2.0.0
- No framework binary changes -- Package.swift only

## [2.0.0] - 2025-04-14
### New Features
- **Item Lists & Shopping Carts** in Tap to Pay
  - Save & reuse items
  - Multi-item carts with automatic totaling
  - Cart state preserved across tap and manual entry flows
  - Simple item management interface
- SwiftData integration for item persistence
- Minimum deployment target raised to iOS 15.0
- SPM support (introduced in 1.12.1)
### Bug Fixes
- Bug fixes and performance improvements

## [1.12.1] - 2025-02-17
- Added Swift Package Manager (SPM) support via `Package.swift`
- Both `Autobooks` and `Autobooks-FiservOnly` available as SPM binary targets

## [1.10.1] - 2024-09-24
- Fixed iPhone 16 compatibility issue (could not access Tap to Pay)
- Vendored PhoneNumberKit 3.8.0
- Improved security: masked accessToken in console logs

## [1.10.0] - 2024-08-30
- **Text a Receipt** -- send receipt link via text message
- Refactored environment configuration (AB.Device/DeviceMode/BackendEnvironment -> AB.Mode)
- Duplicate SDK instance protection
- Virtual terminal URL support
- Locale-aware amount parsing

## [1.8.1] - 2024-04-22
- Updated triPOS SDK to v4.0.2 (includes Apple-required privacy manifest)

## [1.8.0] - 2024-04-18
- **Sales Tax** support for Tap to Pay transactions
- Worldpay Terminal Profile ID fix (use TPIDs from gatewayConfig)
- Updated Worldpay and Fiserv SDKs

## [1.7.2] - 2024-04-17
- Introduced **Fiserv-only SDK variant** (`Autobooks-FiservOnly.xcframework`)
- Fixed Fiserv invalid amount handling for sub-cent values (e.g., $1.333)
- Worldpay Terminal Profile ID fix (use TPIDs from gatewayConfig)

## [1.7.1] - 2024-04-18
- Intermediate build, superseded by 1.7.2 with additional bug fixes

## [1.7.0] - 2024-03-14
### New Features
- **Tipping** -- merchants can receive tips directly in Tap to Pay
- **Settings** screen within the SDK
- Renamed "Transactions" to "Payments" throughout the UI
### Improvements
- Payment Successful/Details screens now scroll
- Payment amounts preserved after cancellation
- Updated Worldpay SDK (triPOS Mobile SDK 4.0.1)
- Deprecated large navigation bar titles
- Segment and Sovran moved from vendored frameworks to packages
- Privacy manifest added
- Bug fixes and performance improvements

## [1.6.4] - 2024-02-26
- Fixed `AB.stop()` to properly force SDK shutdown

## [1.6.3] - 2024-01-23
- Improved first-time user onboarding flow (increased wait messaging from 30s to 5min)
- Improved proximity reader reconnection after host app is backgrounded

## [1.6.2] - 2024-01-15
- Fixed session loss during a connectivity edge case
- Fiserv: Properly orders session initialization/linking
- Fiserv: Session preparation errors now surface in shared log
- Fiserv: Backported 1.7 fix for reader reinitialization on backgrounding

## [1.6.1] - 2023-11-20
- Links in web-based SDK content now open outside the host application
- Support for `blob` and `data` URLs for file downloads

## [1.6.0] - 2023-11-09
- Complete decline code handling overhaul
- User-facing error descriptions for payment failures
- Network reachability checks
- Analytics event tracking overhaul
- Support deep links
- Full-screen modal presentation
- Production CDN integration

## [1.5.1] - 2023-10-13
- New user-facing "Diagnostics & Logs" section for support calls
- UIKit/SwiftUI integration improvements

## [1.5.0] - 2023-10-05
- **Fiserv payment processor** support (in addition to existing Worldpay/triPOS)
- Proper decline handling for both processors
- Removed external FiservTTP dependency (vendored internally)

## [1.4.1] - 2023-09-01
- Enhanced Segment analytics tracking
- Added userId to analytics traits
- Improved bundle reference handling

## [1.4.0] - 2023-08-23
- Dynamic proximity reader connection detection
- Prevent reader session expiration on backgrounding
- Auto-refresh bearer tokens on app resume
- Proper singleton cleanup on `stop()`

## [1.3.1] - 2023-08-07
- Fixed crash on `readCancelled` error from ProximityReader
- Loading screen customization
- Icon improvements

## [1.3.0] - 2023-08-03
- Enhanced UI styling and theming
- WebView completion handler support
- Link color customization
- Improved web feature activity detection (XMLHttpRequest keepalives)

## [1.2.1] - 2023-07-28
- Activity notifications for host app timeout management
- Code linting improvements

## [1.2.0] - 2023-07-28
- UI styling overhaul (customizable primary colors, button styles)
- Custom user agent configuration
- Progress view and button tint customization

## [1.1.3] - 2023-06-30
- Tap to Pay minimum raised from iOS 15.4 to iOS 16.0
- Full Autobooks web feature enabled
- Alternate login credential support (SSO tokens)
- Segment and Sovran auto-vendoring
- Fixed unowned self deallocations
- Automatic bundle version synchronization

## [1.1.2] - 2023-06-17
- Updated Segment Analytics SDK
- watchOS simulator support improvements

## [1.1.1] - 2023-06-08
- ABI stability fixes
- Code signing updates

## [1.1.0] - 2023-06-08
- Major architecture refactor
- Minimum iOS raised from 12.0 to 14.0
- Tap to Pay re-enablement
- Removed fastlane, updated build infrastructure

## [1.0.0] - 2022-11-14
- Production environment by default
- Tap to Pay temporarily disabled (payment form web experience instead)
- Will be re-enabled in a future release

## [0.2.0] - 2022-11-02
- Added `subscriptionKey` to public API for web features

## [0.1.0] - 2022
- Initial SDK release
- Store/Reducer architecture
- Tap to Pay (ProximityReader) integration
- Web feature support (Payment Form, Invoicing, Checkout Pages)
- CocoaPods distribution
