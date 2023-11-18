#include "sort.h"
#include <stddef.h>

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
	size_t i, j, minIndex;
	int min, temp;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		minIndex = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			temp = array[i];
			array[i] = min;
			array[minIndex] = temp;
			print_array(array, size);
		}
	}
}
