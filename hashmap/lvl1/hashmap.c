/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : hashmap
 * @created     : Thursday Dec 22, 2022 23:55:38 MST
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HASHMAP_SIZE 20 
#define MAX_NAME_LEN 256 

#define unreserved 0 
#define reserved 1

typedef struct {
    char name[MAX_NAME_LEN]; 
    int age;
    int status;
} entry; 

typedef struct {
    size_t size; 
    entry** entries; 
} hashmap;

hashmap* map; 

hashmap* init_hashmap() {
    hashmap* map = (hashmap*) malloc(sizeof(hashmap));
    map->size = MAX_HASHMAP_SIZE; 
    map->entries = calloc(MAX_HASHMAP_SIZE,sizeof(entry)); 
    return map;
}

unsigned int hash_function(char* name) {
    unsigned int hash = 0x1337; 
    char c; 
    while ((c = *name++)) {
        hash += c; 
    }
    return hash % MAX_HASHMAP_SIZE; 
}

int hashmap_put(char* name, int age) {
    unsigned int ind = hash_function(name); 
    entry* e = malloc(sizeof(entry));
    strncpy(e->name, name, MAX_NAME_LEN); 
    e->age = age; 
    e->status = reserved;
    map->entries[ind] = e;
    return 0; 
}

void hashmap_print() {
    printf("Start\n");
    for (int i=0; i < MAX_HASHMAP_SIZE; i++) {
        entry* e = map->entries[i];
        if (e != NULL) {
            printf("%s => %d\n", e->name, e->age);
        } else {
            printf("-----\n");
        }
    }
    printf("End\n");
}

int main (int argc, char *argv[])
{
    printf("%u\n", hash_function("Vishal"));
    map = init_hashmap(); 
    hashmap_put("Vishal", 14);
    hashmap_print();
    return 0;
}
