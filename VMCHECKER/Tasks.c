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

    Graph* graph = initializeGraph();
    createGraph(&graph,fh);

    char* firstActor = (char*)calloc(255,sizeof(char));
    char* secondActor = (char*)calloc(255,sizeof(char));

    fgets(firstActor,255,fh);
    fgets(secondActor,255,fh);

    printf("%s",firstActor);
    printf("%s",secondActor);

    int m = visitBFS(&graph,&firstActor,&secondActor);

    if(!m){
        fprintf(wh,"-1");
    }else{
        fprintf(wh,"%d\n",m-1);
    }
    

    fclose(fh);
    fclose(wh);

    freeGraph(&graph);
    free(firstActor);
    free(secondActor);
}