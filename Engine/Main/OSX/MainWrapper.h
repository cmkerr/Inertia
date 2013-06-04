//
//  MainWrapper.h
//  Inertia
//
//  Created by Chris on 13-06-03.
//  Copyright (c) 2013 Chris. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Forward definition for C++ class
struct Main;

@interface MainWrapper : NSObject {
    struct Main *m_Main;
}

-(void) Initialize;
-(void) Shutdown;

@end
