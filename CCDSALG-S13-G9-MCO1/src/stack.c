#include "../header/main.h"

#include <stdlib.h>
#include <string.h>

/*void adjustIndex(StackPtr S){
    int currentInd = S->top;
    int newInd = S->top+1;
    S->top = newInd;
};*/

void showStack(StackPtr S){
    printf("Stack: ");
    while(!isEmptyStack(S)){
        printf("%s, ", pop(S->data));
    }
    printf("\n");
}

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