/**
 * @credit: Copyright (c) hazardev
 * @license: MIT License
 */

// Headers
#include <stdio.h>                  // used for basic IO input / output
#include <string.h>                 // contains useful functions and things for strings


// Globals
#define MAX_TEXT 128                // this is like a variable, i'm using it for the max string size


// Main
int main(void)
{
    // base variables
    char string1[MAX_TEXT];         // using MAX_TEXT from before to create a string with that size
    char string2[MAX_TEXT];
    int number = 0;

    // prompt and get strings from user
    printf("\nEnter text for first string (no spaces) :\n");
    scanf("%s", string1);
    getchar();

    printf("\nEnter text for second string (no spaces) :\n");
    scanf("%s", string2);
    getchar();

    // prompt and get a number from user (ignoring invalid numbers; itll just stay 0)
    printf("\nEnter an integer number :\n");
    scanf("%i", &number);
    getchar();

    // -> bullet point 1 : display the length of both strings
    printf("\nThe length of string 1 is: %lu, the length of string 2 is: %lu\n", strlen(string1), strlen(string2));

    // -> bullet point 2 : display both strings
    printf("\nString 1 is: '%s', string 2 is: '%s'\n", string1, string2);

    // -> bullet point 3 : compare both strings and display the bigger string
    int comparison = strcmp(string1, string2);

    if (comparison == 0)
    {
        printf("\nBoth strings are the same.\n");
    }
    else if (comparison > 0)
    {
        printf("\nThe 'bigger string' is string 1 by %i, which is: '%s'\n", comparison, string1);
    }
    else
    {
        printf("\nThe 'bigger string' is string 2 by %i, which is: '%s'\n", -comparison, string2);
    }

    // -> bullet point 4 : compare a number of characters, (user input), of both strings and display the bigger sub-string
    int sub_comparison = strncmp(string1, string2, number);

    if (sub_comparison == 0)
    {
        printf("\nBoth strings are the same.\n");
    }
    else if (sub_comparison > 0)
    {
        char temp[MAX_TEXT];
        strncpy(temp, string1, number);
        printf("\nThe 'bigger sub-string' is string 1 by %i, which is: '%s'\n", sub_comparison, temp);
    }
    else
    {
        char temp[MAX_TEXT];
        strncpy(temp, string2, number);
        printf("\nThe 'bigger sub-string' is string 2 by %i, which is: '%s'\n", -sub_comparison, temp);
    }

    // -> bullet point 5 : concatenate string2 into string1
    strcat(string1, string2);

    // -> bullet point 6 : display both strings
    printf("\nString 1 is: '%s', string 2 is: '%s'\n", string1, string2);

    // -> bullet point 7 : concatenate the first three characters of string2 to string1
    strncat(string1, string2, 3);

    // -> bullet point 8 : display both strings
    printf("\nString 1 is: '%s', string 2 is: '%s'\n", string1, string2);

    // -> bullet point 9 : copy string2 to string1
    strcpy(string1, string2);

    // -> bullet point 10 : display both strings
    printf("\nString 1 is: '%s', string 2 is: '%s'\n", string1, string2);

    // -> bullet point 10 : copy the first three characters of string1 to string2
    strncpy(string1, string2, 3);

    // -> bullet point 12 : display both strings
    printf("\nString 1 is: '%s', string 2 is: '%s'\n", string1, string2);

    // skip a line, so it looks better 8)
    printf("\n");
}





/**
 *
 *       888b     d888      d8b      888      888
 *       8888b   d8888      Y8P      888      888
 *       88888b.d88888               888      888
 *       888Y88888P888      888      888      888  888
 *       888 Y888P 888      888      888      888 .88P
 *       888  Y8P  888      888      888      888888K
 *       888   "   888      888      888      888 "88b
 *       888       888      888      888      888  888
 *
 *                    Don't question it.
*/