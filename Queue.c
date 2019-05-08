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
        freeQueueNode(&((*queue)->head));
        (*queue)->head = NULL;
        (*queue)->tail = NULL;
    }else{
        (*queue)->head->next->prev = NULL;
        QueueNode* newHead = (*queue)->head->next;
        freeQueueNode(&((*queue)->head));
        (*queue)->head = newHead;
    }
    return value;
}

int topQueue(Queue** queue){
    if(!(*queue)){
        fprintf(stdout,"Cannot perform top queue on NULL queue\n");
        return -1;
    }
    if(!((*queue)->head)){
        return -1;
    }

    int value = (*queue)->head->value;
    return value;
}

int isQueueEmpty(Queue** queue){
    if(!(*queue)){
        return 1;
    }
    if(!((*queue)->head)){
        return 1;
    }
    return 0;
}

void displayQueue(Queue** queue){
    if(!(*queue)){
        fprintf(stdout,"NULL queue to print\n");
        return;
    }
    QueueNode* iter = (*queue)->head;
    fprintf(stdout,"Printing queue: ");
    while(iter){
        int value = iter->value;
        fprintf(stdout,"-> %d ", value);
        iter = iter->next;
    }
    fprintf(stdout,"-> NULL\n");
}

void freeQueue(Queue** queue){
    if(!(*queue)){
        fprintf(stdout,"Cannot free NULL queue\n");
        return;
    }
    QueueNode* iter = (*queue)->head;
    while(iter){
        QueueNode* tmp = iter;
        iter = iter->next;
        freeQueueNode(&tmp);
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
    (*queueNode)->value = 0;
    free((*queueNode));
}