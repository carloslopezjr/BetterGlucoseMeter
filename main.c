#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"



int main()
{
    struct Node *head = NULL;

    Header(); // this will always display the header in the beginning of the program

    // this will keep running until the user exits
    head = MenuOptions(head); // assignes the head variable with the return of menuOptions(head) function

    return 0;
}

/* NEXT UPDATES */ 

// 1: (COMPLETE)
// change printList function to take current date, day, and time

// 2: (COMPLETE)
// complete operations in backupData()
    // change backupData() to export as csv with correct table formats

    // (POSSIBLE FUTURE UPDATES FOR THIS TASK)
    // Add an extra column to the far left that will be called "#"
        // Each row below it will be ordered starting from 1

        // (REASON)
        // Ideally this will help with identifying the data in the future and can specifically call out a certain line the specific data is at
        // Also it looks prettier when you open the file outside the program

// 3: (UNDER CONSTRUCTION) - Working on it 1/12/24 

    // Read the csv data and put it into an array of structs: (COMPLETE)
        // We want to do this because if we have multiple iterations, we would need to read it anyways

    // This would allow me to do binary search when searching for specific data and other searching algorithms

    // add insert function to insert a previous log from a different day and a deletion function


// 4: (FUTURE IMPLEMENTATION)
// change meal tags to be more specific
// Fix Logger() logic to improve user experience

// 5: (FUTER IMPLEMENTATION)
// ideate how to create "Calculate Insulin Dose" option for program

// (IDEA)
// A person's levels are 140, and their going to eat 15 carbs right now. What are the chances they will feel less focused because of it? 



// ---CODE DUMP--- //

/*
for (int i = 0; i < arraySize; i++)
    {
        printf("%d, ", (*dynamicArray)[i].month);
        printf("%d, ", (*dynamicArray)[i].day);
        printf("%d, ", (*dynamicArray)[i].year);
        printf("%d, ", (*dynamicArray)[i].dayName);
        printf("%d, ", (*dynamicArray)[i].hour);
        printf("%d, ", (*dynamicArray)[i].minutes);
        printf("%d, ", (*dynamicArray)[i].seconds);
        printf("%d, ", (*dynamicArray)[i].levels);
        printf("%d, ", (*dynamicArray)[i].focusedLevel);
        printf("%s, ", (*dynamicArray)[i].foodTime);
        printf("%s\n", (*dynamicArray)[i].foodType);
    }

    printf("\n");
*/


// What's the problem? ------------------------ |

// The problem is that we want to make the user input as little as possible to avoid any annoyances.

// When we are asking for data to insert a past log the user forgot to input, we don't want to ask for every single detail to find where it should go

// we will first ask for the context data for the log

// We will then ask for the date the user wants to input, and from there, the program will print out a table of all the related logs for that date in which the user can select the line number in which the log will be added

// if there's no date associated in the database, we will ask for the hour ("Give a general time for this log") for the log and input it into the database


// This is how the program will operate:

// When the user selects the option to insert past log data, we will prompt the user instructions.

// these instructions will be used to determine where their log should reside

// we use the inputs from the user and input them into the binarySearch function
    // the binarySearch function will take 3 inputs, month, day, year

    // when the function is called, we want it to look at the year the user inputted to see if there's any relevant data associated with it
        // if binarySearch can't find relevant data, we will have the binarySearch end and report that 0 "keys" were found

    // since 0 keys were found, the program knows that there is no data logged for that year the user specified, in which now the process of inserting the data all depends on if the log should be inserted after or before a certain point.

        // Here are the multiple cases the program can figure out:

            // Example: Let's say in the database there's only data from 2020 & 2024.
                // If a user enters the year 2023 as the year for their log, the program needs to successfully find the last log the database has for the year 2020. Since in the next line, it the logs will be from 2024. Or vise versa, the program needs to know the first log for the year 2024, and insert before.

                // Algorithm:

                    // the program will check the most recent log in the database. 
                    // it will compare the year the user entered with the last log. If the userYear > lastLog, insert after last log

                    // if the userYear < lastLog, check the first log of the database
                    // if the userYear < firstLog, insert before first log

                    // if the userYear > firstLog && userYear < lastLog, then obviously we need to input it somewhere in between that, in which I don't know the best way to do it. 

                    // Here are some options: 

                        // Lineaer search to find the date gap

                        // Or is there a way for the binarySearch to automatically do that for us?

                        // 

// add updates