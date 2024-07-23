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
    int start_index = search_index(graph, start_vertex);
    if (start_index == -1)
    {
        printf("Vertex not found!\n");
        return;
    }

    printf("Check Graph");

    // Initialize visited array
    bool *visited = (bool *)malloc(num_vertices * sizeof(bool));
    if (visited == NULL)
    {
        printf("Memory Allocation Error: failed to allocate memory in BFS function.");
        return;
    }
    memset(visited, 0, num_vertices * sizeof(bool));

    // Create a queue for BFS
    Queue *queue = createQueue();

    // Store traversal sequence
    int traversal_size = num_vertices * MAX_STR;
    char *result = (char *)malloc(traversal_size * sizeof(char));
    result[0] = '\0';

    // Mark the start vertex as visited and enqueue it
    visited[start_index] = true;
    enqueue(queue, start_index);

    while (!isQueueEmpty(queue))
    {
        // Dequeue a vertex from the queue
        int vertex_index = dequeue(queue);
        char *vertex_name = getVertices(graph, vertex_index);

        strcat(result, vertex_name);
        strcat(result, " ");
        //printf("%s ", getVertices(graph, vertex_index));

        // Get all adjacent vertices of the dequeued vertex
        NodePtr adj_list = getAdjacencyList(graph, vertex_index);
        while (adj_list != NULL)
        {
            int adj_index = search_index(graph, adj_list->vertex);
            if (adj_index != -1 && !visited[adj_index])
            {
                visited[adj_index] = true;
                enqueue(queue, adj_index);
            }
            adj_list = adj_list->next;
        }
    }

    printf("\n");

    free(visited);
    free(queue);
    return result;
}