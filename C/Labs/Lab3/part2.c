/**
 * @credit: Copyright (c) hazardev
 * @license: MIT License
 */

// Headers
#include <stdio.h>


// Globals
#define AMOUNT 20                   // for the amount of numbers to use


// Main
int main(void)
{
    // base variables (including an array for the numbers)
    int numbers[AMOUNT];

    double total = 0;
    double average = 0;

    // get user input for all of the numbers
    for (int i = 0; i < AMOUNT; i++)
    {
        // prompt & get user input
        printf("\nEnter integer #%i : ", i + 1);
        scanf("%i", &numbers[i]);
        getchar();

        // update total
        total += (double) numbers[i];
    }

    // now to get the average, since we already have total, just divide by the amount!
    average = total / AMOUNT;

    printf("\n\nThe average is %.02lf\n\nThe numbers under the average are :\n", average);

    // loop through the numbers again
    for (int i = 0; i < AMOUNT; i++)
    {
        // check if the number is under the average
        if (numbers[i] < average)
        {
            // it is!, print it out.
            printf("%i    ", numbers[i]);
        }
    }

    // style points
    printf("\n\n");
}