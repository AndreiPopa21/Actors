#include "Graph.h"

Graph* initializeGraph(int nodesCount){
    Graph* graph = (Graph*)calloc(1,sizeof(Graph));
    graph->nodesCount = nodesCount;
    graph->nodes = (AdjList**)calloc(nodesCount,sizeof(AdjList*));
    int i;
    for(i = 0; i < nodesCount; i++){
        graph->nodes[i] = (AdjList*)calloc(1,sizeof(AdjList));
    }
    return graph;
}

void freeGraph(Graph** graph){
    if(!(*graph)){
        return;
    }
    if((*graph)->nodes){
        int i;
        int size = (*graph)->nodesCount;
        for(i = 0; i < size; i++){
            freeAdjList(&((*graph)->nodes[i]));
        }
        free((*graph)->nodes);
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