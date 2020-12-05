// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_alloc() { //allocate space for the list_t and set the head to Null and return a pointer to it
  //ptr = (cast-type*) malloc(byte-size) using malloc
  list_t *myList = (list_t *) malloc(sizeof(list_t));
  
  return myList; 
}

void list_free(list_t *l) {
  node_t *dummy = (node_t *) malloc(sizeof(node_t));
  dummy = l->head;
  if(dummy == NULL){
    free(dummy);
  }
  while(dummy != NULL){
    dummy->next = NULL;
    dummy= dummy->next;
  }
  l->head = NULL;
  
}

void list_print(list_t *l) {
  node_t *temp = (node_t *) malloc(sizeof(node_t));
  temp = l->head;
 
  if(temp == NULL){
    printf("Empty LinkedList");
  }
  while(temp != NULL){
    printf("%d ->", temp->value);
    temp = temp->next;
  }
  printf("\n");
}


void list_add_to_back(list_t *l, elem value) {
  node_t *dummy = (node_t *) malloc(sizeof(node_t));
  dummy = l->head;
  
  node_t *temp = (node_t *) malloc(sizeof(node_t));
  temp->value = value;
  
  while(dummy != NULL){
    if(dummy->next == NULL){
      dummy->next = temp;
      temp->next = NULL;
    }
    dummy = dummy->next;
  }
}

void list_add_to_front(list_t *l, elem value) {
  node_t *temp = (node_t *) malloc(sizeof(node_t));
  
  temp->value = value;
  temp->next = l->head;
  l->head = temp;
  
}


int list_length(list_t *l){
  node_t *dummy = (node_t *) malloc(sizeof(node_t));
  dummy = l->head;
  
  if(dummy == NULL){
    return -1;
  }
  
  int counter = 0;
  while(dummy != NULL){
    counter += 1;
    dummy = dummy->next;
  }
  return counter;
}

void list_add_at_index(list_t *l, elem value, int index) {
  node_t *dummy = (node_t *) malloc(sizeof(node_t));
  dummy = l->head;
  
  if(dummy == NULL || index <= -1){
    return ;
  }
  
  node_t *temp = (node_t *) malloc(sizeof(node_t));
  temp->value = value;
  node_t *nxt = (node_t *) malloc(sizeof(node_t));
  
  
  while(dummy != NULL){
    if(index - 1 == 0){
      nxt = dummy->next;
      dummy->next = temp;
      temp->next = nxt;
    }
    index -= 1;
    dummy = dummy->next;
  }
    
}

elem list_remove_from_back(list_t *l) { 
  node_t *dummy = (node_t *) malloc(sizeof(node_t));
  dummy = l->head;
  
  if(dummy == NULL){
    return -1;
  }
  node_t *removedElem = (node_t *) malloc(sizeof(node_t));
  
  if(dummy->next == NULL){
    removedElem->value = dummy->value;
    dummy = NULL;
    return removedElem->value;
  }
  
  
  while(dummy->next->next != NULL){
    dummy = dummy->next;
  }
  
  removedElem->value = dummy->next->value;
  dummy->next = dummy->next->next;
  
  return removedElem->value;
   
}

elem list_remove_from_front(list_t *l) { 
  node_t *removedElem = (node_t *) malloc(sizeof(node_t));
  
  node_t *dummy = (node_t *) malloc(sizeof(node_t));
  dummy = l->head;
  
  if(dummy != NULL){
    removedElem->value = dummy->value;
    dummy = dummy->next;
    l->head = dummy;
    return removedElem->value;
  }
  
  return -1; 
}

elem list_remove_at_index(list_t *l, int index) { 
  node_t *dummy = (node_t *) malloc(sizeof(node_t));
  dummy = l->head;
  
  if(dummy == NULL || index <= -1){
    return ;
  }
  
  node_t *temp = (node_t *) malloc(sizeof(node_t));
  
  elem removedElem = 0;

  while(dummy != NULL){
    if(index - 2 == 0){
      temp = dummy->next->next;
      removedElem = dummy->next->value;
      dummy->next = temp;
      return removedElem;
    }
    index -= 1;
    dummy = dummy->next;
  }
  
  return -1; 
}

bool list_is_in(list_t *l, elem value) {
  node_t *dummy = (node_t *) malloc(sizeof(node_t));
  dummy = l->head;
  
  while(dummy != NULL){
    if(dummy->value == value){
      return true;
    }
    dummy = dummy->next;
  }
  return false; 
}


elem list_get_elem_at(list_t *l, int index) { 
  node_t *dummy = (node_t *) malloc(sizeof(node_t));
  dummy = l->head;
  
  if(dummy == NULL){
    return -1;
  }
  
  while(dummy != NULL){
    if(index - 1 == 0){
      return dummy->value;
    }
    index -= 1;
    dummy = dummy->next;
  }
  
}

int list_get_index_of(list_t *l, elem value) { 
  node_t *dummy = (node_t *) malloc(sizeof(node_t));
  dummy = l->head;
  
  if(dummy == NULL){
    return -1;
  }
  
  elem count = 1;
  while(dummy != NULL){
    if(dummy->value == value){
      return count;
    }
    dummy = dummy->next;
    count += 1;  
  }
  
}
