/*****************************************************************************/
/*!
@file   Transform.h
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   6/19/2016
@brief  contains the interface for the transform component class
*/
/*****************************************************************************/
#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"

class Transform : public Component
{
public:
    Transform();
    ~Transform();
    std::string GetName();
    static Component* Create();

private:
    CPT_TYPE _type;
    unsigned _mID;
    std::string _name;
};
#endif