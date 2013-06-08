//
//  MainWrapper.mm
//  Inertia
//
//  Created by Chris on 13-06-03.
//  Copyright (c) 2013 Chris. All rights reserved.
//

#import "MainWrapper.h"

#include "Engine/Main/Main.h"

@implementation MainWrapper

-(void) Initialize {
    m_Main = new Main(w);

    m_Main->Start();
}

-(void) Shutdown {
    delete m_Main;
}

@end
