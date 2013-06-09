#pragma once

#include "Engine/Main/Window.h"

class View {
public:
    virtual void Initialize(Window *) = 0;
    virtual void Shutdown() = 0;
    
    virtual void makeReady() = 0;
    virtual void present() = 0;
};