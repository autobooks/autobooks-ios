# ``Autobooks``

The Autobooks SDK provides an interface for Apple's ProximityReader framework and various Autobooks web features and API to provide an integrated payment experience for your users. It presents its own standalone UI over that of the embedding app. As such, its architecture is most similar to that of a small app rather than a typical SDK.

## Integrating Autobooks Tap to Pay

There are only a few steps to integrate the Autobooks SDK with your banking app. 

> Before Tap to Pay is fully available, steps 1 and 2 aren't necessary.

1. Before starting integration, your app must be registered with Autobooks in order to be provided the Proximity Reader entitlement and callback URL scheme. Once those are in hand, integration can begin.
2. Add the entitlement to your app's provisioning profile. Once you've registered your app with Autobooks and provided your app's identifier(s), you should see the entitlement available in the Apple Developer Center as a new capability for the identifier. Enable that ability, regenerate your provisioning profiles, and integrate them into your app.
3. After choosing where and when you want to start the Autobooks Tap to Pay feature (usually a button in your app), you can start the feature by calling `startTapToPay` with your Autobooks subscription key and login provider. Your login provider should always provide the latest valid SSO payload for your Autobooks integration. This provider should also renew any expired tokens, as it is used to keep the Autobooks session alive while using the Tap to Pay feature. This method presents the Tap to Pay feature in a full screen presentation, covering your app's UI.

    ```swift
    AB.startTapToPay(subscriptionKey: <subscriptionKey>) {
        await loginProvider.latestLoginToken()
    }
    ```
4. (Optional) Once the user is done with the Tap to Pay feature they can close it directly. However, if your app needs to dismiss the feature while it's in use, you can use the `stop()` method. This should be a last resort and will not always be effective. For instance, if the user is in an active Tap to Pay interaction where the Apple UI is on screen, the feature will dismiss in the background, preventing the user's Tap to Pay session from completing successfully.

    ```swift
    AB.stop()
    ```

## Integrating Autobooks Web Features

Autobooks web features are bundled with the SDK using a simple presentation interface and requiring only a login token from the Autobooks SSO payload.

To start the Autobooks Payment Form feature, provide the Autobooks subscription key and SSO payload as `String`s:

```swift
AB.startPaymentForm(subscriptionKey: <subscriptionKey>, loginToken: <loginToken>)
```

The Invoicing feature can be started similarly:

```swift
AB.startInvoicing(subscriptionKey: <subscriptionKey>, loginToken: <someLoginToken>)
```

## Customizing the Autobooks Experience

All of the `AB.start*` methods allow passing an `AB.Configuration` value to control various behaviors within the SDK. This includes a custom `primaryColor` as well as various network settings useful for testing or debugging the Autobooks integration.

```swift
let configuration = AB.Configuration(environment: .dev, 
                                            primaryColor: .systemOrange, 
                                            responseProvider: .live, 
                                            shouldFallBackToPaymentForm: false)
AB.startTapToPay(subscriptionKey: <subscriptionKey>, configuration: configuration) {
    await loginProvider.latestLoginToken()
}
```

This `Configuration` will run the Tap to Pay feature using the `.dev` backend environment using `.live` data, with a `primaryColor` of `.systemOrange` and without the fallback from Tap to Pay to Payment Form on devices which don't support TTP. `Configuration` values cannot be accessed or mutated once the feature has started.
