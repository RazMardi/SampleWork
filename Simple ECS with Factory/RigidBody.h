/*****************************************************************************/
/*!
@file   RigidBody.h
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   6/19/2016
@brief  contains the interface for the rigidbody component class
*/
/*****************************************************************************/
#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Component.h"

class RigidBody : public Component
{
public:
    RigidBody();
    ~RigidBody();
    std::string GetName();
    static Component* Create();

private:
    CPT_TYPE _type;
    unsigned _mID;
    std::string _name;
};
#endif
