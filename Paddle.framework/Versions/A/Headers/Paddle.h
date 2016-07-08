//
//  Paddle.h
//  Paddle Test
//
//  Created by Louis Harwood on 10/05/2013.
//  Copyright (c) 2016 Paddle. All rights reserved.
//  Version: 3.0.3

#define kPADProductName @"name"
#define kPADOnSale @"on_sale"
#define kPADDiscount @"discount_line"
#define kPADUsualPrice @"base_price"
#define kPADCurrentPrice @"current_price"
#define kPADCurrency @"price_currency"
#define kPADDevName @"vendor_name"
#define kPADTrialText @"text"
#define kPADImage @"image"
#define kPADTrialDuration @"duration"
#define kPADProductImage @"default_image"
#define kPADLicence @"PaddleL"
#define kPADEmail @"PaddleEmail"
#define kPADFirstLaunchDate @"first_launch_date"

#define kPADActivated @"Activated"
#define kPADContinue @"Continue"
#define kPADTrialExpired @"TrialExpired"

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

@protocol PaddleDelegate <NSObject>

@optional
- (void)licenceActivated;
- (void)licenceDeactivated:(BOOL)deactivated message:(NSString *)deactivateMessage;
- (void)paddleDidFailWithError:(NSError *)error;
- (BOOL)willShowBuyWindow;
- (void)productDataReceived;
- (BOOL)shouldDestroyLicenceOnVerificationFail;
- (int)failedAttemptsBeforeLicenceDestruction;
- (NSString *)appGroupForSharedLicense;
@end

@class PADProductWindowController;
@class PADActivateWindowController;
@class PADBuyWindowController;

@interface Paddle : NSObject {
    PADProductWindowController *productWindow;
    PADActivateWindowController *activateWindow;
    PADBuyWindowController *buyWindow;
    NSWindow *devMainWindow;
    
    BOOL isTimeTrial;
    BOOL isOpen;
    BOOL canForceExit;
    BOOL willShowLicensingWindow;
    BOOL hasTrackingStarted;
    BOOL willSimplifyViews;
    BOOL willShowActivationAlert;
    BOOL willContinueAtTrialEnd;
    BOOL isSiteLicensed;
    
    #if !__has_feature(objc_arc)
    id <PaddleDelegate> delegate;
    #endif
}

@property (assign) id <PaddleDelegate> delegate;

@property (nonatomic, retain) PADProductWindowController *productWindow;
@property (nonatomic, retain) PADActivateWindowController *activateWindow;
@property (nonatomic, retain) PADBuyWindowController *buyWindow;
@property (nonatomic, retain) NSWindow *devMainWindow;

@property (assign) BOOL isTimeTrial;
@property (assign) BOOL isOpen;
@property (assign) BOOL canForceExit;
@property (assign) BOOL willShowLicensingWindow;
@property (assign) BOOL hasTrackingStarted;
@property (assign) BOOL willSimplifyViews;
@property (assign) BOOL willShowActivationAlert;
@property (assign) BOOL willContinueAtTrialEnd;
@property (assign) BOOL isSiteLicensed;


+ (Paddle *)sharedInstance;
- (void)startLicensing:(NSDictionary *)productInfo timeTrial:(BOOL)timeTrial withWindow:(NSWindow *)mainWindow;
- (void)startLicensingSilently:(NSDictionary *)productInfo timeTrial:(BOOL)timeTrial;
- (void)startPurchase;
- (void)startPurchaseWithWindow:(NSWindow *)window completionBlock:(void (^)(NSString *email, NSString *licenceCode, BOOL activate))completionBlock;
- (void)startExternalPurchase;
- (void)purchaseProductId:(NSString *)productId withWindow:(NSWindow *)window completionBlock:(void (^)(NSString *response, NSString *email, BOOL completed, NSError *error))completionBlock;

- (NSNumber *)daysRemainingOnTrial;
- (BOOL)productActivated;
- (void)showLicencing;
- (NSString *)activatedLicenceCode;
- (NSString *)activatedEmail;
- (void)showActivateLicence;
- (void)activateLicence:(NSString *)licenceCode email:(NSString *)email withCompletionBlock:(void (^)(BOOL activated, NSError *error))completionBlock;
- (void)verifyLicenceWithCompletionBlock:(void (^)(BOOL verified, NSError *error))completionBlock;

- (void)deactivateLicence;
- (void)deactivateLicenceWithCompletionBlock:(void (^)(BOOL deactivated, NSString *deactivateMessage))completionBlock;

- (void)setApiKey:(NSString *)apiKey;
- (void)setVendorId:(NSString *)vendorId;
- (void)setProductId:(NSString *)productId;

- (void)setCustomProductHeading:(NSString *)productHeading;
- (void)disableTrial:(BOOL)trialSetting;
- (void)disableLicenseMigration;
- (void)disableTrialResetOnDeactivate;
- (void)resetTrialOnVersionUpdateForMajorOnly:(BOOL)onlyMajor;
- (void)overridePrice:(NSString *)price;
- (void)overridePrice:(NSString *)price withCustomMessage:(NSString *)customMessage customProductName:(NSString *)productName;
- (void)overridePrice:(NSString *)price withWindow:(NSWindow *)window completionBlock:(void (^)(NSString *email, NSString *licenceCode, BOOL activate))completionBlock;
- (void)overridePrice:(NSString *)price withWindow:(NSWindow *)window customMessage:(NSString *)customMessage customProductName:(NSString *)productName completionBlock:(void (^)(NSString *email, NSString *licenceCode, BOOL activate))completionBlock;
- (void)overridePriceExternal:(NSString *)price;
- (NSDictionary *)existingLicenseFromAppGroup:(NSString *)appGroup forProductId:(NSString *)productId;

- (void)setPassthrough:(NSString *)passthrough;


@end
