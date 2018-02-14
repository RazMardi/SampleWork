/*****************************************************************************/
/*!
@file   RigidBody.h
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   2/23/2017
@brief  contains the interface for the RigidBody component class. 
*/
/*****************************************************************************/
#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "Component.h"

namespace Core
{
    class RigidBody : public Component
    {
    public:
        RigidBody();
        ~RigidBody();

        static Component* Create();

        void SetKinematic(bool  value);
        void SetStatic(bool  value);
        void SetTrigger(bool  value);
        void SetRestitution(float value);
        void SetMass(float value);

        bool  GetKinematic()   const;
        bool  GetStatic()      const;
        bool  GetTrigger()     const;
        float GetRestitution() const;
        float GetMass()        const;

        friend std::ostream& operator<<(std::ostream & os, RigidBody& rigidbody);
        static std::string name;

    private:
        bool  _isKinematic;
        bool  _isStatic;
        bool  _isTrigger;
        float _restitution;
        float _mass;
    };
}
#endif