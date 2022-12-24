/**
 * @author      : HackOlympus (zeus@hackolympus)
 * @file        : linkedList
 * @created     : Friday Dec 23, 2022 12:58:01 MST
 */
#include <stdio.h>
#include <stdlib.h>

struct node_t{
    int value;
    struct node_t* next;
}; 

typedef struct node_t node ;

node* start = NULL;  // start pointer is NULL when not initialized
node* last = NULL; // last node 
size_t size = 0; // size of linked list

void linkedlist_print() {
    node* n = start;
    int i=0; 
    printf("Start\n");
    while (n != NULL) {
        printf("%d => %d\n", i, n->value);
        n = n->next;
        i++;
    }
    printf("End\n\n");
}

int insert_node(int value) {
    node* n = (node*) malloc(sizeof(node)); 
    if (n == NULL) {
        printf("insert_node malloc failed\n");
        return -1; 
    }
    n->value = value; 
    n->next = NULL;
    
    // if this is first element then point start pointer to it  
    if (start == NULL) 
        start = n; 
    
    // if this is last element the point last pointer to it 
    if (last == NULL) { 
        last = n; 
    } else {
        last->next = n; // else point last pointer's next value to n
        last = n; // and update last pointer 
    }
    size++;
    return 0;
}

int delete_node_first() {
    node* n = start; 
    start = start->next; 
    free(n);
    size--; 
    return 0; 
}

int delete_node(int index) {
    if (index > (size-1)) {
        printf("index more that size"); 
        return -1;
    } 
    
    if (index == 0) {
        delete_node_first();
        return 0; 
    }
    
    int i=0; 
    node* p = NULL; // previous 
    node* n = start;
    
    // l1 -> l2 -> l3 -> l4   
    while (i != index) {
        p = n; 
        n = n->next; 
        i++;
    }
    
    // l1 -> l3 -> l4 
    p->next = n->next;
    free(n); // free (l2) 
    size--;
    return 0;
}

int search_node(int value) {
    int index = 0;
    node* n = start; 

    while (n != NULL) {
        if (n->value == value) 
            return index;  
        index++;
        n = n->next;
    }
    
    return -1; 
}

int main (int argc, char *argv[])
{
    insert_node(10);
    insert_node(20);
    insert_node(30);
    insert_node(40);
    linkedlist_print();
    
    printf("%d @ %d\n\n", 50, search_node(50));

    printf("deleting first node\n");
    delete_node(0);
    linkedlist_print();
   
    printf("deleting last node\n");
    delete_node(size-1); // delete last 
    linkedlist_print();
   
    printf("deleting node at index 1\n"); 
    delete_node(1);
    linkedlist_print();
    
    return 0;
}
