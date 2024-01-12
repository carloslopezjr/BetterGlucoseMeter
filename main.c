#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main()
{

    struct Node *head = NULL;

    // this will always display the header in the beginning of the program
    Header();

    // this will keep running until the user exits
    head = MenuOptions(head); // assignes the head variable with the return of menuOptions(head) function

    // take in the linked list data and back it up into a text file
    visualizeData(head);

    backupData(head);
    
    /*
    while (head != NULL)
    {
        // test to see if time is being stored in node
        printf("Hour: %d\n", head->data.hour);
        printf("Minutes: %d\n", head->data.minutes);
        printf("Seconds: %d\n", head->data.seconds);
        printf("Year: %d\n", head->data.year);

        head = head->next;
    } 
    */
    
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

// 3:
// add insert function to insert a previous log from a different day
    // I might have to switch data to be an array
    // This would allow me to do binary search when searching for specific data and other searching algorithms

    // Task: Find out how the program is creating the linked list after 1 execution 

// (IMPLEMENTATION) - OLD
//  Traverse through the linked list
        // Condition test the insert node's year data member with the current node's year data member:

            // if the condition is true, test the insert node's month data member with the current node's data member
                // else traverse to next node

            // if the condition is true, test the insert node's day data member with the current node's data member
                // else traverse to next node

            // if true, test the insert node's hour data member with the current node's data member
                // else traverse to next node

            // if true, test the insert node's minute data member with the current data member
                // else traverse to next node

            // if true, test thet insert node's seconds data member with the current data member
                // else traverse to next node
    

// fix Logger() logic to improve user experience

// 4:
// change meal tags to be more specific

// 5: 
// ideate how to create "Calculate Insulin Dose" option for program


// (IDEA)
// My levels right now are 140, and I'm going to eat 15 carbs right now. What are the chances I will feel less focused because of it? 
