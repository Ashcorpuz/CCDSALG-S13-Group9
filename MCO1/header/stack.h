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

typedef struct Stack *StackPtr;

typedef struct Stack {
    unsigned int capacity;
    int top;
    char **data;
} Stack;

StackPtr createStack(unsigned int capacity);

void push(StackPtr stack, char *item);
char *pop(StackPtr stack);
char *top(StackPtr stack);

bool isFullStack(StackPtr stack);
bool isEmptyStack(StackPtr stack);
unsigned int sizeStack(StackPtr stack);

#endif // __STACK_H_INCLUDED

/*#ifndef __STACK_H
#define __STACK_H
#include <stdbool.h>

#define MAX 256
typedef struct Stack{
    int capacity;
    char **items;
    int top;
} Stack;

typedef struct Stack *StackPtr;

StackPtr createStack(unsigned int capacity);
void push(StackPtr S, char *x);
char *pop(StackPtr S);
char *top(StackPtr S);
bool stackEmpty(StackPtr S);
bool stackFull(StackPtr S);

#endif // __QUEUE_H
*/