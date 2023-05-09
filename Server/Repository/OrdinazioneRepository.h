#ifndef ORDIANZIONEREPOSITORY_H
#define ORDIANZIONEREPOSITORY_H

#include "DataBase.h"

extern PGconn* connection;
extern pthread_mutex_t connectionMutex;

#endif