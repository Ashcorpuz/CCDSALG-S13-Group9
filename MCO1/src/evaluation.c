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

int applyLogicalNot(int operand){
    return !operand;
}

int evaluatePostfix(QueuePtr postfix) {
    StackPtr stack = createStack(MAX);
    QueuePtr operands = createQueue(MAX);
    QueuePtr expression = createQueue(MAX);
    int result;
    char answer[20];

    while (!queueEmpty(postfix)) {
        char *token = dequeue(postfix);
        if(isspace(*token))
            continue;
        else if(isdigit(*token)){
            enqueue(operands, token);
            push(stack, token);
        }
        else{
            if(isOperator(*token)){
                int operand1, operand2, ans;
                if(strcmp(token, "!")==0){
                    enqueue(expression, deletesLast(operands));
                    operand1 = atoi(deletesLast(expression));
                    ans = applyLogicalNot(operand1);
                    //Check
                    //printf("%s %d\n", token, operand1);
                    //printf("ANS: %d\n", ans);
                }
                else{
                    enqueue(expression, deletesLast(operands));
                    enqueue(expression, deletesLast(operands));
                    operand1 = atoi(deletesLast(expression));
                    operand2 = atoi(deletesLast(expression));
                    //perform operation
                    ans = applyOperator(token, operand1, operand2);
                    //Check
                    //printf("Operands %d %s %d\n", operand1,  token, operand2);   
                    //printf("ANSWER: %d\n", ans);
                }
                sprintf(answer, "%d", ans);
                enqueue(operands, answer);
            }
            else if(isMultiCharOperator(token[0], token[1])){
                enqueue(expression, deletesLast(operands));
                enqueue(expression, deletesLast(operands));
                int operand1 = atoi(deletesLast(expression));
                int operand2 = atoi(deletesLast(expression));

                //checking 
                //printf("Operands %d %s %d\n", operand1,  token, operand2);

                //perform operation
                int ans = applyOperator(token, operand1, operand2);
                //printf("ANSWER: %d\n", ans);
                sprintf(answer, "%d", ans);
                enqueue(operands, answer);
            }
        }
    }
    result = atoi(answer);
    return result;
}