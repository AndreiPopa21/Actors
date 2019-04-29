#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AdjListNode{
    char* actorName;
    struct AdjListNode* next;
}AdjListNode;

typedef struct AdjList{
    struct AdjListNode* head;
}AdjList;

typedef struct Graph{
    int nodesCount;
    struct AdjList* nodes;
}Graph;


#endif