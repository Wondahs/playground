#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>

bool containsPrime(int *arr, int size);
bool isPrimeNum(int num);
void printArray(int *arr, int size);
int firstPrime(int *arr, int size);
int *arrayFromRange(int start, int end);

#endif // HELPERS_H
