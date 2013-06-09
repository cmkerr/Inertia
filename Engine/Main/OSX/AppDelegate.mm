#import "AppDelegate.h"

#import "Main.h"

@implementation AppDelegate

- (void) applicationWillFinishLaunching:(NSNotification *)notification
{
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(windowClosing:)
                                                 name:NSWindowWillCloseNotification
                                               object:nil];
     
}

- (void) windowClosing:(NSNotification *)notification
{
    //Main::s_Main->Stop();
    [NSApp terminate: self];
}

- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication *)sender
{
    Main::s_Main->Stop();
    
    return YES;
}

@end
