#ifndef __NODE_H
#define __NODE_H 1

typedef struct Node *NodePtr;
struct Node
{
    char *vertex;
    NodePtr next;
};
NodePtr createNode(char *vertex, NodePtr next);
void printNode(NodePtr node);
char *getVertex(NodePtr adjacency_list);
NodePtr getNext(NodePtr node);
#endif //__NODE_H