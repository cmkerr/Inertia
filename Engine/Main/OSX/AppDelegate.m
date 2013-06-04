//
//  AppDelegate.m
//  Inertia
//
//  Created by Chris on 13-06-02.
//  Copyright (c) 2013 Chris. All rights reserved.
//

#import "AppDelegate.h"

@implementation AppDelegate

- (void)dealloc
{
    [super dealloc];
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    [NSThread detachNewThreadSelector:@selector(dummyFunc) toTarget:self withObject:nil];
    
    m_Main = [MainWrapper alloc];
    [m_Main Initialize];
    
}

- (void)dummyFunc {
    
}

@end
