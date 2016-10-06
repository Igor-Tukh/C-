#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void copy_mem(size_t size, void*to, void*from){
  char* a = (char*)to;
  char* b = (char*)from;
  
  for(size_t i = 0; i < size; i++){ 
    *(a++) = *(b++);
  }  
}

int mergesort (void* base, size_t num, size_t size, int (*compar)(const void*,const void*)){
  if (num <= 1) 
    return 0;
  
  size_t mid = num / 2;
    
  mergesort(base, mid, size, compar);
  mergesort((void *)((char *)base + mid * size), num - mid, size, compar);
    
  char *b = malloc(num * size);
  char *i1 = base;
  char *i2 = (char*)base + mid*size;
  char *last1 = i2;
  char *last2 = (char*)base + num*size;
   
  for(int i = 0; i < num; i++, b += size){
    if (i2 >= last2 || (i1 < last1 && compar((void*)i1, (void*)i2) <= 0)){
      copy_mem(size, b, i1);        
      i1 += size;
    }
    else{
      copy_mem(size, b, i2);
      i2 += size;
    }
  }
  
  b -= size * num;
    
  copy_mem(num * size, base, (void*)b);  
  free(b);
  
  return 0;
}
