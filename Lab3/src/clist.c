#include "../include/clist.h"
#include "stdlib.h"

void init_list(struct intrusive_list *lst){
  lst -> head = NULL;
}

void add_node(struct intrusive_list *lst, struct intrusive_node *node){
  node -> next = NULL;
  node -> prev = NULL;
  if (lst -> head != NULL){
    lst -> head -> prev = node;
    node -> next = lst -> head;
    lst -> head = node;
  }
  else{
    lst -> head = node;
  }
}

void remove_node(struct intrusive_list *lst, struct intrusive_node *node){
  if (!(node -> prev != NULL)){
    lst -> head = node -> next;
    if (node -> next != NULL) node -> next -> prev = NULL;
  }
  else if (node -> next != NULL){
      node -> prev -> next = node -> next;
      node -> next -> prev = node -> prev;
  }
  else{
    if (node -> prev != NULL) node -> prev -> next = NULL;  
  }
  
}

int get_length(struct intrusive_list *lst){
  int cnt = 0;
  struct intrusive_node *cur = lst -> head;
  
  while (cur != NULL){
    cur = cur -> next;
    cnt++;
  }
  
  return cnt;
}
