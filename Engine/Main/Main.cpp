#include "Main.h"

using std::thread;

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
    
}

void Main::Shutdown()
{
    
}

void Main::Update()
{
    
    
}