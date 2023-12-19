#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

int main()
{

    Header();

    MenuOptions();

    backupData();

    // after backupData has been called

    // open the file and print out the contents

    FILE* fptr;

    fptr = fopen("glucloselogs.txt", "r");

    if (fptr == NULL) {
        perror("Error opening file");
        return 1;
    }


    // this is the buffer for each line
    char buffer[100];

    while(fgets(buffer, sizeof(buffer), fptr) != NULL) {

        printf("%s", buffer);

    }

    fclose(fptr);

    return 0;
}


