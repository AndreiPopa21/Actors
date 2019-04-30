#include "Graph.h"

Graph* initializeGraph(){
    Graph* graph = (Graph*)calloc(1,sizeof(Graph));
    graph->currentSize = 0;
    graph->maxSize = GRAPH_SIZE_INCREMENT;
    graph->nodes = (AdjList**)calloc(GRAPH_SIZE_INCREMENT,sizeof(AdjList*));
    int i;
    for(i = 0; i < GRAPH_SIZE_INCREMENT; i++){
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
        int totalSize = (*graph)->maxSize;
        for(i = 0; i < totalSize; i++){
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