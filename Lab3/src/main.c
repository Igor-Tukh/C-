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

void add_positon(struct intrusive_list *lst, int x, int y) {
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

int main() {
  char c[100];
  int x, y;
  
  struct intrusive_list points;
  init_list(&points);
  
  while (1){
    scanf("%s", c);
    if (strcmp(c, "add") == 0){
      scanf("%d", &x);      
      scanf("%d", &y);
      add_positon(&points, x, y);     
    }
    else if (strcmp(c, "rm") == 0){
      scanf("%d", &x);      
      scanf("%d", &y);
      remove_position(&points, x, y);             
    }
    else if (strcmp(c, "print") == 0){
      show_all_positions(&points);
    }
    else if (strcmp(c, "rma") == 0){
      remove_all_positions(&points);
    }
    else if (strcmp(c, "len") == 0){
      printf("%d\n", get_length(&points));
    }
    else if (strcmp(c, "exit")== 0){
      break;
    }
    else{
      printf("Unknown command\n");
    }    
  }
  remove_all_positions(&points);
}

