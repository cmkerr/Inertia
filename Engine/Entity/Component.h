#pragma once

#include "Engine/Entity/Entity.h"

namespace Inertia {
    
class Component {
    // It may be beneficial to move to a 2-stage update system:
    // 1) First do an Observe() in which the component can see all other
    //    components but cannot modify itself.
    // 2) Second do an Update() in which the component can modify itself
    //    but can no longer see other components
    //
    // Such a system allows for lockless, parallel updates of components
    // with the only synchronization points being at the ends of the
    // Observe() and Update() steps.
    
public:
    Component(Entity *e) : entity(e) {}
    const Entity *entity;
};

}