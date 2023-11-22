#include "sort.h"
#include <stddef.h>
#include <stdlib.h>

/**
 *counting_sort - Sorts an array using counting sort algorithm.
 *@array: Array to sort.
 *@size: size of array
 *
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, i, k;

	if (array == NULL || size < 2)
		return;

	k = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	k += 1;
	count = malloc(sizeof(int) * k);
	if (!count)
		return;
	for (i = 0; i < k; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 1; i < k; i++)
		count[i] += count[i - 1];
	print_array(count, (size_t)k);
	output = malloc(size * sizeof(int));
	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	free(count), free(output);
}
