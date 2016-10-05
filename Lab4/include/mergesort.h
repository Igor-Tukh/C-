#include <stddef.h>

#ifndef MERGESORT_H
#define MERGESORT_H

int mergesort (void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

#endif
