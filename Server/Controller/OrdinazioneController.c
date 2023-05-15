#include "OrdinazioneController.h"

void* ordinazioneController(){
    
    char *msg, *command = malloc(sizeof(char)*DIMBUFF), *result = malloc(sizeof(char)*DIMBUFF);

    int socket;

    while(1){
        pthread_mutex_lock(&ordinazioneMutex);
        
        if(!cqueue_is_empty(ordinazioneQueue)){

            result = memset(result, 0, sizeof(char)*DIMBUFF);
            
            msg  = (char*)cqueue_pop(ordinazioneQueue);
            socket  = (int)cqueue_pop(ordinazioneQueue);
            pthread_mutex_unlock(&ordinazioneMutex);
                
            command = strtok(NULL, "$$");

            
            write(socket, result, strlen(result));
            close(socket);

        }
        pthread_mutex_unlock(&ordinazioneMutex);
    }

    free(command);
    free(result);

    pthread_exit(NULL);
}