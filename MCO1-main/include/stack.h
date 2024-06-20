/**
 * stack.h
 * Author: Ashley Corpuz
 *
 *  Using 'ADT' design pattern
 * 		referenced from: https://leanpub.com/patternsinc
 *
 *  Stack Library Header
 */

#ifndef __STACK_H_INCLUDED
#define __STACK_H_INCLUDED

#include <stdbool.h>
#define STRING_SIZE 8

typedef struct Stack {
    char **data;
    int top;
    int maxSize;
} Stack, *StackPtr;

StackPtr createStack(unsigned int capacity);

void push(StackPtr stack, char *item);
char *pop(StackPtr stack);
char *top(StackPtr stack);

bool isFullStack(StackPtr stack);
bool isEmptyStack(StackPtr stack);
unsigned int sizeStack(StackPtr stack);

#endif // __STACK_H_INCLUDED
