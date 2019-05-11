#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
#include "Queue.h"

#define INF 100000000

void resizeGraph(Graph** graph);
void addListFor(Graph** graph, char* name);
void addEdge(Graph** graph, char* actorName, char* partnerName);
int checkNameDuplicate(Graph** graph, char* name);
int checkEdgeDuplicate(Graph** graph, char* first, char* second);

void createGraph(Graph** graph, FILE* fh);

void pushNode(AdjList** list, char* newActorName);

void pairActorsInList(Graph** graph, AdjList** list);

void createLists(Graph** graph, AdjList** list);

int getGraphNode(Graph** graph, char** name);

void resetVisitedStatus(Graph** graph);

int determineConnectedComp(Graph** graph);

void visitDFS(Graph** graph, AdjList** list);

int visitBFS(Graph** graph, char** firstActor, char** secondActor);

void puncteArticulatie(Graph** graph,int* idx, int* low, FILE* wh);
void dfsCV(Graph** graph, int v, int timp, int* idx, int* low, Queue** queue);

void printGraph(Graph** graph);
void printList(AdjList** list);
void printGraphNodes(Graph** graph);

#endif