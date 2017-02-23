/*****************************************************************************/
/*!
@file   Entity.h
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   2/23/2017
@brief  the interface for the entity class and EntityException class.
*/
/*****************************************************************************/
#ifndef ENTITY_H
#define ENTITY_H

#include "Component.h"
#include <iostream>    /* std::cout          */
#include <map>         /* std::map           */
#include <stdexcept>   /* std::runtime_error */
#include <typeindex>   /* std::type_index    */

namespace Core
{
    typedef std::map<std::string, Component*> ComponentContainer;

    class Entity
    {
    public:
        Entity();
        ~Entity();
        Entity(std::string name);

        void                      AddComponent(std::string name);
        bool                      HasComponent(std::string name) const;
        unsigned                  GetId()          const;
        std::string               GetName()        const;
        const ComponentContainer& GetComponents()  const;
        template <typename T> T*  GetComponent();
        void                      SetId(unsigned id);
        void                      SetName(std::string name);

        friend std::ostream& operator<<(std::ostream & os, Entity& entity);

    private:
        ComponentContainer _components;
        std::string        _name;
        unsigned           _id;
    };

    class EntityException : public std::runtime_error
    {
    public:
        EntityException(std::string message, std::string name, unsigned id);
        const char* what() const throw() override;

    private:
        std::string _message;
        std::string _name;
        unsigned    _entityId;
    };
}

namespace Core
{
    template <typename T>
    T* Entity::GetComponent()
    {
        std::type_index tIndex = typeid(T);
        for (ComponentContainer::const_iterator it = _components.begin(); it != _components.end(); ++it)
        {
            std::type_index index = typeid(*it->second);
            if (tIndex == index)
                return static_cast<T*>(it->second);
        }
        throw EntityException("GetComponent: ", tIndex.name(), _id);
    }
}
#endif
