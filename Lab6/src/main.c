#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include "../include/phonebook.h"

int main(int argc, char* argv[]){
    srand(time(NULL));
    
    phonebook_t * book = malloc(sizeof(phonebook_t));
    
    book -> size = 0;
    book -> capacity = 1;
    book -> humans = malloc(sizeof(human_t));
    
    load_phonebook_xml(argv[1], book);
    print_phonebook(book);
    gen_phonebook(book, rand() % 256);
    save_phonebook_xml(argv[2], book);
    clear_phonebook(book);

}
