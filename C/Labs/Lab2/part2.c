/**
 * @credit: Copyright (c) hazardev
 * @license: MIT License
 */

// Headers
#include <stdio.h>
#include <string.h>
#include <math.h>


// Globals
const float P_ASS = 0.3;
const float P_WRI = 0.6;
const float P_LAB = 0.1;

const float MIN_A = 70;
const float MIN_B = 60;
const float MIN_C = 50;
const float MIN_D = 40;
const float MIN_E = 0;


// Structs
typedef char *string;


// Prototypes
double getPercentageInput(string name);
double getWeightedAverage(double a, double w_a, double b, double w_b, double c, double w_c);
char getGrade(double average);


// Main
int main(void)
{
    // get user inputs
    double assignment = getPercentageInput("assignment");
    double written = getPercentageInput("written exam");
    double lab = getPercentageInput("lab exam");

    // get average & grade
    double average = getWeightedAverage(assignment, P_ASS, written, P_WRI, lab, P_LAB);
    char grade = getGrade(average);

    // output
    printf("\nWeighted average and grade is : %.2lf%% ( %c )\n\n", average, grade);

    // successful return
    return 0;
}


// Functions
double getPercentageInput(string name)
{
    // base variable
    double input = -0.1;

    // loop until proper input
    while (input < 0 || input > 100)
    {
        // message & user input
        printf("\nInput %s percentage: ", name);
        scanf("%lf", &input);
        getchar();

        // check if valid
        if (input < 0 || input > 100)
        {
            printf("\nError: Invalid percentage provided, please make sure it's between 0 - 100%%.");
        }
    }

    // return value
    return input;
}


double getWeightedAverage(double a, double w_a, double b, double w_b, double c, double w_c)
{
    // base variable
    double overall = 0.0;

    // find weighted average
    overall += ((a / 100) * w_a);
    overall += ((b / 100) * w_b);
    overall += ((c / 100) * w_c);
    overall *= 100;

    // return average
    return overall;
}


char getGrade(double average)
{
    // return grade
    if (average >= MIN_A)
    {
        return 'A';
    }
    else if (average >= MIN_B)
    {
        return 'B';
    }
    else if (average >= MIN_C)
    {
        return 'C';
    }
    else if (average >= MIN_D)
    {
        return 'D';
    }
    else if (average >= MIN_E)
    {
        return 'E';
    }
    else
    {
        return 'F';
    }
}