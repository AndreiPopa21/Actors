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

    if(!strcmp(actorName,partnerName)){
        fprintf(stdout,"Cannot add edge to itself\n");
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
        /*fprintf(stdout,"Creating head with -------------------------->%s\n",newActorName);
        */(*list)->head = newNode;
        return;
    }

    AdjListNode* iter = (*list)->head;

    while(iter->next){
        iter = iter->next;
    }
    iter->next = newNode;
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

void printGraphNodes(Graph** graph){
    if(!(*graph)){
        return;
    }
    if(!((*graph)->lists)){
        return;
    }
    int currentSize = (*graph)->currentSize;
    int i;
    for( i = 0; i < currentSize; i++){
        fprintf(stdout,"%d %s",i+1,(*graph)->lists[i]->head->actorName);
    }
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

void resetVisitedStatus(Graph** graph){
    if(!(*graph)){
        return;
    }
    if(!((*graph)->lists)){
        return;
    }
    int currentSize = (*graph)->currentSize;
    int i;
    for( i = 0; i < currentSize; i++){
        (*graph)->lists[i]->head->visited = 0;
    }
}

int determineConnectedComp(Graph** graph){
    if(!(*graph)){
        return 0;
    }
    if(!((*graph)->lists)){
        return 0;
    }
    return 0;
}

void visitDFS(Graph** graph, AdjList** list){
    if(!(*graph)){
        return;
    }
    if(!(*list)){
        return;
    }
    if(!((*graph)->lists)){
        return;
    }
    if((*list)->head->visited){
        return;
    }
    (*list)->head->visited = 1;
    
    AdjListNode* iter = (*list)->head->next;
    while(iter){
        char* name = iter->actorName;
        int currentSize = (*graph)->currentSize;
        int i;
        for(i = 0; i < currentSize; i++){
            if(!strcmp(name,(*graph)->lists[i]->head->actorName)){
                if((*graph)->lists[i]->head->visited == 0){
                    visitDFS(graph,&((*graph)->lists[i]));
                }
                break;
            }
        }
        iter = iter->next;
    }
}

int visitBFS(Graph** graph, char** firstActor, char** secondActor){
    
    if(!(*graph) || !(*firstActor) || !(*secondActor)){
        return 0;
    }
    int distance = 0;

    Queue* queue = initializeQueue();
    int start = getGraphNode(graph,firstActor);
    (*graph)->lists[start]->head->visited = 1;
    enqueue(&queue,start);

    int prevColor = 1;
    
    while(!isQueueEmpty(&queue)){

        /*displayQueue(&queue);*/
        start = dequeue(&queue);
        prevColor = (*graph)->lists[start]->head->visited;
        AdjListNode* iter = (*graph)->lists[start]->head->next;

        while(iter){
            int index = getGraphNode(graph,&(iter->actorName));
            if((*graph)->lists[index]->head->visited==0){
                
                /*if(!strcmp((*secondActor),iter->actorName)){
                    freeQueue(&queue);
                    return prevColor + 1;
                }*/
                
                (*graph)->lists[index]->head->visited = prevColor + 1;
                enqueue(&queue,index);
            }
            iter = iter -> next;
        }
        
    }
    printf("DADADA\n");
    freeQueue(&queue);
    
    int final = getGraphNode(graph,secondActor);
    distance = (*graph)->lists[final]->head->visited;
    return distance;
}

void createGraph(Graph** graph, FILE* fh){
    if(!(*graph)){
        fprintf(stdout,"Cannot create on NULL graph\n");
        return;
    }
    if(!fh){
        return;
    }

    int moviesCount = 0;
    int actorsCount = 0;
    char buffer[255]={'\0'};

    fscanf(fh,"%d ",&moviesCount);
    
    int i,j;
    int actorsTotalCount = 0;
    for(i = 0; i < moviesCount; i++){
        /*movie title*/
        fgets(buffer,255,fh);
        AdjList* bufferList = (AdjList*)calloc(1,sizeof(AdjList));
        bufferList->head  = NULL;

        fprintf(stdout,"%s",buffer);
        /*actors count*/
        fscanf(fh,"%d ",&actorsCount);
        /*fprintf(stdout,"%d\n",actorsCount);*/
        actorsTotalCount +=actorsCount;
        /*each actor name*/
        for(j = 0; j < actorsCount; j++){
            fgets(buffer,255,fh);
            pushNode(&bufferList,buffer);
            /*fprintf(stdout,"%s",buffer);*/
           /* printf("Capul inca e: %s",bufferList->head->actorName);*/
        }
        /*printList(&bufferList);*/
        createLists(graph,&bufferList);
        pairActorsInList(graph,&bufferList);
        freeAdjList(&bufferList);
    }
}

int getGraphNode(Graph** graph, char** name){
    if(!(*graph) || !(*name)){
        return -1;
    }
    int i = 0;
    int graphSize = (*graph)->currentSize;
    for(i = 0; i < graphSize; i++){
        char* n1 = (*graph)->lists[i]->head->actorName;
        char* n2 = (*name);
        if(!strcmp(n1,n2)){
            return i;
        }
    }
    return -1;
}

void puncteArticulatie(Graph** graph, int* idx, int* low, FILE* wh){
    
    if(!(*graph)){
        fprintf(stdout,"Puncte Articulatie on NULL graph\n");
        return;
    }
    int timp = 0;
    int i;
    for(i = 0; i < (*graph)->currentSize; i++){
        idx[i] = -1;
        low[i] = INF;
    }
    Queue* queue = initializeQueue();
    for(i = 0; i < (*graph)->currentSize; i++){
        if(idx[i] == -1){
            dfsCV(graph,i,timp,idx,low, &queue);
        }
    }
    fprintf(wh,"%d\n", getQueueSize(&queue));
    int initialSize = getQueueSize(&queue);
    for(i = 0; i < initialSize; i++){
        int t = dequeue(&queue);
        fprintf(wh,"%s",(*graph)->lists[t]->head->actorName);
    }

    freeQueue(&queue);
}

void dfsCV(Graph** graph, int v, int timp, int* idx, int* low, Queue** queue){
    
    if(!(*graph)){
        return;
    }
    idx[v] = timp;
    low[v] = timp;

    timp = timp + 1;
    Queue* children = initializeQueue();
    AdjListNode* iter = (*graph)->lists[v]->head->next;
    while(iter){
        int iterIndex = getGraphNode(graph,&(iter->actorName));
        if(idx[iterIndex] == -1){
            enqueue(&children,iterIndex);
            dfsCV(graph,iterIndex,timp,idx,low, queue);
            if(low[v] < low[iterIndex]){
                low[v] = low[v];
            }else{
                low[v] = low[iterIndex];
            }
        }
        else{
            if(low[v] < idx[iterIndex]){
                low[v] = low[v];
            }else{
                low[v] = idx[iterIndex];
            }
        }
        iter = iter -> next;
    }
    if(idx[v] == 0){
        if(getQueueSize(&children) >= 2){
            /*printf("%s",(*graph)->lists[v]->head->actorName);*/
            enqueue(queue, v);
        }
    }else{
        int isArticulation = 0;
        while(getQueueSize(&children) > 0){
            int u = dequeue(&children);
            if(low[u] >= idx[v]){
                isArticulation = 1;
            }
        }
        if(isArticulation){
            /*printf("%s",(*graph)->lists[v]->head->actorName);*/
            enqueue(queue,v);
        }
    }
    freeQueue(&children);
}
