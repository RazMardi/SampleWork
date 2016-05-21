/*****************************************************************************/
/*!
@file   Selection.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   5/17/2016
@brief  The Selection Sort algorithm scans the array and looks for the smallest 
value and then swaps it with the current position starting at position zero. 
The position is then incremented along the container until it reaches the end. 
*/
/*****************************************************************************/
#include <iostream>

/******************************************************************************
\fn void Swap(T& a, T&b)
@brief utility function for swapping two values in a container
@param a the first value being swapped
@param b the second value being swapped
*******************************************************************************/
template <typename T>
void Swap(T& a, T&b)
{
    T temp = b;
    b = a;
    a = temp;
}

/******************************************************************************
\fn void SelectionSort(T arr[], unsigned size)
@brief sorts an array via the Selection Sort Algorithm. Time Complexity; 
Best Case: O(N^2), Worst Case: O(N^2)
@param a the array to be sorted
@param size the size of the array
*******************************************************************************/
template <typename T>
void SelectionSort(T arr[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
    {
        unsigned current = i;
        unsigned j = 0;
        for (j = i + 1; j < size; ++j)
            if (arr[j] < arr[current])
                current = j;
        Swap(arr[current], arr[i]);
    }
}

int main()
{
    unsigned arr[] = { 1,3,5,2,8,7,4 };
    unsigned size = sizeof(arr) / sizeof(arr[0]);
    SelectionSort(arr, size);
    for (unsigned i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    return 0;
}