#include "Queue.h"

Queue* initializeQueue(){
    Queue* queue = (Queue*)calloc(1,sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

QueueNode* initializeQueueNode(int value){
    QueueNode* newNode = (QueueNode*)calloc(1,sizeof(QueueNode));
    newNode -> value = value;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}

void enqueue(Queue** queue, int newNode){
    if(!(*queue)){
        fprintf(stdout,"Cannot enqueue in NULL queue\n");
        return;
    }
    QueueNode* node = initializeQueueNode(newNode);
    if(!node){
        return;
    }
    if(!((*queue)->head)){
        (*queue)->head = node;
        (*queue)->tail = node;
        return;
    }
    (*queue)->tail->next = node;
    node->prev = (*queue)->tail;
    (*queue)->tail = node;
}

int dequeue(Queue** queue){
    if(!(*queue)){
        fprintf(stdout,"Cannot dequeue on NULL queue\n");
        return -1;
    }
    if(!((*queue)->head)){
        fprintf(stdout,"No more elements on queue to dequeue\n");
        return -1;
    }
    int value = (*queue)->head->value;
    if(!((*queue)->head->next)){
        (*queue)->head = NULL;
        (*queue)->tail = NULL;
    }else{
        (*queue)->head->next->prev = NULL;
        (*queue)->head = (*queue)->head->next;
    }
    return value;
}

int topQueue(Queue** queue){
    if(!(*queue)){
        fprintf(stdout,"Cannot perform top queue on NULL queue\n");
        return -1;
    }

    int value = (*queue)->head->value;
    return value;
}

int isQueueEmpty(Queue** queue){
    if(!(*queue)){
        return;
    }
    if(!((*queue)->head)){
        return 1;
    }
    return 0;
}

void freeQueue(Queue** queue){
    if(!(*queue)){
        fprintf(stdout,"Cannot free NULL queue\n");
        return;
    }
    QueueNode* iter = (*queue)->head;
    while(iter){
        freeQueueNode(&iter);
    }
    free((*queue));
}

void freeQueueNode(QueueNode** queueNode){
    if(!(*queueNode)){
        fprintf(stdout,"Cannot free NULL queueNode\n");
        return;
    }
    (*queueNode)->next = NULL;
    (*queueNode)->prev = NULL;
    (*queueNode)->value = NULL;
    free((*queueNode));
}