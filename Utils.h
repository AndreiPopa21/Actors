#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

void resizeGraph(Graph** graph);
void addListFor(Graph** graph, char* name);
void addEdge(Graph** graph, char* actorName, char* partnerName);
int checkNameDuplicate(Graph** graph, char* name);
int checkEdgeDuplicate(Graph** graph, char* first, char* second);

void pushNode(AdjList** list, char* newActorName);

void pairActorsInList(Graph** graph, AdjList** list);

void createLists(Graph** graph, AdjList** list);

void printGraph(Graph** graph);
void printList(AdjList** list);
void printGraphNodes(Graph** graph);

#endif