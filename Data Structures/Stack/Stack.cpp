/*****************************************************************************/
/*!
@file   Stack.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   7/2/2016
@brief  A custom Stack class implementation
*/
/*****************************************************************************/
#include <iomanip> /*std::setw*/

namespace DataStructures
{
/******************************************************************************
\fn Stack()
@brief Default constructor for the Stack
*******************************************************************************/
    template <typename Data>
    Stack<Data>::Stack(size_t capacity) : _head(nullptr), _capacity(capacity), _size(0) {}

/******************************************************************************
\fn ~Stack()
@brief Destructor for the Stack, deallocates all items
*******************************************************************************/
    template <typename Data>
    Stack<Data>::~Stack()
    {
        if (!IsEmpty())
            Clear();
    }

/******************************************************************************
\fn void Clear()
@brief removes all items from the Stack
*******************************************************************************/
    template<typename Data>
    void Stack<Data>::Clear()
    {
        while (_head) {
            Item* item = _head->_next;
            delete _head;
            _head = item;
        }
        _size = 0;
    }

/******************************************************************************
\fn Data& Top()
@brief gets the topmost item in the stack, will throw if the stack is empty
@return a reference to the top of the stack
*******************************************************************************/
    template <typename Data>
    Data& Stack<Data>::Top()
    {
		return _head->_data;
    }

/******************************************************************************
\fn void CreateItem(const Data& data)
@brief utility function for creating a new item
@param data the data to be stored inside the newly created item
@return a pointer to the newly created item
*******************************************************************************/
    template <typename Data>
    void Stack<Data>::CreateItem(const Data& data)
    {
        Item* temp;
        try {
            temp = new Item();
        }
        catch (std::bad_alloc &e) {
            std::cerr << "ERROR: Memory allocation Failed! (new): " << e.what() << std::endl;
        }
        temp->_data = data;
        temp->_next = _head;
        _head = temp;
        _size++;
    }

/******************************************************************************
\fn void Push(const Data& data)
@brief adds an item to the top of the Stack if there is room
@param data the data stored inside the item
*******************************************************************************/
    template <typename Data>
    void Stack<Data>::Push(const Data& data)
    {
        if (_size >= _capacity) {
            std::cout << "ERROR: Stack is full" << std::endl;
            return;
        }
        CreateItem(data);
    }

/******************************************************************************
\fn void Pop()
@brief removes an item from the top of the Stack
*******************************************************************************/
    template <typename Data>
    Data Stack<Data>::Pop()
    {
        if (IsEmpty()) {
            std::cout << "ERROR: empty stack" << std::endl;
        }
        Data data = _head->_data;
        Item *temp = _head;
        _head = _head->_next;
        delete(temp);
        return data;
    }

/******************************************************************************
\fn bool operator==(const Stack& other)
@brief compares two stacks to see if both stacks contain the same items
@param other the rhs Stack
@return true if they are equal, false otherwise
*******************************************************************************/
    template <typename Data>
    bool Stack<Data>::operator==(const Stack& other)
    {
        if (IsEmpty() && other.IsEmpty())
            return true;
        if (_size != other._size)
            return false;

        Item* lhs = _head;
        Item* rhs = other._head;

        while (lhs && rhs) {
            if (lhs->_data != rhs->_data)
                return false;
            lhs = lhs->_next;
            rhs = rhs->_next;
        }
        return true;
    }

/******************************************************************************
\fn void IsEmpty() const
@brief checks to see whether the Stack is empty
@return true if the Stack is empty, false otherwise
*******************************************************************************/
    template <typename Data>
    bool Stack<Data>::IsEmpty() const
    {
        return (_head == nullptr);
    }
}

/******************************************************************************
\fn std::ostream& operator<< <Data>(std::ostream & os, const Stack &stack);
@brief overloads the << operator to print out the Stack
@param os a reference to the output stream object
@param stack a reference to the stack being printed out
@return a reference to the output stream containing the stacks data
*******************************************************************************/
template <typename Data>
std::ostream &DataStructures::operator<<(std::ostream & os, const DataStructures::Stack<Data> &stack)
{
    typename DataStructures::Stack<Data>::Item *item = stack._head;
    while (item) {
        os << std::setw(4) << item->_data;
        item = item->_next;
    }
    return os;
}
