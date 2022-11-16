/**
 * @credit: Copyright (c) hazardev
 * @license: MIT License
 * @warning: DO NOT COPY-PASTE THIS AS YOUR ASSIGNMENT.
 * @note: Made as a sample for a C college assignment.
 *        Commented for explenation, without the use of functions or pointers.
 */


// Headers
#include <stdlib.h>                             // 'Standard Library'   (itc. allows for exiting program)
#include <stdio.h>                              // 'Standard IO'        (itc. allows inputs / outputs)
#include <stdbool.h>                            // 'Standard Bool'      (itc. allows the use of bools literally / directly)



// Globals (defined constant variables)
#define BASIC_MULT      1                       // salary multiplier for basic hours pay
#define BASIC_HOURS     39                      // hours worked at which basic pay is
#define BONUS_MULT      1.5                     // salary multiplier for bonus hours pay
#define BONUS_HOURS     50                      // hours worked at which bonus pay is (starts after basic hours)
#define OVERTIME_MULT   2                       // salary multiplier for overtime pay hours (after bonus pay)



// Main
int main(void)
{
    // variables for overall statistics
    double total_pay = 0;
    double total_hours = 0;
    double total_bonus_hours = 0;


    // variables for top employee (set to negative invalid numbers)
    int top_employee_number = -1;
    double top_employee_hours = -1;


    // an infinite loop for taking employee inputs (until -1)
    while (true)
    {

        // base variables for the employee (employee number set to -2, which is an invalid number)
        int employee_number = -2;
        double employee_hours = -1;
        double employee_rate = -1;
        double employee_salary = 0;


        // loop getting input for employee number, until input is valid (not below -1)
        while (employee_number <= -2)
        {
            // print prompt, wait for input, then clear input buffer
            printf("\nPlease enter the employee number or -1 to exit : \n");
            scanf("%i", &employee_number);
            getchar();

            // check if invalid
            if (employee_number < -1)
            {
                // number is below -1; invalid; tell the user (before it loops around again)
                printf("\nYou've entered an invalid employee number!");
            }
        }


        // check if the user entered -1, to exit
        if (employee_number == -1)
        {
            // they have, break the employee loop
            break;
        }


        // loop getting input for hours worked and rate, until valid (not negative)
        while (employee_hours < 0 || employee_rate < 0)
        {
            // make both invalid (negative)
            employee_hours = -1;
            employee_rate = -1;

            // print prompt, wait for input, clear buffer
            printf("\nPlease enter the total hours worked and hourly rate this week : \n");
            scanf("%lf %lf", &employee_hours, &employee_rate);
            getchar();

            // check if invalid
            if (employee_hours < 0 || employee_rate < 0)
            {
                // at least one number is negative; invalid; tell the user (before it loops around again)
                printf("\nYou've entered an invalid number of hours or hourly rate!");
            }
        }


        // calculate salary based on values, using a loop (per every hour)
        for (int i = 0; i < employee_hours; i++)
        {
            // variable for pay multiplier (set to basic multiplier)
            double multiplier = BASIC_MULT;

            // check if the current hour is over ...
            if (i > BONUS_HOURS)
            {
                // ... overtime hours, update multiplier to overtime, add to bonus counter
                multiplier = OVERTIME_MULT;
                total_bonus_hours++;
            }
            else if (i > BASIC_HOURS)
            {
                // ... bonus hours, update multiplier to bonus, add to bonus counter
                multiplier = BONUS_MULT;
                total_bonus_hours++;
            }

            // add current hour's pay to salary
            employee_salary += (employee_rate * multiplier);
        }


        // update total values
        total_pay += employee_salary;
        total_hours += employee_hours;


        // check if current employee tops the last "top employee"
        if (employee_hours > top_employee_hours)
        {
            // it does, update the top to the current employee
            top_employee_number = employee_number;
            top_employee_hours = employee_hours;
        }


        // output message about the current employee
        printf("Employee Number %i has a total salary of %.00lf\n", employee_number, employee_salary);

    }


    // output final summary
    printf("\nTotal company wages are %.00lf\n", total_pay);
    printf("The total number of hours above the %i hours per week is %.lf\n", BASIC_HOURS, total_bonus_hours);

    if (top_employee_hours <= -1)
    {
        // no top employees
        printf("No employees have worked, no max hours available.\n\n");
    }
    else
    {
        // only print top employee if there is at least 1
        printf("Employee %i has the max hours worked of %.00lf\n\n", top_employee_number, top_employee_hours);
    }


    // exit program successfull (0 = success)
    exit(0);

}