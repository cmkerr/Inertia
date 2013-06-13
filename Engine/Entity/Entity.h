#pragma once

#include <uuid/uuid.h>
#include <list>


namespace Inertia {

class Entity {
private:
    char guid[16];

    Entity();
    Entity(const char[]);
    
    // Disallow copying of Entities.
    // Pointers to the entity should be used instead.
    Entity(const Entity&);
    Entity& operator= (const Entity&);
    
    
    static std::list<Entity*> s_entities;
public:

    static Entity* createEntity();
    static Entity* createEntity(const char[]);
    
    /*
    friend bool operator< (const Entity&, const Entity&);
    friend bool operator<= (const Entity&, const Entity&);
    friend bool operator>= (const Entity&, const Entity&);
    friend bool operator> (const Entity&, const Entity&);
     */
    friend bool operator== (const Entity&, const Entity&);
    friend bool operator!= (const Entity&, const Entity&);
};

}