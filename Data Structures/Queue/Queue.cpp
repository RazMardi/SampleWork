/*****************************************************************************/
/*!
@file   Queue.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   7/3/2016
@brief  A custom Queue class implementation using a circular array. This 
implementation will grow the Queue at a factor of 2 if capacity is reached.
It will also shrink the Queue by 1/2 when the size is equal to 1/4 of the 
capacity.
*/
/*****************************************************************************/
namespace DataStructures
{
/******************************************************************************
\fn Queue()
@brief Non Default constructor for the Queue
@param capacity the capacity of the Queue
*******************************************************************************/
    template <typename Data>
    Queue<Data>::Queue(int capacity) : _size(0), _capacity(capacity)
    {
        _array = new Data[capacity];
        for (int i = 0; i < capacity; ++i)
            _array[i] = -1;
        _tail = _capacity - 1;
        _head = 0;
    }

/******************************************************************************
\fn ~Queue()
@brief destructor, deallocates memory allocated during construction
*******************************************************************************/
    template <typename Data>
    Queue<Data>::~Queue()
    {
        if(_array)
            delete[] _array;
    }

/******************************************************************************
\fn Queue(const Queue & rhs)
@brief constructs a container with a copy of each of the elements in rhs
@param rhs the Queue being copied
*******************************************************************************/
    template <typename Data>
    Queue<Data>::Queue(const Queue& rhs) : _size(0), _capacity(0)
    {
        if (rhs.IsEmpty())
            return;
        CopyQueue(rhs);
    }

/******************************************************************************
\fn Queue& operator=(const Queue& rhs)
@brief assigns new contents to the Queue, replacing its current contents
@param rhs the data used for assignment
@return a reference to this Queue
*******************************************************************************/
    template <typename Data>
    Queue<Data>& Queue<Data>::operator=(const Queue& rhs)
    {
        if (&rhs != this) {
            delete[] _array;
            CopyQueue(rhs);
        }
        return *this;
    }

/******************************************************************************
\fn void CopyQueue(const Queue& rhs)
@brief helper function for copying data from rhs to this Queue
@param rhs the data used for copying
*******************************************************************************/
    template <typename Data>
    void Queue<Data>::CopyQueue(const Queue& rhs)
    {
        _capacity = rhs._capacity;
        _size = rhs._size;
        _array = new Data[_capacity];
        for (int i = 0; i < _capacity; ++i)
            _array[i] = rhs._array[i];
        _head = rhs._head;
        _tail = rhs._tail;
    }

/******************************************************************************
\fn void Grow(int newCapacity)
@brief grows the queue's capacity to the newCapacity being passed
@param newCapacity the new capacity of the Queue
*******************************************************************************/
    template <typename Data>
    void Queue<Data>::Grow(int newCapacity)
    {
        Data* newArray = new Data[newCapacity];
        int current = _head;
        for (int i = 0; i < _size; ++i){
            newArray[i] = _array[current];
            current = (current + 1) % _capacity;
        }
        _capacity = newCapacity;
        delete[] _array;
        _array = newArray;
        _head = 0;
        _tail = _size -1;
    }

/******************************************************************************
\fn void Enqueue(const Data item)
@brief adds an item to the Queue, grows the Queue if it is full
@param item the data to be added 
*******************************************************************************/
    template <typename Data>
    void Queue<Data>::Enqueue(const Data item)
    {
        if (IsFull())
            Grow(_capacity * 2);
        _tail = (_tail + 1) % _capacity;
        _array[_tail] = item;
        _size++;
    }

/******************************************************************************
\fn void Dequeue()
@brief removes an item from the Queue if it is not empty
*******************************************************************************/
    template <typename Data>
    void Queue<Data>::Dequeue()
    {
        if (IsEmpty())
            return;
        _head = (_head + 1) % _capacity;
        _size--;
        if (_size > 0 && _size == _capacity / 4)
            Grow(_capacity / 2);
    }

/******************************************************************************
\fn Data Top() const
@brief grabs the element at the front or top of the Queue
@return Data, the top element in the Queue, if the Queue is empty -1
*******************************************************************************/
    template <typename Data>
    Data Queue<Data>::Top() const
    {
        return _array[_head];
    }

/******************************************************************************
\fn Data Bottom() const
@brief grabs the element at the bottom or rear of the Queue
@return Data, the rear or bottom element in the Queue, if the Queue is empty -1
*******************************************************************************/
    template <typename Data>
    Data Queue<Data>::Bottom() const
    {
        return _array[_tail];
    }

/******************************************************************************
\fn bool IsFull() const
@brief checks to see whether the Queue is full
@return bool, true if the Queue is full, false otherwise
*******************************************************************************/
    template <typename Data>
    bool Queue<Data>::IsFull() const
    {
        return (_size >= _capacity);
    }

/******************************************************************************
\fn bool IsEmpty() const
@brief checks to see whether the Queue is empty
@return bool, true if the Queue is empty, false otherwise
*******************************************************************************/
    template <typename Data>
    bool Queue<Data>::IsEmpty() const
    {
        return(_size <= 0); 
    }

/******************************************************************************
\fn void DumpQueue() const
@brief prints out the contents of the Queue
*******************************************************************************/
    template <typename Data>
    void Queue<Data>::DumpQueue() const
    {
        int temp = _head;
        std::cout << "Queue : ";
        if (_size == 0) {
            std::cout << std::endl;
            return;
        }
        while (temp != _tail + 1) {
            std::cout << "|" << _array[temp] << "|" << " ";
            temp++;
        }
        std::cout << std::endl;
    }
}
