/*****************************************************************************/
/*!
@file   Serializer.h
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   6/12/2016
@brief  contains the interface of the Serializer class
*/
/*****************************************************************************/
#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "Inventory.h"
#include "rapidjson/document.h"
#include <string>

class Serializer
{
public:
    Serializer(const std::string& jsonFile);
    void PopulateInventory(Inventory* inventory);

private:
    rapidjson::Document _doc;
};

#endif