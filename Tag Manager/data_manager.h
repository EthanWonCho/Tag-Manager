//
//  data_manager.h
//  Tag Manager
//
//  Created by Ethan Cho on 8/15/24.
//  Last edited by Ethan Cho on 8/15/24.
//

#ifndef data_manager_h
#define data_manager_h

#include <stdlib.h>

typedef struct element {
    int contents;
} Element;

typedef struct storage {
    int size;
    Element* elements;
} Storage;

Storage* init_storage(void) {
    Storage *new_storage = (Storage*)malloc(sizeof(Storage));
    if(!new_storage) return NULL;
    new_storage->size = 2;
    new_storage->elements = (Element*)malloc(2 * sizeof(Element));
    if(!new_storage->elements) return NULL;
    return new_storage;
}

// Conditions
int isinfo(char* tagname) {
    printf("telling if tagname \"%s\" is info or not.\n", tagname);
    return 0;
}


// Verbs
int include_file(char *category, int number) {
    printf("included %s of %d\n", category, number);
    return 0;
}

int add_tag(char *category, int number, char *tagname) {
    printf("added TAG of category \"%s\", number %d and tagname \"%s\".\n", category, number, tagname);
    return 0;
}

int add_info(char *category, int number, char *tagname, char *tagcontents) {
    printf("added INFO of category \"%s\", number %d, tagname \"%s\", tagcontents \"%s\".\n", category, number, tagname, tagcontents);
    return 0;
}

int data_end(void) {
    
    return 0;
}

// Findings

// Cleanups
void free_element(Element *e) {
    e->contents = 1;
}

void free_storage(Storage *s) {
    for(int i=0;i<s->size;++i) {
        free_element(&(s->elements[i]));
    }
    free(s);
    return;
}

#endif /* data_manager_h */
