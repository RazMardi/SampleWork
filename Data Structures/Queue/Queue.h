/*****************************************************************************/
/*!
@file   Queue.h
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   7/3/2016
@brief  contains the interface of the Queue class
*/
/*****************************************************************************/
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream> 

namespace DataStructures
{
    template <typename Data> class Queue;

    template <typename Data>
    class Queue
    {
    public:
        Queue(int capacity);
        ~Queue();
        Queue(const Queue& rhs);
        void CopyQueue(const Queue& rhs);
        Queue& operator=(const Queue& rhs);
        void Enqueue(const Data item);
        void Dequeue();
        void Grow(int capacity);
        Data Top() const;
        Data Bottom() const;
        bool IsFull() const;
        bool IsEmpty() const;
        int Size() const { return _size; }
        int Capacity() const { return _capacity; }
        void DumpQueue() const;

    private:
        Data *_array;
        int _size;
        int _capacity;
        int _head;
        int _tail;
    };
}
#include "Queue.cpp"
#endif