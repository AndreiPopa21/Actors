#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueNode{
    struct QueueNode* next;
    struct QueueNode* prev;
    int value;
}QueueNode;

typedef struct Queue{
    struct QueueNode* head;
    struct QueueNode* tail;
}Queue;


Queue* initializeQueue();
QueueNode* initializeQueueNode(int i);

void enqueue(Queue** queue, int newNode);
int dequeue(Queue** queue);
int topQueue(Queue** queue);
int isQueueEmpty(Queue** queue);

void displayQueue(Queue** queue);

void freeQueue(Queue** queue);
void freeQueueNode(QueueNode** queueNode);

#endif