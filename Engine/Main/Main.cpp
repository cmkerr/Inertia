#include "Main.h"

#include "Game/Components/PositionComponent.h"
#include "Game/Components/LocomotionComponent.h"
#include "Engine/Entity/ComponentManager.h"

#define JOB_MANAGER_THREADS 4

using std::thread;

namespace Inertia {

Main *Main::s_Main = nullptr;

Main::Main(Window *window):
    _running(false),
    m_mainThread(nullptr),
    m_window(window)
{
}

void Main::Start()
{
    _running = true;
    m_mainThread = new thread(&Main::realMain, this);
}

void Main::Stop()
{
    _running = false;
    
    m_mainThread->join();
    delete m_mainThread;
}

bool Main::IsRunning()
{
    return _running;
}

void Main::realMain()
{
#ifdef __APPLE__
    pthread_setname_np("Update Thread");
#endif
     
    // Initialize
    Initialize();
    
    m_window->Show();
    
    
    // Update Loop
    while (_running)
    {
        Update();        
        std::this_thread::yield();
    }
    
    // Shutdown
    Shutdown();
}

void test(Component* comp, InputConcept input, bool value)
{
    LocomotionComponent * loco = (LocomotionComponent*) comp;
    switch (input)
    {
        case InputConcept_MoveLeft:
            loco->movingLeft = value;
            break;
        case InputConcept_MoveRight:
            loco->movingRight = value;
            break;
        case InputConcept_MoveUp:
            loco->movingUp = value;
            break;
        case InputConcept_MoveDown:
            loco->movingDown = value;
            break;
        default:
            break;
    }
}
    
void Main::Initialize()
{
    m_jobManager = new JobManager();
    m_jobManager->Initialize(JOB_MANAGER_THREADS);
    
    m_renderSystem = new RenderSystem();
    m_renderSystem->Initialize(m_window);
    
    m_inputSystem = new InputSystem();
    m_inputSystem->Initialize();
    
    //ERMAGERD HARDCODES
    Entity *e1 = Entity::createEntity("1234512345123451");
    ComponentManager<PositionComponent>::Instance()->addComponent(e1, new PositionComponent(e1, 0,0,-5));
    ComponentManager<LocomotionComponent>::Instance()->addComponent(e1, new LocomotionComponent(e1));
    
    Entity *e2 = Entity::createEntity("12345123451234512");
    ComponentManager<PositionComponent>::Instance()->addComponent(e2, new PositionComponent(e2, 5,0,-5));
    ComponentManager<LocomotionComponent>::Instance()->addComponent(e2, new LocomotionComponent(e2));
    
    Entity *e3 = Entity::createEntity("12345123451234513");
    ComponentManager<PositionComponent>::Instance()->addComponent(e3, new PositionComponent(e3, 0,0,0));
    
    ComponentManager<LocomotionComponent>::iterator it = ComponentManager<LocomotionComponent>::Instance()->begin();
    ComponentManager<LocomotionComponent>::iterator end = ComponentManager<LocomotionComponent>::Instance()->end();
    for (; it != end; ++it)
    {
        m_inputSystem->registerComponent(it.component, InputConcept_MoveLeft, test);
        m_inputSystem->registerComponent(it.component, InputConcept_MoveRight, test);
        m_inputSystem->registerComponent(it.component, InputConcept_MoveUp, test);
        m_inputSystem->registerComponent(it.component, InputConcept_MoveDown, test);
    }
    // END OF HARDCODES
}

void Main::Shutdown()
{
    m_inputSystem->Shutdown();
    delete m_inputSystem;
    
    m_renderSystem->Shutdown();
    delete m_renderSystem;
    
    m_jobManager->Shutdown();
    delete m_jobManager;
}


void Main::Update()
{
    m_inputSystem->Update();
    
    // AI
    
    // Physics
    ComponentManager<LocomotionComponent>::iterator it = ComponentManager<LocomotionComponent>::Instance()->begin();
    ComponentManager<LocomotionComponent>::iterator end = ComponentManager<LocomotionComponent>::Instance()->end();
    for (; it != end; ++it)
    {
        PositionComponent* pos = ComponentManager<PositionComponent>::Instance()->getComponent(it.entity);
        LocomotionComponent* loco = it.component;
        if (loco->movingLeft)
        {
            pos->x -= 0.1;
        }
        if (loco->movingRight)
        {
            pos->x += 0.1;
        }
        if (loco->movingUp)
        {
            pos->y += 0.1;
        }
        if (loco->movingDown)
        {
            pos->y -= 0.1;
        }
    }
    
    
    m_renderSystem->Draw();
}
    
}
