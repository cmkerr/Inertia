
#include "InputSystem.h"

#include "InputConcepts.h"
#include "InputEvents.h"

#ifdef __APPLE__
#include "Engine/Input/OSX/MacInputHandler.h"
#endif

namespace Inertia {

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
}

void InputSystem::Shutdown()
{
    m_inputHandler->deregisterEvents();
    delete m_inputHandler;
}

void InputSystem::registerComponent(Component*, InputConcept)
{
    
}

void InputSystem::Update()
{
    Input i;
    while ((i = m_inputHandler->getInput()).event != InvalidEvent)
    {
        printf ("%d %d %d %d\n", i.event, i.action, i.value1, i.value2);

        
        
    }
}

}
