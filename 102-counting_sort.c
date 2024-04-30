#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - this sorts array of ints in ascending order by
 * counting sort algorithm
 * @array: the array of integers to be sorted
 * @size: the amount of elements in array
 */
void counting_sort(int *array, size_t size)
{
	int p, total, max;
	int *count, *output;

	if (!array || size < 2)
		return;

	max = array[0];
	for (p = 0; p < (int)size; p++)
	{
		if (array[p] > max)
			max = array[p];
	}

	count = calloc((max + 1), sizeof(int));
	if (!count)
		return;
	for (p = 0; p < (int)size; p++)
		count[array[p]]++;

	for (p = 0, total = 0; p < max + 1; p++)
	{
		total = count[p] + total;
		count[p] = total;
	}
	print_array(count, max + 1);

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (p = 0; p < (int)size; p++)
	{
		output[count[array[p]] - 1] = array[p];
		count[array[p]]--;	}

	for (p = 0; p < (int)size; p++)
		array[p] = output[p];
	free(count);
	free(output);
}
