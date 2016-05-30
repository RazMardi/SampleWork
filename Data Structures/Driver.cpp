/*****************************************************************************/
/*!
@file   Driver.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   5/29/2016
@brief  a sample driver to test the functionality of the List
*/
/*****************************************************************************/
#include "List.h"

void Test0()
{
    //PushBack
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing PushBack" << std::endl;
    DataStructures::List<int> list;
    for (int i = 1; i <= 10; i++)
        list.PushBack(i);
    std::cout << "List: " << list << std::endl;
}

void Test1()
{
    //PushFront
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing PushFront" << std::endl;
    DataStructures::List<int> list;
    for (int i = 1; i <= 10; i++)
        list.PushFront(i);
    std::cout << "List: " << list << std::endl;
}

void Test2()
{
    //PopFront
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing PopFront" << std::endl;
    DataStructures::List<int> list;
    for (int i = 1; i <= 10; i++)
        list.PushFront(i);
    std::cout << "List: " << list << std::endl;
    for (int i = 1; i <= 11; i++){
        list.PopFront();
        std::cout << "List: " << list << std::endl;
    }
}

void Test3()
{
    //PopBack
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing PopBack" << std::endl;
    DataStructures::List<int> list;
    for (int i = 1; i <= 10; i++)
        list.PushFront(i);
    std::cout << "List: " << list << std::endl;
    for (int i = 1; i <= 11; i++){
        list.PopBack();
        std::cout << "List: " << list << std::endl;
    }
}

void Test4()
{
    //Clear
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing Clear" << std::endl;
    DataStructures::List<int> list;
    for (int i = 1; i <= 10; i++)
        list.PushFront(i);
    std::cout << "List: " << list << std::endl;
    list.Clear();
    std::cout << "List: " << list << std::endl;
    for (int i = 1; i <= 10; i++)
        list.PushBack(i);
    std::cout << "List: " << list << std::endl;
    list.Clear();
    std::cout << "List: " << list << std::endl;
}

void Test5()
{
    //Find 
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing Find" << std::endl;
    DataStructures::List<int> list;
    for (int i = 1; i <= 10; i++)
        list.PushFront(i);
    std::cout << "List: " << list << std::endl;
    std::cout << "Found 10 at: " << list.Find(10) << std::endl;
    std::cout << "Found 5 at: " << list.Find(5) << std::endl;
    std::cout << "Found 3 at: " << list.Find(3) << std::endl;
    std::cout << "Found 12 at: " << list.Find(12) << std::endl;
    std::cout << "Found 15 at: " << list.Find(15) << std::endl;
    std::cout << "Found 1 at: " << list.Find(1) << std::endl;
    std::cout << std::endl;
}

void Test6()
{
    //RemoveNode
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing Remove Node" << std::endl;
    DataStructures::List<int> list;
    for (int i = 1; i <= 10; i++)
        list.PushFront(i);
    std::cout << "List: " << list << std::endl;
    list.RemoveNode(5); 
    std::cout << "Removing 5 from " << "List: " << list << std::endl;
    list.RemoveNode(2);
    std::cout << "Removing 2 from " << "List: " << list << std::endl;
    list.RemoveNode(1);
    std::cout << "Removing 1 from " << "List: " << list << std::endl;
    list.RemoveNode(7);
    std::cout << "Removing 7 from " << "List: " << list << std::endl;
    list.RemoveNode(8);
    std::cout << "Removing 8 from " << "List: " << list << std::endl;
    list.RemoveNode(12);
    std::cout << "Removing 12 from " << "List: " << list << std::endl;
    list.RemoveNode(5);
    std::cout << "Removing 5 from " << "List: " << list << std::endl;
    list.RemoveNode(3);
    std::cout << "Removing 3 from " << "List: " << list << std::endl;
    std::cout << std::endl;
}

void Test7()
{
    //Front/Back
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing Front/Back/Size" << std::endl;
    DataStructures::List<int> list;
    for (int i = 1; i <= 10; i++)
        list.PushFront(i);

    std::cout << "List: " << list << "Front Node: " << list.Front() << " Size: " << list.Size() << std::endl << std::endl;
    list.RemoveNode(10);
    std::cout << "List: " << list << "Front Node: " << list.Front() << " Size: " << list.Size() << std::endl << std::endl;
    std::cout << "List: " << list << "Back Node: " << list.Back() << " Size: " << list.Size() << std::endl << std::endl;
    list.RemoveNode(1);
    std::cout << "List: " << list << "Back Node: " << list.Back() << " Size: " << list.Size() << std::endl << std::endl;
}

