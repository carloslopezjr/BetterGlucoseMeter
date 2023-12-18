#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void RemoveNewLine(char *stringInput);

void Header();

// int decision(int counter);

void Logger();

void MenuOptions();

void LogIn();

struct LoggerData
{

    int levels;
    // type of day
    // feeling

};

struct Node
{
    struct LoggerData data;

    struct node *next;
    struct node *prev;

};



struct Node* createNode(struct LoggerData newData);
void insertEnd(struct Node **head, struct LoggerData newData);

// we need a data structure to store all the level logs

// create a struct that holds a couple of data members

// store that specific struct into a node for a linked list

#endif