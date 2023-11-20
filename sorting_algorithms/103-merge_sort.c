#include "sort.h"
#include <stdio.h>

/**
 *merge - Sorts arrays usinf merge sort.
 *@array: Array to merge.
 *@low: Index of first element.
 *@mid: Middle index.
 *@high: Index of last element.
 */
void merge(int array[], int low, int mid, int high)
{
	int left_size = mid - low + 1, right_size = high - mid;
	int left[left_size], right[right_size];
	int i, j, k;

	for (i = 0; i < left_size; i++)
		left[i] = array[low + i];
	for (j = 0; j < right_size; j++)
		right[j] = array[mid + 1 + j];
	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);
	i = 0;
	j = 0;
	k = low;
	while (i < left_size && j < right_size)
	{
		if (left[i] < right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < left_size)
	{
		array[k++] = left[i++];
	}
	while (j < right_size)
	{
		array[k++] = right[j++];
	}
	printf("[Done]: ");
	print_array(array, high);
}

/**
 *merge_sort - Sorts an array using merge sort algorithm.
 *@array: Array to sort.
 *@size: Size of array.
 *
 */
void merge_sort(int *array, size_t size)
{
	merger(array, 0, size - 1);
}

/**
 *merger - Helper function for merge_sort.
 *@array: Array to sort.
 *@low: Index of first element.
 *@high: Index of last element.
 */
void merger(int *array, int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = low + (high - low) / 2;

		merger(array, low, mid);
		merger(array, mid + 1, high);

		merge(array, low, mid, high);
	}
}
