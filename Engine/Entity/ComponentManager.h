#pragma once

#include "Entity.h"
#include "Component.h"

#include "External/btree/btree_map.h"

template <class T>
class ComponentManager {
private:
    btree::btree_map<Entity*, T*> m_components;
    
    static ComponentManager<T> s_manager;
public:
    
    void addComponent(Entity* entity, T* component)
    {
        m_components.insert(std::pair<Entity*, T*>(entity, component));
    }
    
    void removeComponent(Entity* entity)
    {
        m_components.erase(entity);
    }
    
    void removeComponent(T* component)
    {
        typename btree::btree_map<Entity*, T*>::iterator it = m_components.begin();
        for (; it != m_components.end(); ++it)
        {
            if (it->second == component)
            {
                m_components.erase(it);
                break;
            }
        }
    }
    
    
    class iterator : public btree::btree_map<Entity*, T*>::iterator {
    private:
        iterator(typename btree::btree_map<Entity*, T*>::iterator it) : btree::btree_map<Entity*, T*>::iterator(it)
        {
            entity = ((typename btree::btree_map<Entity*, T*>::iterator) *this)->first;
            component = ((typename btree::btree_map<Entity*, T*>::iterator) *this)->second;
        }
        friend ComponentManager<T>;
    public:
        Entity *entity;
        T *component;
        
        iterator() : btree::btree_map<Entity*, T*>::iterator()
        {
            //entity =
            entity = nullptr;
            component = nullptr; //((typename std::map<Entity*, T*>::iterator) *this)->first;
        }

        iterator& operator++()
        {
            btree::btree_map<Entity*, T*>::iterator::operator++();

            entity = ((typename btree::btree_map<Entity*, T*>::iterator) *this)->first;
            component = ((typename btree::btree_map<Entity*, T*>::iterator) *this)->second;
            
            return *this;
        }
        iterator operator++(int)
        {
            iterator ret = *this;
            btree::btree_map<Entity*, T*>::iterator::operator++();
            
            entity = ((typename btree::btree_map<Entity*, T*>::iterator) *this)->first;
            component = ((typename btree::btree_map<Entity*, T*>::iterator) *this)->second;
            
            return ret;
        }
        
    };
    
    iterator begin()
    {
        return iterator(m_components.begin());
    }
    
    iterator end()
    {
        return iterator(m_components.end());
    }
    
    static ComponentManager<T>* Instance() { return &s_manager; }
};

template <class T>
ComponentManager<T> ComponentManager<T>::s_manager;

