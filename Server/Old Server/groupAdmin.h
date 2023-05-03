#ifndef GROUPADMIN_H
#define GROUPADMIN_H

#include "utilities/utilities.h"
#include "server.h"


extern pthread_mutex_t groupAdminMutex;
extern pthread_mutex_t msgSenderMutex;
extern pthread_mutex_t connectionMutex;
extern pthread_mutex_t clientsMutex;

extern CQueue* msgSenderQueue;
extern PGconn* connection;
extern node* clients;

char* CreateGroup(char* msg);
void DeleteGroup(char* msg);
char* SearchGroup(char* msg);
char* JoinGroup(char* msg);
void LeaveGroup(char* msg);
char* GetGroupMembers(char* msg);
char* GetGroupRequests(char* msg);
void AcceptGroupRequests(char* msg);
void RejectGroupRequests(char* msg);

void* groupAdmin(void* groupAdminQueue);


#endif