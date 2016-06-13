/*****************************************************************************/
/*!
@file   Item.h
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   6/12/2016
@brief  contains the interface of the Item class
*/
/*****************************************************************************/
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

enum ItemType { Weapon, Armor, Consumable };
class Item
{
public:
    Item(std::string name, unsigned id, unsigned cost, ItemType type);
    
    //Settors
    void SetName(std::string name) { _name = name; }
    void SetID(unsigned id)        { _id = id;     }
    void SetCost(unsigned cost)    { _cost = cost; }
    void SetType(ItemType type)    { _type = type; }

    //Gettors
    std::string GetName() const { return _name; }
    unsigned GetID() const      { return _id;   }
    unsigned GetCost() const    { return _cost; }
    ItemType GetType() const    { return _type; }

private:
    std::string _name;
    unsigned _id;
    unsigned _cost;
    ItemType _type;
    friend std::ostream & operator<< (std::ostream & os, const Item &item);
};
#endif