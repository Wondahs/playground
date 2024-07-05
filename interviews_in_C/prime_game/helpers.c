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
	int num_sqrt;

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
