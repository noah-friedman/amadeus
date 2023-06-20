#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <amadeus/prompt.h>

int main() {
    printf("The A.M.a.D.E.U.S. Project\n");
    printf("Created by Noah Friedman\n");

    // Get the maximum limit for the random number from the user
    int max = prompt_min("Enter a maximum", 1);

    // Initialize random number generator and generate the number the user will guess
    srand(time(NULL));
    int number = rand() % max + 1;

    // Main loop
    while (true) {
        // Get the user's guess
        int guess = prompt_range("Enter a guess", 1, max);

        // Check if the guess is correct
        if (guess == number) {
            printf("Correct!\n");
            break;
        } else if (guess < number) {
            printf("Higher!\n");
        } else {
            printf("Lower!\n");
        }
    }
}
