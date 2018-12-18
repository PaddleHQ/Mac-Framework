//
//  PADKeyWindow.h
//  PaddleSample
//
//  Created by Louis Harwood on 08/05/2013.
//  Copyright (c) 2014 Avalore. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@protocol PADKeyWindowDelegate <NSObject>

- (void)didFinishWithReturnCode:(NSInteger)returnCode window:(NSWindow *)window;

@end

@interface PADKeyWindow : NSWindow

@property (nonatomic, assign) id <PADKeyWindowDelegate> windowDelegate;

- (void)finishWithCode:(NSInteger)returnCode;

@end
