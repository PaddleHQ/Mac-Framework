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
- Use NSAlert on Paddle generated errors and NSLog for all other errors.

## 1.42
Bugfixes:
- Switched from NSAlert to NSLog for errors
- First fix for bug when switching between trial and no trial on the API. Now requires an app restart from the user for changes to take effect (providing the app/framework was started once after the changes where made)

## 1.41
Bugfixes:
- Fixed bug in which NSTextFields didn't respond to key events in some implementations

## 1.4
Features:
- Framework now universal. Works with 32bit and 64bit architectures

Bugfixes:
- Fixed bug in which the framework would not always display discounts correctly
