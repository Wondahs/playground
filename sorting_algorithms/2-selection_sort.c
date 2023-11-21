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
 *selection_sort - Sorts an array using selection sort.
 *@array: Array to sort.
 *@size: Size of array.
 *
 *
 *Return: Nothing.
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_num(array + i, min);
			print_array(array, size);
		}
	}
}
