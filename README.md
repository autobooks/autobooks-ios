# Introduction

The Autobooks SDK provides an interface for Apple's ProximityReader framework and various Autobooks web features and API to provide an integrated payment experience for your users. It presents its own standalone UI over that of the embedding app. As such, its architecture is most similar to that of a small app rather than a typical SDK.

# Integration

The Autobooks SDK requires iOS 12 or above with the Tap to Pay feature requiring iOS 15.4 or later and a supported device (iPhone XS or later). To build it requires Xcode 13.4 or later.

### Swift Package Manager

To integrate using Swift Package Manager, you can add the following line to your `Package.swift` `dependencies` array or add the URL directly to Xcode's package interface.

```swift
.package(url: "https://github.com/Autobooks/autobooks-ios.git", .upToNextMajor(from: "0.1.0"))
```

### CocoaPods

To integrate using CocoaPods, add the following to your `Podfile`.

```ruby
pod 'Autobooks'
```

Once the SDK is added to your project, you can follow our [integration guide](https://autobooks.github.io/autobooks-ios/documentation/autobooks) and documentation to begin enabling the features in your app.

# Architecture

The Autobooks SDK has no dependencies but implements a much simplified version of the [Swift Composable Architecture](https://github.com/pointfreeco/swift-composable-architecture) (TCA). It follows many of the same principles and has a few of the same types but is much more limited.

### Domains

As in TCA, this SDK uses the term "domain" to group state, action, environment, and reducers. Currently the SDK has only a single domain, `RootDomain`, which contains the state and actions for all screens.

### `Reducer`

As in TCA, this SDK uses a `Reducer` type to process state mutations from actions while producing `Effect`s. Unlike TCA, the SDK's `Reducer` is not built on top of Combine. Instead it simply runs `Effect`s using Swift concurrency.

### `Effect`

As in TCA, this SDK uses an `Effect` type as the return value from `Action`s processed by a `Reducer`. These `Effect`s encapsulate an `async` bit of work, with a `Sender` type captured to send actions back into the `Reducer` if necessary.

### `Store`

As in TCA the `Store` type encapsulates the types within a domain, connecting actions to state mutations and allowing consumers to `send` actions while observing state. Unlike TCA, there is no `ViewStore` type, as the separation of `Store` and `ViewStore` is largely an optimization so far unnecessary in the SDK. As with TCA, the SDK's `Store` type uses Combine under the hood for observations, duplicate removal, and integration into SwiftUI's `StateObject` type.

## User Interface

The Autobooks SDK is almost entirely written using SwiftUI. There are three exceptions. The `SupportedFlowController` is a `UINavigationController` subclass which replaces SwiftUI's unreliable native navigation with direct state observation driving stacks of `UIHostingController`s containing the SwiftUI screens. And the `UnsupportedViewController` is a simple controller the screen shown when a device does not support the Tap to Pay feature, whether due to device limitations or OS version. This is implemented as a view controller due to the need to deploy it before iOS 13. And all web features are implemented in screens wrapping a `WKWebView`.
