#include "sort.h"


/**
 *swap_num - Swap two numbers.
 *@a: First number.
 *@b: Second number.
 *
 *
 *Return: Nothing.
 */

void swap_num(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 *bubble_sort - Sorts an array of integers in
 *		ascending order using the Bubble sort algorithm.
 *@array: Array to sort.
 *@size: size of array.
 *
 *
 *Return: Nothing.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	bool sorted = false;

	if (array == NULL || size < 2)
		return;

	while (!sorted)
	{
		sorted = true;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_num(array + i, array + i + 1);
				print_array(array, size);
				sorted = false;
			}
		}
	}
}
