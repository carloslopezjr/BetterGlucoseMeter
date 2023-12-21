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
    

    while (head != NULL)
    {
        // test to see if time is being stored in node
        printf("Hour: %d\n", head->data.hour);
        printf("Minutes: %d\n", head->data.minutes);
        printf("Seconds: %d\n", head->data.seconds);
        printf("Year: %d\n", head->data.year);

        head = head->next;
    } 
    
    return 0; 
}

/* NEXT UPDATES */

// 1: (COMPLETE)
// change printList function to take current date, day, and time

// 2:
// create another text file to backup all the node data


// 3:
// add insert function to insert a previous log from a different day
// change the user logic when using the program to make this work

// 4:
// change meal tags to be more specific
