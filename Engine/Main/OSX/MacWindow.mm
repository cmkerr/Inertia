#import "MacWindow.h"

#import "MenuBuilder.h"
#import "AppDelegate.h"

#import <stdlib.h>

#import <OpenGL/glu.h>

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
    NSWindow *window_ = [[NSWindow alloc]
                         initWithContentRect:rectangle
                         styleMask:styles
                         backing:NSBackingStoreBuffered
                         defer:NO];
    
    [window_ setTitle:@"OGL Framework"];
    
    [window_ setReleasedWhenClosed:NO];
    
    view_ = [[View alloc] initWithFrame:rectangle];
    [window_ setContentView:view_];
    [window_ makeFirstResponder:view_];
    
    //[view_ setFrame:NSMakeRect(0, 0, rectangle.size.width, rectangle.size.height)];
    
    [window_
     performSelectorOnMainThread:@selector(makeKeyAndOrderFront:)
     withObject:nil
     waitUntilDone:YES];
    [NSApp activateIgnoringOtherApps:YES];
    
    [MenuBuilder populateMainMenu];
    
    [NSApp setDelegate: [AppDelegate new]];
    
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
    [m_window makeKeyAndOrderFront:nil];
    [pool release];
}

void MacWindow::Hide()
{
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    [m_window orderOut:nil];
    [pool release];
}

void MacWindow::Close()
{
    [m_window close];
}

void MacWindow::Draw()
{
    [view_ makeReady];
    
    glMatrixMode(GL_MODELVIEW);
    
    // set the background colour
    glClearColor (0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);
    
    // inform the context that the view has been resized    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // prepare for primitive drawing
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 1.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
        glTranslated(0.0, 0.0, -2);
        glBegin(GL_TRIANGLES);
            glColor3d(1.0, 0.0, 0.0);
            glVertex3d(0.0, 0.0, 0.0);
            glColor3d(0.0, 1.0, 0.0);
            glVertex3d(1.0, 0.0, 0.0);
            glColor3d(0.0, 0.0, 1.0);
            glVertex3d(1.0, 1.0, 0.0);
        glEnd();
    glPopMatrix();
    
    [view_ present];
}



