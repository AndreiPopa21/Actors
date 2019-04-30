#include "Graph.h"

Graph* initializeGraph(){
    Graph* graph = (Graph*)calloc(1,sizeof(Graph));
    graph->currentSize = 0;
    graph->maxSize = GRAPH_SIZE_INCREMENT;
    graph->lists = (AdjList**)calloc(GRAPH_SIZE_INCREMENT,sizeof(AdjList*));
    int i;
    for(i = 0; i < GRAPH_SIZE_INCREMENT; i++){
        graph->lists[i] = (AdjList*)calloc(1,sizeof(AdjList));
    }
    return graph;
}

AdjListNode* initializeNode(char* actorName){
    if(actorName[0] == '\0'){
        return NULL;
    }
    AdjListNode* newNode = (AdjListNode*) calloc(1,sizeof(AdjListNode));
    newNode->actorName = actorName;
    newNode->next = NULL;
    return newNode;
}

void freeGraph(Graph** graph){
    if(!(*graph)){
        return;
    }
    if((*graph)->lists){
        int i;
        int totalSize = (*graph)->maxSize;
        for(i = 0; i < totalSize; i++){
            freeAdjList(&((*graph)->lists[i]));
        }
        free((*graph)->lists);
    }
    free((*graph));
}

void freeAdjList(AdjList** list){
    if(!(*list)){
        return;
    }
    while((*list)->head){
        AdjListNode* tmp = (*list)->head;
        (*list)->head = (*list)->head->next;
        free(tmp);
    }
    free((*list));
}