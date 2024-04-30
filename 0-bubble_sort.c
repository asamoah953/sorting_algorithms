#include "sort.h"

/**
 * bubble_sort - this sorts array of integers in ascending order using a bubble
 * sort algorithms
 * @array: array to sort
 * @size: amount of elements in array
 */
void bubble_sort(int *array, size_t size)
{
	size_t p, n;
	int temp;
	bool swapped = true;

	if (!array || size < 2)
		return;

	n = size;
	while (swapped)
	{
		swapped = false;
		for (p = 1; p < n; p++)
		{
			if (array[p - 1] > array[p])
			{
				temp = array[p - 1];
				array[p - 1] = array[p];
				array[p] = temp;
				swapped = true;
				print_array(array, size);
			}
		}
		n--;
	}
}
