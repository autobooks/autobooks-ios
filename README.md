# Autobooks SDK

The Autobooks SDK provides an interface for Apple's ProximityReader framework and various Autobooks web features and API to provide an integrated payment experience for your users. It presents its own standalone UI over that of the embedding app. As such, its architecture is most similar to that of a small app rather than a typical SDK.

## Requirements

### General requirements

* iOS 14+
* Xcode 13.4

### Tap to Pay requirements

* iOS 16+
* Tap to Pay on iPhone entitlement
* A _physical_ iPhone XS or later

## 1. Install the Autobooks SDK

Currently both CocoaPods and manual installs are supported.  Swift Package Manager (SPM) support is coming soon.

### CocoaPods

To integrate using CocoaPods, add the following to your `Podfile`.

```ruby
pod 'Autobooks'
```

### Manual install

1. Download the Autobooks SDK repository.
2. Drag the xcframeworks contained within the `Frameworks` directory into your project, making sure _Copy items if needed_ is checked when Xcode prompts.
3. Drag the xcframeworks that now appear in the Project Navigator into your target's _Frameworks, Libraries, and Embedded Content_ section if necessary.
4. Set the _Embed_ setting to _Embed & Sign_ for each library.


## 2. Set up the entitlement for Tap to Pay on iPhone

You must [set up the Tap to Pay on iPhone Entitlement](https://developer.apple.com/documentation/proximityreader/setting-up-the-entitlement-for-tap-to-pay-on-iphone). To access the request form, you must hold an organization-level Apple Developer account and be logged in as the Account Holder.

## 3. Usage

First, import the Autobooks framework:

```swift
import Autobooks
```

All of the `AB.start*` methods allow passing an `AB.Configuration` value to control various behaviors within the SDK. This includes a custom `primaryColor` as well as various network settings useful for testing or debugging the Autobooks integration.

```swift
    let configuration = AB.Configuration(environment: <#T##AB.BackendEnvironment#>,
                                         primaryColor: <#T##UIColor#>,
                                         responseProvider: <#T##AB.ResponseProvider#>,
                                         shouldFallBackToPaymentForm: <#T##Bool#>)
```

* `environment` specifies where API calls are sent. Options are `.dev`, `.staging`, and `.production`.  The default is `.production`.
* `primaryColor` specifies the control colors, analagous to UIKit's `tintColor` or SwiftUI's `accentColor`.  The default is `.systemBlue`.
* `responseProvider` specifies where responses come from.

  | `AB.BackendEnvironment` | Behavior                                                                                            |
  |-------------------------|-----------------------------------------------------------------------------------------------------|
  | `.stubs(Stubs)`         | Use provided local stubs for all calls. No traffic should go over the network with this setting.    |
  | `.hybrid(Stubs)`        | Use the provided `AB.BackendEnvironment` for login, provided stubs for the rest.                    |
  | `.backendMocked`        | Use the provided `AB.BackendEnvironment` with mocked login endpoint, normal endpoints for the rest. |
  | `.live`                 | Use the provided `AB.BackendEnvironment` for all API calls.                                         |

* `shouldFallBackToPaymentForm` specifies what happens when a user does not meet the iOS version or physical device requirements for a given feature.  If `true`, the user is directed to a web-based virtual terminal.  If `false`, the user receives an error.  The default is `true`.

### Web Features

#### Invoicing
```swift
    AB.startInvoicing(subscriptionKey: <#"your-subscription-key"#>,
                      loginCredential: .token(<#"your-sso-token"#>),
                      configuration: configuration)
```

#### Payment Form
```swift
    AB.startPaymentForm(subscriptionKey: <#"your-subscription-key"#>,
                        loginCredential: .token(<#"your-sso-token"#>)),
                        configuration: configuration)
```

#### Full Autobooks
```swift
    AB.startFullAutobooks(subscriptionKey: <#"your-subscription-key"#>,
                          loginCredential: .token(<#"your-sso-token"#>)),
                          configuration: configuration)
```

### Tap to Pay

```swift
    AB.startTapToPay(subscriptionKey: <#"your-subscription-key"#>,
                     configuration: <#configuration#>,
                     device: <#.real#>) {
        return .token(<#"your-sso-token"#>)
    }
```
