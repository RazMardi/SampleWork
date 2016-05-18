/*****************************************************************************/
/*!
@file   BubbleSort.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   5/17/2016
@brief  The Bubble Sort algorithm is best used on small data sets. Since it must
make multiple passes on the container, it is inefficient on larger data sets.
*/
/*****************************************************************************/
#include <iostream>

/******************************************************************************
\fn void Swap(T& a, T&b)
@brief utility function for swapping two built in data types in a container
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
\fn void BubbleSort(T a[], int size)
@brief A bubble sort works by comparing adjacent items and exchanging
them if they are out of order. Time Complexity; Best Case: O(N), Worst Case: O(N^2)
@param a the array to be sorted
@param size the size of the array
*******************************************************************************/
template <typename T>
void BubbleSort(T a[], unsigned size)
{
    for (int i = 0; i < size - 1; i++)
    {
        unsigned swaps = 0;
        for (unsigned j = 0; j < size - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                Swap(a[j], a[j + 1]);
                swaps = 1;
            }
        }
        if (swaps == 0)
            break;
    }
}

int main()
{
    int arr[] = { 4, 1, 3, 7, 2, 10 };
    unsigned size = sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr, size);
    for (unsigned i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    return 0;
}

