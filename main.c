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

    backupData(head);


    int arrayLength = 0;
    int initialSize = 100;

    struct ArrayNode *dynamicArray;

    // allocate memory for the array data structure
    dynamicArray = (struct ArrayNode *)malloc(initialSize * sizeof(struct ArrayNode));

    // If allocation fails condition
    if (dynamicArray == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
    }

    loadData(&dynamicArray, &arrayLength, &initialSize);

    for (int i = 0; i < arrayLength; i++)
    {
        printf("%d, ", dynamicArray[i].month);
        printf("%d, ", dynamicArray[i].day);
        printf("%d, ", dynamicArray[i].year);
        printf("%d, ", dynamicArray[i].dayName);
        printf("%d, ", dynamicArray[i].hour);
        printf("%d, ", dynamicArray[i].minutes);
        printf("%d, ", dynamicArray[i].seconds);
        printf("%d, ", dynamicArray[i].levels);
        printf("%d, ", dynamicArray[i].focusedLevel);
        printf("%s, ", dynamicArray[i].foodTime);
        printf("%s\n", dynamicArray[i].foodType);
    }

    free(dynamicArray);

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
// My levels right now are 140, and I'm going to eat 15 carbs right now. What are the chances I will feel less focused because of it? 
