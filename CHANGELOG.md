# 3.0.33
- Fixed: Crash on app launch when calling an unset Delegate, typically when using Silent Licensing.

# 3.0.32
- Added: `overridePriceForChildProduct` method
- Fixed: Swift nullability annotations on completion blocks to match actual usage.

# 3.0.31
- Fixed: SilentLicensing inconsistently setting and decrementing remaining trial days

# 3.0.30
- Fixed: Crash when viewing incomplete licence details
- Fixed: Reduced calls to analytics endpoints
- Added: Option to purge v2 licenses with remote verification

# 3.0.29
- Fixed: PayPal instability on older OS X versions.
- Fixed: Activation issues for products being activated with licenses generated for another product when on newer versions of MacOS.

# 3.0.28
- Fixed: Timeout when orders are flagged after checkout
- Fixed: Changed product id check when activating licences to only apply to child products

# 3.0.27
- Added: Ability to override prices in multiple currencies and recurring prices
- Fixed: Issue where debugging option to reset trial would not disable

# 3.0.26
- Fixed: Crash when displaying activation window with not all product information
- Fixed: Not accurately using failedAttempts value from delegate method
- Fixed: Product remaining activated after deactivation in some scenarios
- Fixed: Calling deactivate with no licence crashes

# 3.0.25
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

# 3.0.24
Bugfixes:
- Fixed issue where email passed to `recoverLicencesForEmail` was ignored

# 3.0.23
Features:
- Added Licence Recovery options
- Checkout Details are now returned in completion blocks

Bugfixes:
- Fixed issue where some users would persistently be prompted for PTK tools with schedules
- Fixed issue where product name would be `(null)` on 10.8 Buy Window
- Fixed issue preventing the Buy Window from closing when some passthrough values were set

# 3.0.22
Bugfixes:
- Fixed issue on 10.8 where product names could be null
- Fixed issue when setting certain passthrough values would prevent checkout from closing
- CompletionBlocks on checkout correctly return checkoutId and other details

# 3.0.21
Bugfixes:
- Fixed issue where licences were incorrectly removed after verification when offline
- Improved documentation/warnings during build
- Removed conflicting category names for some users preventing licences from being written

# 3.0.20
Bugfixes:
- Preventing custom schemes in purchase views from throwing errors
- Starting Analytics before licencing resulted in a crash, resolved
- When no internet connection was present some users were unable to continue a trial or activate
- Time Trials were sometimes being incorrectly identifed as expired

# 3.0.19
Bugfixes:
- Fixed issue where products would sometimes incorrectly display as on sale
- Fixed issue where payments via PayPal would fire incorrect webview delegate methods
- Solved issue where trial window would sometimes not be shown as a sheet
- Solved issue where button text would sometimes be blurry

# 3.0.18
Bugfixes:
- Fixed encoding issue on 10.8 when start purchases
- Re-added XCode 7 compatibility
- Fixed issue preventing licencing from starting after it had been cancelled
- Included logging option for debugging purposes

# 3.0.17
Bugfixes:
- Fixed issue with product windows sometimes not displaying a show
- Resolved debug tools not renewing trials
- Fixed issue where older licences would not always verify correctly
- Fixed multiline content in PTK Feedback tool

Features:
- Overridden prices now display in the product window
- Feedback and Audience methods can be used directly without displaying Paddle UI

# 3.0.16
Bugfixes:
- Fixed issue where restore purchases prevented apps from quitting when no internet connection was available
- Fixed a number of localization issues
- Resolved PTK Schedules not always being followed
- Fixed issue where the PTK Feedback tool didn't present acknowledgement

Features:
- Added 'x event' option to PTK schedules, where 'event' is any analytics event
- Added ability for product heading and trial text to be localized via `setCustomProduct...` `Heading` or `TrialText`

# 3.0.15
Bugfixes:
- Fixed crash when attempting to display modal window when one is already present
- New Delegate method `- (BOOL)willPresentModalForWindow:(NSWindow * _Nullable )window;` called before presenting modal window to allow developers to dismiss an existing modal window
- Added "Deactivate" button to existing/activated licence view. Enabled setting `willShowDeactivateLicenceButton` to `YES`

# 3.0.14
Bugfixes:
- Improved handling API connections to reduce SSL issues
- Fixed issue when pasting licence codes
- Resolved issue where some trials did not decrement correctly
- Fixed productActivated responses sometimes being incorrect

# 3.0.13
Bugfixes:
- Fix zero days remaining issue
- Fixed schedules in PTK being ignored
- Increased width of licence code input to fit standard length

