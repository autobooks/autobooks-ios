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

### Configuration

All of the `AB.start*` methods allow passing an `AB.Configuration` value to control various behaviors within the SDK. This includes a custom `AB.Style` as well as various network settings useful for testing or debugging the Autobooks integration.

```swift
    let configuration = AB.Configuration(environment: <#T##BackendEnvironment#>,
                                        style: <#T##Style#>,
                                        responseProvider: <#T##ResponseProvider#>,
                                        shouldFallBackToPaymentForm: <#T##Bool#>,
                                        shouldConfirmClose: <#T##Bool#>,
                                        shouldCloseOnAPIError: <#T##Bool#>,
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
* `shouldCloseOnAPIError` dismisses the SDK interface when encountering 401 and 403 HTTP errors; in other words, it treats these as unrecoverable.  400-level errors should not happen in normal usage as the token is continually refreshed via the `loginProvider`, but this option can be useful for debugging, or to avoid a "Something Went Wrong" screen and provide your own messaging on failure.  The `AB.DismissalReason` returned will be either `.notAuthorized` or `.forbidden`.
* `closeButtonStyle` controls the text displayed to the user to dismiss the SDK. If `.close`, the text is "Close".  If `.signOut`, the text is "Sign Out".  The default is `.close`.
* `webViewsShowControls` controls whether the web features, outlined below, have a back/forward/share/refresh toolbar below web content, similar to `SFSafariViewController`.

### Styling

The `AB.Style` structure is the primary method for customizing the look of SDK interfaces.  The simplest initializer is to set only a `primaryColor`, which will be used to tint UI controls, analagous to UIKit's `tintColor` or SwiftUI's `accentColor`, and will use default `UINavigationBar` and `UIToolbar` classes and settings:

```swift
    let style = AB.Style(primaryColor: <#T##UIColor#>)
```

You can individually override the color for each class of UI element by creating a `AB.Style.Colors` structure.  The default is `.systemBlue`.

```swift
    let colors = AB.Style.Colors(primaryColor: <#T##UIColor#>,
                                 actionButtonColor: <#T##UIColor?#>,
                                 secondaryButtonColor: <#T##UIColor?#>,
                                 tertiaryButtonColor: <#T##UIColor?#>,
                                 linkColor: <#T##UIColor?#>,
                                 progressColor: <#T##UIColor?#>,
                                 progressTrackColor: <#T##UIColor?#>,
                                 confettiColor: <#T##UIColor?#>)

    let style = AB.Style(colors: colors)
```

* `actionButtonColor` applies to action button backgrounds, for example, the Charge button.
* `secondaryButtonColor` applies to secondary button backgrounds, for example, most Try Again buttons.
* `tertiaryButtonColor` applies to tertiary button text, for example, the Manual Card Entry and Receipt view Done buttons.  This button type does not have a background.
* `linkColor` applies to clickable text, for example, the Autobooks "Call us" text prompt which includes our support numnber.  Despite the name, it does not style links in web features.
* `progressColor` is the color shown for the portion of the progress bar that’s filled in linear progress views. This corresponds to `progressTintColor` in `UIProgressView`.
* `progressTrackColor` is the color shown for the portion of the progress bar that _isn’t_ filled in linear progress views. This corresponds to `trackTintColor` in `UIProgressView`.  It may be set to `.clear` if desired.  Be careful about setting this to an opaque background color that does not respect dark mode, for example, `.white` or `.black`.
* `confettiColor` applies to the congratulatory confetti which displays when a user first onboards on to Tap to Pay.

Because the SDK is almost entirely self-contained, you won't receive a direct reference to the underlying `UINavigationController` that's being presented.  To customize this controller to match your branding, you can use the `CustomNavigationBar` object for advanced styling:

```swift
    let colors = AB.Style.Colors(primaryColor: <#T##UIColor#>,
                                 actionButtonColor: <#T##UIColor?#>,
                                 secondaryButtonColor: <#T##UIColor?#>,
                                 tertiaryButtonColor: <#T##UIColor?#>,
                                 linkColor: <#T##UIColor?#>,
                                 progressColor: <#T##UIColor?#>,
                                 confettiColor: <#T##UIColor?#>)
  
    let customNavigationBar = AB.Style.CustomNavigationBar(standardAppearance: <#T##UINavigationBarAppearance?#>,
                                                           compactAppearance: <#T##UINavigationBarAppearance?#>,
                                                           scrollEdgeAppearance: <#T##UINavigationBarAppearance?#>,
                                                           compactScrollEdgeAppearance: <#T##UINavigationBarAppearance?#>,
                                                           navigationBarClass: <#T##AnyClass?#>,
                                                           toolbarClass: <#T##AnyClass?#>)
 
    let style = AB.Style(colors: colors,
                         customNavigationBar: customNavigationBar)
```

If the `standardAppearance` is non-`nil`, all four appearance objects (`standardAppearance`, `compactAppearance`, `scrollEdgeAppearance`, and if on iOS 15 or later, `compactScrollEdgeAppearance`) are passed to the constructed `UINavigationBar`; if unset, the default is constructed like so:

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

For the most complex styling requirements, you may also use the `navigationBarClass` and `toolbarClass` to supply custom `UINavigationBar` and `UIToolbar` subclasses to the `UINavigationController` on instantiation. This is *in addition to* any styling that occurs as part of supplying `UINavigationBarAppearance` objects.

### Notifications

An SDK consumer will often need to know about user activity internal to the SDK to prevent a timeout in the hosting application.  To receive notifications about both web and native activity, subscribe to  `AB.Notifications.userActivity`:

```swift
    NotificationCenter.default.addObserver(self,
                                           selector: #selector(<#preventApplicationTimeout#>),
                                           name: AB.Notifications.userActivity,
                                           object: nil)

    @objc func <#preventApplicationTimeout#>(_ sender: Notification) {
        // Your application should reset its internal idle timer here.
    }
```

See the `AB.Notifications` structure for more events.

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

## Domain List

These are provided for restricted development environments where domains may need to be whitelisted.

### API

#### Autobooks
* https://dev-apim.autobooks.co
* https://staging-apim.autobooks.co
* https://apim.autobooks.co

#### Processing
* https://transaction.elementexpress.com
* https://certtransaction.elementexpress.com
* https://int.api.fiservapps.com
* https://cert.api.fiservapps.com
* https://cat.api.fiservapps.com
* https://connect.fiservapis.com

#### Segment
* https://cdn-settings.segment.com
* https://api.segment.io

### Web

#### Azure Monitor
See [this document](https://learn.microsoft.com/en-us/azure/azure-monitor/app/ip-addresses) for a full list of domains.

#### Autobooks
* https://app.autobooks.co
* https://dev.autobooks.co
* https://staging.autobooks.co
* https://dev-payments.autobooks.co
* https://stg-payments.autobooks.co
* https://payments.autobooks.co

#### Autobooks CDN
* https://preprodcdn.autobooks.co
* https://dev-cdn.autobooks.co
* https://stg-cdn.autobooks.co
* https://prd-cdn.autobooks.co

#### GraphQL
* https://dev-gql.autobooks.co
* https://stg-gql.autobooks.co
* https://gql.autobooks.co

#### Segment
* https://cdn.segment.com
* https://api.segment.io

#### Hubspot
* https://api.hubspot.com
* https://app.hubspot.com
* https://track.hubspot.com
* https://static.hsappstatic.net
* https://js.hs-analytics.net
* https://js.hs-banner.com
* https://js-na1.hs-scripts.com
* https://js.usemessages.com

#### Google Fonts
* https://fonts.gstatic.com
* https://fonts.googleapis.com

#### Fraud monitoring
* https://tst.kaptcha.com

#### User Experience
* https://fast.appcues.com
