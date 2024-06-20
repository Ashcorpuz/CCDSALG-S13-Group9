#include "../header/main.h"

#include <stdlib.h>
#include <string.h>

/*
    Private functions are functions that are only used inside the queue.c file.
    Public functions are functions that can be used outisde the queue.c file.
*/

// Struct representing the stack


// PRIVATE:
void _push(StackPtr stack, char *item)
{
    int nextIndex = stack->top + 1;
    stack->data[nextIndex] = duplicate(item);
    stack->top = nextIndex;
}
char *_pop(StackPtr stack)
{
    int currentIndex = stack->top;
    char *item = duplicate(stack->data[currentIndex]);
    stack->top = currentIndex - 1;
    free(stack->data[currentIndex]);
    return item;
}
char *_top(StackPtr stack)
{
    int index = stack->top;
    char *item = stack->data[index];
    return item;
}
unsigned int _sizestack(StackPtr stack)
{
    return stack->top + 1;
}

// PUBLIC:
StackPtr createStack(unsigned int capacity)
{
    StackPtr stack = malloc(sizeof *stack);
    if (stack == NULL)
        return NULL;
    stack->data = malloc(sizeof(char *) * capacity); // Allocate memory for the data array
    if (stack->data == NULL)
    {
        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->top = -1;
    return stack;
}
void push(StackPtr self, char *item)
{
    if (isFullStack(self))
        return;

    _push(self, item);
}
char *pop(StackPtr self)
{
    if (isEmptyStack(self))
        return NULL;

    return _pop(self);
}
char *top(StackPtr self)
{
    if (isEmptyStack(self))
        return NULL;

    return _top(self);
}
bool isFullStack(StackPtr self)
{
    return _sizestack(self) == self->capacity;
}
bool isEmptyStack(StackPtr self)
{
    return _sizestack(self) == 0;
}
unsigned int sizeStack(StackPtr self)
{
    return _sizestack(self);
}

/*#include "../header/main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

StackPtr createStack(unsigned int size){
    StackPtr S = malloc(sizeof *S);
    S-> top = -1;
    S->capacity = size;
    return S;
}

void _push(StackPtr S, char *x){
    S->top+=1;
    S->items[S->top] = x;
}

void push(StackPtr S, char *x){
    if(stackFull(S)){
        fprintf(stderr, "Stack overflow\n");
    }
    _push(S,x);
};

char *_pop(StackPtr S){
    int currentInd = S->top;
    char *op = S->items[currentInd];
    S->top-=1;
    S->items[currentInd] = "\0";
    return op;
}

char *pop(StackPtr S){
    if(stackEmpty(S))
        return NULL;
    return _pop(S);
};

char *_top(StackPtr S){
    char *op = S->items[S->top];
    printf("check top: %s\n", op);
    return op;
}

char *top(StackPtr S){
    if(stackEmpty(S))
        return NULL;

    return _top(S);
};

bool stackEmpty(StackPtr S){
    return S->top == -1;
};

bool stackFull(StackPtr S){
    return S->top == MAX-1;
};

void appendStack(char *expression, int x){
    sprintf(expression, "%s%d", expression, x);
}*/