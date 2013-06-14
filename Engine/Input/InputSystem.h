#pragma once

#include "InputHandler.h"
#include "InputConcepts.h"
#include "Engine/Entity/Component.h"

#include <map>

namespace Inertia {

typedef void (*InputConceptCallback) (Component*, InputConcept);
struct InputRegistration {
    Component *component;
    InputConceptCallback callback;
    friend bool operator== (const InputRegistration&, const InputRegistration&);
};
    
class InputSystem {
private:
    InputHandler *m_inputHandler;
    
    std::multimap<Input, InputConcept> m_bindings;
    void bindConcept(InputConcept, InputEvent, InputAction);
    
    void loadBindings();
    
    std::multimap<InputConcept, InputRegistration> m_components;
    
public:
    InputSystem();
    
    void Initialize();
    void Shutdown();
    
    void registerComponent(Component*, InputConcept, void (*) (Component*, InputConcept));
    
    void Update();
};

}