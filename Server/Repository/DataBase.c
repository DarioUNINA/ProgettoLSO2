#include "DataBase.h"

void getDBConnection(){
    connection = PQconnectdb("user=postgres password=password dbname=LSO host=localhost");

    if (PQstatus(connection) == CONNECTION_BAD){
        fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(connection));
    }else{
        printf("Connection to database successful\n");
        connectionMutex  = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
    }
}


PGresult* runQuery(char* strings[]){    
    int size = 0, i=0, j, k=0;

    while(strings[i] != NULL){
        size+=strlen(strings[i]);
        i++;
    }

    char query[size+1];

    i=0;

    while(strings[i] != NULL){
        j=0;
        while(strings[i][j] != '\0'){
            query[k] = strings[i][j];
            k++;
            j++;
        }
        i++;
    }

    query[k]='\0';

    printf("La query è: %s\n", query);

    pthread_mutex_lock(&connectionMutex);
    PGresult* res = PQexec(connection, query);
    pthread_mutex_unlock(&connectionMutex);

    return res;
}