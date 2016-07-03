/*****************************************************************************/
/*!
@file   Stack.h
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   7/2/2016
@brief  contains the interface of the Stack class
*/
/*****************************************************************************/
#ifndef STACK_H
#define STACK_H

#include <cstdlib>
#include <iostream> 

namespace DataStructures
{
    template <typename Data> class Stack;

    template <typename Data> 
    std::ostream & operator<<(std::ostream & os, const Stack<Data> &stack);

    template <typename Data>
    class Stack
    {
    public:
        Stack(size_t capacity);
        ~Stack();
        Data& Top();
        void Clear();
        void Push(const Data& data);
        bool IsEmpty() const;
        Data Pop();
        bool operator==(const Stack& other);
        size_t Size() const { return _size; }
        size_t Capacity() const { return _capacity; }
        friend std::ostream & operator<< <Data>(std::ostream & os, const Stack &stack);

    private:
        struct Item
        {
            Item* _next;
            Data _data;
        };
        Item* _head;
		size_t _capacity;
        size_t _size;
        void CreateItem(const Data& data);
    };
}
#include "Stack.cpp"
#endif
