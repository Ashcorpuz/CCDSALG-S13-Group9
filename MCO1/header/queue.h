#ifndef __QUEUE_H
#define __QUEUE_H
#include <stdbool.h>

#define MAX 256
typedef struct Queue{
    char **item;
    int capacity;
    int head;
    int tail;
} Queue;

typedef struct Queue *QueuePtr;

QueuePtr createQueue(unsigned int size);
void enqueue(QueuePtr Q, char *x);
char *dequeue(QueuePtr Q);
char *queueHead(QueuePtr Q);
char *queueTail(QueuePtr Q);
bool queueEmpty(QueuePtr Q);
bool queueFull(QueuePtr Q);
void appendQueue(char *expression, int x);
#endif // __QUEUE_H 