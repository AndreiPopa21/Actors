#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

void resizeGraph(Graph** graph);
void addListFor(Graph** graph, char* name);
int checkNameDuplicate(Graph** graph, char* name);

void printGraph(Graph** graph);
void printList(AdjList** list);

#endif