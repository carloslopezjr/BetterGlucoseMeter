#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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


// STRUCTS //

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

void RemoveNewLine(char *stringInput);

void visualizeData(struct Node *head);

void backupData(struct Node *head);

void printData(struct Node *head, FILE *fptr);

void loadData(struct ArrayNode **dynamicArray, int* arrayLength, int *size);

void allocatedArray(struct ArrayNode *dynamicArray, int size);

void readData();

void clearInputBuffer();

void Header();

struct Node *createNode(struct LoggerData newData);

void insertEnd(struct Node **head, struct Node *newNode);

void printList(struct Node *head, FILE *fptr);

struct Node *Logger(struct Node *head);

struct Node *MenuOptions(struct Node *head);

struct LoggerData currentTime(struct LoggerData inputData);

// void LogIn();

void insert(struct Node *newNode, struct Node *head);

void deleteLog();

// OPTION 5 FUNCTIONS //

double a1cCalculator();

void binarySearch(int monthKey, int dayKey, int yearKey, int arraySize);

#endif