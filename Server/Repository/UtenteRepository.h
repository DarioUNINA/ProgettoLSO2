#ifndef UTENTEREPOSITORY_H
#define UTENTEREPOSITORY_H

#include "DataBase.h"

extern PGconn* connection;
extern pthread_mutex_t connectionMutex;

#endif