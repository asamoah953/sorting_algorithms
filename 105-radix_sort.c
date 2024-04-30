#include "sort.h"
#include <stdlib.h>

/**
 * init_bucket_count - resets bucket_count values to 0
 * @bucket_count: array containing amounts of members for arrays in `buckets`
 */
void init_bucket_count(int *bucket_count)
{
	int p;

	for (p = 0; p < 10; p++)
		bucket_count[p] = 0;
}

/**
 * build_buckets - allocates space for arrays to be held in `buckets`
 * @buckets: array of arrays each containing sorted members of `array`
 * @bucket_count: array containing amounts of members for arrays in `buckets`
 */
void build_buckets(int *bucket_count, int **buckets)
{
	int *bucket;
	int p;

	for (p = 0; p < 10; p++)
	{
		bucket = malloc(sizeof(int) * bucket_count[p]);
		if (!bucket)
		{
			for (; p > -1; p--)
				free(buckets[p]);
			free(buckets);
			exit(EXIT_FAILURE);
		}
		buckets[p] = bucket;
	}
	init_bucket_count(bucket_count);
}

/**
 * find_max - searches array of integers for highest value
 * @array: array of values to be searched
 * @size: number of elements in array
 * Return: largest integer stored in array
 */
int find_max(int *array, size_t size)
{
	int max;
	size_t p;

	max = array[0];
	for (p = 1; p < size; p++)
		if (array[p] > max)
			max = array[p];
	return (max);
}

/**
 * into_array - flattens buckets into array sorted by current digit place,
 * then prints results and frees current buckets for next pass
 * @array: array of values to be printed
 * @size: number of elements in array
 * @buckets: array of arrays each containing sorted members of `array`
 * @bucket_count: array containing amounts of members for arrays in `buckets`
 */
void into_array(int *array, size_t size, int **buckets, int *bucket_count)
{
	int p, m, k;

	/* flatten bucket members in order into array sorted by place */
	for (k = 0, p = 0; k < 10; k++)
	{
		for (m = 0; m < bucket_count[k]; m++, p++)
			array[p] = buckets[k][m];
	}
	/* print results */
	print_array(array, size);
	/* free buckets from current pass */
	for (p = 0; p < 10; p++)
		free(buckets[p]);
}

/**
 * radix_sort - Sorts array of integers in ascending order using a Radix sort
 * alogrithm starting with the LSD, the 'least significant (1s place) digit',
 * and sorting by next digit to left. Size of `bucket_count` here determined
 * by max range of key variance (digits 0-9), other solutions may be needed for
 * much larger ranges.
 * @array: array of values to be sorted
 * @size: number of elements in array
 */
void radix_sort(int *array, size_t size)
{
	int **buckets;
	int bucket_count[10];
	int max, max_digits, pass, divisor, digit;
	size_t p;

	if (!array || size < 2)
		return;
	buckets = malloc(sizeof(int *) * 10);
	if (!buckets)
		exit(1);
	/* find amount of places in largest element */
	max = find_max(array, size);
	for (max_digits = 0; max > 0; max_digits++)
		max /= 10;
	/* one sorting pass for each place in max_digits */
	for (pass = 0, divisor = 1; pass < max_digits; pass++, divisor *= 10)
	{
		init_bucket_count(bucket_count);
		/* find amount of members in each bucket */
		for (p = 0; p < size; p++)
		{
			digit = (array[p] / divisor) % 10;
			bucket_count[digit]++;
		}
		build_buckets(bucket_count, buckets);
		/* fill buckets sorting by digit at current power of 10 */
		for (p = 0; p < size; p++)
		{
			digit = (array[p] / divisor) % 10;
			buckets[digit][bucket_count[digit]] = array[p];
			bucket_count[digit]++;
		}
		into_array(array, size, buckets, bucket_count);
	}
	free(buckets);
}
