#ifndef __GRAPH_H
#define __GRAPH_H 0
#include "node.h"
#include "queue.h"

typedef struct Graph *GraphPtr;

GraphPtr createGraph(int vertices);
void addVertex(GraphPtr graph, int index, char *name);
void addEdge(GraphPtr Graph, char *source, char *destination);
void printGraph(GraphPtr graph);
int search_index(GraphPtr graph, char *vertex);
NodePtr getAdjacencyList(GraphPtr graph, int index);
char *getVertices(GraphPtr graph, int index);
void startVisit(GraphPtr graph, int startVertexIndex);
int getVisited(GraphPtr graph, int index);
#endif //__GRAPH_H