/*****************************************************************************/
/*
@file   BubbleSort.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   5/17/2016
@brief  The Bubble Sort algorithm is best used on small data sets. Since it must 
make multiple passes on the container, it is inefficient on larger data sets.
*/
/*****************************************************************************/

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
them if they are out of order. Time Complexity O(N^2). 
@param a the array to be sorted
@param size the size of the array
*******************************************************************************/
template <typename T>
void BubbleSort(T a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
       int swaps = 0;
       for (int j = 0; j < size - i - 1; j++)
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
