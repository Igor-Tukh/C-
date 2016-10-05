#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void cpy(size_t size, void*to, void*from){
  char* a = (char*)to;
  char* b = (char*)from;
  
  for(int i = 0; i < size; i++) *(a + i) = *(b + i);
}

int mergesort (void* base, size_t num, size_t size, int (*compar)(const void*,const void*)){
  if (num > 1){
    size_t mid = num / 2;
    
    mergesort(base, mid, size, compar);
    mergesort((void *)((char *)base + mid * size), num - mid, size, compar);
    
    char *b = malloc(num * size);
    char *i1 = base;
    char *i2 = (char*)base + mid*size;
    char *last1 = i2;
    char *last2 = (char*)base + num*size;
    
    for(int i = 0; i < num; i++){
      if (i2 >= last2 || (i1 < last1 && compar((void*)i1, (void*)i2) <= 0)){
        cpy(size, b+i*size, i1);        
        i1 += size;
      }
      else{
        cpy(size, b+i*size, i2);
        i2 += size;
      }
    }
    
    cpy(num * size, base, (void*)b);  
    free(b);
  }
  return 0;
}
