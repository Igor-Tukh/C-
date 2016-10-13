#ifndef POSITION_H
#define POSITION_H

#include "clist.h"

typedef struct position_node {
    int x;
    int y;
    struct intrusive_node node;
} position_node;

void remove_position(struct intrusive_list *list, int x, int y);
void add_position(struct intrusive_list *list, int x, int y);
void show_all_positions(struct intrusive_list *list);
void remove_all(struct intrusive_list *list);
void remove_all_positions(struct intrusive_list *lst);

#endif
