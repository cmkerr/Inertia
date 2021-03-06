#pragma once

#include "View.h"

#include "Engine/Main/Window.h"

namespace Inertia {

class RenderSystem {
private:
    View *m_view;
    
public:
    RenderSystem();
    
    
    void Initialize(Window *);
    void Shutdown();
    
    void Draw();
    
};

}