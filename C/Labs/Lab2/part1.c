/**
 * @credit: Copyright (c) hazardev
 * @license: MIT License
 * @note: too lazy to account for buffer over/underflow
 */

// Headers
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>


// Structs
typedef char *string;

typedef struct input
{
    bool valid;
    int value;
}
input;


// Prototypes
input *getNextInput(string msg);


// Main
int main(void)
{
    // variables
    double sum = 0, avg = 0;
    double min = INT_MAX, max = INT_MIN;

    int i_total = 0;
    int i_valid = 0;

    // loop for input
    while (true)
    {
        // create new input
        string prompt = malloc(32 * sizeof(char));
        sprintf(prompt, "Enter integer #%i : ", i_valid + 1);
        input *next = getNextInput(prompt);

        // increment total inputs
        i_total += 1;

        // if valid, ...
        if (next->valid == true)
        {
            // ... check for -1, break loop
            if (next->value == -1)
            {
                i_total -= 1;
                free(next);
                break;
            }

            // ... increment valid inputs
            i_valid += 1;

            // ... add to sum
            sum += next->value;

            // ... check and update if min
            if (next->value < min)
            {
                min = next->value;
            }

            // ... check and update if max
            if (next->value > max)
            {
                max = next->value;
            }

            // ... clean up memory
            free(next);
        }
    }

    // final math
    avg = sum / (double) i_valid;

    // output results
    printf("\n\nYou've inputted %i entries, %i of which were valid.", i_total, i_valid);
    printf("\n\nSummary");
    printf("\nTotal sum :          %.00lf", sum);
    printf("\nTotal average :      %.00lf", avg);
    printf("\nSmallest number :    %.00lf", min);
    printf("\nLargest number :     %.00lf", max);
    printf("\n\n");

    // return success
    exit(0);
}


// Functions
input *getNextInput(string msg)
{
    // reserve memory & check
    input *new = (input *) calloc(1, sizeof(input));
    if (new == NULL)
    {
        // couldnt create input; clean up and abort
        printf("Error creating input, system out of memory?\n");
        free(new);
        printf("Aborting...\n");
        exit(1);
    }

    // base variables
    int chk = INT_MIN;
    int num = chk;

    // get input and check (ignoring buffer under/overflow -> @note)
    printf("%s", msg);
    scanf("%i", &num);
    getchar();

    if (num == chk)
    {
        // invalid
        new->valid = false;
        new->value = 0;
        printf("\nYou've entered an invalid integer! Use -1 to exit.\n");
    }
    else
    {
        // valid
        new->valid = true;
        new->value = num;
    }

    // return
    return new;
}