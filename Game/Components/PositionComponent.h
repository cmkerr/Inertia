#pragma once

#include "Engine/Entity/Component.h"


namespace Inertia {

class PositionComponent : public Component {
private:
        
public:
    double x, y, z;

    PositionComponent(Entity *e, double _x, double _y, double _z) : Component(e), x(_x), y(_y), z(_z) {}
};

}