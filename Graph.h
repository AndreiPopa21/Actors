#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRAPH_SIZE_INCREMENT 50

typedef struct AdjListNode{
    char* actorName;
    struct AdjListNode* next;
    int visited;
}AdjListNode;

typedef struct AdjList{
    struct AdjListNode* head;
}AdjList;

typedef struct Graph{
    int maxSize;
    int currentSize;
    struct AdjList** lists;
}Graph;

Graph* initializeGraph();
AdjListNode* initializeNode(char* actorName);
void freeGraph(Graph** graph);
void freeAdjList(AdjList** list);


#endif