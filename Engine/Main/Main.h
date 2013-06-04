#pragma once

/**
	This class is the platform-independent main class for the engine. It
	handles initialization of all top-level systems and contains the main
	update loop.
*/

#include <thread>

class Main {
private:
    bool _running;
    std::thread *m_mainThread;

    void Initialize();
    
    void Update();
    
    void Shutdown();
    
    
public:
    Main();
    
    
    void Start();
    void Stop();
    
    
    void realMain();

};
