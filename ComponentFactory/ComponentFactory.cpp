/*****************************************************************************/
/*!
@file   ComponentFactory.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   2/23/2017
*/
/*****************************************************************************/
#include "ComponentFactory.h"

namespace Factory
{
    ComponentFactory& ComponentFactory::GetInstance()
    {
        static ComponentFactory _instance;
        return _instance;
    }

    void ComponentFactory::RegisterComponent(std::string name, Factory::CreateComponent callback)
    {
        if (!_componentMap.insert(std::make_pair(name, callback)).second)
            throw ComponentFactoryException("Unable To Register Component: ", name);
    }

    void ComponentFactory::UnRegisterComponent(std::string name)
    {
        if(!_componentMap.erase(name) == 1)
            throw ComponentFactoryException("Unable To Unregister Component: ", name);
    }

    Core::Component* ComponentFactory::CreateComponent(std::string name)
    {
        ComponentMap::const_iterator it = _componentMap.find(name);
        if (it == _componentMap.end())
        {
            throw ComponentFactoryException("Unknown Component: ", name);
        }
        Core::Component* retVal = (it->second)();
        return retVal;
    }

    ComponentFactoryException::ComponentFactoryException(std::string message, std::string name) : std::runtime_error(""),
    _message(message), _name(name)
    {
        _message.append(_name);
    }

    const char*  ComponentFactoryException::what() const throw()
    {
        return _message.c_str();
    }
}