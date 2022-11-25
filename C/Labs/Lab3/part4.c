/**
 * @credit: Copyright (c) hazardev
 * @license: MIT License
 */

// Headers
#include <stdio.h>


// Prototypes
void instructions();
float average(int a, int b, int c);
void display(float num);


// Main
int main(void)
{
    // print instructions to the user
    instructions();

    // base array of numbers
    int numbers[3];

    // get 3 numbers from user input
    for (int i = 0; i < 3; i++)
    {
        printf("\nNumber #%i: ", i + 1);
        scanf("%i", &numbers[i]);
        getchar();
    }

    // get the average
    float avg = average(numbers[0], numbers[1], numbers[2]);

    // display the average
    display(avg);
}


// Functions
void instructions()
{
    /**
     *  Prints out the instructions for use, for the user.
    */

    printf("\nType in 3 numbers to get the average of them!\nMake sure they're integers, no decimals.\n");
}


float average(int a, int b, int c)
{
    /**
     *  Returns the average of three integers in a float.
    */

    float avg = (float) a + (float) b + (float) c;
    avg = avg / 3;
    return avg;
}


void display(float num)
{
    /**
     *  Displays a float to the user and writes it to a file "result.txt"
    */

    FILE *file = fopen("result.txt", "w");
    if (file == NULL)
    {
        printf("\nCouldn't open/save to file!\n");
    }
    else
    {
        fprintf(file, "%f", num);
        fclose(file);
    }

    printf("\nThe average your three numbers is : %f\n\n", num);
}

