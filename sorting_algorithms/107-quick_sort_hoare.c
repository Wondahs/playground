#include "sort.h"

int hoare_partition(int *a, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
void quick_helper(int *a, int low, int high, size_t size);

/**
 * swap_num - Swap two numbers.
 * @a: First number.
 * @b: Second number.
 * Return: Nothing.
 */
void swap_num(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
							}


/**
 * hoare_partition - function that implements Lumoto partition scheme.
 * @a: array
 * @low: 1st element
 * @high: last element
 * @size: size
 * Return: index of swapped element
 */
int hoare_partition(int *a, int low, int high, size_t size)
{
	int pivot = a[high], right, left;

	left = low - 1;
	right = high + 1;

	while (left < right)
	{
		do {
			left++;
		} while (a[left] < pivot);

		do {
			right--;
		} while (a[right] > pivot);

		if (left < right)
		{
			swap_num(a + left, a + right);
			print_array(a, size);
		}
	}
	return left;
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

	if (high - low > 0)
	{
		pi = hoare_partition(a, low, high, size);

		quick_helper(a, low, pi - 1, size);
		quick_helper(a, pi, high, size);
	}
}

/**
 * quick_sort_hoare - Quick sort using Hoare partition.
 *@array: array to sort
 *@size: size of array
 *Return: nothing.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;
	quick_helper(array, 0, size - 1, size);
}
