
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

void InputSystem::registerComponent(Component* component, InputConcept concept, InputConceptCallback function)
{
    InputRegistration registration;
    registration.component = component;
    registration.callback = function;
    
    m_components.insert(std::pair<InputConcept, InputRegistration>(concept, registration));
}

void InputSystem::bindConcept(InputConcept concept, bool value, InputEvent event, InputAction action)
{
    Input input;
    input.event = event;
    input.action = action;
    
    m_bindings.insert(std::pair<Input, std::pair<InputConcept, bool>>(input, std::pair<InputConcept, bool>(concept, value)));
}
    
void InputSystem::loadBindings()
{
    bindConcept(InputConcept_MoveLeft, true, InputEvent_Key_A, InputAction_KeyDown);
    bindConcept(InputConcept_MoveLeft, true, InputEvent_Key_A, InputAction_KeyRepeat);
    bindConcept(InputConcept_MoveLeft, false, InputEvent_Key_A, InputAction_KeyUp);
    bindConcept(InputConcept_MoveLeft, true, InputEvent_Key_LeftArrow, InputAction_KeyDown);
    bindConcept(InputConcept_MoveLeft, true, InputEvent_Key_LeftArrow, InputAction_KeyRepeat);
    bindConcept(InputConcept_MoveLeft, false, InputEvent_Key_LeftArrow, InputAction_KeyUp);
    
    bindConcept(InputConcept_MoveRight, true, InputEvent_Key_D, InputAction_KeyDown);
    bindConcept(InputConcept_MoveRight, true, InputEvent_Key_D, InputAction_KeyRepeat);
    bindConcept(InputConcept_MoveRight, false, InputEvent_Key_D, InputAction_KeyUp);
    bindConcept(InputConcept_MoveRight, true, InputEvent_Key_RightArrow, InputAction_KeyDown);
    bindConcept(InputConcept_MoveRight, true, InputEvent_Key_RightArrow, InputAction_KeyRepeat);
    bindConcept(InputConcept_MoveRight, false, InputEvent_Key_RightArrow, InputAction_KeyUp);
    
    bindConcept(InputConcept_MoveUp, true, InputEvent_Key_W, InputAction_KeyDown);
    bindConcept(InputConcept_MoveUp, true, InputEvent_Key_W, InputAction_KeyRepeat);
    bindConcept(InputConcept_MoveUp, false, InputEvent_Key_W, InputAction_KeyUp);
    bindConcept(InputConcept_MoveUp, true, InputEvent_Key_UpArrow, InputAction_KeyDown);
    bindConcept(InputConcept_MoveUp, true, InputEvent_Key_UpArrow, InputAction_KeyRepeat);
    bindConcept(InputConcept_MoveUp, false, InputEvent_Key_UpArrow, InputAction_KeyUp);
    
    bindConcept(InputConcept_MoveDown, true, InputEvent_Key_S, InputAction_KeyDown);
    bindConcept(InputConcept_MoveDown, true, InputEvent_Key_S, InputAction_KeyRepeat);
    bindConcept(InputConcept_MoveDown, false, InputEvent_Key_S, InputAction_KeyUp);
    bindConcept(InputConcept_MoveDown, true, InputEvent_Key_DownArrow, InputAction_KeyDown);
    bindConcept(InputConcept_MoveDown, true, InputEvent_Key_DownArrow, InputAction_KeyRepeat);
    bindConcept(InputConcept_MoveDown, false, InputEvent_Key_DownArrow, InputAction_KeyUp);
}
    
void InputSystem::Update()
{
    Input input;
    while ((input = m_inputHandler->getInput()).event != InputEvent_Invalid)
    {
        std::pair<std::multimap<Input, std::pair<InputConcept, bool>>::iterator, std::multimap<Input, std::pair<InputConcept, bool>>::iterator> binds = m_bindings.equal_range(input);
        
        for (std::multimap<Input, std::pair<InputConcept, bool>>::iterator it = binds.first; it != binds.second; ++it)
        {
            
            std::pair<std::multimap<InputConcept, InputRegistration>::iterator, std::multimap<InputConcept, InputRegistration>::iterator> comps = m_components.equal_range(it->second.first);
            for (std::multimap<InputConcept, InputRegistration>::iterator it2 = comps.first; it2 != comps.second; ++it2)
            {
                InputRegistration reg = it2->second;
                
                reg.callback(reg.component, it2->first, it->second.second);
            }
        }
    }
}

}
