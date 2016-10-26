#include <expat.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "../include/phonebook.h"
#include "../include/names.h"

#define BUFFER_SIZE 500

typedef struct data_s {
    phonebook_t *book;
    size_t number_cnt;
} data_t;

void push_back_human(phonebook_t *book, human_t *human){   
    if (book -> size == book -> capacity){
        book -> capacity *= 2;
        book -> humans = realloc(book -> humans, sizeof(human_t) * book -> capacity);
    }        
    (book -> humans)[book -> size++] = *human;
}

void start_element(void *data, const char *element, const char **attribute) {
    if (strcmp(element, "human") == 0){
        human_t new_human;
        char * str = (char *)attribute[1];
        strcpy(new_human.name, strtok(str, " "));
        strcpy(new_human.middle_name, strtok(NULL, " "));
        strcpy(new_human.family_name, strtok(NULL, " "));
        new_human.numbers_cnt = 0;
        data_t *cur_data = (data_t *) data;
        push_back_human(cur_data -> book, &new_human);        
    }    
}

void get_number(const char *content, char * dest, int length){
    int cnt = 0;
    for (int i = 0; i < length; i++){
        char c = content[i];
        if (c != '\0' && c != '\t' && c != '\n' && c != 10 && c != ' '){
            *(dest++) = c;
            cnt++;
        }
    }
    *dest = '\0';
}

void end_element(void *data, const char *element) {
    if (strcmp(element, "human") == 0){
        data_t *cur_data = (data_t *) data;
        cur_data -> number_cnt = 0;    
    }
}

void handle_data(void *data, const char *content, int length) {
    data_t *cur_data = (data_t *) data;
    phonebook_t *book = cur_data -> book;
    
    if (book -> size > 0){
        char * number = malloc((length + 1) * sizeof(char));
        get_number(content, number, length);
    
        if (strlen(number)){
            strcpy((book -> humans)[book -> size - 1].phones[cur_data -> number_cnt++], number);
            (book -> humans)[book -> size - 1].numbers_cnt++;
        }
        
        free(number);
    }    
}

int compar (const void * a, const void * b){
    human_t* h1 = (human_t *) a;
    human_t* h2 = (human_t *) b;
    
    if (strcmp(h1 -> family_name, h2 -> family_name) == 0){
        if (strcmp(h1 -> name, h2 -> name) == 0){
            return strcmp(h1 -> middle_name, h2 -> middle_name);
        }
        return strcmp(h1 -> name, h2 -> name);
    }
    return strcmp(h1 -> family_name, h2 -> family_name);
}

int load_phonebook_xml(const char *filename, phonebook_t *book){
    char buff[BUFFER_SIZE];
    
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open input file\n");
        return 1;
    }

    data_t data;
    data.book = book;
    data.number_cnt = 0;
    
    XML_Parser parser = XML_ParserCreate(NULL);
    XML_SetUserData(parser, &data);
    XML_SetElementHandler(parser, start_element, end_element);
    XML_SetCharacterDataHandler(parser, handle_data);
    
    memset(buff, 0, BUFFER_SIZE);

    size_t len = 0;
    int done = 0;
    do {
        len = fread(buff, sizeof(char), BUFFER_SIZE, fp);
        done = len < BUFFER_SIZE;

        if (XML_Parse(parser, buff, len, done) == XML_STATUS_ERROR) {
            printf("Error: %s\n", XML_ErrorString(XML_GetErrorCode(parser)));
            return 2;
        }
    } while (!done);

    qsort(data.book -> humans, data.book -> size, sizeof(human_t), compar);
    XML_ParserFree(parser);
    fclose(fp);
    
    return 0;
}

int save_phonebook_xml(const char *filename, phonebook_t *book){
    FILE *fp = fopen(filename, "w");
    
    if (fp == NULL){
        //printf("Failed to open output file");
        return 1;
    }
    
    fprintf(fp, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    fprintf(fp, "<phonebook>\n");
    
    for(int i = 0; i < book -> size; i++){
        human_t cur_human = (book -> humans)[i];
        
        fprintf(fp, "\t<human name=\"%s %s %s\">\n", cur_human.name, cur_human.middle_name, cur_human.family_name);
        for(int j = 0; j < cur_human.numbers_cnt; j++){
            if (strlen(cur_human.phones[j]) > 0){
               fprintf(fp, "\t\t<phone>%s</phone>\n", cur_human.phones[j]);
            }
        }
        fprintf(fp, "\t</human>\n");
    }
    fprintf(fp, "</phonebook>\n");
    fclose(fp);
}

void print_phonebook(phonebook_t *book){
    printf("%zu\n", book -> size);
    for(int i = 0; i < book -> size; i++){
        printf("name: ");
        
        printf("%s\n", (book -> humans)[i].name);
        printf("middle name: ");
        printf("%s\n", (book -> humans)[i].middle_name);
        printf("family name: ");
        printf("%s\n", (book -> humans)[i].family_name);

        for(int j = 0; j < ((book -> humans)[i]).numbers_cnt; j++){
            if (strlen((book -> humans)[i].phones[j])){
                printf("phone: ");
                printf("%s\n", (book -> humans)[i].phones[j]);
            }
            else{
                break;
            }
        }    
    }    
}

void gen_phonebook(phonebook_t *book, size_t size){
    srand(time(NULL));
    
    clear_phonebook(book);
    
    book = malloc(sizeof(phonebook_t));
    
    book -> size = 0;
    book -> capacity = 1;
    book -> humans = malloc(sizeof(human_t));
    
    for (int i = 0; i < size; i++){
        human_t new_human;
        
        int name_ind = rand() % NAMES_CNT;
        int family_ind = rand() % FAMILY_NAMES_CNT;
        int middle_ind = rand() % MIDDLE_NAMES_CNT;
        new_human.numbers_cnt = 0;
        strcpy(new_human.name, kNames[name_ind]);
        strcpy(new_human.family_name, kFamilyNames[family_ind]);
        strcpy(new_human.middle_name, kMiddleNames[middle_ind]);
        
        size_t number_cnt = rand() % 9 + 1;
        
        for(int j = 0; j < number_cnt; j++){
            int len = rand() % 19 + 1;
            
            for(int k = 0; k < len; k++){
                int r = rand() % 10;
                new_human.phones[j][k] = r + '0';
                new_human.numbers_cnt++;    
            }
            
            new_human.phones[j][len] = '\0';     
        }
        
        new_human.numbers_cnt = number_cnt;
        push_back_human(book, &new_human);
    }   
}

void clear_phonebook(phonebook_t *book){
    free(book -> humans);
    free(book);
}


human_t get_human(phonebook_t *book, char* family_name){
    for(int i = 0; i < book -> size; i++){
        if (strcmp(book -> humans[i].family_name, family_name) == 0){
            return book -> humans[i];
        }
    }
}
