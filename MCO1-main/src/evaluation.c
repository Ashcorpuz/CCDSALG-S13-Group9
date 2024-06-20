#include "../include/main.h"
#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int evaluatePostfix(char *postfix, char *error) {
    StackPtr s = createStack(MAX);
    if (s == NULL) {
        strcpy(error, "Memory allocation failed");
        return 0;
    }

    char *token = strtok(postfix, " ");
    int val1, val2;

    while (token != NULL) {
        if (isdigit(token[0])) {
            push(s, token);
        } else if (strcmp(token, "!") == 0) {
            if (isEmptyStack(s)) {
                strcpy(error, "Invalid expression");
                return 0;
            }
            val1 = atoi(pop(s));
            char result[STRING_SIZE];
            snprintf(result, STRING_SIZE, "%d", !val1);
            push(s, result);
        } else {
            if (isEmptyStack(s)) {
                strcpy(error, "Invalid expression");
                return 0;
            }
            val2 = atoi(pop(s));
            if (isEmptyStack(s)) {
                strcpy(error, "Invalid expression");
                return 0;
            }
            val1 = atoi(pop(s));
            char result[STRING_SIZE];
            if (strcmp(token, "+") == 0) {
                snprintf(result, STRING_SIZE, "%d", val1 + val2);
            } else if (strcmp(token, "-") == 0) {
                snprintf(result, STRING_SIZE, "%d", val1 - val2);
            } else if (strcmp(token, "*") == 0) {
                snprintf(result, STRING_SIZE, "%d", val1 * val2);
            } else if (strcmp(token, "/") == 0) {
                if (val2 == 0) {
                    strcpy(error, "Division by zero error!");
                    return 0;
                }
                snprintf(result, STRING_SIZE, "%d", val1 / val2);
            } else if (strcmp(token, "%") == 0) {
                if (val2 == 0) {
                    strcpy(error, "Division by zero error!");
                    return 0;
                }
                snprintf(result, STRING_SIZE, "%d", val1 % val2);
            } else if (strcmp(token, "^") == 0) {
                int power = 1;
                for (int i = 0; i < val2; i++) {
                    power *= val1;
                }
                snprintf(result, STRING_SIZE, "%d", power);
            } else if (strcmp(token, ">") == 0) {
                snprintf(result, STRING_SIZE, "%d", val1 > val2);
            } else if (strcmp(token, "<") == 0) {
                snprintf(result, STRING_SIZE, "%d", val1 < val2);
            } else if (strcmp(token, ">=") == 0) {
                snprintf(result, STRING_SIZE, "%d", val1 >= val2);
            } else if (strcmp(token, "<=") == 0) {
                snprintf(result, STRING_SIZE, "%d", val1 <= val2);
            } else if (strcmp(token, "==") == 0) {
                snprintf(result, STRING_SIZE, "%d", val1 == val2);
            } else if (strcmp(token, "!=") == 0) {
                snprintf(result, STRING_SIZE, "%d", val1 != val2);
            } else if (strcmp(token, "&&") == 0) {
                snprintf(result, STRING_SIZE, "%d", val1 && val2);
            } else if (strcmp(token, "||") == 0) {
                snprintf(result, STRING_SIZE, "%d", val1 || val2);
            } else {
                strcpy(error, "Invalid operator");
                return 0;
            }
            push(s, result);
        }
        token = strtok(NULL, " ");
    }

    if (sizeStack(s) != 1) {
        strcpy(error, "Invalid expression");
        return 0;
    }

    int result = atoi(pop(s));
    free(s->data);
    free(s);
    return result;
}
