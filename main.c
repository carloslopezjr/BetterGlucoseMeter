#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int main()
{

    struct Node *head = NULL;

    // this will always display the header in the beginning of the program
    Header();

    // this will keep running until the user exits
    MenuOptions(head);

    // take in the linked list data and back it up into a text file
    backupData(head);

    return 0;
}


