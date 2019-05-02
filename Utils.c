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

void addEdge(Graph** graph, char* actorName, char* partnerName){
    if(!(*graph)){
        fprintf(stdout,"Cannot add edge on NULL graph\n");
        return;
    }
    if((actorName[0]=='\0') || (partnerName[0]=='\0')){
        fprintf(stdout,"NULL names for adding edge\n");
        return;
    }

    if(!checkEdgeDuplicate(graph,actorName,partnerName)){
        int i = 0;
        int currentSize  = (*graph)->currentSize;
        while(i < currentSize){
            char* some = (*graph)->lists[i]->head->actorName;
            if(!strcmp(some,actorName)){
                pushNode(&((*graph)->lists[i]),partnerName);
                break;
            }
            i++;
        }
    }

    if(!checkEdgeDuplicate(graph,partnerName,actorName)){
        int i = 0;
        int currentSize  = (*graph)->currentSize;
        while(i < currentSize){
            char* some = (*graph)->lists[i]->head->actorName;
            if(!strcmp(some,partnerName)){
                pushNode(&((*graph)->lists[i]),actorName);
                break;
            }
            i++;
        }
    }
}

void pushNode(AdjList** list, char* newActorName){
    if(!(*list)){
        fprintf(stdout,"Cannot push to NULL list\n");
        return;
    }
    AdjListNode* newNode = initializeNode(newActorName);

    if(!((*list)->head)){
        fprintf(stdout,"Creating head with -------------------------->%s\n",newActorName);
        (*list)->head = newNode;
        return;
    }

    AdjListNode* iter = (*list)->head;

    while(iter->next){
        iter = iter->next;
    }
    iter->next = newNode;
    fprintf(stdout,"Pushed node to list with name %s\n", newNode->actorName);
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

int checkEdgeDuplicate(Graph** graph, char* first, char* second){
    if(!(*graph)){
        return 1;
    }
    if(!((*graph)->lists)){
        return 1;
    }
    if((first[0]=='\0')||(second[0]=='\0')){
        return 1;
    }

    int hasDuplicate = 0;
    int currentSize = (*graph)->currentSize;
    int i;
    for( i = 0; i < currentSize; i++){
        char* some = (*graph)->lists[i]->head->actorName;
        if(!strcmp(some,first)){
            AdjListNode* iter = (*graph)->lists[i]->head;
            while(iter){
                if(!strcmp(iter->actorName,second)){
                    hasDuplicate = 1;
                    break;
                }
                iter = iter -> next;
            }
            break;
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
    fprintf(stdout,"Printing list...\n");
    AdjListNode* iter = (*list)->head;
    while(iter){
        fprintf(stdout,"%s -> ",iter->actorName);
        iter = iter -> next;
    }
    fprintf(stdout,"NULL\n");
}

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

void createLists(Graph** graph, AdjList** list){
    if(!(*graph)){
        return;
    }
    if(!(*list)){
        return;
    }

    if(!((*list)->head)){
        return;
    }

    AdjListNode* iter = (*list)->head;
    while(iter){
        addListFor(graph,iter->actorName);
        iter = iter -> next;
    }
}