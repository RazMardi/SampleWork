/*****************************************************************************/
/*!
@file   Entity.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   6/19/2016
@brief  contains the implementation for the entity class
*/
/*****************************************************************************/
#include "Entity.h"
#include "Factory.h"
#include "MemoryUtils.h"
#include <stdexcept> /*out_of_range*/

unsigned Entity::_tID = 0;

/******************************************************************************
\fn Entity()
@author Razmig Mardirossian
@brief default constructor, creates a new entity with a unique ID
*******************************************************************************/
Entity::Entity() : _alive(true), _active(true), _mID(IDGenerator()(_tID)){}

/******************************************************************************
\fn ~Entity()
@author Razmig Mardirossian
@brief destructor, free's all components attached to the entity
*******************************************************************************/
Entity::~Entity()
{
    Memory::FreeMapMemory(_components);
}

/******************************************************************************
\fn AddComponent(CPT_TYPE type)
@author Razmig Mardirossian
@brief add's a component to the entity via the factory
@param type the enum type representing the component
*******************************************************************************/
void Entity::AddComponent(CPT_TYPE type)
{
    Component* tempCpt = CREATE_CPT(type);
    _components.emplace(std::make_pair(type, tempCpt));
}

/******************************************************************************
\fn HasComponent(CPT_TYPE type) const
@author Razmig Mardirossian
@brief checks an entity for a given component
@param type the enum type representing the component
@return true if the component is attached to the entity, false otherwise
*******************************************************************************/
bool Entity::HasComponent(CPT_TYPE type) const
{
    try {
        _components.at(type);
    }
    catch (const std::out_of_range&) {
        return false;
    }
    return true;
}

