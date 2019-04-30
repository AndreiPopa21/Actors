#include "Utils.h"

void resizeGraph(Graph** graph){
    if(!(*graph)){
        fprintf(stdout,"Cannot resize NULL graph\n");
        return;
    }

    int currMaxSize = (*graph)->maxSize;
    int newMaxSize = currMaxSize + GRAPH_SIZE_INCREMENT;
    (*graph)->nodes = (AdjList**)realloc((*graph)->nodes,newMaxSize*sizeof(AdjList*));
    int i;
    for(i = currMaxSize; i < newMaxSize; i++){
        (*graph)->nodes[i] = (AdjList*)calloc(1,sizeof(AdjList));
    }
    (*graph)->maxSize = newMaxSize;
}