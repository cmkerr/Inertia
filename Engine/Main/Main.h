#pragma once

/**
	This class is the platform-independent main class for the engine. It
	handles initialization of all top-level systems and contains the main
	update loop.
*/

#include "Engine/Job/JobManager.h"

#include <thread>

class Main {
private:
    bool _running;
    std::thread *m_mainThread;

    JobManager *m_jobManager;
    
    void Initialize();
    
    void Update();
    
    void Shutdown();
    
    
public:
    Main();
    
    
    void Start();
    void Stop();
    
    
    void realMain();

};
