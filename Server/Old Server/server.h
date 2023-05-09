#ifndef SERVER_H
#define SERVER_H

#include "userAdmin.h"
#include "sendMsg.h"
#include "groupAdmin.h"
#include "friendAdmin.h"
#include "utilities/utilities.h"
#include "cqueue.h"

#include <pthread.h>
#include <unistd.h>
#include <sys/queue.h>

PGconn* connection;
CQueue* userAdminQueue;
CQueue* groupAdminQueue;
CQueue* friendAdminQueue;
CQueue* msgSenderQueue;


pthread_t userAdminThread;
pthread_t groupAdminThread;
pthread_t friendAdminThread;
pthread_t msgSenderThread;


PGresult* runQuery(char* strings[]);

char* getCommand(char** msg);

void executeCommand(char* msg);

void receiveClientData(int mySocket);

void startThreads();

PGconn* getDBConnection();

void init();

void start();

#endif