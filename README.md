# Paddle Mac SDK
This is the official Mac SDK for [Paddle](https://www.paddle.com), documentation is available [here](https://www.paddle.com/docs/sdk/mac).

### v3.0.25

*We strongly advise you test this Paddle Framework build thoroughly as we’ve made a significant changes in this release to support 10.13 and Child Products.*

These include:

- Added: Provisional 10.13 Support
- Added: PayPal checkout window title now updates based on state from PayPal.
- Added: Option to disable remote verification for legacy licenses.
- Added: Closing the checkout window now closes the PayPal window if it’s presented.
- Fixed: Crash when aborting PayPal fixed
- Fixed: License unicode edge cases resulting in “lost” licenses.
- Fixed: Moving to site licensing no-longer invalidates your previous license.
- Fixed: Webview network calls returning after checkout is closed no-longer crash or show system error alerts.
- Fixed: Any purchase completion blocks now return all available checkout data.
- Removed: IAP support in favour of Child Products.
