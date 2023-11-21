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
 * lumoto_partition - function that implements Lumoto partition scheme.
 * @a: array
 * @low: 1st element
 * @high: last element
 * @size: size
 * Return: index of swapped element
 */
int hoare_partition(int *a, int low, int high, size_t size)
{
	int pivot = a[high], right, left, i;

	left = low;
	right = high - 1;

	printf("%d\n", left);
	while (left <= right)
	{
		i = left;
		while (i <= right)
		{
			if (a[i] <= pivot)
			{
				swap_num(&a[i], &a[left]);
				print_array(a, size);
			}
			i++;
		}
		i = right;
		while (i >= left)
		{
			if (a[i] > pivot)
				swap_num(&a[i], &a[right]);
			print_array(a, size);
			i--;
		}
		right--;
		left++;
	}
	return right;
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
		pi = hoare_partition(a, low, high, size);

		quick_helper(a, low, pi - 1, size);
		quick_helper(a, pi + 1, high, size);
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
