#pragma once

class Window {
public:
    virtual void Initialize() = 0;
    virtual void HandleEvents() = 0;
    
    virtual void Show() = 0;
    virtual void Hide() = 0;
    virtual void Close() = 0;
    
    
    virtual void Draw() =0;
};