//
//  SnipViewController.h
//  Bob
//
//  Created by ripper on 2019/11/27.
//  Copyright © 2019 ripperhe. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface SnipViewController : NSViewController

@property (nonatomic, strong) NSImage *image;
@property (nonatomic, copy) void(^startBlock)(void);
@property (nonatomic, copy) void(^endBlock)(NSImage * _Nullable image);

@end

NS_ASSUME_NONNULL_END
