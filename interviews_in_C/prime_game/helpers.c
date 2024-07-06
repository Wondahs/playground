#include "helpers.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

/**
 * isPrimeNum - Checks if a num is a prime.
 * - num: number to check
 *
 * Return: true if number is prime. False otherwise.
 */
bool isPrimeNum(int num) {
	int num_sqrt = 0;

	if (num <= 1)
		return false;
	if (num <= 3)
		return true;
	if (num % 2 == 0 || num % 3 == 0)
		return false;
	num_sqrt = (int) sqrt(num) + 1;
	for (int i = 5; i <= num_sqrt; i += 6) {
		if (num % i == 0 || num % (i + 2) == 0)
			return false;
	}
	return true;
}

/**
 * containsPrime - Checks if an array contains at least one prime number
 * - arr: Array to check
 * - size: size of array
 *
 *   Return: true if array contains prime, false otherwise.
 */
bool containsPrime(int *arr, int size) {

	if (!arr)
		return false;

	for (int i = 0; i < size; i++) {
		if (isPrimeNum(arr[i]))
			return true;
	}
	return false;
}


/**
 * printArray - Prints an array
 */
void printArray(int *arr, int size) {
	for (int i = 0; i < size; i++)
		printf("%d%s", arr[i], i < size - 1 ? ", " : ".");
	printf("\n");
}


/**
 * firstPrime - Retrieves the first prime in an array.
 * - arr: Array to check
 * - size: Size of array
 *
 * Return: First prime if exists, - 1 otherwise.
 */
int firstPrime(int *arr, int size) {
	int i = 0;
	while (i < size) {
		if (isPrimeNum(arr[i]))
			return arr[i];
	i++;
	}
	return -1;
}

/**
 * arrayFromRange - Creates an array from a range
 * - start: Starting point
 * - end: Ending point(Excluded)
 * 
 * Return: Array containing numbers starting from @start to @end.
 * 		   Returns NULL if failed.
 */
int *arrayFromRange(int start, int end) {
	if (!start || !end || start > end)
		return NULL;
	int *arr = malloc(sizeof(int) * (end - start));
	for (int i = start; i < end; i++) {
		arr[i - start] = i;
	}
	return arr;
}

/**
 * countMultiples - Counts the multiples of a given prime number in an array.
 *
 * @param arr: The array in which to count the multiples.
 * @param size: The size of the array.
 * @param prime: The prime number whose multiples should be counted.
 *
 * @return: The number of multiples of the given prime number in the array.
 *          Returns 0 if the array is NULL, the size is less than or equal to 0, or the prime number is less than or equal to 1.
 */
int countMultiples(int *arr, int size, int prime) {
    int multipleCount = 0;

    // Count the multiples of the prime number in the array
    for (int i = 0; i < size; i++) {
        if (arr[i] % prime == 0)
            multipleCount++;
    }

    return multipleCount;
}

/**
 * copyWithoutMultiples - Creates a new array excluding multiples of a given prime number.
 *
 * @param arr: The original array from which to create the new array.
 * @param size: The size of the original array.
 * @param prime: The prime number whose multiples should be excluded from the new array.
 *
 * @return: A new array containing only the elements from the original array that are not multiples of the given prime number.
 *          The function returns NULL if the original array is NULL, the size is less than or equal to 0, or the prime number is less than or equal to 1.
 *          The caller is responsible for freeing the memory allocated for the new array.
 */
int *copyWithoutMultiples(int *arr, int old_size, int new_size, int prime) {
    int j = 0;
    int *new_arr = NULL;

    // Allocate memory for the new array
    new_arr = malloc(sizeof(int) * (new_size));

    // Copy the elements from the original array to the new array, excluding multiples of the prime number
    for (int i = 0; i < old_size; i++) {
        if (arr[i] % prime)
            new_arr[j++] = arr[i];
    }

    return new_arr;
}
