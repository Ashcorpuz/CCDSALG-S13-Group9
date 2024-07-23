#ifndef __QUEUE_H
#define __QUEUE_H 2

typedef struct QueueNode
{
    int vertex_index;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

QueueNode *createQueueNode(int vertex_index);
Queue *createQueue();
void enqueue(Queue *queue, int vertex_index);
int dequeue(Queue *queue);
int isQueueEmpty(Queue *queue);
#endif //__QUEUE_H