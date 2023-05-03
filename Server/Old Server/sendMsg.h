#ifndef SENDMSG_H
#define SENDMSG_H

#include "utilities/utilities.h"
#include "server.h"

extern pthread_mutex_t msgSenderMutex;
extern pthread_mutex_t connectionMutex;
extern pthread_mutex_t clientsMutex;

extern CQueue* msgSenderQueue;
extern PGconn* connection;
extern node* clients;


void* sendMsg();

#endif