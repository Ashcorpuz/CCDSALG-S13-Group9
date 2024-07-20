#include "../header/main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void toExpression(QueuePtr Q, char *postfix){
    QueuePtr queue = Q;
    while (!queueEmpty(queue))
    {
        strcat(postfix, dequeue(queue));
    }
    printf("Postfix:\n");
    printf("\033[34m%s\033[0m\n\n", postfix);
}

void infixToPostfix(char *infix, QueuePtr postfixResult, QueuePtr evaluateQueue){
    bool isParenthesisOpen = false;
    StackPtr stack = createStack(MAX);
    StackPtr tempStack = createStack(MAX);

    for(int i=0; infix[i]; i++){
        if(isspace(infix[i]))
            continue;
        else if(isdigit(infix[i])){
            char operand[10]; //Assumes that maximum no of digits is 10
            int j = 0;
            while(isdigit(infix[i])){
                operand[j++] = infix[i++];
            }
            operand[j] = '\0'; //Resets content of operand
            enqueue(postfixResult, operand);    
            enqueue(postfixResult, " "); //add space
            enqueue(evaluateQueue, operand);    
            enqueue(evaluateQueue, " ");
            i--;
        }
        else if(infix[i] == '('){
            isParenthesisOpen = true;
            push(stack,"(");
            push(tempStack,"(");
            //printf("Top: %s\n", top(stack));
        }
        
        else if(infix[i] == ')'){
            isParenthesisOpen = false;
            while (!isEmptyStack(stack) && strcmp(top(stack), "(") !=0)
            {
                enqueue(postfixResult, pop(stack));
                enqueue(postfixResult, " ");
            }
            pop(stack);
            while (!isEmptyStack(tempStack) && strcmp(top(tempStack), "(") !=0)
            {
                enqueue(evaluateQueue, pop(tempStack));
                enqueue(evaluateQueue, " ");
            }
            pop(tempStack);
            //printf("Top: %s\n", top(stack));
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
                enqueue(postfixResult, pop(stack));
                enqueue(postfixResult, " ");
            }
            push(stack, operator);

            while (!isEmptyStack(tempStack) && precedence(operator) <= precedence(top(tempStack)))
            {
                enqueue(evaluateQueue, pop(tempStack));
                enqueue(evaluateQueue, " ");
            }
            push(tempStack, operator);
            //printf("Top: %s\n", top(stack));
        }
    }
    while(!isEmptyStack(stack)){
        enqueue(postfixResult, pop(stack));
    }
    while(!isEmptyStack(tempStack)){
        enqueue(evaluateQueue, pop(tempStack));
    }
}