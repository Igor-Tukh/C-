#include "../include/clist.h"
#include "stdio.h"
#include "stddef.h"
#include "string.h"
#include "stdlib.h"

#define container_of(ptr, type, member) (type*)((char*)(ptr) - offsetof(type, member))

struct position_node {
  int x, y;
  struct intrusive_node node;
};

void remove_position(struct intrusive_list *lst, int x, int y) {
  struct intrusive_node *cur = lst -> head;
  while (cur != NULL){
    struct position_node *pnode = container_of(cur, struct position_node, node);
    struct intrusive_node *next = cur-> next;
    if (pnode -> x == x && pnode -> y == y){
      remove_node(lst, cur);
      free(pnode);   
    }
    cur = next;
  }
}

void add_position(struct intrusive_list *lst, int x, int y) {
  struct position_node *newnode = malloc(sizeof(struct position_node));
  newnode -> x = x;
  newnode -> y = y;
  add_node(lst, &(newnode-> node));
}

void show_all_positions(struct intrusive_list *lst) {
  struct intrusive_node *cur = lst -> head;
  while (cur != NULL){
    struct position_node *pnode = container_of(cur, struct position_node, node);
    printf("(%d %d) ", pnode -> x, pnode -> y);
    cur = cur -> next;
  }
  printf("\n");
}

void remove_all_positions(struct intrusive_list *lst) {
  struct intrusive_node *cur = lst -> head;
  while (cur != NULL){
    struct position_node *pnode = container_of(cur, struct position_node, node);
    struct intrusive_node *next = cur -> next;
    remove_node(lst, cur);
    free(pnode);
    cur = next;   
  }
}
