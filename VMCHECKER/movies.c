#include <stdio.h>
#include <stdlib.h>

#include "Tasks.h"

/*fisier sursa pentru rezolvarea primei probleme*/

int main(int argc, char* argv[]){

    /*verificarea a numarului corect de argumente*/
    if(argc == 4){
        fprintf(stdout,"You gave enough arguments\n");
        char* task = argv[1];
        char* inputFile = argv[2];
        char* outputFile = argv[3];

        printf("%s\n",task);

        /*verificarea fisierelor de input si output*/
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

        /*rezolvarea task-ului corespunzator*/
        if(!strcmp(task,"-c1")){
            fprintf(stdout,"First task\n");
            TaskOne(inputFile,outputFile);
        }else if(!strcmp(task,"-c2")){
            fprintf(stdout,"Second task\n");
            TaskTwo(inputFile,outputFile);
        }else if(!strcmp(task,"-c3")){
            fprintf(stdout,"Third task\n");
            TaskThree(inputFile,outputFile);
        }else if(!strcmp(task,"-b")){
            fprintf(stdout,"Bonus task\n");
        }else{
            fprintf(stdout,"No relevant task\n");
            exit(0);
        }
    }else{
        fprintf(stdout,"You did not provide enough arguments\n");
        exit(0);
    }
    return 0;
}