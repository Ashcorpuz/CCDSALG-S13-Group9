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
            //Evaluate Postfix
            /*NOTE
                please fix yung evaluatePostfix na lang, see notes there
            */
            evaluation = evaluatePostfix(evaluateQueue);
            printf("Evaluate:\n");
            printf("\033[32m%d\033[0m\n", evaluation);
        }
    }
    printf("END\n");
    return 0;
}