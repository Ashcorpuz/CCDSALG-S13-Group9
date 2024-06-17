/**
 * queue.h
 * Author: Ashley Corpuz, Princess Escobar, Herise Visto
 *
 * Using 'ADT' design pattern
 * 	referenced from: https://leanpub.com/patternsinc
 * Queue has limitations, after a bit of enqueuing and dequeuing,
 * the size of queue is reduced.
 * That's why this queue is modified to Circular Queue.
 *
 * Opaque Data Type
 *
 * Circular Queue reference: https://www.programiz.com/dsa/queue
 * Queue Library Header
 */

#ifndef __QUEUE_H_INCLUDED
#define __QUEUE_H_INCLUDED

#include <stdbool.h>

#define STRING_SIZE 8

typedef struct Queue *QueuePtr;

QueuePtr createQueue(unsigned int capacity);

void enqueue(QueuePtr queue, char *item);
char *dequeue(QueuePtr queue);
char *peek(QueuePtr queue);

bool isFullQueue(QueuePtr queue);
bool isEmptyQueue(QueuePtr queue);
unsigned int sizeQueue(QueuePtr queue);

#endif // __QUEUE_H_INCLUDED
