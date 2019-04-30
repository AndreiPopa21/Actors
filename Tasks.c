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
    fprintf(stdout,"%d\n",moviesCount); 


    int i,j;
    for(i = 0; i < moviesCount; i++){
        fgets(buffer,255,fh);
        fprintf(stdout,"%s",buffer);
        fscanf(fh,"%d ",&actorsCount);
        fprintf(stdout,"%d\n",actorsCount);
        
        for(j = 0; j < actorsCount; j++){
            fgets(buffer,255,fh);
            fprintf(stdout,"%s",buffer);
        }
    }
    fclose(fh);

}