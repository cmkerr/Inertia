#pragma once

#import "Engine/Main/Window.h"
#import "View.h"

#import <Cocoa/Cocoa.h>

class MacWindow : public Window {
private:
    NSWindow *m_window;
    View *view_;
    
    void setupMenu();
    
public:
    MacWindow();
    
    virtual void Initialize();
    virtual void HandleEvents();
    
    virtual void Show();
    virtual void Hide();
    virtual void Close();
    
    virtual void Draw();
};