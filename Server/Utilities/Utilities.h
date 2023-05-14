#ifndef UTILITIES_H
#define UTILITIES_H

#define DIMBUFF 1500

#include "postgresql/libpq-fe.h"
#include "cqueue.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>



char* getNewToken(char** string);

int connectSocket(int mySocket, struct sockaddr_in serverAddr);

int getSocket();

#endif