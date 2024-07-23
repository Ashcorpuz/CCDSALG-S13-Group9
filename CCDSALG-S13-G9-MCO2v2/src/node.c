#include "../includes/node.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

NodePtr createNode(char *vertex, NodePtr next)
{
    NodePtr new_node = (NodePtr)malloc(sizeof(struct Node));
    if (new_node == NULL)
    {
        printf("Memory Allocation Erorr: failed to alocate memory in createNode function.");
        return NULL;
    }

    new_node->vertex = strdup(vertex); // duplicate string.
    new_node->next = next;
    return new_node;
}

void printNode(NodePtr node)
{
    NodePtr temp = node;
    while (temp)
    {
        printf("%s -> ", temp->vertex);
        temp = temp->next;
    }
    printf("\n");
}

char *getVertex(NodePtr node)
{
    return node->vertex;
}

NodePtr getNext(NodePtr node)
{
    return node->next;
}