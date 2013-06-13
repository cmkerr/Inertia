#pragma once


namespace Inertia {

class Window {
public:
    virtual void Initialize() = 0;
    virtual void Show() = 0;
    virtual void Close() = 0;
    
    virtual void HandleEvents() = 0;

    virtual void* GetNativeHandle() = 0;
};

}