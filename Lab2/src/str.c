#include <stddef.h>
#include "../include/str.h"

char * strcpy(char * destination, const char * source){
    char *destcopy = destination;
    char *sourcecopy = source;
    while(*sourcecopy){
        *destcopy = *sourcecopy;
        sourcecopy++;
        destcopy++;
    }
    *destcopy = '\0'; 
    return destination;
}

char * strcat(char * destination, const char * source){
    char *tail = destination;
    while (*tail) tail++;   
    char *sourcecopy = source;
    while (*sourcecopy){
        *tail = *sourcecopy;
        tail++;
        sourcecopy++;    
    }
    *tail = '\0';
    return destination;     
}

int strcmp(const char * str1, const char * str2){
    char *str1copy = str1;
    char *str2copy = str2;
    while (*str1copy && *str1copy == *str2copy){
        str1copy++;
        str2copy++; 
    }
    return *str1copy - *str2copy;
}

size_t strlen(const char * str){
	char * cur = str;
    while(*cur) cur++;
    return str - cur;
}


