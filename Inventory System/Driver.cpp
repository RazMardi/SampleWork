/*****************************************************************************/
/*!
@file   Driver.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   6/12/2016
@brief  A basic driver for testing functionality of the inventory.
*/
/*****************************************************************************/
#include "Inventory.h"
#include <iostream>  
#include <time.h>    
#define ID_START 100

void Test0()
{
    //constructor
    std::cout << "Test 0: Constructor " << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    Inventory inventory(100, "data.json");
    inventory.DumpInventory();
    std::cout << std::endl;
}

void Test1()
{
    //adding duplicate ID's, RemoveItem, FindItem
    std::cout << "Test 1: Remove/Find & Duplicates " << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    Inventory inventory(100, "data.json");
    for (unsigned i = ID_START; i < ID_START + 10; ++i) 
        inventory.RemoveItem(i);
    inventory.AddItem(Item("Cane", 110, 300, ItemType::Weapon));
    inventory.AddItem(Item("Leather Gloves", 115, 100, ItemType::Armor));
    inventory.DumpInventory();
    std::cout << std::endl;
}

void Test2()
{
    //stress, adding 500 items and removing
    std::cout << "Test 2: 500 Items Add & Remove/Find " << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    Inventory inventory(500, "data.json");
    for (unsigned i = ID_START; i < inventory.GetCapacity(); ++i)
        inventory.AddItem(Item("Cane", i, 300, ItemType::Weapon));
    for (unsigned i = ID_START; i < inventory.GetCapacity(); ++i)
        inventory.RemoveItem(i);
    inventory.DumpInventory();
}

int main()
{
    clock_t begin, end;
    begin = clock();

    Test0();
    Test1();
    Test2();
    
    end = clock();
    std::cout << "Elapsed Time: " << (double)(end - begin) / CLOCKS_PER_SEC << std::endl;
    return 0;
}