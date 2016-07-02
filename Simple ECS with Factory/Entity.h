/*****************************************************************************/
/*!
@file   Entity.h
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   6/19/2016
@brief  the base entity class used to represent all objects in the world
*/
/*****************************************************************************/
#ifndef ENTITY_H
#define ENTITY_H

#include "Component.h"
#include <unordered_map>
#include <assert.h>

#define GETCPT( cpttype ) \
GetComponent< cpttype >(CPT_##cpttype)

typedef std::unordered_map<CPT_TYPE, Component*> ComponentMap;

class Entity 
{
public:
    Entity();
    ~Entity();

    void AddComponent(CPT_TYPE type);
    bool HasComponent(CPT_TYPE type) const;

    //settors
    void SetName(std::string name) { _name = name;     }
    void SetAlive(bool alive)      { _alive = alive;   }
    void SetActive(bool active)    { _active = active; }

    //gettors
    const bool  IsAlive() const  { return _alive; }
    const bool  IsActive() const { return _active;}
    unsigned    GetId()   const  { return _mID;   }
    std::string GetName() const  { return _name;  }
    template <typename T> T* GetComponent(CPT_TYPE type);

private:
    ComponentMap _components;
    std::string _name;
    bool _alive;
    bool _active;
    unsigned _mID;
    static unsigned _tID;
};

template <typename T>
T* Entity::GetComponent(CPT_TYPE type) {
    assert(!(_components.find(type) == _components.end()));
    return static_cast<T*>(_components[type]);
}
#endif
