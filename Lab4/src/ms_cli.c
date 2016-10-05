#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/mergesort.h"

int cmpr_int(const void * a,const void* b){
  return *((int*)a) - *((int*)b);
}

int cmpr_char(const void* a,const void* b){
  return *((unsigned char*)a) - *((unsigned char*)b);
}

int cmpr_string(const void* a,const void* b){
  return strcmp(*((char**)a), *((char**)b));
}

int string_to_int(char* s){
  int ans = 0;
  int sgn = 1;
  if (*s == '-') sgn = -1;
  for (int i = (1-sgn)/2; *(s + i) != '\0'; i++){
    ans = ans * 10 + (int)(*(s + i))-(int)'0';
  }
  return ans * sgn;
}
int main(int argc,  char* argv[]){
  if (strcmp(argv[1], "int") == 0){
    int *a = malloc((argc - 2) * sizeof(int)); 
    for(int i = 0; i < argc - 2; i++) *(a+i) = string_to_int(argv[i + 2]);
    mergesort(a, argc - 2, sizeof(int), cmpr_int);
    for(int i = 0; i < argc - 2; i++) printf("%d ", a[i]);
    free(a);    
  }
  else if (strcmp(argv[1], "char") == 0){
    char *a = malloc((argc - 2) * sizeof(char)); 
    for(int i = 0; i < argc - 2; i++) *(a+i) = *(argv[i + 2]);
    mergesort(a, argc - 2, sizeof(char), cmpr_char);
    for(char* i = a; i < a + argc - 2; i++) printf("%c ", *i);
    free(a);    
  }
  else{
    char **a = malloc(sizeof(char*) * (argc - 2)); 
    for(int i = 0; i < argc - 2; i++) *(a+i) = (argv[i + 2]);
    mergesort(a, argc - 2, sizeof(char*), cmpr_string);
    for(char** i = a; i < a + argc - 2; i++) printf("%s ", *i);
    free(a);    
  }    
  return 0;
}
