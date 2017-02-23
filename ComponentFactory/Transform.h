/*****************************************************************************/
/*!
@file   Transform.h
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   2/23/2017
@brief  contains the interface for the Transform component class.
*/
/*****************************************************************************/
#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"
#include "Math.h"

namespace Core
{
    class Transform : public Component
    {
    public:
        Transform();
        ~Transform();

        static Component* Create();

        void SetTranslation(const Math::Vector3 trans);
        void SetScale(const Math::Vector3 scale);
        void SetRotation(const Math::Vector3 rot);

        void SetTranslation(float x, float y, float z);
        void SetScale(float x, float y, float z);
        void SetRotation(float x, float y, float z);

        Math::Vector3 GetTranslation() const;
        Math::Vector3 GetScale()       const;
        Math::Vector3 GetRotation()    const;

        friend std::ostream& operator<<(std::ostream & os, Transform& trans);

    private:
        Math::Vector3 _translation;
        Math::Vector3 _scale;
        Math::Vector3 _rotation;
    };
}
#endif