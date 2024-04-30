#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using a shell
 * sort algorithm, with space sizes determined by a decreasing Knuth seqeuence
 * @array: array of integers to be sorted
 * @size: amount of elements in array
 */
void shell_sort(int *array, size_t size)
{
	int p, m, space, n, Knuth_max, temp;

	if (!array || size < 2)
		return;

	n = (int)size;
	for (space = 1; space < n; space = (space * 3) + 1)
	{
		Knuth_max = space;
	}
/* Start with the largest Knuth seq value less than n as space, */
/* and work down sequence to a space of 1 */
	for (space = Knuth_max; space > 0; space = (space - 1) / 3)
	{
		/* Do a spaced insertion sort for this space size. */
		for (p = space; p < n; p++)
		{
			/* add array[p] to space sorted elements; */
			/* save array[p] in temp in preparation to overwrite */
			temp = array[p];
			/* shift earlier space-sorted elements up until the */
			/* correct location for array[i] is found */
			for (m = p; m >= space && array[m - space] > temp; m -= space)
			{
				array[m] = array[m - space];
			}
/* temp original array[p]) to its correct location */
			array[m] = temp;
		}
		print_array(array, size);
	}
}
