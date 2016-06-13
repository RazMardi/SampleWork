/*****************************************************************************/
/*!
@file   Inventory.h
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   6/12/2016
@brief  contains the interface of the Inventory class
*/
/*****************************************************************************/
#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory
{
public:
    Inventory(unsigned capcacity);
    Inventory(unsigned capacity, const std::string& filename);
    ~Inventory();

    bool ValidateID(unsigned id) const;
    bool AddItem(Item item);
    Item* CreateItem(Item item);
    bool RemoveItem(unsigned id);
    int FindItem(unsigned id);
    void DumpInventory() const;
    unsigned GetSize() const { return _size; };
    unsigned GetCapacity() const { return _capacity; };

private:
    unsigned _size;
    unsigned _capacity;
    std::vector<Item*> _items;
};
#endif
