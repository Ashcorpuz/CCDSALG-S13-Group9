#include "../include/main.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    QueuePtr postfix = createQueue(MAX);
    int option;
    char infix[MAX];
    /*
    char infix[MAX] = "8*(5^4+2)-6^2/(9*3)";
    
    infixToPostfix(infix, postfix);
    printf("result: ");
     */

    while (1)
    {
        printf("\nOption:\n");
        printf("[1] Infix\n");
        printf("[0] Exit\n");
        printf("Choice:");
        scanf("%d", &option);

        if (option == 1)
        {
            int option2;
               printf("Enter Infix Expression: ");
               scanf("%s", infix);

               printf("\n[1] Evaluate Infix");
               printf("\n[2] Convert to Postfix");
               printf("\nChoice: ");
               scanf("%d", &option2);

               if(option2 == 1){
                printf("\nEvaluating...");

               }
               else if (option2 == 2)
               {
                infixToPostfix(infix,postfix);
                printf("result: ");
                while (!isEmptyQueue(postfix))
                {
                    printf("%s", dequeue(postfix));
                }
                printf("\n");

                free(postfix);
               }
        }
        else if (option == 0)
        {
            exit(0);
        }
        else{
            printf("Invalid Option\n");
        }
    }
    
/*while (!isEmptyQueue(postfix))
    {
        printf("%s", dequeue(postfix));
    }
    printf("\n");

    free(postfix); */
    return 0;
}