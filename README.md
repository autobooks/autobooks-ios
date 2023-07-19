# Autobooks SDK

The Autobooks SDK provides an interface for Apple's ProximityReader framework and various Autobooks web features and API to provide an integrated payment experience for your users. It presents its own standalone UI over that of the embedding app. As such, its architecture is most similar to that of a small app rather than a typical SDK.

## Requirements

### Minimum requirements

* iOS 14+
* Xcode 13.4

Additionally, a US-based IP address may be required to connect to the Autobooks SDK backend.

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

All of the `AB.start*` methods allow passing an `AB.Configuration` value to control various behaviors within the SDK. This includes a custom `AB.Style` as well as various network settings useful for testing or debugging the Autobooks integration.

```swift
    let configuration = AB.Configuration(environment: <#T##BackendEnvironment#>,
                                        style: <#T##Style#>,
                                        responseProvider: <#T##ResponseProvider#>,
                                        shouldFallBackToPaymentForm: <#T##Bool#>,
                                        shouldConfirmClose: <#T##Bool#>,
                                        closeButtonStyle: <#T##CloseButtonStyle#>,
                                        webViewsShowControls: <#T##Bool#>)
```

* `environment` specifies where API calls are sent. Options are `.dev`, `.staging`, and `.production`.  The default is `.production`.
* `style` specifies a structure for display customization.  See the section _Styling_ below for more information.
* `responseProvider` specifies where responses come from.

  | `AB.BackendEnvironment` | Behavior                                                                                            |
  |-------------------------|-----------------------------------------------------------------------------------------------------|
  | `.stubs(Stubs)`         | Use provided local stubs for all calls. No traffic should go over the network with this setting.    |
  | `.hybrid(Stubs)`        | Use the provided `AB.BackendEnvironment` for login, provided stubs for the rest.                    |
  | `.backendMocked`        | Use the provided `AB.BackendEnvironment` with mocked login endpoint, normal endpoints for the rest. |
  | `.live`                 | Use the provided `AB.BackendEnvironment` for all API calls.                                         |

* `shouldFallBackToPaymentForm` controls what happens when a user does not meet the iOS version or physical device requirements for a given feature.  If `true`, the user is directed to a web-based virtual terminal.  If `false`, the user receives an error.  The default is `true`.
* `shouldConfirmClose` specifies whether a confirmation is presented to the user before dismissing the SDK interface.  The default is `false`.
* `closeButtonStyle` controls the text displayed to the user to dismiss the SDK. If `.close`, the text is "Close".  If `.signOut`, the text is "Sign Out".  The default is `.close`.
* `webViewsShowControls` controls whether the web features, outlined below, have a back/forward/share/refresh toolbar below web content, similar to `SFSafariViewController`.

### Styling

The `AB.Style` structure is the primary method for customizing the look of SDK interfaces.

```swift
    let style = AB.Style(primaryColor: <#T##UIColor#>,
                         actionButtonColor: <#T##UIColor?#>,
                         secondaryButtonColor: <#T##UIColor?#>,
                         tertiaryButtonColor: <#T##UIColor?#>,
                         navigationBarAppearance: <#T##UINavigationBarAppearance?#>)

```

There is one required argument, the `primaryColor`, which will be used to tint UI controls, analagous to UIKit's `tintColor` or SwiftUI's `accentColor`.  The default is `.systemBlue`.  The remaining arguments are optional but will override the `primaryColor` if supplied:

* `actionButtonColor` applies to action buttons, e.g. 

The `navigationBarAppearance` object is the only non-`UIColor` argument and is used for styling SDK `UINavigationBar`s.  It is passed unmodified to the navigation bar's `standardAppearance` property; if unset, the default is constructed like so:

```swift
    let customAppearance = UINavigationBarAppearance()
    customAppearance.configureWithDefaultBackground()

    let barButtonItemAppearance = UIBarButtonItemAppearance(style: .plain)
    barButtonItemAppearance.normal.titleTextAttributes = [.foregroundColor: style.primaryColor]
    barButtonItemAppearance.disabled.titleTextAttributes = [.foregroundColor: style.primaryColor]
    barButtonItemAppearance.highlighted.titleTextAttributes = [.foregroundColor: style.primaryColor]
    barButtonItemAppearance.focused.titleTextAttributes = [.foregroundColor: style.primaryColor]

    customAppearance.buttonAppearance = barButtonItemAppearance
    customAppearance.backButtonAppearance = barButtonItemAppearance
    customAppearance.doneButtonAppearance = barButtonItemAppearance

    navigationBar.standardAppearance = customAppearance
```

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

Check the value of the `AB.supportsTapToPay` property to determine if the device meets the minimum requirements for Tap to Pay, then call:

```swift
    AB.startTapToPay(subscriptionKey: <#"your-subscription-key"#>,
                     configuration: <#configuration#>,
                     device: <#.real#>) {
        return .token(<#"your-sso-token"#>)
    }
```
