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

struct LoggerData
{

    // we want this data to be stored in the node for easier sorting in the future

    // date formatted
    // month number
    // day number
    // year number

    int month;
    int day;
    int year;

    // day
    // name
    int dayName;

    // hour formatted
    // hour number
    // minutes number

    int hour;
    int minutes;
    int seconds;

    int levels;
    int focusedLevel;
    int foodType;
    int foodTime;
};

struct Node
{
    struct LoggerData data;

    struct Node *next;
    struct Node *prev;
};

struct ArrayNode {

    int month;
    int day;
    int year; 
    int dayName;
    int hour;
    int minutes;
    int seconds;
    int levels;
    int focusedLevel;

    char foodTime[20];
    char foodType[20];

};

// -------Menu Option Function------- //
struct Node *MenuOptions(struct Node *head);

// --|1.1| Logger Option View Logs Functions--- //
int readData();

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
int binarySearch(int monthKey, int dayKey, int yearKey, int start, int arraySize, struct ArrayNode** dynamicArray, int *numFound);
void insertAt();
void backupData(struct Node *head);
void printData(struct Node *head, FILE *fptr);

// ---|2| Carb Planner Functions--- //

// ---|3| Calculate Insulin Dose Functions--- //

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