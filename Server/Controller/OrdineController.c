#include "OrdineController.h"

void* ordineController(){
    char *msg, *command = malloc(sizeof(char)*DIMBUFF), *result = malloc(sizeof(char)*DIMBUFF);

    int socket;

    while(1){
        pthread_mutex_lock(&ordineMutex);
        
        if(!cqueue_is_empty(ordineQueue)){

            result = memset(result, 0, sizeof(char)*DIMBUFF);
            
            msg  = (char*)cqueue_pop(ordineQueue);
            socket  = (int)cqueue_pop(ordineQueue);
            pthread_mutex_unlock(&ordineMutex);
                
            command = strtok(NULL, "$$");

            if(strcmp(command, "getCarrello") == 0)
                getCarrello(strtok(NULL, "$$"), result);

            if(strcmp(command, "addBevandaToOrdine") == 0){
                char* bevanda = strtok(NULL, "$$");
                char* username = strtok(NULL, "$$");
                addBevandaToOrdine(bevanda, username);
            }

            if(strcmp(command, "removeBevandaFromOrdine") == 0){
                char* bevanda = strtok(NULL, "$$");
                char* username = strtok(NULL, "$$");
                removeBevandaFromOrdine(bevanda, username);
            }

            if(strcmp(command, "chiudiOrdine") == 0)
                chiudiOrdine(strtok(NULL, "$$"));

            
            write(socket, result, strlen(result));
            close(socket);
        }

        pthread_mutex_unlock(&ordineMutex);
    }

    free(command);
    free(result);
    pthread_exit(NULL);
}