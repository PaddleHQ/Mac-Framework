//
//  Paddle.h
//  Paddle Test
//
//  Created by Louis Harwood on 10/05/2013.
//  Copyright (c) 2013 Paddle. All rights reserved.
//

#define kPADProductName @"product_name"
#define kPADOnSale @"on_sale"
#define kPADDiscount @"discount_line"
#define kPADUsualPrice @"usual_price"
#define kPADCurrentPrice @"current_price"
#define kPADCurrency @"price_currency"
#define kPADDevName @"developer_name"
#define kPADTrialText @"trial_text"
#define kPADImage @"product_image"
#define kPADTrialDuration @"trial_duration"
#define kPADProductImage @"default_image"

#define kPADActivated @"Activated"
#define kPADContinue @"Continue"

#import <Foundation/Foundation.h>

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
}

@property (nonatomic, retain) PADProductWindowController *productWindow;
@property (nonatomic, retain) PADActivateWindowController *activateWindow;
@property (nonatomic, retain) PADBuyWindowController *buyWindow;
@property (nonatomic, retain) NSWindow *devMainWindow;

@property (assign) BOOL isTimeTrial;
@property (assign) BOOL isOpen;


+ (Paddle *)sharedInstance;
- (void)startLicensing:(NSString *)apiKey vendorId:(NSString *)vendorId productId:(NSString *)productId timeTrial:(BOOL)timeTrial productInfo:(NSDictionary *)productInfo withWindow:(NSWindow *)mainWindow;

- (NSNumber *)daysRemainingOnTrial;
- (BOOL)productActivated;
- (void)showLicencing;
- (NSString *)activatedLicenceCode;
- (NSString *)activatedEmail;

@end
