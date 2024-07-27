
#include "../includes/queue.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create a new queue node
QueueNode *createQueueNode(int vertex_index)
{
    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
    if (new_node == NULL)
    {
        printf("Memory Allocation Error: failed to allocate memory for QueueNode.");
        exit(1);
    }
    new_node->vertex_index = vertex_index;
    new_node->next = NULL;
    return new_node;
}

// Function to create a queue
Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL)
    {
        printf("Memory Allocation Error: failed to allocate memory for Queue.");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue an element
void enqueue(Queue *queue, int vertex_index)
{
    QueueNode *new_node = createQueueNode(vertex_index);
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = new_node;
        return;
    }
    queue->rear->next = new_node;
    queue->rear = new_node;
}

// Function to dequeue an element
int dequeue(Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue Underflow: No elements to dequeue.\n");
        exit(1);
    }
    QueueNode *temp = queue->front;
    int vertex_index = temp->vertex_index;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    return vertex_index;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue *queue)
{
    return queue->front == NULL;
}
