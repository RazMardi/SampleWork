/*****************************************************************************/
/*!
@file   Factory.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   6/19/2016
@brief  contains the implementation for the Factory class
*/
/*****************************************************************************/
#include "Factory.h"

Factory* Factory::_mFactory = nullptr;
CPTCreatorMap Factory::_mCPTCreatorMap(0);

/******************************************************************************
\fn Create()
@author Razmig Mardirossian
@brief creates a factory instance if one does not currently exists
*******************************************************************************/
void Factory::Create()
{
    if (!_mFactory)
        _mFactory = new Factory;
}

/******************************************************************************
\fn Init()
@author Razmig Mardirossian
@brief adds the respective components Create() function pointers to the map
*******************************************************************************/
void Factory::Init()
{
    _mCPTCreatorMap[CPT_Transform] = Transform::Create;
    _mCPTCreatorMap[CPT_RigidBody] = RigidBody::Create;
}

/******************************************************************************
\fn CreateEntity()
@author Razmig Mardirossian
@brief creates a raw entity class without components
@return Entity*, a pointer to the newly created Entity
*******************************************************************************/
Entity* Factory::CreateEntity()
{
    return new Entity;
}

/******************************************************************************
\fn Destroy()
@author Razmig Mardirossian
@brief frees the memory allocated in Create() for the factory instance
*******************************************************************************/
void Factory::Destroy()
{
    delete _mFactory;
}
