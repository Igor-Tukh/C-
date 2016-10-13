#include "../include/position.h"
#include "stdio.h"
#include "stddef.h"
#include "string.h"
#include "stdlib.h"

#define container_of(ptr, type, member) (type*)((char*)(ptr) - offsetof(type, member))

void count(struct intrusive_node *inode, void* arg){
    int *intarg = (int *)arg;
    (*intarg)++;    
}

void print(struct intrusive_node *inode, void* arg){
    struct position_node *pnode = container_of(inode, struct position_node, node);
    char *outputformat = (char*)arg;
    printf(outputformat, pnode -> x, pnode -> y);
}
    
void apply(struct intrusive_list *lst, void (*op)(struct intrusive_node *node, void *), void *arg){
    struct intrusive_node *cur = lst -> head;
    while (cur -> next != NULL) cur = cur -> next;
    while (cur != NULL){
        op(cur, arg);      
        cur = cur -> prev;          
    }   
}

// To make numbers signed we will use ones complemention method

int read_from_bin(FILE *fname){
    int a = 0;
    int ans = 0;
    for (int i = 0; i < 3; i++){
        if (fread(&a, sizeof(char), 1, fname) == 1){
            ans += (a << (i * 8));
        }
        else{
            return (1 << 25);
        }        
    }
    if ((ans >> 23) == 1){
        ans = ans - ((1 << 24) - 1);
    }
    return ans;
}

void write_to_bin(FILE *fname, int val){
    if (val < 0) val = ((1 << 24) - 1) + val;
    for (int i = 0; i < 3; i++){
        char write_val = (char)(val & ((1 << 8) - 1));
        fwrite(&write_val, sizeof(char), 1, fname);
        val = val >> 8;            
    }
}

int main(int argc,  char* argv[]){
    struct intrusive_list data;
    init_list(&data);
    
    int x, y;    
    if (strcmp(argv[1], "loadtext") == 0){
        FILE *f = fopen(argv[2], "r");    
        while (fscanf(f, "%d %d\n", &x, &y) == 2){
            add_position(&data, x, y);
        }
        fclose(f);
    }
    else{
        FILE *f = fopen(argv[2], "rb");    
        x = read_from_bin(f);
        while (x != (1 << 25)){
            y = read_from_bin(f);
            add_position(&data, x, y);
            x = read_from_bin(f);
        }           
        fclose(f);
    }    
   
    if (strcmp(argv[3], "savetext") == 0){
        FILE *f = fopen(argv[4], "w"); 
        struct intrusive_node *cur = (&data) -> head;
        while (cur -> next != NULL) cur = cur -> next;
        while (cur != NULL){
            struct position_node *pnode = container_of(cur, struct position_node, node);
            fprintf(f, "%d %d\n", pnode -> x, pnode -> y);
            cur = cur -> prev;
        }
        fclose(f);
    }
    else if (strcmp(argv[3], "savebin") == 0){
        FILE *f = fopen(argv[4], "wb"); 
        struct intrusive_node *cur = (&data) -> head;
        while (cur -> next != NULL) cur = cur -> next;
        while (cur != NULL){
            struct position_node *pnode = container_of(cur, struct position_node, node);
            write_to_bin(f, pnode -> x);
            write_to_bin(f, pnode -> y);
            cur = cur -> prev;
        }
        fclose(f);
    } else if (strcmp(argv[3], "count") == 0){
        int counter = 0;
        apply(&data, count, &counter);
        printf("%d\n", counter);   
    } else if (strcmp(argv[3], "print") == 0){
        apply(&data, print, argv[4]);
    }
    remove_all_positions(&data);   
    return 0;
}
