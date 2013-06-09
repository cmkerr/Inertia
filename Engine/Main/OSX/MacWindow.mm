#import "MacWindow.h"

#import "MenuBuilder.h"
#import "AppDelegate.h"

#import <stdlib.h>


MacWindow::MacWindow() : m_window(nullptr) {}

void MacWindow::Initialize()
{
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    
    [NSApplication sharedApplication];
    [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
    
    unsigned int styles =
        NSClosableWindowMask |
        NSTitledWindowMask;
    
    NSRect rectangle = NSMakeRect(100, 100, 640, 480);
    m_window = [[NSWindow alloc]
                         initWithContentRect:rectangle
                         styleMask:styles
                         backing:NSBackingStoreBuffered
                         defer:NO];
    
    [m_window setTitle:@"Inertia"];
    [m_window setReleasedWhenClosed:NO];
    
    [MenuBuilder populateMainMenu];
    
    
    [NSApp setDelegate: [AppDelegate new]];
    [NSApp activateIgnoringOtherApps:YES];
        
    [NSApp finishLaunching];
    
    [pool release];
}

void MacWindow::HandleEvents()
{
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    NSEvent* event = [NSApp nextEventMatchingMask:NSAnyEventMask
                            untilDate:[NSDate distantPast]
                            inMode:NSDefaultRunLoopMode
                            dequeue:YES];
    if (event) {
        [NSApp sendEvent:event];
        [NSApp updateWindows];
    }
    [pool release];
}

void MacWindow::Show()
{
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];

    [m_window
     performSelectorOnMainThread:@selector(makeKeyAndOrderFront:)
     withObject:nil
     waitUntilDone:YES];
    
    [pool release];
}

void MacWindow::Close()
{
    [m_window close];
}

void* MacWindow::GetNativeHandle()
{
    return m_window;
}

