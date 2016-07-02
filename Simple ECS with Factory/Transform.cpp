/*****************************************************************************/
/*!
@file   Tranform.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   6/19/2016
@brief  contains the implementation of the Tranform class
*/
/*****************************************************************************/
#include "Transform.h"

/******************************************************************************
\fn Transform()
@author Razmig Mardirossian
@brief default constructor, creates a new Transform with a unique ID
*******************************************************************************/
Transform::Transform() : 
    _type(CPT_Transform), 
    _mID(IDGenerator()(Component::cptID)),
    _name("Transform"){}

/******************************************************************************
\fn ~Transform()
@author Razmig Mardirossian
@brief destructor
*******************************************************************************/
Transform::~Transform() {}

/******************************************************************************
\fn Create()
@author Razmig Mardirossian
@brief allocates memory for a Transform instance
@return Component*, a pointer to a newly created Transform instance
*******************************************************************************/
Component* Transform::Create() 
{ 
    return new Transform; 
}

/******************************************************************************
\fn GetName()
@author Razmig Mardirossian
@brief gets the name of the component
@return a std::string, the name of the component
*******************************************************************************/
std::string Transform::GetName()
{
    return _name; 
}
