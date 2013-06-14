
#include "InputSystem.h"

#include "InputConcepts.h"
#include "InputEvents.h"

#ifdef __APPLE__
#include "Engine/Input/OSX/MacInputHandler.h"
#endif

namespace Inertia {

bool operator== (const InputRegistration& i1, const InputRegistration& i2)
{
    return i1.component == i2.component && i1.callback == i2.callback;
}
    
InputSystem::InputSystem() : m_inputHandler(nullptr)
{
}

void InputSystem::Initialize()
{
#ifdef __APPLE__
    m_inputHandler = new MacInputHandler();
#else
#ERROR UNDEFINED PLATFORM
#endif
    m_inputHandler->registerEvents();
    
    loadBindings();
}

void InputSystem::Shutdown()
{
    m_inputHandler->deregisterEvents();
    delete m_inputHandler;
}

void InputSystem::registerComponent(Component* component, InputConcept concept, void (*function)(Component*, InputConcept))
{
    InputRegistration registration;
    registration.component = component;
    registration.callback = function;
    
    m_components.insert(std::pair<InputConcept, InputRegistration>(concept, registration));
}

void InputSystem::bindConcept(InputConcept concept, InputEvent event, InputAction action)
{
    Input input;
    input.event = event;
    input.action = action;
    
    m_bindings.insert(std::pair<Input, InputConcept>(input, concept));
}
    
void InputSystem::loadBindings()
{
    bindConcept(InputConcept_MoveLeft, InputEvent_Key_A, InputAction_KeyDown);
    bindConcept(InputConcept_MoveLeft, InputEvent_Key_A, InputAction_KeyRepeat);
    
    bindConcept(InputConcept_MoveRight, InputEvent_Key_D, InputAction_KeyDown);
    bindConcept(InputConcept_MoveRight, InputEvent_Key_D, InputAction_KeyRepeat);
    
    bindConcept(InputConcept_MoveUp, InputEvent_Key_W, InputAction_KeyDown);
    bindConcept(InputConcept_MoveUp, InputEvent_Key_W, InputAction_KeyRepeat);
    
    bindConcept(InputConcept_MoveDown, InputEvent_Key_S, InputAction_KeyDown);
    bindConcept(InputConcept_MoveDown, InputEvent_Key_S, InputAction_KeyRepeat);
}
    
void InputSystem::Update()
{
    Input input;
    while ((input = m_inputHandler->getInput()).event != InputEvent_Invalid)
    {
        std::pair<std::multimap<Input, InputConcept>::iterator, std::multimap<Input, InputConcept>::iterator> binds = m_bindings.equal_range(input);
        for (std::multimap<Input, InputConcept>::iterator it = binds.first; it != binds.second; ++it)
        {
            
            std::pair<std::multimap<InputConcept, InputRegistration>::iterator, std::multimap<InputConcept, InputRegistration>::iterator> comps = m_components.equal_range(it->second);
            for (std::multimap<InputConcept, InputRegistration>::iterator it2 = comps.first; it2 != comps.second; ++it2)
            {
                InputRegistration reg = it2->second;
                
                reg.callback(reg.component, it2->first);
            }
        }
    }
}

}
