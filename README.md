# Introduction

The Autobooks SDK provides an interface for Apple's ProximityReader framework and various Autobooks web features and API to provide an integrated payment experience for your users. It presents its own standalone UI over that of the embedding app. As such, its architecture is most similar to that of a small app rather than a typical SDK.

# Integration

The Autobooks SDK requires iOS 14 or above with the Tap to Pay feature requiring iOS 15.4 or later and a supported device (iPhone XS or later). To build it requires Xcode 13.4 or later.

### CocoaPods

To integrate using CocoaPods, add the following to your `Podfile`.

```ruby
pod 'Autobooks'
```

Once the SDK is added to your project, you can follow our [integration guide](https://autobooks.github.io/autobooks-ios/documentation/autobooks) and documentation to begin enabling the features in your app.
