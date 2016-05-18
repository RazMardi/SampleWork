/*****************************************************************************/
/*!
@file   InsertionSort.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   5/17/2016
@brief  The Insertion Sort Algorithm starts with a sorted list and continually
inserts the next element into its proper position in the sorted list.
We consider the first element in the unsorted list to be a list of one and 
partition the list into two portions; a sorted portion and an unsorted 
portion.
*/
/*****************************************************************************/

/******************************************************************************
\fn void InsertionSort(T a[], int size)
@brief sorts an array via the Insertion Sort Algorithm. Time Complexity; 
Best Case: O(N), Worst Case: O(N^2)
@param a the array to be sorted
@param size the size of the array
*******************************************************************************/
template <typename T>
void InsertionSort(T a[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;
	int current = a[i];
	while ((j > 0) && (a[j - 1] > current))
	{
	    a[j] = a[j - 1];
	    j--;
	}
	a[j] = current;
    }
}
