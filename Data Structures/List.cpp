/*****************************************************************************/
/*!
@file   List.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   5/29/2016
@brief  A custom Doubly Linked-List class implementation mirroring some of 
the functionality of the Standard Template Libraries List implementations. 
The Doubly Link List allows O(K) time when adding to the back of the list 
due to the list's tail pointer and a previous pointer on each of the nodes. 
*/
/*****************************************************************************/
#include <iomanip> /*std::setw*/

namespace DataStructures
{
/******************************************************************************
\fn List()
@brief Default constructor for the List 
*******************************************************************************/
    template<typename Data>
    List<Data>::List() : _head(nullptr), _tail(nullptr), _size(0){}

/******************************************************************************
\fn ~List()
@brief Destructor for the List, deallocates all nodes
*******************************************************************************/
    template <typename Data>
    List<Data>::~List()
    {
        if(!IsEmpty())
            Clear();
    }

/******************************************************************************
\fn List(const List & rhs)
@brief constructs a container with a copy of each of the elements in rhs
@param rhs the list being copied
*******************************************************************************/
    template<typename Data>
    List<Data>::List(const List & rhs) : _head(nullptr), _tail(nullptr), _size(0)
    {
        Node* pNode = rhs._head;
        while (pNode){
            PushBack(pNode->data);
            pNode = pNode->next;
        }
    }

/******************************************************************************
\fn List& operator=(const List& rhs)
@brief Assigns new contents to the list, replacing its current contents
@param rhs the data used for assignment 
@return a reference to this list
*******************************************************************************/
    template <typename Data>
    List<Data>& List<Data>::operator=(const List& rhs)
    {
        if (&rhs != this) {
            Clear();
            Node* pNode = rhs._head;
            while (pNode != nullptr) {
                PushBack(pNode->data);
                pNode = pNode->next;
            }
        }
        return *this;
    }

/******************************************************************************
\fn Node()
@brief constructs a node object
@param value the data to be stored inside the newly created node
*******************************************************************************/
    template <typename Data>
    List<Data>::Node::Node(Data value) : data(value){}

/******************************************************************************
\fn ~Node()
@brief Destructor for the node object
*******************************************************************************/
    template <typename Data>
    List<Data>::Node::~Node(){}

/******************************************************************************
\fn Node *CreateNode(const Data& value) const
@brief utility function for allocating anew node 
@param the value to be stored inside the newly created node
@return a pointer to the newly created node
*******************************************************************************/
    template <typename Data>
    typename List<Data>::Node* List<Data>::CreateNode(const Data& value) const
    {
        Node* node;
        try {
            node = new Node(value);
        }catch (std::bad_alloc &e) {
            std::cerr << "Memory allocation Failed! (new): " << e.what() << std::endl;
            return nullptr;
        }
        node->next = nullptr;
        node->prev = nullptr;
        _size++;
        return node;
    }

/******************************************************************************
\fn bool IsEmpty() const
@brief checks to see whether the list is empty
@return true if the list is empty, false otherwise
*******************************************************************************/
    template <typename Data>
    bool List<Data>::IsEmpty() const
    {
        if (_head == nullptr)
            return true;
        return false;
    }

/******************************************************************************
\fn void PushBack(const Data& value)
@brief adds an item to the end of the list
*******************************************************************************/
    template <typename Data>
    void List<Data>::PushBack(const Data& value)
    {
        Node* pNode = _tail;
        if (pNode == nullptr) {
            pNode = CreateNode(value);
            _head = pNode;
            _tail = pNode;
        }else{
            _tail = CreateNode(value);
            _tail->prev = pNode;
            pNode->next = _tail;
        }
    }

/******************************************************************************
\fn void PushFront(const Data& value)
@brief adds an item to the front of the list
*******************************************************************************/
    template <typename Data>
    void List<Data>::PushFront(const Data& value)
    {
        Node* pNode = _head;
        if (pNode == nullptr){
            pNode = CreateNode(value);
            _head = pNode;
            _tail = pNode;
        }else{
            _head = CreateNode(value);
            _head->next = pNode;
            pNode->prev = _head;
        }
    }

/******************************************************************************
\fn void PopFront()
@brief removes an item from the front of the list
*******************************************************************************/
    template <typename Data>
    void List<Data>::PopFront()
    {
        if (IsEmpty()){
            std::cout << "Failed to delete : No Items in List";
        }else{
            Node* pNode = _head;
            _head = _head->next;
            delete pNode;
            _size--;
        }
    }

/******************************************************************************
\fn void PopBack()
@brief removes an item from the end of the list
*******************************************************************************/
    template <typename Data>
    void List<Data>::PopBack()
    {
        if (IsEmpty()){
            std::cout << "Failed to delete : No Items in List";
        }else{
            Node* pNode = _tail;
            _tail = pNode->prev;
            if (_tail == nullptr)
                _head = nullptr;
            else
                _tail->next = nullptr;
            delete pNode;
            _size--;
        }
    }

/******************************************************************************
\fn void Clear()
@brief removes all nodes from the list
*******************************************************************************/
    template <typename Data>
    void List<Data>::Clear()
    {
        if (IsEmpty()){
            std::cout << "List is already empty";
        }else{
            Node* pNode = _head;
            while (pNode){
                Node* temp = pNode;
                pNode = pNode->next;
                delete temp;
                _size--;
            }
            _head = nullptr;
            _tail = nullptr;
        }
    }

/******************************************************************************
\fn int Find(const Data& value)
@brief finds the position of an item in the list by value
@param value the value stored inside the item being found
@return if the item is found the index of the item in the list, otherwise -1
*******************************************************************************/
    template <typename Data>
    int List<Data>::Find(const Data& value) const
    {
        if (IsEmpty()) {
            std::cout << "Failed to Find Item: No Items in the List";
            return -1;
        }else {
            Node* pNode = _head;
            int count = 0;
            while (pNode) {
                if (pNode->data == value) {
                    return count;
                }else {
                    count++;
                    pNode = pNode->next;
                }
            }
            std::cout << "Item does not exist: "; 
            return -1;
        }
    }

/******************************************************************************
\fn void RemoveNode(const Data& value)
@brief removes a item from the list by value
@param value the value of the item to be deleted
*******************************************************************************/
    template <typename Data>
    void List<Data>::RemoveNode(const Data& value)
    {
        int location = Find(value);
        if (location == -1) {
            return;
        }else {
            if (location == _size - 1) { //last node, constant access
                PopBack();
                return;
            }else if (location == 0) { //first node, constant access
                PopFront();
                return;
            }else{  //linear search
                Node* pNode = _head;
                for (int i = 0; i < location; ++i)
                    pNode = pNode->next;
                Node* temp = pNode->next;
                Node* prev = pNode->prev;
                delete pNode;
                _size--;
                prev->next = temp;
                temp->prev = prev;
            }
        }
    }
    
/******************************************************************************
\fn void Reverse()
@brief reverses the items in the list 
*******************************************************************************/
    template <typename Data>
    void List<Data>::Reverse()
    {
        if (IsEmpty()) {
            std::cout << "Failed to Reverse : No Items in List";
        }else{
            Node* pNode = _head;
            while (pNode){
                Node* temp = pNode->next;
                pNode->next = pNode->prev;
                pNode->prev = temp; 
                if (temp == nullptr){
                    _tail = _head;
                    _head = pNode;
                }
                pNode = temp;
            }
        }
    }

/******************************************************************************
\fn void Insert(unsigned position, const Data& value)
@brief inserts an item into the list at a given position
@param position the index the item will be inserted
@param value the data to be stored inside the item
*******************************************************************************/
    template <typename Data>
    void List<Data>::Insert(unsigned position, const Data& value)
    {
        if (IsEmpty()){
            std::cout << "Cannot Insert at position " << position << " : No Items in List";
        }else if (position >= _size || position < 0) {
            std::cout << "Cannot Insert at position " << position << " : Out of Bounds";
        }else if (position == 0) {
            PushFront(value);
        }else if (position == _size - 1){
            PushBack(value);
        }else{ 
            Node* pNode = _head;
            for (unsigned i = 0; i < position; ++i) 
                pNode = pNode->next;
            Node* newNode = CreateNode(value);
            pNode->prev->next = newNode;
            newNode->next = pNode;
        }
    }

/******************************************************************************
\fn const Data& Front() const
@brief calling this function on an empty container causes undefined behaviour
@return a reference to the first element in the list
*******************************************************************************/
    template <typename Data>
    const Data& List<Data>::Front() const
    {
        return _head->data;
    }

/******************************************************************************
\fn const Data& Back() const
@brief calling this function on an empty container causes undefined behaviour
@return a reference to the last element in the list
*******************************************************************************/
    template <typename Data>
    const Data& List<Data>::Back() const
    {
        return _tail->data;
    }

/******************************************************************************
\fn unsigned Size() const
@brief returns the number of items in the list 
@return the size of the list 
*******************************************************************************/
    template <typename Data>
    unsigned List<Data>::Size() const
    {
        return _size;
    }
}

/******************************************************************************
\fn std::ostream & operator<< <Data>(std::ostream & os, const List &list);
@brief overloads the << operator to print out the list 
@param os a reference to the output stream object
@param list a reference to the list being printed out 
@return a reference to the output stream containing the lists data
*******************************************************************************/
template <typename Data>
std::ostream &DataStructures::operator<<(std::ostream & os, const DataStructures::List<Data> &list)
{
    typename DataStructures::List<Data>::Node *pNode = list._head;
    while (pNode){
        os << std::setw(4) << pNode->data;
        pNode = pNode->next;
    }
    os << std::endl;
    return os;
}
