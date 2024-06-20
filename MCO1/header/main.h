#ifndef __MAIN_H_INCLUDED
#define __MAIN_H_INCLUDED

#include "queue.h"
#include "stack.h"
#define MAX 256

void infixToPostfix(char *infix, QueuePtr postfixResult, QueuePtr evaluateQueue);
void toExpression(QueuePtr Q, char *postfix);
bool isOperator (char op);
bool isMultiCharOperator(char op1, char op2);
char *duplicate(const char *str);
int evaluatePostfix(QueuePtr postfix);
#endif //__MAIN_H_INCLUDED