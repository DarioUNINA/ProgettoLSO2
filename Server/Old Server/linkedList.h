#ifndef LINKDED_LIST_H
#define LINKDED_LIST_H

#include "utilities/utilities.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node{;
   client key;
   struct node *next;

}node;


void printList(node *head);

node* insert(node* head, client key);

node* deleteFirst(node *head);

bool isEmpty(node *head);

int length(node *head);

node* find(node *head, client key);

node* deleteData(node *head, char* key);

node* getNode();

#endif