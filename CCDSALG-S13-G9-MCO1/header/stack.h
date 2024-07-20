#ifndef __STACK_H_INCLUDED
#define __STACK_H_INCLUDED

#include <stdbool.h>
#define STRING_SIZE 8

typedef struct Stack *StackPtr;

typedef struct Stack {
    unsigned int capacity;
    int top;
    char **data;
} Stack;

StackPtr createStack(unsigned int capacity);

void showStack(StackPtr S);
//void adjustIndex(StackPtr stack);

void push(StackPtr stack, char *item);
char *pop(StackPtr stack);
char *top(StackPtr stack);

bool isFullStack(StackPtr stack);
bool isEmptyStack(StackPtr stack);
unsigned int sizeStack(StackPtr stack);

#endif // __STACK_H_INCLUDED