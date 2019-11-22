//
//  TranslateWindowController.h
//  Bob
//
//  Created by ripper on 2019/11/17.
//  Copyright © 2019 ripperhe. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface TranslateWindowController : NSWindowController

@property (nonatomic, assign) BOOL hadShow;

+ (instancetype)shared;

- (void)showAtCenter;

- (void)showAtMouseLocation;

@end

NS_ASSUME_NONNULL_END
