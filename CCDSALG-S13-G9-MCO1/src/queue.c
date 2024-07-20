#include "../header/main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 256  // Define the maximum size of the queue

void adjustIndex(QueuePtr Q){
    int currentInd = Q->head;
    int newInd = Q->head+1;
    Q->head = newInd;
};

char *_deletesLast(QueuePtr Q){
    char *op = queueTail(Q);
    Q->item[Q->tail-1] = "\0";
    //free(Q->item[Q->head]); // deletes first element
    Q->tail-=1;
    return op;
}

char *deletesLast(QueuePtr Q){
    if(Q->head == Q->tail){
        fprintf(stderr, "Queue is empty\n");
    }
    char *op = _deletesLast(Q);
    return op;
}

QueuePtr createQueue(unsigned int size) {
    QueuePtr Q = malloc(sizeof *Q);
    Q->capacity = size;
    Q->head = 0;
    Q->tail = 0;
    Q->item = malloc(size * sizeof(char *));
    return Q;
}

void _enqueue(QueuePtr Q, char *op){
    Q->item[Q->tail] = malloc(strlen(op) + 1);
    strcpy(Q->item[Q->tail], op);
    Q->tail++;
}

void enqueue(QueuePtr Q, char *x){
    if(queueFull(Q)){
        fprintf(stderr, "Queue is full\n");
    }
    _enqueue(Q, x);
}

char *_dequeue(QueuePtr Q){
    char *op = Q->item[Q->head];
    Q->item[Q->head] = "\0";
    //free(Q->item[Q->head]); // deletes first element
    Q->head+=1;
    return op;
}

char *dequeue(QueuePtr Q){
    if(Q->head == Q->tail){
        fprintf(stderr, "Queue is empty\n");
    }
    char *op = _dequeue(Q);
    return op;
}

char *queueHead(QueuePtr Q){
    if(queueEmpty(Q)){
        fprintf(stderr, "Queue is empty\n"); 
    }
    return Q->item[Q->head];
}

char *queueTail(QueuePtr Q){
    if(queueEmpty(Q)){
        fprintf(stderr, "Queue is empty\n"); 
    }
    //return _queueTail(Q);
    return Q->item[Q->tail-1];
}

bool queueEmpty(QueuePtr Q){
    return Q->head == Q->tail;
}

bool queueFull(QueuePtr Q) {
    return (Q->tail + 1) % MAX == Q->head;
}

void appendQueue(char *expression, int x){
    sprintf(expression, "%s%d", expression, x);
}