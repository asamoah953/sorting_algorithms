#include "sort.h"

/**
 * iParent - returns index of parent node for an array arranged as a binary
 * tree, for index i
 * @i: starting index to determine parent node index
 * Return: index of parent node
 */
int iParent(int i)
{
	return ((i - 1) / 2);
}

/**
 * iLeftChild- returns index of left child branch for an array arranged as
 * a binary tree, for index i
 * @i: starting index to determine left child branch index
 * Return: index of left child node
 */
int iLeftChild(int i)
{
	return ((2 * i) + 1);
}

/**
 * ConvertToHeap - arranges array of integers into a heap/binary tree scheme
 * @array: array of integers
 * @size: number of elements in array
 */
void ConvertToHeap(int *array, size_t size)
{
	int start;

	start = iParent(size - 1);

	while (start >= 0)
	{
		SiftDown(array, size, start, size - 1);
		start--;
	}
}

/**
 * SiftDown - this shuffles heap/binary tree sorted array into array sorted by
 * ascending value
 * @array: array of values to be sorted in place, from heap to ascending
 * @size: number of elements in array
 * @start: starting index
 * @end: ending index
 */
void SiftDown(int *array, size_t size, int start, int end)
{
	int begin, space, temp, child;

	begin = start;

	while (iLeftChild(begin) <= end)
	{
		child = iLeftChild(begin);
		space = begin;

		if (array[space] < array[child])
			space = child;
		if (child + 1 <= end && array[space] < array[child + 1])
			space = child + 1;
		if (space != begin)
		{
			temp = array[begin];
			array[begin] = array[space];
			array[space] = temp;
			print_array(array, size);
			begin = space;
		}
		else
			return;
	}
}

/**
 * heap_sort - sorts array of integers in ascending order using a heap sort
 * sift-down alogrithm
 * @array: array of values to be sorted
 * @size: number of elements in array
 */
void heap_sort(int *array, size_t size)
{
	int iEnd, temp;

	if (!array || size < 2)
		return;

	ConvertToHeap(array, size);

	iEnd =  (int)size - 1;
	while (iEnd > 0)
	{
		temp = array[iEnd];
		array[iEnd] = array[0];
		array[0] = temp;
		print_array(array, size);
		iEnd--;
		SiftDown(array, size, 0, iEnd);
	}
}
