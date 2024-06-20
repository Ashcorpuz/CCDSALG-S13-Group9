#include "../header/main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int applyOperator(char *operator, int operand1, int operand2) {
    if (strcmp(operator, "+") == 0) return operand1 + operand2;
    if (strcmp(operator, "-") == 0) return operand1 - operand2;
    if (strcmp(operator, "*") == 0) return operand1 * operand2;
    if (strcmp(operator, "/") == 0) {
        if (operand2 == 0) {
            printf("Division by zero error!\n");
            exit(EXIT_FAILURE);
        }
        return operand1 / operand2;
    }
    if (strcmp(operator, "%") == 0) return operand1 % operand2;
    if (strcmp(operator, "^") == 0) return (int)pow(operand1, operand2);
    if (strcmp(operator, "<") == 0) return operand1 < operand2;
    if (strcmp(operator, ">") == 0) return operand1 > operand2;
    if (strcmp(operator, "<=") == 0) return operand1 <= operand2;
    if (strcmp(operator, ">=") == 0) return operand1 >= operand2;
    if (strcmp(operator, "==") == 0) return operand1 == operand2;
    if (strcmp(operator, "!=") == 0) return operand1 != operand2;
    if (strcmp(operator, "&&") == 0) return operand1 && operand2;
    if (strcmp(operator, "||") == 0) return operand1 || operand2;
    return 0;
}

bool isOperand(char *op){
    for (int i = 0; op[i] != '\0'; i++) {
        if (!isdigit(op[i])) return false;
    }
    return true;
}

int evaluatePostfix(QueuePtr postfix) {
    StackPtr stack = createStack(MAX);
    int result;
    printf("HELLO\n");

    while (!queueEmpty(postfix)) {
        printf("Hello\n\n");
        char *token = dequeue(postfix);
        if(isOperand(token)){
            push(stack, atoi(token));
            printf("Stack: %d\n", atoi(token));
        }

        /*
        if (strcmp(token, " ") == 0) { // to skip the spacess
            continue;
        }

        if (isdigit(token[0])) { // kapag token is operand, it will push sa stack
            push(stack, token);
        } else {
            // kapag yung token operator, i-ppop two operands from the stack 
            int operand2 = atoi(pop(stack));
            int operand1 = atoi(pop(stack));
            int result = applyOperator(token, operand1, operand2);

            char resultStr[12]; 
            snprintf(resultStr, 12, "%d", result);
            push(stack, resultStr);
        }*/
    }
    /*
    int result = atoi(pop(stack));
    free(stack);
    return result;*/
    return result;
}