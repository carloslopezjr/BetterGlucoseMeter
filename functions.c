#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "functions.h"

void RemoveNewLine(char *stringInput)
{

    stringInput[strcspn(stringInput, "\n")] = 0;
}

// gets the head from the main function
void backupData(struct Node* head) {
    
    // look for file text file in the current directory
    DIR *dir;

    struct dirent *entry;

    dir = opendir(".");

    if (dir == NULL) {
        perror("Error opening up directory");
        // return 1;
    }

    int fileNotFound = 0; // 0 == file wasn't found, 1 == file was found

    while ((entry = readdir(dir)) != NULL) {

        // check to see if it meets the name criteria, then open if it does
        if (strcmp(entry->d_name, "glucloselogs.txt") == 0)
        {
            // append new data to the file
            printf("File was found\n");
            fileNotFound++;

            FILE* fptr;

            fptr = fopen("glucloselogs.txt", "a");


            // take the linked list data and paste it into the file
                // if file already has data, go to the next avaliable space

            fprintf(fptr, "This is new data after the file was found\n");

            // close the file when done
            fclose(fptr);

        }
    }

    // prompt that the file wasn't found, then make a file
    if (fileNotFound != 1) {

        FILE* fptr;

        fptr = fopen("glucloselogs.txt", "w");

        // create column header for the text file
        char date[10] = "Date";
        char day[10] = "Day";
        char time[10] = "Time";
        char levels[10] = "Levels";
        char focus[10] = "Focus R8";
        char foodTime[10] = "Meal Time";
        char foodType[10] = "Meal Type";

        fprintf(fptr, "%-10s|%-10s|%-10s|%-10s|%-10s|%-10s|%-10s|\n", date, day, time, levels, focus, foodTime, foodType);

        for (int i = 0; i < 77; i++) {
            fprintf(fptr, "-");
        }
        fprintf(fptr, "\n");

        // take the linked list data and paste it into the file
        printList(head, fptr);

        // close the file when done
        fclose(fptr);
    }

    closedir(dir);

    // read data from the text file and output it
    readData(); // comment out if you don't want the program to print in the terminal the contents in the text file

}

void loadData() {
    
    // look for text file in current directory

    // check to see if it meets the name criteria

        // if it meets the name criteria, load the data into a linked list

            // load the data into the linked list from top -> bottom

}

void readData() {

    FILE *fptr;

    fptr = fopen("glucloselogs.txt", "r");

    if (fptr == NULL)
    {
        perror("Error Opening File");
        exit(EXIT_FAILURE);
    }


    // this is the buffer for each line
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fptr) != NULL)
    {

        printf("%s", buffer);

    }

    fclose(fptr);

}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void Header()
{

    printf("-----WELCOME TO GLUCLOSE LOGGER V.2-----\n");
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

        exit(EXIT_FAILURE); // I don't know what this does
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


// gets the head from 
void printList(struct Node* head, FILE* fptr) {

    struct Node* current = head; 

    while (current != NULL) {

        // print current date
        char date[10] = "10/12/23";
        fprintf(fptr, "%-10s|", date);

        // print current day
        char day[10] = "Monday";
        fprintf(fptr, "%-10s|", day);

        // print current time
        char time[10] = "10:10am";
        fprintf(fptr, "%-10s|", time);

        // print gluclose levels
        fprintf(fptr, "%-10d|", current->data.levels);

        // print cognative rating
        fprintf(fptr, "%-10d|", current->data.focusedLevel);

        // print foodTime tag
        enum FoodTime foodTime = current->data.foodTime;
        
        switch (foodTime)
        {
        case 1:
            // char word[15] = "Morning";
            fprintf(fptr, "%-10s|", "Morning");
            break;
        case 2:
            // char word[15] = "Afternoon";
            fprintf(fptr, "%-10s|", "Afternoon");
            break;
        case 3:
            // char word[15] = "Evening";
            fprintf(fptr, "%-10s|", "Evening");
            break;
        case 4:
            // char word[15] = "Midnight";
            fprintf(fptr, "%-10s|", "Midnight");
            break;
        }

            // print foodType tag
            enum FoodType foodType = current->data.foodType;
            switch (foodType)
            {
            case 1:
                // char word[15] = "Breakfast";
                fprintf(fptr, "%-10s|", "Breakfast");
                break;
            case 2:
                // char word[15] = "Lunch";
                fprintf(fptr, "%-10s|", "Lunch");
                break;
            case 3:
                // char word[15] = "Dinner";
                fprintf(fptr, "%-10s|", "Dinner");
                break;
            case 4:
                // char word[15] = "Snack";
                fprintf(fptr, "%-10s|", "Snack");
                break;
            }

        fprintf(fptr, "\n");

        // Go To The Next Node
        current = current->next;
    }

    fprintf(fptr, "\n");
}

// this gets called by menuOptions() function
struct Node* Logger(struct Node* head)
{



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
        printf("Rate 1-10 How Focused You Feel?: ");
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

    return head;

    // printList(head);
}

// gets called in the main.c file
struct Node* MenuOptions(struct Node* head)
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

        if (selection == 1) // if user selects 1, then run logger
        {
            head = Logger(head);
            
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

    return head;

}

// this function is not in use
/*void LogIn()
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

    MenuOptions(head);
} */




