#include "linkedList.h"




//insert link at the first location
node* insert(node* head, client key) {

   if(head == NULL){
      head = (node*) malloc(sizeof(node));
      head->key = key;
      head->next = NULL;
      
   }else{
      node *link = (node*) malloc(sizeof(node));
      link->key = key;
      link->next = head;
      head = link;
   }

   return head;
}

//delete first item
node* deleteFirst(node *head) {

   node *tempLink = head->next;
   free(head);

   return head;
}

//is list empty
bool isEmpty(node *head) {
   return head == NULL;
}

int length(node *head) {
   int length = 0;
   node *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

//find a link with given key
node* find(node *head, client key) {

   //start from the first link
   node* current = head;

   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key.username != key.username) {
	
      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }      
	
   //if data found, return the current Link
   return current;
}

//delete a link with given key
node* deleteData(node *head, char* key) {

   //start from the first link
   node* current = head;
   node* previous = NULL;
	
   //if list is empty+
   
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key.username != key) {

      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->next;
   } else {
      //bypass the current link
      previous->next = current->next;
   }    

   free(current);
	
   return head;
}


node* getNode(){
   node* temp = (node*) malloc(sizeof(node));
   temp->next = NULL;
   return temp;

}