# 3.0.12
Features:
- Added ability to set checkout attributes for PaddleJS

Bugfixes:
- Fixed issue when app version isn't using semantic versioning resulting in checkout not loading
- Fixed silent licensing crashing when framework attempted to display product info

# 3.0.11
Bugfixes:
- Fixed checkout issue for guest users
- Fixed issue resetting trials during development

# 3.0.10
Features:
- Improved checkout process to allow for more product types
- Added ability to pre-fill coupon(s) for multiple products

Bugfixes:
- Fixed scenario where onlyDestroyLicenceOnVerificationFail produced a false positive
- Deprecated Happiness and Ratings methods in PTK

# 3.0.9
Features
- Added `onlyDestroyLicenceOnVerificationFail` delegate for verification

Bugfixes
- Prevented displaying a sheet when one is already attached

# 3.0.8
Features:
- ShowActivateLicence with completionBlock for use with silent licensing but using Paddle UI for activation
- Improved handling of completion blocks in silent licensing

# 3.0.7
Bugfixes:
- Switched to @rpath for Installation Directory

# 3.0.6
Bugfixes:
- Fixed crash on checkout when using Paypal
- Improved checking of correct values in productInfo NSDictionary

# 3.0.5
Features:
- Framework exposes module for better Swift support
- Nullability annotation added

# 3.0.4
Bugfixes:
- Allow showing activate window and attach to window
- Improved tool scheduling
- Product activated delegate fix to not show alert

Features:
- Improved security on app group license publishing

# 3.0.3
Bugfixes:
- Reset failed attempts on successful verification or activation
- If licence activated delegate is implemented don't also show alert

Features:
- Upgrade pricing from different app using app groups
- Customise product and subtext on price override

# 3.0.2
Bugfixes:
- Fix for licenses being incorrectly removed when original activation was performed using the v1 API

# 3.0.1
Bugfixes:
- Fixed text alignment in buttons
- Corrected listed version in header
- Fixed purchase view crash on multiple loads

# 3.0.0
Features:
- Remote verification
- Remote deactivation
- Silent licensing
- Purchase/Activate methods with block callbacks
- Improved security of local licenses

# 2.4.4
Bugfixes:
- Force locale in PAK for better date/time handling
- Use UUID when en0 is not available. Fix for https://support.apple.com/en-us/HT6672

# 2.4.3
Bugfixes:
- Licencing window now uses the local currency where possible
- Analytics crash involving writing from multiple threads fixed
- Price override now works on first launch

Features:
- Ability to launch licence activation window directly
- Delegate methods for Happiness and Rating tools in PTK

# 2.4.2
Bugfixes:
- Improved price override to deal with lack of keys on first run
- Prevented licences from being deactivated if API side deactivation fails

# 2.4.1
Features:
- IAP Recovery for PaddleStoreKit
- Set base language to en-US

# 2.4.0
Features:
- Localization for 12 languages
- TrialExpired Notifications
- Passthrough data on purchases

Bugfixes:
- Resolved a number of memory leaks
- Resetting of trials in development environment improved

# 2.3.9
Bugfixes:
- Fixed issue preventing existing/activated licences from being displayed using showLicencing
- Stopped Paypal IAP window from using runloops other than main to fix non-responsive issue

# 2.3.8
Bugfixes:
- Appropriate error message when trying to activate with empty licence code
- Removed memory leak when gathering hardware data
- Fixed small deactivate bug

# 2.3.7
Bugfixes:
- Fixed issue where trial windows sometimes do not dismiss correctly
- Fixed paypal loading issue in PSK

# 2.3.6
Bugfixes:
- JSON Parsing, nil data, issue resolved
- Window centering
- Import Cocoa in header for Swift support

# 2.3.5
Bugfixes:
- UI fixes for OS X 10.11
- Centering licencing windows
- Fix for lost licences

# 2.3.4
Bugfixes:
- Fixed issue for < 3 character analytics event names
- Ensure analytics data is always sent over https
- Fixed issues regarding licences not being stored correctly

# 2.3.2
Features:
- Scheduler includes analytics events scheduling: next event.name
- Inclusion of default license
- Started moving to new v3 API

Bugfixes:
- Licence changed to License
- Fix 'week' schedules

# 2.3.1
Bugfixes:
- Layout and shadow issues in PTK

# 2.3.0
Features:
- PaddleToolKit
	- Happiness
	- Rating
	- Feedback
	- Email Subscribe
	- Scheduler

