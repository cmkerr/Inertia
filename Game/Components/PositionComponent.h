#pragma once

#include "Engine/Entity/Component.h"

class PositionComponent : public Component {
private:
    double x, y, z;
    
public:
    PositionComponent(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
};