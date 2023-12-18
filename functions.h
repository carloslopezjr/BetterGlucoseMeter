#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void RemoveNewLine(char *stringInput);

void Header();

void Logger();

void MenuOptions();

void LogIn();

enum FoodType {

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

struct LoggerData
{

    int foodType;
    int foodTime;
    int focusedLevel;
    int levels;
};

struct Node
{
    struct LoggerData data;

    struct Node *next;
    struct Node *prev;

};

struct Node* createNode(struct LoggerData newData);

void insertEnd(struct Node **head, struct LoggerData newData);

// we need a data structure to store all the level logs

// create a struct that holds a couple of data members

// store that specific struct into a node for a linked list

#endif