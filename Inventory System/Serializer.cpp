/*****************************************************************************/
/*!
@file   Serializer.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   6/12/2016
@brief  Used to parse the JSON file and construct the initial items in the inventory
*/
/*****************************************************************************/
#include "Serializer.h"
#include "rapidjson/error/en.h" /*GetParseError_En*/
#include <sstream>              /*stringstream*/
#include <fstream>              /*ifstream*/

/******************************************************************************
\fn Serializer(const std::string& jsonFile)
@brief the constructor for the serializer 
@param jsonFile the file being parsed 
*******************************************************************************/
Serializer::Serializer(const std::string& jsonFile)
{
    std::stringstream ss;
    std::ifstream ifs;
    ifs.open(jsonFile.c_str(), std::ios::binary);
    ss << ifs.rdbuf(); 
    ifs.close();

    if (_doc.Parse<0>(ss.str().c_str()).HasParseError()) {
        fprintf(stderr, "\nError(offset %u): %s\n",
            (unsigned)_doc.GetErrorOffset(),
            GetParseError_En(_doc.GetParseError()));
    }
}

/******************************************************************************
\fn PopulateInventory(Inventory* inv)
@brief populates the inventory with items found in the parsed JSON file
@param inv a pointer to the inventory
*******************************************************************************/
void Serializer::PopulateInventory(Inventory* inv)
{
    const rapidjson::Value& inventory = _doc["Inventory"];

    for (rapidjson::SizeType i = 0; i < inventory.Size(); i++) {
        unsigned id = inventory[i]["id"].GetUint();
        std::string name = inventory[i]["name"].GetString();
        unsigned cost = inventory[i]["cost"].GetUint();
        unsigned type = inventory[i]["type"].GetUint();
        Item temp = { name, id, cost, static_cast<ItemType>(type) };
        inv->AddItem(temp);
    }
}
