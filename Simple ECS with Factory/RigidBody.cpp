/*****************************************************************************/
/*!
@file   RigidBody.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   6/19/2016
@brief  contains the implementation of the RigidBody class
*/
/*****************************************************************************/
#include "RigidBody.h"

/******************************************************************************
\fn RigidBody() 
@author Razmig Mardirossian
@brief default constructor, creates a new Rigidbody with a unique ID
*******************************************************************************/
RigidBody::RigidBody() :
    _type(CPT_RigidBody),
    _mID(IDGenerator()(Component::cptID)),
    _name("RigidBody") {}

/******************************************************************************
\fn ~RigidBody()
@author Razmig Mardirossian
@brief destructor
*******************************************************************************/
RigidBody::~RigidBody() {}

/******************************************************************************
\fn Create() 
@author Razmig Mardirossian
@brief allocates memory for a RigidBody instance
@return Component*, a pointer to a newly created RigidBody instance
*******************************************************************************/
Component* RigidBody::Create() 
{
    return new RigidBody; 
}

/******************************************************************************
\fn GetName() 
@author Razmig Mardirossian
@brief gets the name of the component
@return a std::string, the name of the component
*******************************************************************************/
std::string RigidBody::GetName() 
{
    return _name; 
}
