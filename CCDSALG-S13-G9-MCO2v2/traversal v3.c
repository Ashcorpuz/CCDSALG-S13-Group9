#include "../includes/traversal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_STR 124

char *DFS(GraphPtr graph, char *start_vertex, int num_vertices)
{
    int *visited = (int *)malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++)
        visited[i] = 0;

    StackPtr stack = createStack(num_vertices);
    char *start_vertex_name = strdup(start_vertex);
    push(stack, start_vertex_name);
    visited[search_index(graph, start_vertex)] = 1;

    // Store traversal sequence
    int traversal_size = num_vertices * MAX_STR;
    char *result = (char *)malloc(traversal_size * sizeof(char));
    result[0] = '\0';

    while (!isEmpty(stack))
    {
        char *current_vertex = pop(stack);
        int current_index = search_index(graph, current_vertex);
        if (current_index == -1)
        {
            free(current_vertex);
            continue;
        }

        strcat(result, current_vertex);
        strcat(result, " ");
        //printf("%s ", current_vertex);

        NodePtr adjacency_list = getAdjacencyList(graph, current_index);
        while (adjacency_list)
        {
            char *adjacency_vertex = strdup(getVertex(adjacency_list));
            int adjacency_index = search_index(graph, adjacency_vertex);

            if (adjacency_index != -1 && !visited[adjacency_index])
            {
                push(stack, adjacency_vertex);
                visited[adjacency_index] = 1;
            }
            else
            {
                free(adjacency_vertex);
            }
            adjacency_list = getNext(adjacency_list);
        }
        free(current_vertex);
    }
    result[strlen(result) -1] = '\0';
    printf("\n");
    free(visited);
    destroyStack(stack);
    return result;
}

char *BFS(GraphPtr graph, char *start_vertex, int num_vertices)
{
    int *visited = (int *)malloc(num_vertices * sizeof(int));
    for (int i = 0; i < num_vertices; i++)
        visited[i] = 0;

    QueuePtr queue = createQueue(num_vertices);
    char *start_vertex_name = strdup(start_vertex);
    enqueue(queue, start_vertex_name);
    visited[search_index(graph, start_vertex)] = 1;

    // Store traversal sequence
    int traversal_size = num_vertices * MAX_STR;
    char *result = (char *)malloc(traversal_size * sizeof(char));
    result[0] = '\0';

    while (!isEmpty(queue))
    {
        char *current_vertex = dequeue(queue);
        int current_index = search_index(graph, current_vertex);
        if (current_index == -1)
        {
            free(current_vertex);
            continue;
        }

        strcat(result, current_vertex);
        strcat(result, " ");
        //printf("%s ", current_vertex);

        NodePtr adjacency_list = getAdjacencyList(graph, current_index);
        while (adjacency_list)
        {
            char *adjacency_vertex = strdup(getVertex(adjacency_list));
            int adjacency_index = search_index(graph, adjacency_vertex);

            if (adjacency_index != -1 && !visited[adjacency_index])
            {
                enqueue(queue, adjacency_vertex);
                visited[adjacency_index] = 1;
            }
            else
            {
                free(adjacency_vertex);
            }
            adjacency_list = getNext(adjacency_list);
        }
        free(current_vertex);
    }
    result[strlen(result) - 1] = '\0';
    printf("\n");
    free(visited);
    destroyQueue(queue);
    return result;
}
