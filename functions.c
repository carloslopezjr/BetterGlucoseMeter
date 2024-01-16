#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include "functions.h"

// -------Menu Option Function------- //
struct Node *MenuOptions(struct Node *head) // gets called in the main.c file
{
    int selection;

    int num = 1;
    while (num != 0)
    {
        printf("|1| Logs |2| Carb Planner |3| Calculate Insulin Dose |4| Food-To-Carbs |5| A1C Goal Planner |6| Exit\n\n");

        if (num == 1)
        {
            printf("Selection: ");
            scanf("%d", &selection);
            printf("\n");
        }
        else
        {
            printf("Select Option Between 1-6: ");
            scanf("%d", &selection);
            printf("\n");
        }

        if (selection == 1) // if user selects 1, then run logger
        {
            int selection;
            int num = 1;

            while (num == 1)
            {
                printf("|1| View Logs |2| Log Current Levels |3| Log Past Levels |4| Remove Last Log \n\n");

                printf("Selection: ");
                scanf("%d", &selection);
                printf("\n");

                if (selection == 1)
                {
                    readData();
                    printf("\n");
                    num = 0;
                }
                else if (selection == 2)
                {
                    // printf("Log Current Levels\n");
                    head = Logger(head);
                    visualizeData(head);
                    backupData(head);
                    num = 0;
                }
                else if (selection == 3) // log past levels
                {

                    int arrayLength = 0;
                    int initialSize = 100;

                    int numFound = 0; // this will be used for the binary search
                    

                    struct ArrayNode *dynamicArray; // initalized here to use in other functions

                    int check = initializeDynamicArray(&dynamicArray, &arrayLength, &initialSize); // starts the dynamic array data structure

                    printf("The check value: %d\n", check);
                    printf("Array length: %d\n\n", arrayLength);

                    if (check == 0) {
                        printf("| --- File not found --- |\n\n");
                        break;
                    }

                    // if (arrayLength == 1)
                    // {
                    // printf("No File Found\n\n");
                    // break;
                    // }

                    int month, day, year, hour, minutes; // this is the important data needed to find where to insert

                    // Enter the date for this log?
                    printf("Please enter the date for this log (MM/DD/YYYY): ");
                    scanf("%d/%d/%d", &month, &day, &year);
                    printf("\n");

                    // What time for this log?
                    // printf("Please enter the time for this log (HH:MM): ");
                    // scanf("%d:%d", &hour, &minutes);
                    // printf("\n");

                    // add a search function here to search through the array of structs to find the right point to place it
                    int answer = binarySearch(month, day, year, 0, arrayLength, &dynamicArray, &numFound);

                    printf("%d\n", numFound);
                    printf("%d\n\n", answer);

                    // if (answer < 0) {
                        // printf("Index wasn't found\n\n");
                    // }
                    // else {
                        // printf("Index was found at: %d\n\n", answer);
                    // }



                    // get other context data about levels, focus r8, etc.

                    free(dynamicArray); // make sure to free the array once it's done

                    num = 0; // return this to exit this option
                }
                else
                {
                    printf("Please select valid option.\n");
                }
            }
        }
        else if (selection == 2)
        {
            // option 2: Carb Planner
            printf("-------------------\n");
            printf("Option 2: (UNDER CONSTRUCTION) \n");
            printf("-------------------\n\n");
        }
        else if (selection == 3)
        {
            // option 3: Calculate Insulin Dose
            // Take the total carbs of the food and tell the user the total insulin needed to meidate it
            printf("-------------------\n");
            printf("Option 3: (UNDER CONSTRUCTION) \n");
            printf("-------------------\n\n");
        }
        else if (selection == 4)
        {
            // option 4: Food-To-Carbs
            printf("-------------------\n");
            printf("Option 4: (UNDER CONSTRUCTION) \n");
            printf("-------------------\n\n");
        }
        else if (selection == 5)
        {
            // option 5: A1C Goal Planner

            int selection;
            int num = 1;

            while (num == 1)
            {
                printf("|1| Set Goal |2| Track Progress |3| Edit Goal |4| Go Back\n\n");

                printf("Selection: ");
                scanf("%d", &selection);
                printf("\n");

                if (selection == 1)
                {
                    double neededAverage = a1cCalculator();
                    printf("This will be the average levels needed to achieve that goal: %2.0lf mg/dL\n\n", neededAverage);
                    num = 0;
                }
                else if (selection == 2)
                {
                    // FUNCTIONALITY:
                    // This process will look back at your data based on the marked date the user started the goal and average out the level numbers.

                    // It will tell you if you're on pace to meet your goal or not

                    // It can also tell you what are the highest levels in relation to the foods that were ate

                    // Overall it will give advice on what to keep doing and what to stop doing
                    printf("Track Progress\n\n");
                    num = 0;
                }
                else if (selection == 3)
                {

                    // FUNCTIONALITY:
                    // This will allow the user to remove their old goal and add a new goal into their profile

                    // The function will average the old goal just so the user knows their progress before they set the new one.

                    printf("Edit Goal\n\n");
                    num = 0;
                }
                else
                {
                    printf("Please select valid option.\n\n");
                }
            }

            // I want it to print out the top items I eat that usual leave my levels around this range

            // I want to set a 3 month timer for the program to know and I can check up on my progress when I ask
            // EXAMPLE: Once I set my goal, the program marks it and then the next time I get on, I can selection the option to see how I'm doing on my goal.

            // the program would start from that date I set the goal and scan all the levels I logged from then, and tell me if I'm underachieving or overachieving
        }
        else if (selection == 6)
        {
            // exit
            printf("-------------------\n");
            printf("See you later! :D\n");
            printf("-------------------\n\n");

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

// --|1.1| Logger Option View Logs Functions--- //
int readData() // prints each line of the gluclose logs to the terminal
{

    FILE *fptr;

    fptr = fopen("glucloselogs.txt", "r");

    if (fptr == NULL)
    {
        printf("| --- No File On Record To View --- |\n");
    }

    // this is the buffer for each line
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fptr) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(fptr);
}


// ---|1.1 & 1.2|Logger Option Functions--- //
struct Node *Logger(struct Node *head) // this gets called by menuOptions() function
{

    time_t now = time(NULL);

    int counter = 0;
    char answer;

    int stopper = 1; // condition

    // this starts the iteration that the user will input their data, so we want the current time from this specific iteration of the program
    while (stopper != 0)
    {

        struct LoggerData inputData;

        // Ask the user if they will be logging current data,old data, or current data and old data

        // If user selects to log old data

        // the only extra step they need to do is type in the month, day and year and the time.

        // we don't ask for specific time, just the hour (ex: 11 am)

        // in the data table, the program will auto fill in the time (ex: 11 am == 11:00AM)

        // STORING TIME DATA HERE
        inputData = currentTime(inputData);

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
        struct Node *newNode = createNode(inputData);

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
                break;     // returns break into the while loop
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

struct LoggerData currentTime(struct LoggerData inputData)
{

    time_t now = time(NULL);

    // STORING TIME DATA HERE
    struct tm *cur_time = localtime(&now); // calculates the local time and holds calculations of a bunch of different times

    // store month integer here
    inputData.month = cur_time->tm_mon;

    // store day integer here
    inputData.day = cur_time->tm_mday; // day of the month

    // store year integer here
    inputData.year = cur_time->tm_year + 1900;
    // inputData.year += 1900;

    // store day name as number
    inputData.dayName = cur_time->tm_wday;

    // store hour in 24hr format
    inputData.hour = cur_time->tm_hour;

    // store minutes
    inputData.minutes = cur_time->tm_min;

    // store seconds
    inputData.seconds = cur_time->tm_sec;

    return inputData;
}

void insertEnd(struct Node **head, struct Node *newNode) // takes a newNode and inserts it to the end of the linked list
{

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {

        struct Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newNode;
        newNode->prev = current;
    }
}

void visualizeData(struct Node *head) // creates text file that will later provide visual of all the logs the user has made
{
    DIR *dir; // look for file text file in the current directory

    struct dirent *entry;

    dir = opendir(".");

    if (dir == NULL)
    {
        perror("Error opening up directory");
    }

    int fileNotFound = 0; // 0 == file wasn't found, 1 == file was found

    while ((entry = readdir(dir)) != NULL)
    {

        if (strcmp(entry->d_name, "glucloselogs.txt") == 0) // check to see if it meets the name criteria, then open if it does
        {
            // append new data to the file
            fileNotFound++;

            FILE *fptr;

            fptr = fopen("glucloselogs.txt", "a");

            // if file already has data, go to the next avaliable space
            printList(head, fptr); // take the linked list data and paste it into the file

            fclose(fptr); // close the file when done
        }
    }

    if (fileNotFound != 1) // prompt that the file wasn't found, then make a file
    {

        FILE *fptr;

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

        for (int i = 0; i < 77; i++)
        {
            fprintf(fptr, "-");
        }
        fprintf(fptr, "\n");

        printList(head, fptr); // take the linked list data and paste it into the file

        fclose(fptr); // close the file when done
    }

    closedir(dir);

    // read data from the text file and output it
    // readData(); // comment out if you don't want the program to print in the terminal the contents in the text file
}

void printList(struct Node *head, FILE *fptr) // called by visualizeData() and uses file ptr to print/format data into file
{

    time_t now = time(NULL);

    struct tm *cur_time = localtime(&now);

    struct Node *current = head;

    while (current != NULL)
    {

        // print current date
        char date[20];
        strftime(date, 20, "%m/%d/%y", cur_time);
        fprintf(fptr, "%-10s|", date);

        // print current day
        char day[20];
        strftime(day, 20, "%A", cur_time);
        fprintf(fptr, "%-10s|", day);

        // print current time
        char time[20];
        strftime(time, 20, "%I:%M%p", cur_time);
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
}

// -------|1.3 & 1.4| Logger Option Remove/Insert Functions------- //

// ---Allocate Memory (Array of Structs) Functions--- //
int initializeDynamicArray(struct ArrayNode **dynamicArray, int *arrayLength, int *initialSize) // allocates data for the data in csv file, and calls loadData()
{
    // allocate memory for the array data structure
    *dynamicArray = (struct ArrayNode *)malloc((*initialSize) * sizeof(struct ArrayNode));

    // If allocation fails condition
    if (*dynamicArray == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        // Handle the error as needed
    }

    int fileCheck = loadData(dynamicArray, arrayLength, initialSize);

    return fileCheck;
}

int loadData(struct ArrayNode **dynamicArray, int *arrayLength, int *size) // this will read data from the csv file and add it into an array data structure
{
    // look for csv file in the current directory
    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");

    if (dir == NULL)
    {
        perror("Error opening up directory");
    }

    int fileCheck = 0; // 0 == file wasn't found, 1 == file was found

    // iterate through the dir while it's not NULL
    while ((entry = readdir(dir)) != NULL)
    {
        // if it meets the name criteria, load the data into an array
        if (strcmp(entry->d_name, "backupData.csv") == 0)
        {
            fileCheck++;

            FILE *fptr;

            // open and read data from the file
            fptr = fopen("backupData.csv", "r");

            // we then store that newNode into a dynamically allocated array
            char buffer[100];
            if (fgets(buffer, sizeof(buffer), fptr) == NULL)
            {
                // this means that there isn't a file in place
                fprintf(stderr, "Couldn't read the first line\n");
                fclose(fptr);
            }

            // set current index for array
            int currentIndex = 0;

            // we iterate through the file and take all the data and plug it into the first index of the dynamicArray variable
            while (fscanf(fptr, "%d, %d, %d, %d, %d, %d, %d, %d, %d, %15[^,], %15[^,\n]", &(*dynamicArray)[currentIndex].month, &(*dynamicArray)[currentIndex].day, &(*dynamicArray)[currentIndex].year, &(*dynamicArray)[currentIndex].dayName, &(*dynamicArray)[currentIndex].hour, &(*dynamicArray)[currentIndex].minutes, &(*dynamicArray)[currentIndex].seconds, &(*dynamicArray)[currentIndex].levels, &(*dynamicArray)[currentIndex].focusedLevel, (*dynamicArray)[currentIndex].foodTime, (*dynamicArray)[currentIndex].foodType) == 11)
            {
                // ^^^ need to change food type and food time into integers and use enum to convert data
                currentIndex++;

                // this checks to see if the current count of the index has exceeded the set initial value for the array
                if (currentIndex >= *size)
                {
                    *size *= 2;

                    // count how many times we've stored into the structure, and reallocate memory if it exceeds initial size
                    *dynamicArray = (struct ArrayNode *)realloc(*dynamicArray, *size * sizeof(struct ArrayNode));

                    // failure condition
                    if (*dynamicArray == NULL)
                    {
                        fprintf(stderr, "Memory reallocation failed\n");
                    }
                }
            }

            // assigns arrayLength with the value of the current index to use outside scope
            *arrayLength = currentIndex;

            fclose(fptr);
        }
    }

    // prompt that the file wasn't found
    // if (fileCheck != 1)
    // {
    // printf("No File Found\n\n");
    //     }
    
    closedir(dir);

    return fileCheck;
}

int binarySearch(int monthKey, int dayKey, int yearKey, int start, int arraySize, struct ArrayNode** dynamicArray, int *numFound)
{

    int numFound = 0;

    // this function will start in the middle of the array
    int mid = start + (arraySize - 1) / 2;

    if (numFound == 0) {
        return mid;
    } 
    else if (numFound == 1) {
        return 
    }

    if (start > arraySize) {
        return mid;
    }

    // it will check the year data member to find the right month of the key
    if ((*dynamicArray)[mid].year == yearKey) {

        numFound += 1;
        // continue to look for the month key
        if ((*dynamicArray)[mid].month == monthKey) {

            numFound += 1;
            // continue to look for the day
            if ((*dynamicArray)[mid].day == dayKey) {
                numFound += 1;
                return mid;
            }
            else if ((*dynamicArray)[mid].day > dayKey)
            {
                return binarySearch(monthKey, dayKey, yearKey, start, mid - 1, dynamicArray, numFound);
            }
            else
            {
                return binarySearch(monthKey, dayKey, yearKey, mid + 1, arraySize, dynamicArray, numFound);
            }
        }
        
        else if ((*dynamicArray)[mid].month > monthKey) {

            return binarySearch(monthKey, dayKey, yearKey, start, mid - 1, dynamicArray, numFound);
        } else {

            return binarySearch(monthKey, dayKey, yearKey, mid + 1, arraySize, dynamicArray, numFound);
        }
    }

    else if ((*dynamicArray)[mid].year > yearKey) {

        return binarySearch(monthKey, dayKey, yearKey, start, mid - 1, dynamicArray, numFound);
    } 

    else {

        return binarySearch(monthKey, dayKey, yearKey, mid + 1, arraySize, dynamicArray, numFound);
    }



    // once it finds the right month, it will look for the right day, but still cutting in half

    // this will keep going until it finds the day before the
}

void insertAt(){
    printf("Not in use");
}

// ---|2| Carb Planner Functions--- //

// ---|3| Calculate Insulin Dose Functions--- //

// ---|4| Food-To-Carbs Functions--- //

// ---|5| A1C Calculator Functions--- //
double a1cCalculator()
{

    double input = 0;
    double calculation;

    printf("What is your desired A1C? ");
    scanf("%lf", &input);
    printf("\n");

    if (input < 4.0 || input > 7.0)
    {

        int count = 0;
        while (count == 0)
        {
            printf("This is a concerning goal. Please select an ideal goal: ");
            scanf("%lf", &input);
            printf("\n");

            if (input < 4.0 || input > 7.0)
            {
                count = 0;
            }
            else
            {
                count = 1;
            }
        }
    }

    // printf("That's a good goal, let's set it up!\n\n");
    // printf("%0.1lf", input);

    calculation = 28.7 * input - 46.7;

    return calculation;
}


// ---Misc Functions--- //
void Header()
{

    printf("-----WELCOME TO GLUCLOSE LOGGER V.2-----\n");
    printf("\n");
}

void RemoveNewLine(char *stringInput) // function not is use
{
    stringInput[strcspn(stringInput, "\n")] = 0;
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// --Backup Data into CSV Functions--//
void backupData(struct Node *head) // backs up data into a csv file
{
    // look for file text file in the current directory
    DIR *dir;

    struct dirent *entry;

    dir = opendir(".");

    if (dir == NULL)
    {
        perror("Error opening up directory");
    }

    int fileNotFound = 0; // 0 == file wasn't found, 1 == file was found

    // search directory for file name (backupData.txt)
    while ((entry = readdir(dir)) != NULL)
    {
        // check to see if it meets the name criteria, then open if it does
        if (strcmp(entry->d_name, "backupData.csv") == 0)
        {
            // append new data to the file
            fileNotFound++;

            // required set up for file appending
            FILE *fptr;
            fptr = fopen("backupData.csv", "a");

            // loop through each nodes data members and print it into file
            // if file already has data, go to the next avaliable space
            printData(head, fptr);

            // close the file when done
            fclose(fptr);
        }
    }

    // if file isn't present, create the file
    if (fileNotFound != 1)
    {

        FILE *fptr;

        fptr = fopen("backupData.csv", "w");

        // create a column header to specify each data section
        char month[15] = "Month";
        char day[15] = "Day";
        char year[15] = "Year";
        char dayName[15] = "Day-Name";
        char hour[15] = "Hour";
        char minutes[15] = "Minutes";
        char seconds[15] = "Seconds";
        char levels[15] = "Levels";
        char focus[15] = "Focus-R8";
        char foodTime[15] = "Meal-Time";
        char foodType[15] = "Meal-Type";

        fprintf(fptr, "%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", month, day, year, dayName, hour, minutes, seconds, levels, focus, foodTime, foodType);

        // take the linked list data and paste it into the file
        printData(head, fptr);

        // close the file when done
        fclose(fptr);
    }

    closedir(dir);
}

void printData(struct Node *head, FILE *fptr) // takes in head ptr & file ptr from backupData() & printsData into csv file
{

    struct Node *current = head;

    while (current != NULL)
    {

        fprintf(fptr, "%d, %d, %d, %d, %d, %d, %d, %d, %d, ", current->data.month, current->data.day, current->data.year, current->data.dayName, current->data.hour, current->data.minutes, current->data.seconds, current->data.levels, current->data.focusedLevel);

        // print foodTime tag
        enum FoodTime foodTime = current->data.foodTime;

        switch (foodTime)
        {
        case 1:
            fprintf(fptr, "%s, ", "Morning");
            break;
        case 2:
            fprintf(fptr, "%s, ", "Afternoon");
            break;
        case 3:
            fprintf(fptr, "%s, ", "Evening");
            break;
        case 4:
            fprintf(fptr, "%s, ", "Midnight");
            break;
        }

        // print foodType tag
        enum FoodType foodType = current->data.foodType;

        switch (foodType)
        {
        case 1:
            fprintf(fptr, "%s", "Breakfast");
            break;
        case 2:
            fprintf(fptr, "%s", "Lunch");
            break;
        case 3:
            fprintf(fptr, "%s", "Dinner");
            break;
        case 4:

            fprintf(fptr, "%s", "Snack");
            break;
        }

        fprintf(fptr, "\n");

        // Go To The Next Node
        current = current->next;
    }
}
