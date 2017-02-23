/*****************************************************************************/
/*!
@file   Transform.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   2/23/2017
*/
/*****************************************************************************/
#include "Transform.h"
#include "ComponentFactory.h"

namespace Core
{
    REGISTER_CPT("Transform", Transform::Create);

    Transform::Transform() : Component()
    {
        _translation = Math::Vector3(1.0f, 1.0f, 1.0f);
        _rotation    = Math::Vector3(1.0f, 1.0f, 1.0f);
        _scale       = Math::Vector3(1.0f, 1.0f, 1.0f);
    }

    Transform::~Transform()
    {

    }

    Component* Transform::Create()
    {
        return new Transform;
    }

    void Transform::SetTranslation(const Math::Vector3 trans)
    {
        _translation = trans;
    }

    void Transform::SetScale(const Math::Vector3 scale)
    {
        _scale = scale;
    }

    void Transform::SetRotation(const Math::Vector3 rot)
    {
        _rotation = rot;
    }

    void Transform::SetTranslation(float x, float y, float z)
    {
        _translation.SetX(x);
        _translation.SetY(y);
        _translation.SetZ(z);
    }

    void Transform::SetScale(float x, float y, float z)
    {
        _scale.SetX(x);
        _scale.SetY(y);
        _scale.SetZ(z);
    }

    void Transform::SetRotation(float x, float y, float z)
    {
        _rotation.SetX(x);
        _rotation.SetY(y);
        _rotation.SetZ(z);
    }

    Math::Vector3 Transform::GetTranslation() const
    {
        return _translation;
    }

    Math::Vector3 Transform::GetScale() const
    {
        return _scale;
    }

    Math::Vector3 Transform::GetRotation() const
    {
        return _rotation;
    }

    std::ostream& operator<<(std::ostream & os, Transform& transform)
    {
        os << "Transform     " << std::endl;
        os << "---------     " << std::endl;
        os << "Translation:  " << transform._translation << std::endl;
        os << "Scale:        " << transform._scale       << std::endl;
        os << "Rotation:     " << transform._rotation    << std::endl;
        return os;
    }
}