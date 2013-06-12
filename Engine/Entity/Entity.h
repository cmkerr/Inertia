#pragma once

#include <uuid/uuid.h>
#include <list>

class Entity {
private:
    char guid[16];

    Entity();
    Entity(const char[]);
    
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