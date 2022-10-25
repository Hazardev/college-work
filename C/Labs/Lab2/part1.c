/**
 * @credit: Copyright (c) hazardev
 * @license: MIT License
 */

// Headers
#include <stdio.h>
#include <string.h>
#include <math.h>


// Main
int main(void)
{
    // variables
    double space;
    double width;

    // get user inputs (using scanf)
    printf("Input total space available: ");
    scanf("%lf", &space);
    printf("Input tile width: ");
    scanf("%lf", &width); // */

    // check if valid, or if any fit
    if (width == 0.0 || space == 0.0)
    {
        // display message & return fail
        if (space == 0.0) { printf("\n"); }
        printf("\nError\n\nPlease use decimal numbers, other than 0.0\n\n");
        return 1;
    }
    if (width >= space)
    {
        // display message & return success
        printf("\nResult\n\nNo tiles will fit in the space provided\n\n");
        return 0;
    }

    // calculate amounts / math
    int amount = 0;
    double gap = 0;
    for (double i = space; i > 0; i -= width)
    {
        if (i - width < (double) 0)
        {
            gap = i / 2;
        }
        else
        {
            amount += 1;
        }
    }

    int black = (int) ((double) floor((double) amount / 2) + (amount % 2));
    int white = (int) ((double) floor((double) amount / 2));

    // display result
    printf("\nResult\n");
    printf("\nFor the total space of %f, and tiles being %f wide,\n", space, width);
    printf("\nYou will need %i tiles total\n", amount);
    printf("%i black\n", black);
    printf("%i white\n\n", white);
    printf("A gap of %f, each side, is needed to center the tiles\n\n", gap);

    // return success
    return 0;
}