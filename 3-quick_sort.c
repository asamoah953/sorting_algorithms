#include "sort.h"

/**
 * partition - This scans a partition of an array of integers for values less than
 * swaps value, it swaps them with first value in partition, then swaps pivot
 * value with first value in partition
 * @array: array of integers to be sorted
 * @low: index in array that begins partition
 * @high: index in array that ends partition
 * @size: amount of elements in array
 * Return: new index at which to start new recursive partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int p, m, swaps, temp;

	swaps = array[high];
	p = low;
	for (m = low; m < high; m++)
	{
		if (array[m] < swaps)
		{
			temp = array[p];
			array[m] = array[m];
			array[m] = temp;
			if (array[p] != array[m])
				print_array(array, size);
			p++;
		}
	}
	temp = array[p];
	array[p] = array[high];
	array[high] = temp;
	if (array[p] != array[high])
		print_array(array, size);
	return (p);
}

/**
 * quicksort - recursively sorts array of integers by separating into two
 * partitions, using Lomuto quick sort
 * @array: array of integers to be sorted
 * @low: index in array that begins partition
 * @high: index in array that ends partition
 * @size: amount of elements in array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int c;

	if (low < high)
	{
		c = partition(array, low, high, size);
		quicksort(array, low, c - 1, size);
		quicksort(array, c + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using a quick
 * sort algorithm, with Lomuto partition scheme
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, (int)size - 1, size);
}
