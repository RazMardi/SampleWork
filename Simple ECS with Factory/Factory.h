/*****************************************************************************/
/*!
@file   Factory.h
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   6/19/2016
@brief  a singleton factory class used to create objects and components
*/
/*****************************************************************************/
#ifndef FACTORY_H
#define FACTORY_H

#include "Entity.h"
#include "ComponentIncludes.h"
#include <string>
#include <unordered_map>

typedef Component* (*ComponentType)();
typedef std::unordered_map<CPT_TYPE, ComponentType> CPTCreatorMap;

#define CREATE_CPT( cpttype ) \
    ((*Factory::GetCreatorMap())[cpttype])();

class Factory
{
public:
    static void Create();
    static void Init();
    static void Destroy();
    static Entity* CreateEntity();
    static Factory* GetInstance() { return _mFactory; }
    static CPTCreatorMap* GetCreatorMap() { return &_mCPTCreatorMap; }

private:
    Factory(){}
    static Factory* _mFactory;
    static CPTCreatorMap _mCPTCreatorMap;
};
#endif