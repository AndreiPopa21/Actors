#include <stdio.h>
#include <stdlib.h>

#include "Tasks.h"

int main(int argc, char* argv[]){

    if(argc == 4){
        fprintf(stdout,"You gave enough arguments\n");
    }else{
        fprintf(stdout,"You did not provide enough arguments\n");
        exit(0);
    }
    return 0;
}