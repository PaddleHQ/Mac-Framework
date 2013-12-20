Paddle Framework
======================
This repository houses the latest releases, and up-to-date documentation for the Paddle framework.

--------------

* **Latest Release Version:** 1.43
* **Release Date:** 20th December 2013

--------------

_**Note:** Please liase with your Paddle contact/ account manager if you have any integration issues or concerns._

### Basic Setup
To setup the Paddle licencing framework there are just a few simple steps:
* Add the Paddle framework to your Xcode project by dragging from the finder.
![Drag Paddle framework into Xcode](https://paddle-static.s3.amazonaws.com/framework-documentation/add-framework.png)
Make sure you 'Add To Target' for your app.
![Add to Xcode Target](http://paddle-static.s3.amazonaws.com/framework-documentation/add-to-target.png)
* The Paddle framework requires WebKit to be included in your project. Project->Target->Build Phases->Link Binary With Libraries->Add WebKit.
![Include webkit in Xcode project](http://paddle-static.s3.amazonaws.com/framework-documentation/add-webkit.png)
* Now you need to tell Xcode to copy the framework into your project. Still within 'Build Phases' add a build phase (New Copy Files Build Phase), make sure 'Destination' is set to 'Frameworks'.
![Copy files build phase for framework](http://paddle-static.s3.amazonaws.com/framework-documentation/build-phases.png)
* At the top of your AppDelegate.h import the Paddle framework
	`#import <Paddle/Paddle.h>`


In `applicationDidFinishLaunching` you first need to create an NSDictionary containing the default values for your product, like so:
```
NSDictionary *productInfo = [NSDictionary dictionaryWithObjectsAndKeys:
	@"10.00", kPADCurrentPrice,
	@"Test Developer", kPADDevName,
	@"USD", kPADCurrency,
	@"http://www.macupdate.com/util/iconlg/17227.png", kPADImage,
	@"Test Product 2", kPADProductName,
	@"7", kPADTrialDuration,
	@"Thanks for downloading a trial of our product", kPADTrialText,
	@"paddleicon.png", kPADProductImage, //Image file in your project
	nil];
```

Now you can start the Paddle licencing process with the `startLicencing` method. This method accepts your API Key, Vendor ID, Product ID and also your applications main window to present the sheet from.
```
	[[Paddle sharedInstance] startLicensing:@"b012ef9a656a4bca5dc98b0032a1a15c" vendorId:@"91" productId:@"2" 
	timeTrial:YES productInfo:productInfo withWindow:self.window];
```

The complete method in your AppDelegate.h, would look like:
```
	- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
		{
    	NSDictionary *productInfo = [NSDictionary dictionaryWithObjectsAndKeys:
                                 @"10.00", kPADCurrentPrice,
                                 @"Test Developer", kPADDevName,
                                 @"USD", kPADCurrency,
                                 @"http://www.macupdate.com/util/iconlg/17227.png", kPADImage,
                                 @"Test Product 2", kPADProductName,
                                 @"7", kPADTrialDuration,
                                 @"Thanks for downloading a trial of our product", kPADTrialText,
                                 @"paddleicon.png", kPADProductImage, //Image file in your project
                                 nil];
    
    	[[Paddle sharedInstance] startLicensing:@"b012ef9a656a4bca5dc98b0032a1a15c"
						vendorId:@"91"
						productId:@"2"
						timeTrial:YES
						productInfo:productInfo
						withWindow:self.window];
	}
```


### Optional Methods
Before using any of the methods below, ensure that the `startLicencing` method has been called.

#### Days remaining
At any time you can ask Paddle for the number of days remaining on a customer trial by using
		`- (NSNumber *)daysRemainingOnTrial;`
For example
```
	NSNumber *daysRemaining = [[Paddle sharedInstance] daysRemainingOnTrial];
```
If you haven't set your product up as a time-trial then this method will return `0` as the number of days remaining.

#### Product Activated (Restricting app features)
If you wish to use the framework to restrict features, rather than as a time trial, you can use the following method to discover if the product has or hasn't been activated
		`- (BOOL)productActivated;`
For example
```
	BOOL productActivated = [[Paddle sharedInstance] productActivated];
	if (productActivated) {
		//Product has been activated - enable feature
	} else {
		//Product not activated - disable feature
	}
```

#### Display Licencing View
If at any point you wish to display the licencing views then simply use the following method
		`- (void)showLicencing;`
For example
```
	[[Paddle sharedInstance] showLicencing];
```

#### Get Activated Licence Code and Email
Once a user has activated your app you may wish to display the email address and licence code used to activate. There are two simple methods you can use to retrieve this information
		`- (NSString *)activatedEmail;`
		`- (NSString *)activatedLicenceCode;`
Both will return null if the product has not been activated. A simple example to use these would be
```
	NSString *email = [[Paddle sharedInstance] activatedEmail];
	NSString *licenceCode = [[Paddle sharedInstance] activatedLicenceCode];
```

#### Notification for Activation
You can also receive notifications when your app has been activated. If your app has already been activated then this notification will be sent when your app first starts the Paddle framework.

First of all, you should add an observer to receive the notifications
```
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotification:) name:kPADActivated object:nil];
```
Then implement the `handleNotification` method to receive, and act, on the notification
```
  - (void)handleNotification:(NSNotification *)note {
	  NSLog(@"Product Activated");
  }
```

