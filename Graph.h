#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRAPH_SIZE_INCREMENT 50

/*fisier pentru definirea structurii unui graf*/


/*structura pentru un nod din lista de adiacenta a grafului*/
typedef struct AdjListNode{
    char* actorName;
    struct AdjListNode* next;
    int visited;
}AdjListNode;

/*structura pentru o lista de adiacenta*/
typedef struct AdjList{
    struct AdjListNode* head;
}AdjList;

/*structura specifica grafului*/
typedef struct Graph{
    int maxSize;
    int currentSize;
    struct AdjList** lists;
}Graph;

/*functie care initializeaza un graf*/
Graph* initializeGraph();
/*functie care initializeaza un nod intr-un graf*/
AdjListNode* initializeNode(char* actorName);
/*functie care elibereaza din memorie un graf*/
void freeGraph(Graph** graph);
/*functie care elibereaza din memorie o lista de adiacenta*/
void freeAdjList(AdjList** list);


#endif