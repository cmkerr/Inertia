#pragma once

#import "Engine/Main/Window.h"

#import <Cocoa/Cocoa.h>


namespace Inertia {

class MacWindow : public Window {
private:
    NSWindow *m_window;
    
public:
    MacWindow();
    
    virtual void Initialize();
    virtual void Show();
    virtual void Close();
    
    virtual void HandleEvents();
    
    virtual void* GetNativeHandle();
};

}