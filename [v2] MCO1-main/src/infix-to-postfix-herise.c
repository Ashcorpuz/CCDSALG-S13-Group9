#include "../include/main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *_intToString(const int num)
{
    int len = snprintf(NULL, 0, "%d", num);
    char *str = malloc((len + 1) * sizeof(char));
    if (str == NULL)
        return NULL;
    snprintf(str, len + 1, "%d", num);
    return str;
}
int precedence(char *op)
{
    if (strcmp(op, "^") == 0)
        return 3; // High priority.
    else if (strcmp(op, "/") == 0 || strcmp(op, "*") == 0)
        return 2; // Mid priority.
    else if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0)
        return 1; // Low priority.
    else
        return -1;
}
bool isOperator (char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void infixToPostfix(const char *infix, QueuePtr result){
    StackPtr stack = createStack(MAX);
    bool isParenthesisOpen = false;

    for(int i=0; infix[i]; i++){
        if(isdigit(infix[i])){
            char operand[] = {infix[i], '\0'};
            enqueue(result, operand);    
        }
        else if(infix[i] == '('){
            isParenthesisOpen = true;
            push(stack,"(");
        }
        else if(infix[i] == ')'){
            isParenthesisOpen = false;
            while (!isEmptyStack(stack) && strcmp(top(stack), "(") !=0)
            {
                enqueue(result, pop(stack));
            }
            pop(stack);
        }
        else if(isOperator(infix[i])){
            char operator[2] = {infix[i], '\0'};
            
            while (!isEmptyStack(stack) && precedence(operator) <= precedence(top(stack)))
            {
                enqueue(result, pop(stack));
            }
            push(stack, operator);
        }
    }
    while(!isEmptyStack(stack)){
        enqueue(result, pop(stack));
    }
}