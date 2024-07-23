#include "../includes/graph.h"
#include "../includes/traversal.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR 124
#define MAX_VERTICES 100
#define BLUE "\033[34m"
#define WHITE "\033[0m"
#define GREEN "\033[32m"
#define PURPLE "\033[35m"
#define RED "\033[31m"

char *showVertexIDdegrees(char sources[][MAX_STR], int source_count, int edges_count[])
{
    char *result = (char *)malloc(MAX_STR * sizeof(char));
    result[0] = '\0';

    for (int i = 0; i < source_count; i++)
    {
        char line[MAX_STR];
        snprintf(line, sizeof(line), "%s %d\n", sources[i], edges_count[i]);
        //printf("%s%s %d%s\n", BLUE, sources[i], edges_count[i], WHITE);

        strcat(result, line);
    }

    return result;
}

void outputFile(char *vertexIDs, char *dfs_result, char *bfs_result){
    FILE *outputFile = fopen("TRAVERSAL.txt", "w");
    
    fprintf(outputFile, "%s%s%s\n", BLUE, vertexIDs, WHITE);
    fprintf(outputFile, "%sBFS Traversal: %s%s\n", GREEN, bfs_result, WHITE);
    fprintf(outputFile, "%sDFS Traversal: %s%s\n", PURPLE, dfs_result, WHITE);
    
    fclose(outputFile);
}


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
        printf("%s%s not found.%s", RED, file_name, WHITE);
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
        printf("%sVertex %s not found.%s", RED, start_vertex, WHITE);
        return 0;
    }

    char *vertexIDs = showVertexIDdegrees(sources, source_count, edges_count);
    //printf("%s%s%s", BLUE, vertexIDs, WHITE);

    char *dfs_result = DFS(graph, start_vertex, number_of_vertices);
    //printf("%sDFS Traversal: %s%s\n", GREEN, dfs_result, WHITE);

    char *bfs_result = BFS(graph, start_vertex, number_of_vertices);
    //printf("%sBFS Traversal: %s%s\n", PURPLE, bfs_result, WHITE);
    fclose(fptr);

    //draw
    


    outputFile(vertexIDs, dfs_result, bfs_result);
    return 0;
}
