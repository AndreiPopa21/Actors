#include "Tasks.h"

void TaskOne(char* input, char* output){
    
    FILE* fh = fopen(input,"r+");
    FILE* wh = fopen(output,"w+");

    if(!fh){
        fprintf(stdout,"Could not open input file\n");
        return;
    }
    if(!wh){
        fprintf(stdout,"Could not open output file\n");
        return;
    }

    int moviesCount = 0;
    int actorsCount = 0;

    char buffer[255]={'\0'};

    Graph* graph = initializeGraph();

    fscanf(fh,"%d ",&moviesCount);
    /*fprintf(stdout,"%d\n",moviesCount); */


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
        createLists(&graph,&bufferList);
        pairActorsInList(&graph,&bufferList);
        freeAdjList(&bufferList);
    }
   /* printGraphNodes(&graph);*/

    int components = 0;
    int currentSize = graph->currentSize;
    for(i = 0; i < currentSize; i++){
        if(!graph->lists[i]->head->visited){
            components++;
            visitDFS(&graph,&(graph->lists[i]));
            printf("Finished\n");
        }
    }
    printf("There are %d components\n",components);

    resetVisitedStatus(&graph);
    
    fprintf(wh,"%d\n",components);

    
    freeGraph(&graph);
    fclose(fh);
    fclose(wh);

}