/**
 * @credit: Copyright (c) hazardev
 * @license: MIT License
 * @note: FACT_LIMIT tested against ULLONG_MAX
 */

// Headers
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


// Globals
#define FACT_LIMIT 66


// Structs
typedef char *string;


// Prototypes
int getUserInt(string msg);
unsigned long long getFactorial(int i);


// Main
int main(void)
{
    // get int from user & check
    int num = getUserInt("\nEnter an integer for factorial");
    if (num < 0)
    {
        // abort with error code
        printf("\nUnable to get negative factorials.\n\n");
        exit(1);
    }

    // get factorial
    unsigned long long fact = getFactorial(num);

    // output
    printf("\nFactorial for %d = %llu\n\n", num, fact);

    // exit successfully
    exit(0);
}


// Functions
int getUserInt(string msg)
{
    // base variables
    int chk = INT_MIN;
    int num = chk;

    // get user input
    printf("%s : ", msg);
    scanf("%d", &num);
    getchar();

    // check if valid, & against limit
    if (num == chk)
    {
        printf("\nInvalid integer given, try again!\n\n");
        exit(1);
        // return getUserInt(msg);
    }
    else if (num >= FACT_LIMIT)
    {
        printf("\nThe buffer would overflow with your number, %i is the max!\n\n", FACT_LIMIT);
        exit(1);
        // return getUserInt(msg);
    }
    else
    {
        return num;
    }
}


unsigned long long getFactorial(int num)
{
    // check for negative
    if (num <= 0)
    {
        return 0;
    }

    // base variable
    unsigned long long fact = 1;

    // math
    for (int i = 1; i <= num; i++)
    {
        fact *= i;
    }

    // returned
    return fact;
}