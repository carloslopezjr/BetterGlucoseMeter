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
    backupData(head);

    return 0;
}

/* NEXT UPDATES */

// 1:
// change printList function to take current date, day, and time

// 2:
// change meal tags to be more specific


// 3:
// add insert function to insert a previous log from a different day


