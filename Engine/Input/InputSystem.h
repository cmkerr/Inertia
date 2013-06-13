#pragma once

#include "InputHandler.h"
#include "InputConcepts.h"
#include "Engine/Entity/Component.h"

namespace Inertia {

class InputSystem {
private:
    InputHandler *m_inputHandler;
    
    void bindConcept(InputConcept, Input);
    
public:
    InputSystem();
    
    void Initialize();
    void Shutdown();
    
    void registerComponent(Component*, InputConcept);
    
    void Update();
};

}