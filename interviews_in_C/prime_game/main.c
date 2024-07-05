#include "helpers.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int *num_arr;
	int size;
	int i = 0;
	bool cPrime;

	printf("Enter array size\n");
	scanf("%d", &size);

	num_arr = (int *)malloc((size_t)size * sizeof(int));
	while (i < size) {
		int num;
		printf("Enter number %d.\n", i + 1);
		scanf("%d", &num);

		num_arr[i] = num;
		i++;
	}
	cPrime = containsPrime(num_arr, size);
	printf("Array: ");
	printArray(num_arr, size);
	printf("It %s.\n", cPrime ? "contains prime" : "does not contain prime");
	if (cPrime)
		printf("First prime: %d.\n", firstPrime(num_arr, size));
	free(num_arr);
	return 0;
}
