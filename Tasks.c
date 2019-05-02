#include "Tasks.h"

void TaskOne(char* input, char* output){
    
    FILE* fh = fopen(input,"r+");
    if(!fh){
        return;
    }
    int moviesCount = 0;
    int actorsCount = 0;

    char* movieTitle = NULL;
    char* actorName = NULL;
    char buffer[255]={'\0'};

    fscanf(fh,"%d ",&moviesCount);
    /*fprintf(stdout,"%d\n",moviesCount); */


    int i,j;
    for(i = 0; i < moviesCount; i++){
        /*movie title*/
        fgets(buffer,255,fh);
        AdjList* bufferList = (AdjList*)calloc(1,sizeof(AdjList));
        bufferList->head  = NULL;

        fprintf(stdout,"%s",buffer);
        /*actors count*/
        fscanf(fh,"%d ",&actorsCount);
        /*fprintf(stdout,"%d\n",actorsCount);*/
        
        /*each actor name*/
        for(j = 0; j < actorsCount; j++){
            fgets(buffer,255,fh);
            pushNode(&bufferList,buffer);
            /*fprintf(stdout,"%s",buffer);*/
           /* printf("Capul inca e: %s",bufferList->head->actorName);*/
        }
        printList(&bufferList);
        /*printf("%s ",bufferList->head->actorName);
        */freeAdjList(&bufferList);
    }
    fclose(fh);

}