#pragma once

/**
	This class is the platform-independent main class for the engine. It
	handles initialization of all top-level systems and contains the main
	update loop.
*/

#include "Engine/Job/JobManager.h"
#include "Engine/Main/Window.h"
#include "Engine/Render/RenderSystem.h"

#include <thread>

class Main {
private:
    bool _running;
    std::thread *m_mainThread;
    
    Window *m_window;
    JobManager *m_jobManager;
    RenderSystem *m_renderSystem;
    
    void Initialize();
    void Update();
    void Shutdown();

    void realMain();
    
public:
    static Main *s_Main;
    
    Main(Window *);
    
    void Start();
    void Stop();
    
    bool IsRunning();
    
    friend std::thread;
};
