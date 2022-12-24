/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : hashmap
 * @created     : Wednesday Dec 21, 2022 11:54:40 MST
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME_LEN 256
#define MAX_HASHMAP_LEN 20

#define free 0
#define reserved 1

typedef struct {
    char* key;  
    int value; 
    int status;
    struct entry* next; 
} entry;

typedef struct {
    size_t size; 
    entry** entries; // pointer to pointer to entry  
} hashmap; 

hashmap* map;

unsigned int hash_function(char* name)
{
    unsigned int hash = 0x1337;
    char c; 
    while ((c = *name++)) { 
        hash += c;
    }
    return hash % MAX_HASHMAP_LEN;
}

hashmap* init_hashmap()
{
    hashmap* m = malloc(sizeof(hashmap)); 
    m->size = MAX_HASHMAP_LEN;
    m->entries = calloc(sizeof(entry), MAX_HASHMAP_LEN);
    return m; 
}

void print_hashmap()
{
    printf("Start\n");
    entry* e; 
    while ((e = *map->entries++) != NULL) {       
        if (e->status == free) {
            printf("-----\n");
        } else {
            printf("%s => %d\n", e->key, e->value);
        }
    }
    printf("End\n");
}

int hashmap_put(char* key, int value) 
{
    unsigned int ind = hash_function(key); 
    entry* e = map->entries[ind];
    if (e->status == free) {
        e->status = reserved; 
        e->key = key; 
        e->value = value; 
        e->next = NULL; 
    } else {
        return -1; 
    }
    return 0; 
}


// int insert_element(char* person_name, int person_age)
// {
//     unsigned int hash = hash_function(person_name);
//     if (hashmap[hash]->status == free) {
//         strncpy(hashmap[hash]->name, person_name, MAX_NAME_LEN);
//         hashmap[hash]->age = person_age;
//         hashmap[hash]->status = reserved;
//     } else {
//         int back_ind = hash - 1;
//         int front_ind = hash + 1;
//
//         while (back_ind > 0 && front_ind < MAX_HASHMAP_LEN && hashmap[front_ind]->status == reserved && hashmap[back_ind]->status == reserved) {
//             front_ind++;
//             back_ind--;
//         }
//
//         if (hashmap[front_ind]->status == free) {
//             strncpy(hashmap[front_ind]->name, person_name, MAX_NAME_LEN);
//             hashmap[front_ind]->age = person_age;
//             hashmap[front_ind]->status = reserved;
//         } else if (hashmap[back_ind]->status == free) {
//             strncpy(hashmap[back_ind]->name, person_name, MAX_NAME_LEN);
//             hashmap[back_ind]->age = person_age;
//             hashmap[back_ind]->status = reserved;
//         } else {
//             return -1;
//         }
//     }
//     return 0;
// }

// void delete_element(char* name)
// {
//     unsigned int hash = hash_function(name);
// }

// int value_lookup() {
//     return NULL;
//
// }

int main(int argc, char* argv[])
{
    map = init_hashmap();

    hashmap_put("Vishal", 10); 
    // insert_element("Vishal", 18);
    // insert_element("Umang", 20);
    // insert_element("Kumar", 21);
    // insert_element("Sammy", 22);
    // insert_element("Zeus", 18);
    // insert_element("Coolboy", 18);
    // insert_element("DukeNukem", 20);
    // insert_element("Wolfenstein", 15);
    //
    print_hashmap();
    return 0;
}
