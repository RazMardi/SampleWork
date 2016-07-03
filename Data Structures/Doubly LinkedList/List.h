/*****************************************************************************/
/*!
@file   List.h
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   5/29/2016
@brief  contains the interface of the List class
*/
/*****************************************************************************/
#ifndef LIST_H
#define LIST_H
#include <iostream> 

namespace DataStructures
{
    template <typename Data> class List;

    template <typename Data>
    std::ostream & operator<<(std::ostream & os, const List<Data> &list);

    template <typename Data>
    class List
    {
    public:
        List();
        ~List();
        List(const List& rhs);
        List& operator=(const List& rhs);

        bool IsEmpty() const;
        void PushBack(const Data& value);
        void PushFront(const Data& value);
        void PopFront();
        void PopBack();
        void Clear();
        int Find(const Data& value) const;
        void RemoveNode(const Data& value); 
        void Reverse();
        void Insert(unsigned position, const Data& value);
        const Data& Front() const;
        const Data& Back() const;
        unsigned Size() const;
        friend std::ostream & operator<< <Data>(std::ostream & os, const List &list);

    private:
        struct Node
        {
            Node(Data data);
            ~Node();
            Node* next;
            Node* prev;
            Data data;
        };
        Node *_head; 
        Node *_tail; 
        Node *CreateNode(const Data& value) const;
        mutable unsigned _size;  
    };
}
#include "List.cpp"
#endif