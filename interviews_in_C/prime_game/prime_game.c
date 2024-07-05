#include "helpers.h"


char *primeGame(int rounds, int *arr) {
    if (!rounds || !arr)
        return NULL;
    
    int MariaWins, BenWins = 0;

    for (int i = 0; i < rounds; i++) {
        int *currentList = arrayFromRange(1, arr[i] + 1);
        int turns = 3;

        while (containsPrime(currentList, arr[i])) {
            int currentPrime = firstPrime(currentList, arr[i]);

            if (currentPrime) {

            }
        }
    }
}