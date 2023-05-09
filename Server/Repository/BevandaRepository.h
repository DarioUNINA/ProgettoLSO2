#ifndef BEVANDAREPOSITORY_H
#define BEVANDAREPOSITORY_H

#include "DataBase.h"

extern PGconn* connection;
extern pthread_mutex_t connectionMutex;

#endif