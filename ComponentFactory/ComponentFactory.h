/*****************************************************************************/
/*!
@file   ComponentFactory.h
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   2/23/2017
@brief  the interface for the ComponentFactory class, ComponentFactoryExeption
class and the Registrar class. The component factory is responsible for 
holding all metadata related to component construction. The registrar is 
responsible for registering components for construction. 
*/
/*****************************************************************************/
#ifndef COMPONENT_FACTORY_H
#define COMPONENT_FACTORY_H

#include <map>
#include <typeindex>
#include "Component.h"

#define REGISTER_CPT(name, callback) \
static Factory::Registrar registrar(name, callback) 

namespace Factory
{
    typedef Core::Component*(*CreateComponent)();
    typedef std::map<std::string, CreateComponent> ComponentMap;
     
    class ComponentFactory
    {
    public:
        void RegisterComponent           (std::string name, CreateComponent callback);
        void UnRegisterComponent         (std::string name);
        Core::Component* CreateComponent (std::string name);
        static ComponentFactory& GetInstance();

    private:
        ComponentFactory(){}
        ComponentFactory(const ComponentFactory&) {}
        ComponentMap       _componentMap;
    };

    class ComponentFactoryException : public std::runtime_error
    {
    public:
        ComponentFactoryException(std::string message, std::string name);
        const char* what() const throw() override;

    private:
        std::string _message;
        std::string _name;
    };

    class Registrar 
    {
    public:
        Registrar(std::string className, CreateComponent callback)
        {
            ComponentFactory::GetInstance().RegisterComponent(className, callback);
        }
    };
}
#endif
