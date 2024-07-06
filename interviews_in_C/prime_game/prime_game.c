#include "helpers.h"


/**
 * @brief Plays a game where two players take turns removing multiples of prime numbers from a list.
 * @param rounds The number of rounds to play.
 * @param arr An array of integers representing the upper limit for each round.
 * @return A string indicating the winner ("Maria", "Ben", or NULL for a draw).
 * 
 * The game starts with a list of integers from 1 to the upper limit of the first round.
 * Players take turns removing multiples of prime numbers from the list.
 * The game continues until there are no more prime numbers in the list.
 * The player who takes the last turn wins the round.
 * The function returns the name of the winner after all rounds have been played.
 * If there is a draw, the function returns NULL.
 * 
 * @note The function assumes that the input array is not NULL and contains at least one element.
 * @note The function frees the memory allocated for the current list at the end of each round.
 */
char *primeGame(int rounds, int *arr) {
    if (!rounds || !arr)
        return NULL;
    
    int new_size = 0, current_size = 0;
    int MariaWins = 0, BenWins = 0;

    for (int i = 0; i < rounds; i++) {
        int *currentList = arrayFromRange(1, arr[i] + 1);
        current_size = arr[i];
        int turns = 3;
        
        while (containsPrime(currentList, current_size)) {
            int currentPrime = firstPrime(currentList, current_size);
            int multipleCount = countMultiples(currentList, current_size, currentPrime);
            new_size = current_size - multipleCount;

            if (currentPrime) {
                int *new_list = copyWithoutMultiples(currentList, current_size, new_size, currentPrime);
                current_size = new_size;
                free(currentList);
                currentList = new_list;
            }
            turns++;
        }

        if (turns % 2 == 0) {
            MariaWins++;
        } else {
            BenWins++;
        }
        free(currentList);
    }

    if (MariaWins > BenWins) {
        return "Maria";
    } else if (BenWins > MariaWins) {
        return "Ben";
    } else {
        return NULL;
    }
}
