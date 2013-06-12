#pragma once

#include "Entity.h"
#include "Component.h"

#include <map>


template <class T>
class ComponentManager {
private:
    std::map<Entity*, T*> m_components;
    
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
        typename std::map<Entity*, T*>::iterator it = m_components.begin();
        for (; it != m_components.end(); ++it)
        {
            if (it->second == component)
            {
                m_components.erase(it);
                break;
            }
        }
    }
    
    
    class iterator : public std::map<Entity*, T*>::iterator {
    private:
        iterator(typename std::map<Entity*, T*>::iterator it) : std::map<Entity*, T*>::iterator(it)
        {
            entity = ((typename std::map<Entity*, T*>::iterator) *this)->first;
            component = ((typename std::map<Entity*, T*>::iterator) *this)->second;
        }
        friend ComponentManager<T>;
    public:
        Entity *entity;
        T *component;
        
        iterator() : std::map<Entity*, T*>::iterator()
        {
            //entity =
            entity = nullptr;
            component = nullptr; //((typename std::map<Entity*, T*>::iterator) *this)->first;
        }

        iterator& operator++()
        {
            std::map<Entity*, T*>::iterator::operator++();

            entity = ((typename std::map<Entity*, T*>::iterator) *this)->first;
            component = ((typename std::map<Entity*, T*>::iterator) *this)->second;
            
            return *this;
        }
        iterator operator++(int)
        {
            iterator ret = *this;
            std::map<Entity*, T*>::iterator::operator++();
            
            entity = ((typename std::map<Entity*, T*>::iterator) *this)->first;
            component = ((typename std::map<Entity*, T*>::iterator) *this)->second;
            
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

/*
template <class T>
class ComponentManager {
private:
    static ComponentManager<T> *s_manager;
    
    std::map<Entity, T*> m_components;
    
public:
    class iterator;
    
    void addComponent(Entity& entity, T* component)
    {
        m_components.insert(std::pair<Entity, T*>(entity, component ));
    }
    
    void removeComponent(Entity& entity)
    {
        m_components.erase(entity);
    }
    
    T* getComponent(Entity& e)
    {
        T* comp = nullptr;
        
        typename std::map<Entity, T*>::iterator it = m_components.find(e);
        if (it != m_components.end())
            comp = it->second;
        
        return comp;
    }
    
    
    ComponentManager<T>::iterator begin()
    {
        ComponentManager<T>::iterator it;
        it.it = m_components.begin();
        
        it.entity = it.it->first;
        it.component = it.it->second;
        
        return it;
    }
    
    ComponentManager<T>::iterator end()
    {
        ComponentManager<T>::iterator it;
        it.it = m_components.end();
        
        it.entity = it.it->first;
        it.component = it.it->second;
        
        return it;
    }
    
    static ComponentManager<T>* Instance()
    {
        if (!s_manager)
            s_manager = new ComponentManager<T>();
        
        return s_manager;
    }
    
    class iterator {
    private:
        typename std::map<Entity, T*>::iterator it;
    public:
        Entity entity;
        T* component;
        
        friend bool operator==(const ComponentManager<T>::iterator& i1, const ComponentManager<T>::iterator& i2);// {return i1.it == i2.it; }
        friend bool operator!=(const ComponentManager<T>::iterator& i1, const ComponentManager<T>::iterator& i2);// {return i1.it != i2.it; }
        
        iterator& operator++()
        {
            ++it;
            
            entity = it->first;
            component = it->second;
            
            return *this;
        }
        
        iterator operator++(int)
        {
            iterator old = *this;
            
            ++it;
            
            entity = it->first;
            component = it->second;
            
            return old;
        }
        
        friend class ComponentManager;
    };
};

template <class T>
bool operator==(const typename ComponentManager<T>::iterator& i1, const typename ComponentManager<T>::iterator& i2) {return i1.it == i2.it; }

template <class T>
bool operator!=(const typename ComponentManager<T>::iterator& i1, const typename ComponentManager<T>::iterator& i2) {return i1.it != i2.it; }

template <class T>
ComponentManager<T>* ComponentManager<T>::s_manager = nullptr;
*/