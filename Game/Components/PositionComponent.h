#pragma once

#include "Engine/Entity/Component.h"


namespace Inertia {

class PositionComponent : public Component {
private:
        
public:
    double x, y, z;

    PositionComponent(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
};

}