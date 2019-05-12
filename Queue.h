#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*fisier pentru definirea structurii unei cozi*/
/*coada a fost utilizata in rezolvarea task-urilor 2 si 3*/

/*structura pentru definirea unui nod in coada*/
typedef struct QueueNode{
    struct QueueNode* next;
    struct QueueNode* prev;
    int value;
}QueueNode;

/*structura pentru definirea unei cozi*/
typedef struct Queue{
    struct QueueNode* head;
    struct QueueNode* tail;
}Queue;

/*functie de initializare a cozii*/
Queue* initializeQueue();
/*functie de initializarea a unui nod de coada*/
QueueNode* initializeQueueNode(int i);

/*functie care adauga un nod in coada*/
void enqueue(Queue** queue, int newNode);
/*functie care scoate un nod din coada*/
int dequeue(Queue** queue);
/*functie care intoarce primul element din coada*/
int topQueue(Queue** queue);
/*functie care verifica daca o coada este nula*/
int isQueueEmpty(Queue** queue);

/*functie care afiseaza structura unei cozi*/
void displayQueue(Queue** queue);

/*functie care intoarce marimea cozii*/
int getQueueSize(Queue** queue);

/*functie pentru eliberarea din memorie a unei cozi*/
void freeQueue(Queue** queue);
/*functie pentur eliberarea din memorie a unui nod de coada*/
void freeQueueNode(QueueNode** queueNode);

#endif