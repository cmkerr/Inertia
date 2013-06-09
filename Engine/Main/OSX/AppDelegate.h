#pragma once

#import <Cocoa/Cocoa.h>

@interface AppDelegate : NSObject<NSApplicationDelegate>

- (void) applicationWillFinishLaunching:(NSNotification *)notification;

- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication *)sender;

@end
