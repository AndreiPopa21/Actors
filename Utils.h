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

void pushNode(AdjList** list, char* newActorName);

void pairActorsInList(Graph** graph, AdjList** list){

    if(!(*graph)){
        return;
    }
    if(!(*list)){
        fprintf(stdout,"Cannot pair in NULL list\n");
        return;
    }
    if(!((*list)->head)){
        return;
    }
    if(!((*list)->head->next)){
        return;
    }
    AdjListNode* primaryIter = (*list)->head;
    AdjListNode* secondaryIter;
    while(primaryIter){
        secondaryIter = primaryIter->next;
        while(secondaryIter){
            addEdge(graph,primaryIter->actorName,secondaryIter->actorName);
            secondaryIter =secondaryIter ->next;
        }
        primaryIter = primaryIter -> next;
    }
}

void printGraph(Graph** graph);
void printList(AdjList** list);

#endif