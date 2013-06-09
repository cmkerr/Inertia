#pragma once

#include "Engine/Render/View.h"

#include "Engine/Main/Window.h"

#ifdef __OBJC__
#import  "CocoaView.h"
#else
class CocoaView;
#endif

class MacView : public View {
private:
    CocoaView *m_view;
    
public:
    MacView();
    
    virtual void Initialize(Window *);
    virtual void Shutdown();
    
    virtual void makeReady();
    virtual void present();
    
};