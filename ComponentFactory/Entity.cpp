/*****************************************************************************/
/*!
@file   Entity.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   2/23/2017
*/
/*****************************************************************************/
#include "Entity.h"
#include "ComponentFactory.h"
#include "IDGenerator.h"

namespace Core
{
    Entity::Entity() : _name("")
    {
        Utilities::IDGenerator::AssignIDToEntity(this);
    }

    Entity::Entity(std::string name) : _name(name)
    {
        Utilities::IDGenerator::AssignIDToEntity(this);
    }

    Entity::~Entity()
    {
        ComponentContainer::iterator it;
        for (it = _components.begin(); it != _components.end(); ++it)
            delete(it->second);
        _components.clear();
    }

    void Entity::AddComponent(std::string name)
    {
        Component* temp = Factory::ComponentFactory::GetInstance().CreateComponent(name);
        temp->SetOwner(this);
        if(!(_components.emplace(name, temp)).second)
            throw EntityException("Component Already Attached to Entity: ", name, _id);
    }

    bool Entity::HasComponent(std::string name) const
    {
        ComponentContainer::const_iterator it;
        it = _components.find(name);
        return (it == _components.end());
    }

    unsigned Entity::GetId() const
    {
        return _id;
    }

    std::string Entity::GetName() const
    {
        return _name;
    }

    const ComponentContainer& Entity::GetComponents() const
    {
        return _components;
    }

    void Entity::SetId(unsigned id)
    {
        _id = id;
    }

    void Entity::SetName(std::string name)
    {
        _name = name;
    }

    std::ostream& operator<<(std::ostream & os, Entity& entity)
    {
        os << "Name:       " << entity._name << std::endl;
        os << "Id:         " << entity._id << std::endl;
        return os;
    }

    EntityException::EntityException(std::string message, std::string name, unsigned id) : std::runtime_error(""),
     _message(message), _name(name), _entityId(id)
    {
        _message.append(_name + " Entity ID: ");
        _message.append(std::to_string(_entityId));
    }

    const char*  EntityException::what() const throw() 
    {
        return _message.c_str();
    }
}