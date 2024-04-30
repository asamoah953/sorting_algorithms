#include "sort.h"

/**
 * selection_sort -This sorts array of ints using the selction sort
 * algorithm
 * @array: array of ints to be sorted
 * @size: amount of elements the array
 */
void selection_sort(int *array, size_t size)
{
	int p, m, min_m, temp, n = (int)size;

	if (!array || size < 2)
		return;

	/* at every position in the n-member array */
	for (p = 0; p < n - 1; p++)
	{
		/* scan from that position to the end, */
		min_m = p;
		for (m = p + 1; m < n; m++)
		{
			/* determine the minimum value in that range */
			if (array[m] < array[min_m])
			{
				min_m = m;
			}
		}
		/* if lower than the value at start of range, */
		/* then swap them */
		if (min_m != p)
		{
			temp = array[p];
			array[p] = array[min_m];
			array[min_m] = temp;
			print_array(array, size);
		}
	}
}
