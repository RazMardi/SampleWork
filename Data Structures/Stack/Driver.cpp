/*****************************************************************************/
/*!
@file   Driver.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   7/2/2016
@brief  a sample driver to test the functionality of the Stack
*/
/*****************************************************************************/
#include "Stack.h"

void Test0()
{
    //Push/Pop
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing Push/Pop" << std::endl << std::endl;
    DataStructures::Stack<int> stack(10);
    for (int i = 1; i <= 10; i++)
        stack.Push(i);
    std::cout << "Stack: " << stack << std::endl;
    for (int i = 1; i <= 10; i++) {
        stack.Pop();
        std::cout << "Stack: " << stack << std::endl;
    }
}

void Test1()
{
    //Clear
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing Clear" << std::endl << std::endl;
    DataStructures::Stack<int> stack(10);
    for (int i = 1; i <= 10; i++)
        stack.Push(i);
    std::cout << "Stack: " << stack << std::endl;
    stack.Clear();
    std::cout << "Stack: " << stack << std::endl;
    for (int i = 1; i <= 10; i++)
        stack.Push(i);
    std::cout << "Stack: " << stack << std::endl;
    stack.Clear();
    std::cout << "Stack: " << stack << std::endl;
}


void Test2()
{
    //Top
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing Top" << std::endl << std::endl;
    DataStructures::Stack<int> stack(10);
    for (int i = 1; i <= 10; i++)
        stack.Push(i);
    std::cout << "Stack: " << stack << std::endl;
    std::cout << "Top: " << stack.Top() << std::endl << std::endl;
    stack.Pop();
    std::cout << "Stack: " << stack << std::endl;
    std::cout << "Top: " << stack.Top() << std::endl << std::endl;
    stack.Pop();
    std::cout << "Stack: " << stack << std::endl;
    std::cout << "Top: " << stack.Top() << std::endl << std::endl;
}

void Test3()
{
    //Equality
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Testing Equality" << std::endl << std::endl;
    
    DataStructures::Stack<int> stack(10);
    for (int i = 1; i <= 10; i++)
        stack.Push(i);
    std::cout << "Stack: " << stack << std::endl;

    DataStructures::Stack<int> stack2(10);
    for (int i = 1; i <= 10; i++)
        stack2.Push(i);
    std::cout << "Stack2: " << stack << std::endl;
    std::cout << "Equal: " << (stack == stack2) << std::endl << std::endl;

    stack.Pop();
    stack.Pop();
    std::cout << "Stack: " << stack << std::endl;
    std::cout << "Stack2: " << stack << std::endl;
    std::cout << "Equal: " << (stack == stack2) << std::endl << std::endl;

    stack.Clear();
    stack2.Clear();
    std::cout << "Stack: " << stack << std::endl;
    std::cout << "Stack2: " << stack << std::endl;
    std::cout << "Equal: " << (stack == stack2) << std::endl << std::endl;
}

int main()
{
    Test0();
    Test1();
    Test2();
    Test3();
    return 0;
}
