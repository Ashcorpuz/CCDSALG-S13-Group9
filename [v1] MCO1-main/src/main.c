#include "../include/main.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    QueuePtr postfix = createQueue(MAX);
    char infix[MAX] = "8*(5^4+2)-6^2/(9*3)";
    infixToPostfix(infix, postfix);
    printf("result: ");

    while (!isEmptyQueue(postfix))
    {
        printf("%s", dequeue(postfix));
    }
    printf("\n");

    free(postfix);
    return 0;
}