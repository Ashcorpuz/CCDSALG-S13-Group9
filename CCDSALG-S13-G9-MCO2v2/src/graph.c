#include "../includes/graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_PAIRS 100

struct Graph
{
    int num_vertices;
    int *visited;
    NodePtr *adjacency_list;
    char **vertices;
};

GraphPtr createGraph(int vertices)
{
    GraphPtr graph = (GraphPtr)malloc(sizeof(struct Graph));
    if (graph == NULL)
    {
        printf("Memory Allocation Erorr: failed to alocate memory in createGraph function.");
        return NULL;
    }
    graph->num_vertices = vertices;

    graph->adjacency_list = (NodePtr *)malloc(vertices * sizeof(NodePtr));
    graph->visited = (int *)malloc(vertices * sizeof(int));
    graph->vertices = (char **)malloc(vertices * sizeof(char *));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjacency_list[i] = NULL;
        graph->visited[i] = 0;
        graph->vertices[i] = NULL;
    }

    return graph;
}

void addVertex(GraphPtr graph, int index, char *name)
{
    graph->vertices[index] = strdup(name);
}

int pairExists(int x, int y, int pairs[][2], int pair_count)
{
    for (int i = 0; i < pair_count; i++)
    {
        if ((pairs[i][0] == x && pairs[i][1] == y) || (pairs[i][0] == y && pairs[i][1] == x))
            return 1; // true
    }
    return 0; // false
}

void addEdge(GraphPtr graph, char *source, char *destination)
{
    static int count = 0;
    static int pairs[MAX_PAIRS][2];
    int source_index = -1, destination_index = -1;
    for (int i = 0; i < graph->num_vertices; i++)
    {
        if (strcmp(graph->vertices[i], source) == 0)
            source_index = i;
        if (strcmp(graph->vertices[i], destination) == 0)
            destination_index = i;
    }

    if (source_index != -1 && destination_index != -1)
    {
        if (!pairExists(source_index, destination_index, pairs, count))
        {
            pairs[count][0] = source_index;
            pairs[count][1] = destination_index;
            count++;
            NodePtr new_node = createNode(destination, graph->adjacency_list[source_index]);
            graph->adjacency_list[source_index] = new_node;

            new_node = createNode(source, graph->adjacency_list[destination_index]);
            graph->adjacency_list[destination_index] = new_node;
        }
    }
}

void printGraph(GraphPtr graph)
{
    for (int i = 0; i < graph->num_vertices; i++)
    {
        printf("\n Adjacency list of vertex %s\n", graph->vertices[i]);
        printNode(graph->adjacency_list[i]);
    }
}

int search_index(GraphPtr graph, char *vertex)
{
    for (int i = 0; i < graph->num_vertices; i++)
    {
        if (strcasecmp(graph->vertices[i], vertex) == 0)
        {
            return i;
        }
    }

    return -1; // not found
}

NodePtr getAdjacencyList(GraphPtr graph, int index)
{
    return graph->adjacency_list[index];
}

void startVisit(GraphPtr graph, int startVertexIndex)
{
    graph->visited[startVertexIndex] = 1;
}

char *getVertices(GraphPtr graph, int index)
{
    return graph->vertices[index];
}

int getVisited(GraphPtr graph, int index)
{
    return graph->visited[index];
}