void Test8()
{
    //Reverse
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing Reverse" << std::endl;
    DataStructures::List<int> list;
    for (int i = 1; i <= 10; i++)
        list.PushFront(i);
    std::cout << "List: " << list << std::endl;
    list.Reverse();
    std::cout << "List: " << list << std::endl;
    list.Reverse();
    std::cout << "List: " << list << std::endl;
    list.Clear();
    list.Reverse();
    std::cout << std::endl << std::endl;
}

void Test9()
{
    //Insert
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing Insert" << std::endl;
    DataStructures::List<int> list;
    for (int i = 1; i <= 10; i++)
        list.PushFront(i);
    std::cout << "List: " << list << std::endl;

    std::cout << "Inserting 12 at position 3" << std::endl; 
    list.Insert(3, 12);
    std::cout << "List: " << list << std::endl;

    std::cout << "Inserting 15 at position 2" << std::endl;
    list.Insert(2, 15);
    std::cout << "List: " << list << std::endl;

    std::cout << "Inserting 1 at position 0" << std::endl;
    list.Insert(0, 1);
    std::cout << "List: " << list << std::endl;

    std::cout << "Inserting 20 at position 12" << std::endl;
    list.Insert(12, 20);
    std::cout << "List: " << list << std::endl;

    std::cout << "Inserting 8 at position 14" << std::endl;
    list.Insert(14, 8);
    std::cout << std::endl << std::endl;;
}

void Test10()
{
    //Copy Constructor
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing Copy Constructor" << std::endl;
    DataStructures::List<int> list;
    for (int i = 1; i <= 10; i++)
        list.PushFront(i);
    std::cout << "List: " << list << " Size: " << list.Size() << std::endl << std::endl;

    DataStructures::List<int> list2(list); //explicit call
    std::cout << "List2: " << list2 << " Size: " << list2.Size() << std::endl << std::endl;
    list2.Clear(); 

    std::cout << "List2: " << list2 << " Size: " << list2.Size() << std::endl << std::endl;
    DataStructures::List<int> list3(list2); //explicit call, empty list 
    std::cout << "List3: " << list3 << " Size: " << list3.Size() << std::endl << std::endl;
}

void Test11()
{
    //Assignment Operator
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing Assignment Operator" << std::endl;
    DataStructures::List<int> list;
    for (int i = 1; i <= 10; i++)
        list.PushFront(i);
    std::cout << "List: " << list << " Size: " << list.Size() << std::endl << std::endl;

    DataStructures::List<int> list2;
    for (int i = 1; i <= 10; i++)
        list2.PushBack(i);
    std::cout << "List2: " << list2 << " Size: " << list2.Size() << std::endl << std::endl;

    std::cout << "Assigning list 2 to list" << std::endl;
    list2 = list;
    std::cout << "List2: " << list2 << " Size: " << list2.Size() << std::endl << std::endl;

    DataStructures::List<int> list3;
    for (int i = 1; i <= 20; i++)
        list3.PushBack(i);
    std::cout << "List3: " << list3 << " Size: " << list3.Size() << std::endl << std::endl;

    std::cout << "Assigning list 2 to list3" << std::endl;
    list2 = list3;
    std::cout << "List2: " << list2 << " Size: " << list2.Size() << std::endl << std::endl;

    std::cout << "Assigning list 3 to list" << std::endl;
    list3 = list;
    std::cout << "List3: " << list3 << " Size: " << list3.Size() << std::endl << std::endl;
}

int main()
{
    Test0();  //PushBack
    Test1();  //PushFront
    Test2();  //PopFront
    Test3();  //PopBack
    Test4();  //Clear
    Test5();  //Find 
    Test6();  //RemoveNode
    Test7();  //Front/Back
    Test8();  //Reverse
    Test9();  //Insert
    Test10(); //Copy Constructor
    Test11(); //Assignemnt operator

    std::cin.get();
    return 0;
}