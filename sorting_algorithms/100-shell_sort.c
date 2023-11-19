#include "sort.h"
#include <stddef.h>

/**
 *shell_sort - Sorts an array of size @size using shell sort algorithm.
 *@array: Array to sort.
 *@size: Size of @array.
 *
 *
 *Return: Nothing.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i = 0, j;
	int temp;

	while (gap <= size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			temp = array[i];
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap /= 3;
	}
}
