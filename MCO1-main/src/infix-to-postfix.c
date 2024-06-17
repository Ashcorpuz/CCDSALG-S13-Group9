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
        return 7; // Highest priority
    else if(strcmp(op, "!") ==0)
        return 6; // higher priority
    else if (strcmp(op, "/") == 0 || strcmp(op, "*") == 0 || strcmp(op, "%") == 0)
        return 5; // high priority
    else if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0)
        return 4; // mid priority
    else if(strcmp(op, "<") == 0 || strcmp(op, ">") == 0 || strcmp(op, "<=") == 0 || strcmp(op, ">=") == 0)
        return 3; // low priority
    else if(strcmp(op, "==") == 0 || strcmp(op, "!=") ==0)
        return 2; // lower priority   
    else if(strcmp(op, "||") == 0 || strcmp(op, "&&") == 0)
        return 1; // lowest priority
    else
        return -1;
}

bool isOperator (char op){
    return 
        op == '<' || op == '>' ||
        op == '+' || op == '-' || 
        op == '*' || op == '/' || op == '%' || 
        op == '!' || 
        op == '^';
}

bool isMultiCharOperator(char op1, char op2) {
    return (op1 == '|' && op2 == '|') ||
           (op1 == '&' && op2 == '&') ||
           (op1 == '=' && op2 == '=') ||
           (op1 == '>' && op2 == '=') ||
           (op1 == '<' && op2 == '=');
}

void infixToPostfix(const char *infix, QueuePtr result){
    StackPtr stack = createStack(MAX);
    bool isParenthesisOpen = false;

    for(int i=0; infix[i]; i++){
        if(isdigit(infix[i])){
            char operand[10]; //Assumes that maximum no of digits is 10
            int j = 0;
            while(isdigit(infix[i])){
                operand[j++] = infix[i++];
            }
            operand[j] = '\0'; //Resets content of operand
            enqueue(result, operand);    
            enqueue(result, " "); //add space
            i--;
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
                enqueue(result, " ");
            }
            pop(stack);
        }
        else if(isOperator(infix[i]) || isMultiCharOperator(infix[i], infix[i+1])){
            char operator[2];
            bool isMultiCharOp = false;

            //Handles Multiple Characters Operators
            if((infix[i] == '|' &&  infix[i+1] == '|') || (infix[i] == '&' &&  infix[i+1] == '&') ||
                (infix[i] == '=' &&  infix[i+1] == '=') || (infix[i] == '>' &&  infix[i+1] == '=') || (infix[i] == '<' &&  infix[i+1] == '=')){
                operator[0] = infix[i];
                operator[1] = infix[i+1];
                operator[2] = '\0';
                isMultiCharOp = true;
                i++;
            }
            else {
                operator[0] = infix[i];
                operator[1] = '\0';
                operator[2] = '\0';
                
            }
            
            while (!isEmptyStack(stack) && precedence(operator) <= precedence(top(stack)))
            {
                enqueue(result, pop(stack));
                enqueue(result, " ");
            }
            push(stack, operator);
        }
    }
    while(!isEmptyStack(stack)){
        enqueue(result, pop(stack));
    }
}