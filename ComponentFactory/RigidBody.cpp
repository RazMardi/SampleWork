/*****************************************************************************/
/*!
@file   RigidBody.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   2/23/2017
*/
/*****************************************************************************/
#include "RigidBody.h"
#include "ComponentFactory.h"

namespace Core
{
    REGISTER_CPT("RigidBody", RigidBody::Create);

    RigidBody::RigidBody() : Component()
    {
        _mass = 1.0f;
        _restitution = 0.0f;
        _isTrigger = false;
        _isKinematic = false;
        _isStatic = false;
    }

    RigidBody::~RigidBody()
    {

    }

    Component* RigidBody::Create()
    {
        return new RigidBody;
    }

    void RigidBody::SetKinematic(bool value)
    {
        _isKinematic = value;
    }

    void RigidBody::SetStatic(bool value)
    {
        _isStatic = value;
    }

    void RigidBody::SetTrigger(bool value)
    {
        _isTrigger = value;
    }

    void RigidBody::SetRestitution(float value)
    {
        _restitution = value;
    }

    void RigidBody::SetMass(float value)
    {
        _mass = value;
    }

    bool RigidBody::GetKinematic() const
    {
        return _isKinematic;
    }

    bool RigidBody::GetStatic() const
    {
        return _isStatic;
    }

    bool RigidBody::GetTrigger() const
    {
        return _isTrigger;
    }

    float RigidBody::GetRestitution() const
    {
        return _restitution;
    }

    float RigidBody::GetMass() const
    {
        return _mass;
    }

    std::ostream& operator<<(std::ostream & os, RigidBody& rigidbody)
    {
        os << "RigidBody    "  << std::endl;
        os << "---------    " << std::endl;
        os << "Mass:        "  << rigidbody._mass        << std::endl;
        os << "Kinematic:   "  << rigidbody._isKinematic << std::endl;
        os << "Static:      "  << rigidbody._isStatic    << std::endl;
        os << "Trigger:     "  << rigidbody._isTrigger   << std::endl;
        os << "Restitution: "  << rigidbody._restitution << std::endl;
        return os;
    }
}