#pragma once
#include "InputEvents.h"

namespace Inertia {

class InputHandler {
public:
    virtual ~InputHandler() {};
    
    virtual void registerEvents() = 0;
    virtual void deregisterEvents() = 0;
    
    virtual Input getInput() = 0;
};

}