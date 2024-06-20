#ifndef __MAIN_H_INCLUDED
#define __MAIN_H_INCLUDED

#include "queue.h"
#include "stack.h"

#define MAX 256

void infixToPostfix(const char *infix, QueuePtr result);
int evaluatePostfix(char *postfix, char *error);
char *duplicate(const char *str);

#endif // __MAIN_H_INCLUDED