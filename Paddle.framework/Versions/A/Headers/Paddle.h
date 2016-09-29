//
//  Paddle.h
//  Paddle Test
//
//  Created by Louis Harwood on 10/05/2013.
//  Copyright (c) 2016 Paddle. All rights reserved.
//  Version: 3.0.9

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
#define kPADCouponProduct @"productId"
#define kPADCouponCode @"couponCode"

#define kPADActivated @"Activated"
#define kPADContinue @"Continue"
#define kPADTrialExpired @"TrialExpired"

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

@protocol PaddleDelegate <NSObject>

@optional
- (void)licenceActivated;
- (void)licenceDeactivated:(BOOL)deactivated message:(nullable NSString *)deactivateMessage;
- (void)paddleDidFailWithError:(nullable NSError *)error;
- (BOOL)willShowBuyWindow;
- (void)productDataReceived;
- (BOOL)shouldDestroyLicenceOnVerificationFail;
- (int)failedAttemptsBeforeLicenceDestruction;
- (BOOL)onlyDestroyLicenceOnVerificationFail;
- (nonnull NSString *)appGroupForSharedLicense;
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

@property (nullable, assign) id <PaddleDelegate> delegate;

@property (nullable, nonatomic, retain) PADProductWindowController *productWindow;
@property (nullable, nonatomic, retain) PADActivateWindowController *activateWindow;
@property (nullable, nonatomic, retain) PADBuyWindowController *buyWindow;
@property (nullable, nonatomic, retain) NSWindow *devMainWindow;

@property (assign) BOOL isTimeTrial;
@property (assign) BOOL isOpen;
@property (assign) BOOL canForceExit;
@property (assign) BOOL willShowLicensingWindow;
@property (assign) BOOL hasTrackingStarted;
@property (assign) BOOL willSimplifyViews;
@property (assign) BOOL willShowActivationAlert;
@property (assign) BOOL willContinueAtTrialEnd;
@property (assign) BOOL isSiteLicensed;


+ (nonnull Paddle *)sharedInstance;
- (void)startLicensing:(nonnull NSDictionary<NSString *, NSString *> *)productInfo timeTrial:(BOOL)timeTrial withWindow:(nullable NSWindow *)mainWindow;
- (void)startLicensingSilently:(nonnull NSDictionary<NSString *, NSString *>  *)productInfo timeTrial:(BOOL)timeTrial;
- (void)startPurchase;
- (void)startPurchaseWithWindow:(nonnull NSWindow *)window completionBlock:(nullable void (^)( NSString * _Nullable email,  NSString * _Nullable licenceCode, BOOL activate))completionBlock;
- (void)startExternalPurchase;
- (void)purchaseProductId:(nonnull NSString *)productId withWindow:(nullable NSWindow *)window completionBlock:(nonnull void (^)(NSString * _Nullable response, NSString * _Nullable email, BOOL completed, NSError * _Nullable error))completionBlock;

- (nonnull NSNumber *)daysRemainingOnTrial;
- (BOOL)productActivated;
- (void)showLicencing;
- (nullable NSString *)activatedLicenceCode;
- (nullable NSString *)activatedEmail;
- (void)showActivateLicence;
- (void)showActivateLicenceWithWindow:(nullable NSWindow *)window;
- (void)showActivateLicenceWithWindow:(nullable NSWindow *)window licenceCode:(nullable NSString *)licenceCode email:(nullable NSString *)email withCompletionBlock:(nonnull void(^)(BOOL activated))completionBlock;
- (void)activateLicence:(nonnull NSString *)licenceCode email:(nonnull NSString *)email withCompletionBlock:(nonnull void (^)(BOOL activated, NSError * _Nonnull error))completionBlock;
- (void)verifyLicenceWithCompletionBlock:(nonnull void (^)(BOOL verified, NSError * _Nullable error))completionBlock;

- (void)deactivateLicence;
- (void)deactivateLicenceWithCompletionBlock:(nonnull void (^)(BOOL deactivated, NSString * _Nullable deactivateMessage))completionBlock;

- (void)setApiKey:(nonnull NSString *)apiKey;
- (void)setVendorId:(nonnull NSString *)vendorId;
- (void)setProductId:(nonnull NSString *)productId;

- (void)setCustomProductHeading:(nonnull NSString *)productHeading;
- (void)disableTrial:(BOOL)trialSetting;
- (void)disableLicenseMigration;
- (void)disableTrialResetOnDeactivate;
- (void)resetTrialOnVersionUpdateForMajorOnly:(BOOL)onlyMajor;
- (void)overridePrice:(nonnull NSString *)price;
- (void)overridePrice:(nonnull NSString *)price withCustomMessage:(nullable NSString *)customMessage customProductName:(nullable NSString *)productName;
- (void)overridePrice:(nonnull NSString *)price withWindow:(nullable NSWindow *)window completionBlock:(nonnull void (^)(NSString * _Nullable email, NSString * _Nullable licenceCode, BOOL activate))completionBlock;
- (void)overridePrice:(nonnull NSString *)price withWindow:(nullable NSWindow *)window customMessage:(nullable NSString *)customMessage customProductName:(nullable NSString *)productName completionBlock:(nonnull void (^)(NSString * _Nullable email, NSString * _Nullable licenceCode, BOOL activate))completionBlock;
- (void)overridePriceExternal:(nonnull NSString *)price;
- (nullable NSDictionary *)existingLicenseFromAppGroup:(nonnull NSString *)appGroup forProductId:(nonnull NSString *)productId;

- (void)setPassthrough:(nonnull NSString *)passthrough;
- (void)addCoupon:(nonnull NSString *)couponCode forProductId:(nullable NSString *)productId;
- (void)addCoupons:(nonnull NSArray *)coupons;


@end
