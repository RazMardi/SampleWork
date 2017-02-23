/*****************************************************************************/
/*!
@file   Component.h
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   2/23/2017
@brief  the interface for the base component class. Components must be 
registered to the ComponentFactory inside their implementation files to 
ensure they can be properly constructed via the factory.
*/
/*****************************************************************************/
#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

namespace Core
{
    class Entity;

    class Component
    {
    public:
        Component(){}
        virtual ~Component() {}

        void SetOwner(Entity* entity)         { _owner = entity; }
        void SetName(std::string name)        { _name = name;    }
        const std::string&  GetName()  const  { return _name;    }
        Entity*             GetOwner() const  { return _owner;   }

    protected:
        std::string _name;
        Entity* _owner;
    };
}
#endif