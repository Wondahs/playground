#include "sort.h"

/**
 * lumoto_partition - function that implements Lumoto partition scheme.
 * @a: array
 * @low: 1st element
 * @high: last element
 * @size: size
 * Return: index of swapped element
 */
int lumoto_partition(int *a, int low, int high, size_t size)
{
	int i, j, swap, pivot = a[high];

	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (a[j] <= pivot)
		{
			i++;
			swap = a[i];
			a[i] = a[j];
			a[j] = swap;
			if (i != j)
			print_array(a, size);
		}
	}
	swap = a[i + 1];
	a[i + 1] = a[high];
	a[high] = swap;
	if (high != (i + 1))
		print_array(a, size);
	return (i + 1);
}

/**
 * quick_helper - Helper function for quick_sort.
 * @a: array
 * @low: low
 * @high: high
 * @size: length of array
 * Return: void
 */
void quick_helper(int *a, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lumoto_partition(a, low, high, size);

		quick_helper(a, low, pi - 1, size);
		quick_helper(a, pi + 1, high, size);
	}
}

/**
 * quick_sort - function
 *@array: array to sort
 *@size: size of array
 *Return: nothing.
 */
void quick_sort(int *array, size_t size)
{
	quick_helper(array, 0, size - 1, size);
}
