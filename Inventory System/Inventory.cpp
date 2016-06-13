/*****************************************************************************/
/*!
@file   Inventory.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   6/12/2016
@brief  A simple inventory system that can be used in an rpg or adventure game. 
*/
/*****************************************************************************/
#include "Inventory.h"
#include "Serializer.h"
#include <iostream>  /*std::cout*/
#include <algorithm> /*std::swap*/

/******************************************************************************
\fn Inventory(unsigned capacity)
@brief constructs an empty inventory with a given capacity
@param capacity the max items this inventory will carry
*******************************************************************************/
Inventory::Inventory(unsigned capacity) : _capacity(capacity), _size(0) {}

/******************************************************************************
\fn Inventory(unsigned capacity, const std::string& filename)
@brief constructs an inventory with a given capacity containing items from a JSON file
@param capacity the max items this inventory will carry
@param filename the JSON file containing the item database
*******************************************************************************/
Inventory::Inventory(unsigned capacity, const std::string& filename): _capacity(capacity), _size(0)
{
    Serializer serializer(filename);
    serializer.PopulateInventory(this);
}

/******************************************************************************
\fn ~Inventory()
@brief destructor for the inventory, cleans up items and reset's the capacity
*******************************************************************************/
Inventory::~Inventory()
{
    while (_size != 0){
        Item* item = _items.back();
        _items.pop_back();
        delete item;
        _size--;
    }
    _capacity = 0;
}

/******************************************************************************
\fn ValidateID(unsigned id) const
@brief checks a given ID to ensure it does not already exists before adding into the inventory 
@param id the ID of the item being validated
@return true if the id is valid, false otherwise
*******************************************************************************/
bool Inventory::ValidateID(unsigned id) const
{
    for (auto it = _items.begin(); it != _items.end(); ++it) {
        if ((*it)->GetID() == id) {
            std::cout << "ERROR: ID already exists, adding " << id << std::endl;
            return false;
        }
    }
    return true;
}

/******************************************************************************
\fn CreateItem(Item item)
@brief allocates memory for a new item
@param item the item being created
@return a pointer to the newly created item
*******************************************************************************/
Item* Inventory::CreateItem(Item item)
{
    return new Item(item.GetName(), item.GetID(), item.GetCost(), item.GetType());
}

/******************************************************************************
\fn AddItem(Item item)
@brief adds an item to the inventory if there is space
@param item the item being added
@return true if the item was added, false otherwise
*******************************************************************************/
bool Inventory::AddItem(Item item)
{
    if (_size < _capacity) {
        if (ValidateID(item.GetID())) {
            _items.push_back(CreateItem(item));
            _size++;
            return true;
        }
        else 
            return false;
    }
    std::cout << "ERROR: Could not insert item, Inventory full" << std::endl;
    return false;
}

/******************************************************************************
\fn RemoveItem(unsigned id)
@brief removes an item from the inventory
@param id the ID of the item being removed
@return true if the item was removed, false otherwise
*******************************************************************************/
bool Inventory::RemoveItem(unsigned id)
{
    int temp = FindItem(id);
    if (temp >= 0){
        std::swap(_items[temp], _items.back());
        Item* item = _items.back();
        _items.pop_back();
        delete item;
        _size--;
        return true;
    }
    return false;
}

/******************************************************************************
\fn FindItem(unsigned id)
@brief searches the inventory for an item by a given ID
@param id the ID of the item to search
@return the index of the item if found, -1 otherwise
*******************************************************************************/
int Inventory::FindItem(unsigned id)
{
    unsigned index = 0;
    for (auto it = _items.begin(); it != _items.end(); ++it){
        if ((*it)->GetID() == id)
            return index;
        index++;
    }
    std::cout << "ERROR: Item does not exist" << std::endl;
    return -1;
}

/******************************************************************************
\fn DumpInventory() const
@brief prints out the contents of the inventory 
*******************************************************************************/
void Inventory::DumpInventory() const
{
    for (auto it = _items.begin(); it != _items.end(); ++it){
        std::cout << (*(*it)) << std::endl;
    }
}
