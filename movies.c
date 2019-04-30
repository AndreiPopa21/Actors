#include <stdio.h>
#include <stdlib.h>

#include "Tasks.h"

int main(int argc, char* argv[]){

    if(argc == 4){
        fprintf(stdout,"You gave enough arguments\n");
        char* task = argv[1];
        char* inputFile = argv[2];
        char* outputFile = argv[3];

        printf("%s\n",task);

        FILE* input = fopen(inputFile,"r+");
        if(!input){
            fprintf(stdout,"Could not open input file\n");
            exit(0);
        }
        fclose(input);

        FILE* output = fopen(outputFile,"w+");
        if(!output){
            fprintf(stdout,"Could not open output file\n");
            exit(0);
        }
        fclose(output);

        if(!strcmp(task,"-c1")){
            fprintf(stdout,"First task\n");
            /*TaskOne(inputFile,outputFile);*/
        }else if(!strcmp(task,"-c2")){
            fprintf(stdout,"Second task\n");
        }else if(!strcmp(task,"-c3")){
            fprintf(stdout,"Third task\n");
        }else if(!strcmp(task,"-b")){
            fprintf(stdout,"Bonus task\n");
        }else{
            fprintf(stdout,"No relevant task\n");
            exit(0);
        }
        
        
        Graph* graph = initializeGraph();
        char* name1 = "Theon";
        char* name2 = "Sansa";
        char* name3 = "Bran";
        char* name4 = "Arya";
        AdjList* list = (AdjList*)calloc(1,sizeof(AdjList));
        pushNode(&list,name1);
        pushNode(&list,name2);
        pushNode(&list,name3);
        pushNode(&list,name1);
        createLists(&graph,&list);
        pairActorsInList(&graph,&list);
        freeAdjList(&list);
        
        list = (AdjList*)calloc(1,sizeof(AdjList));
        pushNode(&list,name2);
        pushNode(&list,name3);
        pushNode(&list,name4);
        createLists(&graph,&list);
        pairActorsInList(&graph,&list);
        freeAdjList(&list);
        

        printGraph(&graph);
        freeGraph(&graph);

    }else{
        fprintf(stdout,"You did not provide enough arguments\n");
        exit(0);
    }
    return 0;
}