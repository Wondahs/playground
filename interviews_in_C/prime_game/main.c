#include "helpers.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int *num_arr = malloc(3000 * sizeof(int));

	for (int i = 0; i < 3000; i++)
		num_arr[i] = i + 1;

    int size = 3000;
	
	// printf("Array: ");
	// printArray(num_arr, size);
	printf("Winner is %s.\n", primeGame(size, num_arr));
	free(num_arr);
	return 0;
}
