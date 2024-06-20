#include "../header/main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int applyOperator(char *operator, int operand1, int operand2) {
    if (strcmp(operator, "+") == 0) return operand1 + operand2;
    else if (strcmp(operator, "-") == 0) return operand1 - operand2;
    else if (strcmp(operator, "*") == 0) return operand1 * operand2;
    else if (strcmp(operator, "/") == 0) {
        if (operand2 == 0) {
            printf("Division by zero error!\n");
            exit(EXIT_FAILURE);
        }
        return operand1 / operand2;
    }
    else if (strcmp(operator, "%") == 0) return operand1 % operand2;
    else if (strcmp(operator, "^") == 0) return (int)pow(operand1, operand2);
    else if (strcmp(operator, "<") == 0) return operand1 < operand2;
    else if (strcmp(operator, ">") == 0) return operand1 > operand2;
    else if (strcmp(operator, "<=") == 0) return operand1 <= operand2;
    else if (strcmp(operator, ">=") == 0) return operand1 >= operand2;
    else if (strcmp(operator, "==") == 0) return operand1 == operand2;
    else if (strcmp(operator, "!=") == 0) return operand1 != operand2;
    else if (strcmp(operator, "&&") == 0) return operand1 && operand2;
    else if (strcmp(operator, "||") == 0) return operand1 || operand2;
    else
    return NULL;
}

int evaluatePostfix(QueuePtr postfix) {
    StackPtr stack = createStack(MAX);
    QueuePtr operands = createQueue(MAX);
    int result;
    char answer[20];

    while (!queueEmpty(postfix)) {
        char *token = dequeue(postfix);
        //printf("Token: %s\n", token);
        if(isspace(*token))
            continue;
        else if(isdigit(*token)){
            enqueue(operands, token);
            push(stack, token);
        }
        else{
            /*NOTE
            problem here is yung pagkakasunod ng eevaluate na expression, yun na lang need i-fix*/

            if(isOperator(*token)){
                int operand1 = atoi(dequeue(operands));
                int operand2 = atoi(dequeue(operands));
                
                //checking of passing [pa-delete na lang if done na kayo mag debug]
                printf("Operands %d %s %d\n", operand1,  token, operand2);

                //perform operation
                int ans = applyOperator(token, operand1, operand2);
                printf("ANSWER: %d\n", ans);
                sprintf(answer, "%d", ans);
                enqueue(operands, answer);
            }
            else if(isMultiCharOperator(token[0], token[1])){
                int operand1 = atoi(dequeue(operands));
                int operand2 = atoi(dequeue(operands));

                //checking of passing [pa-delete na lang if done na kayo mag debug]
                printf("Operands %d %s %d\n", operand1,  token, operand2);

                //perform operation
                int ans = applyOperator(token, operand1, operand2);
                printf("ANSWER: %d\n", ans);
                sprintf(answer, "%d", ans);
                enqueue(operands, answer);
            }
        }
    }
    result = atoi(answer);
    return result;
}