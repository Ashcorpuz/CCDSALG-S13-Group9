#include "../include/main.h"

#include <stdlib.h>
#include <string.h>

/*
    Private functions are functions that are only used inside the queue.c file.
    Public functions are functions that can be used outisde the queue.c file.
*/

// Struct representing the stack
struct Stack
{
    unsigned int capacity;
    int top;
    char **data;
};

// PRIVATE:
static void _push(StackPtr stack, char *item)
{
    int nextIndex = stack->top + 1;
    stack->data[nextIndex] = strdup(item);
    stack->top = nextIndex;
}
static char *_pop(StackPtr stack)
{
    int currentIndex = stack->top;
    char *item = strdup(stack->data[currentIndex]);
    stack->top = currentIndex - 1;
    free(stack->data[currentIndex]);
    return item;
}
static char *_top(StackPtr stack)
{
    int index = stack->top;
    char *item = stack->data[index];
    return item;
}
static unsigned int _sizestack(StackPtr stack)
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
