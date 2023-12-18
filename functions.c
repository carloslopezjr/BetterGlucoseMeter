#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

void RemoveNewLine(char *stringInput)
{

    stringInput[strcspn(stringInput, "\n")] = 0;
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
        printf("Memory allocation failed.\n");

        // I don't know what this does
        exit(EXIT_FAILURE);
    }

    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void insertEnd(struct Node** head, struct Node* newNode) {
    // struct Node* newNode = createNode(newData);

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
        printf("|1| Breakfast\n|2| Lunch\n|3| Dinner\n|4| Snack\n");
        printf("\n");
        printf("What Type Of Food Did You Eat?: ");
        scanf("%d", &inputData.foodType);
        printf("\n");

        // When You Ate The Food
        printf("|1| Morning\n|2| Afternoon\n|3| Evening\n|4| Midnight\n");
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
        printf("-----Levels were successfully logged-----");
    }
    else
    {
        printf("-----Level was successfully logged-----");
    }

    printf("\n");

    printList(head);
}

void MenuOptions()
{

    int selection;

    printf("|1| Logger\n|2| Carb Planner\n|3| Calculate Insulin Dose\n|4| Food-To-Carbs\n|5| A1C Goal Planner\n");

    printf("\n");

    int num = 1;
    while (num != 0)
    {

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
            num = 0;
        }
        else if (selection == 2)
        {
            printf("Option 2");
            // option 2
            num = 0;
        }
        else if (selection == 3)
        {
            printf("Option 3");
            // option 3
            num = 0;
        }
        else if (selection == 4)
        {
            printf("Option 4");
            // option 4
            num = 0;
        }
        else if (selection == 5)
        {
            printf("Option 4");
            // option 5
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
