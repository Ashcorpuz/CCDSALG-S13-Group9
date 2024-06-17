#include "../include/main.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Struct representing the queue
struct Queue
{
    unsigned int capacity; // Max size of queue
    int front;             // First in line
    int rear;              // Last in line
    char **data;           // Holds the data stored // Changed to INT due to specific reasons
};

// Add an item to the queue
void _enqueue(QueuePtr queue, char *item)
{
    // Calculate the rear with the circular queue.
    int updatedRear = (queue->rear + 1) % queue->capacity;

    // update rear
    queue->rear = updatedRear;

    // pass the string to data
    queue->data[updatedRear] = duplicate(item);
}

// Remove an item from the queue
char *_dequeue(QueuePtr queue)
{
    // Calculate the front with the circular queue
    int updatedFront = (queue->front + 1) % queue->capacity;

    // update front
    queue->front = updatedFront;

    // pass the copy of data to variable
    char *data = duplicate(queue->data[updatedFront]);

    // free the allocated space
    free(queue->data[updatedFront]);

    // set it to NULL
    queue->data[updatedFront] = NULL;

    return data;
}

// Get the front item of the queue without removing it
char *_peek(QueuePtr queue)
{
    // Calculate the front using circular queue
    int currentFront = (queue->front + 1) % queue->capacity;

    // get the data
    char *data = queue->data[currentFront];

    return data;
}

// Get the current size of the queue
unsigned int _sizequeue(QueuePtr queue)
{
    bool justInitialized = queue->front == -1 && queue->rear == -1;
    bool isEqual = queue->rear == queue->front && queue->front != -1;
    bool isWrapped = queue->front > queue->rear;

    if (justInitialized)
        return 0;
    if (isEqual)
    {
        bool isEmpty = _peek(queue) == NULL;
        return isEmpty ? 0 : queue->capacity;
    }
    else
    {
        if (isWrapped)
            return (queue->capacity - queue->front) + queue->rear;
        else
            return queue->rear - queue->front;
    }
}

// Initialize a new queue with the given capacity
// Create a new queue instance with the given capacity
QueuePtr createQueue(unsigned int capacity)
{
    // Allocate enough space for queue.
    QueuePtr queue = malloc(sizeof *queue);
    if (queue == NULL)
        return NULL;

    queue->data = malloc(sizeof(char *) * capacity);
    if (queue->data == NULL)
        return NULL;

    // Initialize capacity, front and rear.
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    return queue;
}
// Add an item to the queue
void enqueue(QueuePtr self, char *item)
{
    if (isFullQueue(self))
        return;

    _enqueue(self, item);
}

// Remove an item from the queue
char *dequeue(QueuePtr self)
{
    if (isEmptyQueue(self))
        return NULL;

    return _dequeue(self);
}

// Get the front item of the queue without removing it
char *peek(QueuePtr self)
{
    if (isEmptyQueue(self))
        return NULL;

    return _peek(self);
}

// Check if the queue is full
bool isFullQueue(QueuePtr self)
{
    return _sizequeue(self) == self->capacity;
}

// Check if the queue is empty
bool isEmptyQueue(QueuePtr self)
{
    return _sizequeue(self) == 0;
}

// Get the current size of the queue
unsigned int sizeQueue(QueuePtr self)
{
    return _sizequeue(self);
}
