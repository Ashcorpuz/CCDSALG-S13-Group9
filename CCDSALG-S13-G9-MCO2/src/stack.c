#include "../includes/stack.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Stack
{
    char **items;
    int top;
    int capacity;
};

StackPtr createStack(int capacity)
{
    StackPtr stack = (StackPtr)malloc(sizeof(struct Stack));
    if (stack == NULL)
    {
        printf("Memory Allocation Erorr: failed to alocate memory in createStack function.");
        return NULL;
    }

    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (char **)malloc(stack->capacity * sizeof(char *));
    if (stack->items == NULL)
    {
        printf("Memory Allocation Error: Failed to allocate memory for stack items.\n");
        free(stack);
        return NULL;
    }
    for (int i = 0; i < capacity; i++)
    {
        stack->items[i] = NULL;
    }
    return stack;
}

void push(StackPtr stack, char *item)
{
    if (stack->top == stack->capacity - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = item;
}

char *pop(StackPtr stack)
{
    if (stack->top == -1)
    {
        printf("Stack Underflow");
        return "\0";
    }
    return stack->items[stack->top--];
}

int isEmpty(StackPtr stack)
{
    return stack->top == -1;
}

void destroyStack(StackPtr stack)
{
    free(stack->items);
    free(stack);
}