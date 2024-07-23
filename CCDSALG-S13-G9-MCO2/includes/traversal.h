#ifndef __TRAVERSAL_H
#define __TRAVERSAL_H 4

#include "graph.h"
#include "node.h"
#include "queue.h"
#include "stack.h"

void DFS(GraphPtr graph, char *start_vertex, int num_vertices);
void BFS(GraphPtr graph, char *startVertex, int num_vertices);

#endif