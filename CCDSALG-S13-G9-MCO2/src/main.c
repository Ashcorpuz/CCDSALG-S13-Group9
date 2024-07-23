#include "../includes/graph.h"
#include "../includes/traversal.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR 124
#define MAX_VERTICES 100

int main()
{

    FILE *fptr;
    char file_name[MAX_STR];

    printf("Input filename: ");
    fgets(file_name, MAX_STR, stdin);
    file_name[strcspn(file_name, "\n")] = 0;
    fptr = fopen(file_name, "r");

    if (fptr == NULL)
    {
        printf("\033[31m%s not found.\033[0m", file_name);
        return 1;
    }

    char line[MAX_STR];
    int number_of_vertices = 0;

    // READ FIRST LINE OF THE FILE,
    // * First line consists of number of vertices
    if (fscanf(fptr, "%s", line) != EOF)
    {
        number_of_vertices = atoi(line);
    }
    GraphPtr graph = createGraph(number_of_vertices);

    // READ THE VERTICES
    // * First word is the vertex, the other next to it is edges
    char sources[MAX_VERTICES][MAX_STR];
    char destinations[MAX_VERTICES][MAX_STR];
    int edges_count[MAX_VERTICES] = {0};
    int source_count = 0;
    int destination_count = 0;

    char source[MAX_STR] = {0};
    while (fscanf(fptr, "%s", line) != EOF)
    {
        if (strcmp(line, "-1") == 0)
        {
            if (source[0] != 0)
                source[0] = 0;
        }
        else
        {
            if (source[0] == 0)
            {
                edges_count[source_count] = 0;
                addVertex(graph, source_count, line);
                strcpy(source, line);
                strcpy(sources[source_count++], line);
            }
            else
            {
                strcpy(destinations[destination_count++], line);
                edges_count[source_count - 1]++;
            }
        }
    }

    for (int i = 0, k = 0; i < source_count; i++)
    {
        for (int j = 0; j < edges_count[i]; j++)
        {
            addEdge(graph, sources[i], destinations[k++]);
        }
    }

    char start_vertex[MAX_STR];
    printf("Input start vertex for the traversal: ");
    fgets(start_vertex, MAX_STR, stdin);
    start_vertex[strcspn(start_vertex, "\n")] = 0;

    int list_index = search_index(graph, start_vertex);

    if (list_index == -1)
    {
        printf("\033[31mVertex %s not found.\033[0m", start_vertex);
        return 0;
    }

    DFS(graph, start_vertex, number_of_vertices);
    BFS(graph, start_vertex, number_of_vertices);
    fclose(fptr);
    return 0;
}
