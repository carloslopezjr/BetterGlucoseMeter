#include <stdio.h>
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

/*
int decision(int counter)
{

    char answer;

    printf("Log more levels? (Y/N): ");


    int flag2 = 1;

    while (flag2 != 0){

        scanf("%s", &answer);
        printf("\n");

        if (answer == 'Y')
        {
            counter++;
            continue;
        }
        else if (answer == 'N')
        {
            flag2 = 0;

        }
        else
        {
            printf("Invalid Option: Try again\n");
            printf("\n");
        }
    }

    return counter;
}

*/

void Logger()
{

    int time;
    int tag;
    int level;
    int counter = 0;

    char answer;

    int stopper = 1; // condition
    while (stopper != 0)
    {

        // first options
        printf("|1| Breakfast\n|2| Lunch\n|3| Dinner\n|4| Early Snack\n|5| Late Snack\n");
        printf("\n");
        printf("Specify a time: ");
        scanf("%d", &time);
        printf("\n");

        // second options (under construction)

        /*
        printf("|1| Morning\n|2| Afternoon\n|3| Evening\n|4| Night\n");
        printf("\n");
        printf("What did you eat: ");
        scanf("%d", &tag);
        printf("\n");
        */

        // enter level(s)
        printf("Enter your level: ");
        scanf("%d", &level);
        printf("\n");

        int stopper2; // condition2
        while (stopper2 == 0)
        {

            // promps user if they want to add more levels
            printf("Log more levels? (Y/N): ");
            scanf("%s", &answer);
            printf("\n");

            // checks answer from user input
            if (answer == 'Y')
            {
                counter++; // increments the counter for prompt purposes
                break;     // returns break into the while loop
            }
            else if (answer == 'N')
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