#include "../include/main.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define ANSI_COLOR_RESET "\x1b[0m"

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    QueuePtr postfix = createQueue(MAX);
    QueuePtr converted = createQueue(MAX);
    char infix[MAX];
    char error[50] = "";
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
            infixToPostfix(infix,postfix);
            converted = postfix;
            printf("\nEvaluation: ");
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            /* Insert Code for Evaluation*/
            printf("\nEvaluation: ");
            int result = evaluatePostfix(postfix, error);
            if (strlen(error) > 0) {
                printf("%s", error);
            } else {
                printf("%d", result);
            }
            printf(ANSI_COLOR_RESET); // resets text color
            printf("\nPostfix: ");
            
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            while (!isEmptyQueue(converted))
            {
                printf("%s", dequeue(converted));
            }
            printf("\n\n");
            free(postfix);
        }
    }
    return 0;
}