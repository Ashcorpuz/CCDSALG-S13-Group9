#include "../include/main.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define ANSI_COLOR_RESET "\x1b[0m"

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    QueuePtr postfix = createQueue(MAX);
    char infix[MAX];
    /*
    Sample
    Infix: 8*(5^4+2)-6^2/(9*3);
    Evaluation: 5014.67 (rounded off)
    Postfix: 8 5 4 ^ 2 + * 6 2 ^ 9 3 * / -
     */

    while (strcmp(infix, "QUIT") != 0)
    {
        printf(ANSI_COLOR_RESET);
        printf("Expression Evaluation\n");
        printf("Enter Infix Expression: ");
        scanf("%s", infix);

        if(strcmp(infix, "QUIT")==0){
            printf("Exiting the program...");
            return 0;
        }
        else{
            printf("\nEvaluation: ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            /* Insert Code for Evaluation*/

            printf(ANSI_COLOR_RESET); // resets text color
            printf("\nPostfix: ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            infixToPostfix(infix,postfix);
            while (!isEmptyQueue(postfix))
            {
                printf("%s", dequeue(postfix));
            }
            printf("\n\n");
            free(postfix);
        }
    }
    return 0;
}