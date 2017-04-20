//
//  PADDataStore.h
//  Paddle
//
//  Created by Louis Harwood on 01/12/2014.
//  Copyright (c) 2017 Paddle. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PADDataStore : NSObject {
    NSMutableDictionary *rootObject;
    NSString *apiKey;
    NSString *vendorId;
    NSString *productId;
    BOOL shouldDestroy;
    int failedAttempts;
    BOOL isSilentLicensing;
    NSDictionary *jsAttributes;
}

@property (nonatomic, retain) NSMutableDictionary *rootObject;
@property (nonatomic, copy) NSString *apiKey;
@property (nonatomic, copy) NSString *vendorId;
@property (nonatomic, copy) NSString *productId;
@property (assign) BOOL shouldDestroy;
@property (assign) int failedAttempts;
@property (assign) BOOL isSilentLicensing;
@property (nonatomic, strong) NSDictionary *jsAttributes;

+ (PADDataStore *)sharedInstance;
- (void)migrateData;
- (void)synchronize;
- (void)load;
- (void)setObject:(id)object forKey:(NSString *)key;
- (void)setHashObject:(id)object forKey:(NSString *)key;
- (id)objectForKey:(NSString *)key;
- (id)hashObjectForKey:(NSString *)key isvalid:(BOOL *)valid;
- (void)removeObjectForKey:(NSString *)key;
- (NSDictionary *)dictionaryForKey:(NSString *)key;

@end
