#ifndef __STACK_H
#define __STACK_H 3
#include "../includes/node.h"

typedef struct Stack *StackPtr;

StackPtr createStack(int capacity);
void push(StackPtr stack, char *item);
char *pop(StackPtr stack);
int isEmpty(StackPtr stack);
void destroyStack(StackPtr stack);
#endif //__STACK_H