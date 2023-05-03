#ifndef FRIENDADMIN_H
#define FRIENDADMIN_H

#include "utilities/utilities.h"
#include "server.h"


extern pthread_mutex_t friendAdminMutex;
extern pthread_mutex_t msgSenderMutex;
extern pthread_mutex_t connectionMutex;
extern pthread_mutex_t clientsMutex;

extern CQueue* msgSenderQueue;
extern PGconn* connection;
extern node* clients;

char* SearchUser(char* msg);
char* AddFriend(char* msg);
char* RemoveFriend(char* msg);
char* ShowFriends(char* msg);
char* ShowFriendRequests(char* msg);
void AcceptFriendRequest(char* msg);
void RejectFriendRequest(char* msg);

void* friendAdmin(void* friendAdminQueue);

#endif