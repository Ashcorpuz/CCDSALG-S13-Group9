#ifndef __MAIN_H_INCLUDED
#define __MAIN_H_INCLUDED

#include "queue.h"
#include "stack.h"

#define MAX 256

int infixToPostfix(const char *infix, QueuePtr result);
char *duplicate(const char *str);

#endif //__MAIN_H_INCLUDED