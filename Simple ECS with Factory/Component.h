/*****************************************************************************/
/*!
@file   Component.h
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   6/19/2016
@brief  the interface for the component class including the enumeration for
the component types
*/
/*****************************************************************************/
#ifndef COMPONENT_H
#define COMPONENT_H

#include "IDGenerator.h"
#include <iostream>
#include <string>

enum  CPT_TYPE 
{
    CPT_Transform,
    CPT_RigidBody
};

class Component
{
public:
    Component();
    virtual ~Component();

protected:
    static unsigned cptID;
};
#endif
