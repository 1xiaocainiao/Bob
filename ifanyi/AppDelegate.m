//
//  AppDelegate.m
//  ifanyi
//
//  Created by ripper on 2019/10/19.
//  Copyright © 2019 ripperhe. All rights reserved.
//

#import "AppDelegate.h"
#import <Carbon/Carbon.h>

OSStatus GlobalHotKeyHandler(EventHandlerCallRef nextHandler, EventRef theEvent, void *userData) {
    EventHotKeyID hotKeyCom;
    GetEventParameter(theEvent, kEventParamDirectObject, typeEventHotKeyID, NULL, sizeof(hotKeyCom), NULL, &hotKeyCom);
    uint32 hotKeyId = hotKeyCom.id;
    switch (hotKeyId) {
        case kVK_ANSI_D:
            [[NSNotificationCenter defaultCenter] postNotificationName:@"translate" object:nil];
            break;
    }
    return noErr;
}

@interface AppDelegate ()

@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application
    
    [self addGlobalHotKey:kVK_ANSI_D];
}


- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}

- (void)addGlobalHotKey:(uint32)keyCode {
    EventHotKeyRef       gMyHotKeyRef;
    EventHotKeyID        gMyHotKeyID;
    EventTypeSpec        eventType;
    eventType.eventClass = kEventClassKeyboard;
    eventType.eventKind = kEventHotKeyPressed;
    InstallApplicationEventHandler(&GlobalHotKeyHandler,1,&eventType,NULL,NULL);
    gMyHotKeyID.signature = 0;
    gMyHotKeyID.id = keyCode;
    RegisterEventHotKey(keyCode, optionKey, gMyHotKeyID, GetApplicationEventTarget(), 0, &gMyHotKeyRef);
}

@end
