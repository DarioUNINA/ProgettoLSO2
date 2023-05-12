#include "BevandaController.h"

void* bevandaController(){

    char *msg, *command = malloc(sizeof(char)*DIMBUFF), *result = malloc(sizeof(char)*DIMBUFF);
    int socket;

    while(1){
        pthread_mutex_lock(&bevandaMutex);
        
        if(!cqueue_is_empty(bevandaQueue)){
            
            msg  = (char*)cqueue_pop(bevandaQueue);
            socket  = (int)cqueue_pop(bevandaQueue);
            pthread_mutex_unlock(&bevandaMutex);
                
            command = strtok(NULL, "$$");

            // if(strcmp(command, "SearchUser") == 0){ //scrivere comandi
            //     result = SearchUser(msg);
            // }
            
            write(socket, result, DIMBUFF);
        }
        pthread_mutex_unlock(&bevandaMutex);
    }

    free(command);
    free(result);
    pthread_exit(NULL);
}   