#ifndef FUNCTIONS_H
#define FUNCTIONS_H


// ---ENUMS--- //
enum FoodType
{

    BREAKFAST = 1,
    LUNCH = 2,
    DINNER = 3,
    SNACK = 4

};

enum FoodTime
{

    MORNING = 1,
    AFTERNOON = 2,
    EVENING = 3,
    MIDNIGHT = 4

};

// ---STRUCTS--- //

struct LoggerData // we want this data to be stored in the node for easier sorting in the future
{

    // date formatted
    int month; // month number
    int day;   // day number
    int year;  // year number

    int dayName; // value will represent the number day of the week (Monday, Tuesday, etc.)

    // time formatted
    int hour; // hour formatted
    int minutes; // minutes number
    int seconds; // seconds number

    // context data
    int levels; // blood sugar levels
    int focusedLevel; // user's focus-level in relation to blood sugar
    int foodTime; // time the food was ate
    int foodType; // type of food ate
    
};

struct Node
{
    struct LoggerData data;
    struct Node *next;
    struct Node *prev;
};

struct ArrayNode { // nodes that will be added to an array called "Array of Structs"

    // date formatted
    int month; // month number
    int day;   // day number
    int year;  // year number

    int dayName; // value will represent the number day of the week (Monday, Tuesday, etc.)

    // time formatted
    int hour;    // hour formatted
    int minutes; // minutes number
    int seconds; // seconds number

    // context data
    int levels;       // blood sugar levels
    int focusedLevel; // user's focus-level in relation to blood sugar

    // char array since csv file holds this info as a string and this node will be getting it's data from the csv file
    char foodTime[20]; // time the food was ate
    char foodType[20]; // type of food ate
};

// -------Menu Option Function------- //
struct Node *MenuOptions(struct Node *head);

// --|1.1| Logger Option View Logs Functions--- //
void readData();

// ---|1.1 & 1.2|Logger Option Functions--- //
struct Node *Logger(struct Node *head);
struct Node *createNode(struct LoggerData newData);
struct LoggerData currentTime(struct LoggerData inputData);
void insertEnd(struct Node **head, struct Node *newNode);
void visualizeData(struct Node *head);
void printList(struct Node *head, FILE *fptr);

// -------|1.3 & 1.4| Logger Option Remove/Insert Functions------- //
int initializeDynamicArray(struct ArrayNode **dynamicArray, int *arrayLength, int *initialSize);
int loadData(struct ArrayNode **dynamicArray, int *arrayLength, int *size);
int binarySearch(struct ArrayNode userInput, int low, int high, struct ArrayNode** dynamicArray, int *numFound);
void insertAt();
void removeLog();

// ---|2| Carb Planner Functions--- //

// ---|3| Calculate Insulin Dose Functions--- //
double foodToDosage(int carbs);

// ---|4| Food-To-Carbs Functions--- //

// ---|5| A1C Calculator Functions--- //
double a1cCalculator();

// ---Misc Functions--- //
void RemoveNewLine(char *stringInput);
void clearInputBuffer();
void Header();

// --Backup Data into CSV Functions--//
void backupData(struct Node *head);
void printData(struct Node *head, FILE *fptr);

#endif