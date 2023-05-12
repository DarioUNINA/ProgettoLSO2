#include "OrdineController.h"

void* ordineController(){
    char *msg, *command, *result;

    int socket;

    while(1){
        pthread_mutex_lock(&ordineMutex);
        
        if(!cqueue_is_empty(ordineQueue)){
            
            msg  = (char*)cqueue_pop(ordineQueue);
            socket  = (int)cqueue_pop(ordineQueue);
            pthread_mutex_unlock(&ordineMutex);
                
            command = strtok(NULL, "$$");

            // if(strcmp(command, "SearchUser") == 0){ //scrivere comandi
            //     result = SearchUser(msg);
            // }
            
        }
        pthread_mutex_unlock(&ordineMutex);
    }
}