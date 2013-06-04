#include "Main.h"

#define JOB_MANAGER_THREADS 4

using std::thread;

#include <pthread.h>

Main::Main(): _running(false), m_mainThread(nullptr) {}

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

void Main::realMain()
{
    // Initialize
    Initialize();
    
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
    
}

void Main::Shutdown()
{
    m_jobManager->Shutdown();
    delete m_jobManager;
}

void Main::Update()
{
    
    
}