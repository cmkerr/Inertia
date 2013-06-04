//
//  AppDelegate.h
//  Inertia
//
//  Created by Chris on 13-06-02.
//  Copyright (c) 2013 Chris. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "MainWrapper.h"

@interface AppDelegate : NSObject <NSApplicationDelegate>
{
    MainWrapper *m_Main;
}

@property (assign) IBOutlet NSWindow *window;

@end
