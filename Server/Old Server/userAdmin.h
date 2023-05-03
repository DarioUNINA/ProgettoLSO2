#ifndef USERADMIN_H
#define USERADMIN_H

#include "utilities/utilities.h"
#include "server.h"

#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


extern pthread_mutex_t userAdminMutex;
extern pthread_mutex_t msgSenderMutex;
extern pthread_mutex_t connectionMutex;
extern pthread_mutex_t clientsMutex;

extern CQueue* msgSenderQueue;
extern PGconn* connection;
extern node* clients;

char* LogIn(char* msg);
char* CreateUser(char* msg);
char* DeleteUser(char* msg);
char* ChangePwd(char* msg);
char* ForgotPwd(char* msg);
char* GetQuestion(char* msg);
char* GetAllQuestions(char* msg);

void* userAdmin(void* userAdminQueue);


#endif