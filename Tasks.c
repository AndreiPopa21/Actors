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

    Graph* graph = initializeGraph();
    
    /*create the graph using the input file*/
    createGraph(&graph,fh);
   
    int i;
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

void TaskTwo(char* input, char* output){
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

    fclose(fh);
    fclose(wh);
}