#include "Main.h"

#define JOB_MANAGER_THREADS 4

using std::thread;

Main *Main::s_Main = nullptr;

Main::Main(Window *window): _running(false), m_mainThread(nullptr), m_window(window) {}

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


void Main::Initialize()
{
    m_jobManager = new JobManager();
    m_jobManager->Initialize(JOB_MANAGER_THREADS);
    
    m_renderSystem = new RenderSystem();
    m_renderSystem->Initialize(m_window);
}

void Main::Shutdown()
{
    m_renderSystem->Shutdown();
    delete m_renderSystem;
    
    m_jobManager->Shutdown();
    delete m_jobManager;
}


void Main::Update()
{
    m_renderSystem->Draw();
}
