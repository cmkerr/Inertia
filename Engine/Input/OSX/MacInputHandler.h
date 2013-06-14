#pragma once

#include "Engine/Input/InputHandler.h"
#include "Engine/Input/InputEvents.h"

#include <queue>

#ifdef __OBJC__
#import  <Cocoa/Cocoa.h>
#else
class NSEvent;
typedef void* id;
#endif

#include <mutex>

namespace Inertia {

class MacInputHandler : public InputHandler{
private:
    std::mutex m_mutex;
    std::queue<Input> m_inputQueue;
    
    inline void queueInput(Input);
    inline Input dequeueInput();
    
    InputEvent translateNativeEvent(unsigned short);
    
    id m_eventMonitor;
    void handleEvent(NSEvent *);
    
public:
    virtual void registerEvents();
    virtual void deregisterEvents();
    
    virtual Input getInput();
};

}
