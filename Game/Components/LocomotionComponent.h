#pragma once

#include "Engine/Entity/Component.h"

namespace Inertia {

class LocomotionComponent : public Component {
public:
    bool movingRight = false;
    bool movingLeft = false;
    bool movingUp = false;
    bool movingDown = false;
    
    LocomotionComponent(Entity *e) : Component(e) {}
};

}