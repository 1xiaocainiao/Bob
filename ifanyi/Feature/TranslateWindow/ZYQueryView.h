//
//  ZYQueryView.h
//  ifanyi
//
//  Created by ripper on 2019/11/13.
//  Copyright © 2019 ripperhe. All rights reserved.
//

#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZYQueryView : NSView

@property (nonatomic, strong) NSScrollView *scrollView;
@property (nonatomic, strong) NSTextView *textView;
@property (nonatomic, strong) NSButton *audioButton;
@property (nonatomic, strong) NSButton *textCopyButton;

@property (nonatomic, copy) void(^audioActionBlock)(ZYQueryView *view);
@property (nonatomic, copy) void(^copyActionBlock)(ZYQueryView *view);

@end

NS_ASSUME_NONNULL_END
