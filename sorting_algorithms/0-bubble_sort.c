#include "sort.h"
#include <stdbool.h>
#include <stddef.h>

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
	int temp;
	size_t i;
	bool sorted = false;

	while (!sorted)
	{
		sorted = true;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
				sorted = false;
			}
		}
	}
}
