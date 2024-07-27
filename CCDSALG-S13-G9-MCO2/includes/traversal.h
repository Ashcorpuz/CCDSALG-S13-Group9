#ifndef __TRAVERSAL_H
#define __TRAVERSAL_H 4

#include "graph.h"
#include "node.h"
#include "queue.h"
#include "stack.h"

char *DFS(GraphPtr graph, char *start_vertex, int num_vertices);
char *BFS(GraphPtr graph, char *startVertex, int num_vertices);

#endif