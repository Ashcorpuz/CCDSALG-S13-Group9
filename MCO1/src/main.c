#include "../header/main.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    char infixExpression[MAX] = "\0";
    char postfixExpression[MAX] = "\0";
    QueuePtr postfixQueue = createQueue(MAX);
    QueuePtr evaluateQueue = createQueue(MAX);
    int evaluation;

    /*
    Sample
    Infix: 8*(5^4+2)-6^2/(9*3);
    Evaluation: 5014.67 (rounded off)
    Postfix: 8 5 4 ^ 2 + * 6 2 ^ 9 3 * / -
     */
    while (strcmp(infixExpression, "QUIT") != 0){
        strcpy(postfixExpression, "");
        strcpy(infixExpression, "");
        printf("Expression Evaluation\n");
        printf("Enter Infix Expression: ");
        scanf("%s", infixExpression);

        if(strcmp(infixExpression, "QUIT")==0){
            printf("Exiting the program...");
            return 0;
        }
        else{
            //Convert Infix to postfix
            infixToPostfix(infixExpression, postfixQueue, evaluateQueue);
            toExpression(postfixQueue, postfixExpression);
            // check if napapass yung values [will delete]
            printf("check evaluation queue: %d\n", queueEmpty(evaluateQueue));
            //Evaluate Postfix
            //evaluation = evaluatePostfix(postfix);
        }
    }
    printf("END\n");
    return 0;
}