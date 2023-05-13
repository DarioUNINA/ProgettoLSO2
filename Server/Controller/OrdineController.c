#include "OrdineController.h"

void* ordineController(){
    char *msg, *command = malloc(sizeof(char)*DIMBUFF), *result = malloc(sizeof(char)*DIMBUFF);

    int socket;

    while(1){
        pthread_mutex_lock(&ordineMutex);
        
        if(!cqueue_is_empty(ordineQueue)){
            
            msg  = (char*)cqueue_pop(ordineQueue);
            socket  = (int)cqueue_pop(ordineQueue);
            pthread_mutex_unlock(&ordineMutex);
                
            command = strtok(NULL, "$$");

            if(strcmp(command, "getCarrello") == 0)
                getOrdini(strtok(NULL, "$$"), result);

            
            write(socket, result, DIMBUFF);
        }
        pthread_mutex_unlock(&ordineMutex);
    }

    free(command);
    free(result);
    pthread_exit(NULL);
}