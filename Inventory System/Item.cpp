/*****************************************************************************/
/*!
@file   Item.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   6/12/2016
@brief  The item interface used for the created items in the inventory
*/
/*****************************************************************************/
#include "Item.h"

/******************************************************************************
\fn Item(std::string name, unsigned id, unsigned cost, ItemType type)
@brief constructs an item with the given parameters
@param name the name of the item
@oaram id the unique ID representing the item
@param cost how much the item costs
@param type the enum type of the item (Weapon, Armor, Consumable)
*******************************************************************************/
Item::Item(std::string name, unsigned id, unsigned cost, ItemType type)
{
    _name = name;
    _id = id;
    _cost = cost;
    _type = type;
}

/******************************************************************************
\fn std::ostream& operator<<(std::ostream & os, const Item &item)
@brief overloads the << operator to print the contents of the item
@param os a reference to the ostream object
@param item a reference to the item being printed
*******************************************************************************/
std::ostream& operator<<(std::ostream & os, const Item &item)
{
    os << "Name: " << item._name << std::endl;
    os << "ID: "   << item._id << std::endl;
    os << "Cost: " << item._cost << std::endl;
    os << "Type: " << item._type << std::endl;
    return os;
}
