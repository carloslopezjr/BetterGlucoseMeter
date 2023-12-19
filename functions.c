#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "functions.h"

void RemoveNewLine(char *stringInput)
{

    stringInput[strcspn(stringInput, "\n")] = 0;
}

void backupData() {
    
    // look for file text file in the current directory
    DIR *dir;

    struct dirent *entry;

    dir = opendir(".");

    if (dir == NULL) {
        perror("Error opening up directory");
        // return 1;
    }

    // if file == 0, file was not found
    int fileNotFound = 0;

    while ((entry = readdir(dir)) != NULL) {

        // check to see if it meets the name criteria
        if (strcmp(entry->d_name, "glucloselogs.txt") == 0)
        {
            printf("main.c is FOUND\n");
            fileNotFound++;
        }

    }

    if (fileNotFound != 1) {
        printf("File was not found\n");
    }

    closedir(dir);


        // if no file exists, make one

    

        // if it meets the name criteria, open the file

            // take the linked list data and paste it into the file

                // if file already has data, go to the next avaliable space

            // close the file when done

}

void loadData() {
    
    // look for text file in current directory

    // check to see if it meets the name criteria

        // if it meets the name criteria, load the data into a linked list

            // load the data into the linked list from top -> bottom

}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void Header()
{

    printf("-----WELCOME TO GLUCLOSE LOGGER V.1-----\n");
    printf("\n");
}

struct Node *createNode(struct LoggerData newData)
{
    // allocate memory for the node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        // prints the message in the error output
        fprintf(stderr, "Memory allocation failed.\n");

        // I don't know what this does
        exit(EXIT_FAILURE);
    }

    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void insertEnd(struct Node** head, struct Node* newNode) {

    if (*head == NULL) {
        *head = newNode;
    } else {
        
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        
        current->next = newNode;
        newNode->prev = current;
    }
}

void printList(struct Node* head) {

    printf("------GLUCLOSE LOGS------\n");
    printf("\n");

    struct Node* current = head;
    
    while (current != NULL) {

        enum FoodType foodType = current->data.foodType;
        enum FoodTime foodTime = current->data.foodTime;

        printf("Gluclose Level: %d \n", current->data.levels);

        switch (foodType) {
            case 1:
                printf("Food Type: Breakfast\n");
                break;
            case 2:
                printf("Food Type: Lunch\n");
                break;
            case 3:
                printf("Food Type: Dinner\n");
                break;
            case 4:
                printf("Food Type: Snack\n");
                break;
        }

        switch (foodTime)
        {
        case 1:
            printf("Time: Morning\n");
            break;
        case 2:
            printf("Time: Afternoon\n");
            break;
        case 3:
            printf("Time: Evening\n");
            break;
        case 4:
            printf("Time: Midnight\n");
            break;
        }

        printf("Focused Rating: %d \n", current->data.focusedLevel);
        printf("\n");

        // Go To The Next Node
        current = current->next;
    }

    printf("-------------------------\n");
    printf("\n");
}

void Logger()
{

    struct Node *head = NULL;

    int counter = 0;
    char answer;

    int stopper = 1; // condition
    while (stopper != 0)
    {

        struct LoggerData inputData;

        // The Type Of Food
        printf("|1| Breakfast |2| Lunch |3| Dinner |4| Snack\n");
        printf("\n");
        printf("What Type Of Food Did You Eat?: ");
        scanf("%d", &inputData.foodType);
        printf("\n");

        // When You Ate The Food
        printf("|1| Morning |2| Afternoon |3| Evening |4| Midnight\n");
        printf("\n");
        printf("When Did You Eat It?: ");
        scanf("%d", &inputData.foodTime);
        printf("\n");

        // Rate 1-10 How You Focused You Feel
        printf("Rate 1-10 How Focused You Feel: ");
        scanf("%d", &inputData.focusedLevel);
        printf("\n");
        

        // enter level(s)
        printf("Enter your level: ");
        scanf("%d", &inputData.levels);
        printf("\n");


        // create a new node after collecting all data
        struct Node* newNode = createNode(inputData);


        // insert new data into a node
        insertEnd(&head, newNode);

        clearInputBuffer();

        int stopper2 = 0; // condition2
        while (stopper2 == 0)
        {

            // promps user if they want to add more levels
            printf("Want To Log More Levels? (Y/N): ");
            scanf("%c", &answer); // fixed from using %s to using %c because of errors with whitespace
            printf("\n");

            // checks answer from user input
            if (answer == 'Y' || answer == 'y')
            {
                counter++; // increments the counter for prompt purposes
                break; // returns break into the while loop
            }
            else if (answer == 'N' || answer == 'n')
            {
                stopper = 0;  // stops the outer while loop
                stopper2 = 1; // stops the inner while loop
            }
            else
            { // repeats until valid input
                printf("Invalid Option: Try again\n");
                printf("\n");
            }
        }
    }

    // correct grammar depending on scenario
    if (counter > 0)
    {
        printf("-----Levels were successfully logged-----\n");
    }
    else
    {
        printf("-----Level was successfully logged-----\n");
    }

    printf("\n");

    printList(head);
}

void MenuOptions()
{

    int selection;


    int num = 1;
    while (num != 0)
    {

        printf("|1| Logger |2| Carb Planner |3| Calculate Insulin Dose |4| Food-To-Carbs |5| A1C Goal Planner |6| Exit\n");

        printf("\n");

        if (num == 1)
        {
            printf("Selection: ");
            scanf("%d", &selection);
            printf("\n");
        }
        else
        {
            printf("Select Option Between 1-4: ");
            scanf("%d", &selection);
            printf("\n");
        }

        if (selection == 1)
        {
            Logger();
            
        }
        else if (selection == 2)
        {
            printf("Option 2");
            // option 2
           
        }
        else if (selection == 3)
        {
            printf("Option 3");
            // option 3
            
        }
        else if (selection == 4)
        {
            printf("Option 4");
            // option 4
            
        }
        else if (selection == 5)
        {
            printf("Option 5");
            // option 5
            
        }
        else if (selection == 6) {
            // exit
            num = 0;
        }
        else
        {
            ++num;
            printf("Option %d out of range.\n\n", selection);
        }
    }
}

void LogIn()
{

    char username[100];
    char password[100];

    printf("Enter Username: ");
    fgets(username, 100, stdin);

    printf("Enter Password: ");
    fgets(password, 100, stdin);
    printf("\n");

    printf("---Successful Login---\n\n");

    RemoveNewLine(username);

    printf("Welcome %s! Please select an option: \n\n", username);

    MenuOptions();
}
