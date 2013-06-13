#include "Entity.h"

#include <cstring>


namespace Inertia {

std::list<Entity*> Entity::s_entities;

Entity::Entity()
{
    memset(guid, 0, sizeof(guid));
}

Entity::Entity(const char _guid[])
{
    strncpy(guid, _guid, sizeof(guid));
}

Entity* Entity::createEntity()
{
    Entity::s_entities.push_back(new Entity());
    
    return s_entities.back();
}

Entity* Entity::createEntity(const char guid[])
{
    Entity::s_entities.push_back(new Entity(guid));
    return s_entities.back();
}

/*
Entity::Entity(const Entity& e)
{
    strncpy(guid, e.guid, sizeof(guid));
}

Entity& Entity::operator=(const Entity& e)
{
    strncpy(guid, e.guid, sizeof(guid));
    
    return *this;
}
 */

/*
bool operator< (const Entity& e1, const Entity& e2)
{
    return strncmp(e1.guid, e2.guid, sizeof(e1.guid)) < 0;
}

bool operator<= (const Entity& e1, const Entity& e2)
{
    return strncmp(e1.guid, e2.guid, sizeof(e1.guid)) <= 0;
}

bool operator>= (const Entity& e1, const Entity& e2)
{
    return strncmp(e1.guid, e2.guid, sizeof(e1.guid)) >= 0;
}

bool operator> (const Entity& e1, const Entity& e2)
{
    return strncmp(e1.guid, e2.guid, sizeof(e1.guid)) > 0;
}*/

bool operator== (const Entity& e1, const Entity& e2)
{
    return strncmp(e1.guid, e2.guid, sizeof(e1.guid)) == 0;
}

bool operator!= (const Entity& e1, const Entity& e2)
{
    return strncmp(e1.guid, e2.guid, sizeof(e1.guid)) != 0;
}

}