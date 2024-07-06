#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

bool containsPrime(int *arr, int size);
bool isPrimeNum(int num);
void printArray(int *arr, int size);
int firstPrime(int *arr, int size);
int *arrayFromRange(int start, int end);
int *copyWithoutMultiples(int *arr, int old_size, int new_size, int prime);
char *primeGame(int rounds, int *arr);
int countMultiples(int *arr, int size, int prime);

#endif // HELPERS_H