## 2.2.6
Bugfixes:
- Deactivate issue when for older licenses fixed

Features:
- PSK Purchase view responds to Esc key for closing
- Delegate method willShowBuyWindow for overriding purchasing behaviour

## 2.2.5
Features:
- startPurchase method for launching straight into the buy view for the product
- disableLicenseMigration method to prevent old licenses from < 2.2.x SDK from being transferred
- disableTrialResetOnDeactivate method to NOT reset trial periods when an activation is deactivated

Bugfixes:
- Analytics data is NOT sent when an app is run from Xcode/debugger for more accurate data

## 2.2.4
Features:
- Ability to override product price

## 2.2.3
Features:
- Debugging of time trials
- Resetting time trials for app version updates

## 2.2.2
Bugfixes:
- Improved validation of analytics data
- Preventing too many attempted connections to analytics
- Improving timeout errors on license activation

## 2.2.1
Bugfixes:
- Improved migration script from < 2.2 versions
- NSNotificationCenter notifications fix
- Friendly license activation message
- Continuing Time Trial button text changed from 'Quit' to 'Close'

## 2.2
Features:
- Paddle Analytics Kit
- License and product data storage moved to custom storage
- Trial data more secure
- User email included in purchase receipts
- Allows for feature limited trials after time trial completion
- Custom product view headings
- Allows for custom activation alerts

## 2.18
Features:
- UI updated for Yosemite
- Licensing windows are now draggable when not displayed as a sheet
- Grammar correction number of days remaining label

## 2.16
Bugfixes:
- Last activated date updated on successful verification

## 2.15
Bugfixes:
- Supports Retina displays on Purchase view
- Fixed Yosemite shadow bug
- Purchase view now draggable

## 2.13
Bugfixes:
- SSL/Verify delegate method fix. Some products were able to verify but delegate methods not being called

## 2.12
Bugfixes:
- Fixed modal web view when being used with JDK based apps
- PSKReceipt delegate issue on some implementations

## 2.11
Bugfixes:
- Truncated pricing in certain localizations
- Conflicting class names with other popular OS classes

Features:
- App descriptions displayed and sized appropriately

## 2.1
Bugfixes:
- Paypal payment window
- Fixed 'test  product' text issue
- Encryption issues

## 2.02
Bugfixes:
- Product icon display issue
- Preparation for local verification

## 2.01
Features:
- Added `showStoreViewForProductIds:(NSArray *)productIds` to PSK
- Added `startLicensing:(NSDictionary *)productInfo timeTrial:(BOOL)timeTrial withWindow:(NSWindow *)mainWindow` to Paddle. For starting licensing after settings keys
- Added `paddleDidFailWithError:(NSError *)error` delegate method to Paddle.h

Bugfixes:
- Error handling of no API keys set when initiating

## 2.0
Features:
- PaddleStoreKit (PSK) added to allow for In App Purchases
- Display a 'store' for your products, an individual product or open a 'purchase' view instantly
- Purchase verification for receipts
- Valid receipts stored locally and can be re-verified at any time

## 1.6
Features:
- Store activation_id on successful license activation for future verification

## 1.54
Bugfixes:
- Fix for product_image null value

## 1.53
Features:
- Added option to disable display of licensing view (willShowLicensingWindow)

Bugfixes:
- Improved de-activate licence cleanup
- Miscellaneous visual/UI fixes
- Improved unit tests
- Updated copyright information for 2014

## 1.52
Bugfixes:
- Licence changed to License in remaining locations
- Strip whitespace and new line characters when pasting email/license
- Added ActivityIndicator while checking license validity
- Improved security when quitting app with expired trial and no license (see docs for options)

## 1.51
Bugfixes:
- Changed Licence to License
- Internal reporting of device info to API fix

## 1.5
Bugfixes:
- Timeout increased to 30 seconds
- Licence activation, only one at a time, activation confirmation message

Features:
- Deactivate method included
- Device info for API to improve activations and debugging

## 1.43
Bugfixes:
- NSAlert from errors generated by Paddle rather than NSLog for ALL errors

## 1.42
Bugfixes:
- Switched from NSAlert to NSLog for errors
- First fix for bug when switching between trial and no trial on the API. Now requires an app restart from the user for changes to take effect (providing the app/framework was started once after the changes where made)

## 1.41
Bugfixes
- Fixed bug in which NSTextFields would not respond to key events in some implementations

## 1.4

Bugfixes:
- Fixed bug in which the framework would not always display discounts correctly
