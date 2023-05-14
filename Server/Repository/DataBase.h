
#ifndef DATABASE_H
#define DATABASE_H

#include "postgresql/libpq-fe.h"
#include <stdlib.h>
#include <string.h>
#include <pthread.h>



PGconn* connection;
pthread_mutex_t connectionMutex;


void getDBConnection();
PGresult* runQuery(char* strings[]);


#endif