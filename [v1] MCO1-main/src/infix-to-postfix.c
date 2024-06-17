#include "../include/main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *_intToString(const int num)
{
    int len = snprintf(NULL, 0, "%d", num);
    char *str = malloc((len + 1) * sizeof(char));
    if (str == NULL)
        return NULL;
    snprintf(str, len + 1, "%d", num);
    return str;
}
int precedence(char *op)
{
    if (strcmp(op, "^") == 0)
        return 3; // High priority.
    else if (strcmp(op, "/") == 0 || strcmp(op, "*") == 0)
        return 2; // Mid priority.
    else if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0)
        return 1; // Low priority.
    else
        return -1;
}

int infixToPostfix(const char *infix, QueuePtr result)
{
    StackPtr ops = createStack(MAX);
    int index = 0;
    char current;
    bool isParenthesisOpen = false;

    while (infix[index] != '\0')
    {
        current = infix[index++];

        if (isspace(current))
            continue;

        if (isdigit(current))
        {
            int num = current - '0';
            while (infix[index] && isdigit(infix[index]))
            {
                num = num * 10 + (infix[index++] - '0');
            }
            enqueue(result, _intToString(num));
        }
        else if (current == '(')
        {
            isParenthesisOpen = true;
            push(ops, "(");
        }
        else if (current == ')')
        {
            isParenthesisOpen = false;
            while (!isEmptyStack(ops) && strcmp(top(ops), "("))
            {
                enqueue(result, pop(ops));
            }
            pop(ops);
        }
        else
        {
            char op[3] = {current, '\0'};
            if (infix[index] && isdigit(infix[index]) && !isspace(infix[index]) && infix[index] != '(')
                op[1] = infix[index];
            op[2] = '\0';
            while (!isEmptyStack(ops) && precedence(top(ops)) >= precedence(op))
            {
                if (isParenthesisOpen)
                    break;
                enqueue(result, pop(ops));
            }
            push(ops, op);
        }
    }

    while (!isEmptyStack(ops))
    {
        enqueue(result, pop(ops));
    }
    free(ops);
    return 0;
}
