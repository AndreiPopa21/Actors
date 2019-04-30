#include "Utils.h"

void resizeGraph(Graph** graph){
    if(!(*graph)){
        fprintf(stdout,"Cannot resize NULL graph\n");
        return;
    }

    int currMaxSize = (*graph)->maxSize;
    int newMaxSize = currMaxSize + GRAPH_SIZE_INCREMENT;
    (*graph)->lists = (AdjList**)realloc((*graph)->lists,newMaxSize*sizeof(AdjList*));
    int i;
    for(i = currMaxSize; i < newMaxSize; i++){
        (*graph)->lists[i] = (AdjList*)calloc(1,sizeof(AdjList));
    }
    (*graph)->maxSize = newMaxSize;
}

void addListFor(Graph** graph, char* name){
    if(!(*graph)){
        fprintf(stdout,"Cannot add list in a NULL graph\n");
        return;
    }
    if(name[0]=='\0'){
        fprintf(stdout,"Cannot add list for NULL name\n");
        return;
    }

    if(!checkNameDuplicate(graph,name)){
        int currentSize = (*graph)->currentSize;
        int maxSize = (*graph)->maxSize;

        if(currentSize == maxSize){
            resizeGraph(graph);
        }

        AdjListNode* newHead = initializeNode(name);
        (*graph)->lists[currentSize]->head = newHead;
        (*graph)->currentSize ++;

    }else{
        fprintf(stdout,"Name duplicate\n");
        return;
    }

}

int checkNameDuplicate(Graph** graph, char* name){
    if(!(*graph)){
        return 1;
    }

    if(!((*graph)->lists)){
        return 1;
    }

    if(name[0]=='\0'){
        return 1;
    }
    int currentSize = (*graph)->currentSize;
    int hasDuplicate = 0;
    int i;

    for(i = 0; i < currentSize; i++){
        char* actorName = (*graph)->lists[i]->head->actorName;
        if(!strcmp(name,actorName)){
            hasDuplicate = 1;
        }
    }
    if(hasDuplicate){
        return 1;
    }
    return 0;
}

void printGraph(Graph** graph){
    if(!(*graph)){
        return;
    }
    int currentSize = (*graph)->currentSize;
    int i;
    fprintf(stdout,"Printing graph:\n");
    for( i = 0; i < currentSize; i++){
        printList(&((*graph)->lists[i]));
    }
    fprintf(stdout,"Current size: %d | Max size: %d\n",(*graph)->currentSize,(*graph)->maxSize);
}

void printList(AdjList** list){
    if(!(*list)){
        return;
    }
    if(!(*list)->head){
        fprintf(stdout,"NULL list\n");
        return;
    }
    AdjListNode* iter = (*list)->head;
    while(iter){
        fprintf(stdout,"%s -> ",iter->actorName);
        iter = iter -> next;
    }
    fprintf(stdout,"NULL\n");
}