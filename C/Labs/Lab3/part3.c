/**
 * @credit: Copyright (c) hazardev
 * @license: MIT License
 * @note: Avoiding functions to avoid confusion,
 *        which is why I copy pasted a section of code.
 */

// Headers
#include <stdio.h>


// Globals
#define MATRIX_SIZE 3               // the size of the matrices (x, y)


// Main
int main(void)
{
    // base matrices
    double matrix_1[MATRIX_SIZE][MATRIX_SIZE];
    double matrix_2[MATRIX_SIZE][MATRIX_SIZE];

    // initial prompt
    printf("\nYou can seperate your numbers with a space to add more than one at once!\n");

    // loops to iterate over all matrix 1 slots ([0, 0], [0, 1] ... [3, 3])
    for (int y = 0; y < MATRIX_SIZE; y++)
    {
        for (int x = 0; x < MATRIX_SIZE; x++)
        {
            // prompt and get user input
            printf("\nEnter number for (%i, %i) of matrix 1: ", y, x);
            scanf("%lf", &matrix_1[y][x]);
            getchar();
        }
    }

    // loops to iterate over all matrix 2 slots (copy-pasted from above, this is bad practice)
    for (int y = 0; y < MATRIX_SIZE; y++)
    {
        for (int x = 0; x < MATRIX_SIZE; x++)
        {
            // prompt and get user input
            printf("\nEnter number for (%i, %i) of matrix 1: ", y, x);
            scanf("%lf", &matrix_2[y][x]);
            getchar();
        }
    }

    // print resulting matix
    printf("\nResulting matrix after adding both is :\n\n");

    for (int y = 0; y < MATRIX_SIZE; y++)
    {
        for (int x = 0; x < MATRIX_SIZE; x++)
        {
            printf("%.02lf\t\t\t", matrix_1[y][x] +  matrix_2[y][x]);
        }

        printf("\n\n");
    }
}