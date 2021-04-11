/*
 -------------------------------------
 File:    hash.c
 Project: raox6250_a09

 -------------------------------------
 Author:  Nausher Rao
 ID:      190906250
 Email:   raox6250@mylaurier.ca
 Version  2021-03-31
 -------------------------------------
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "hash.h"

int hash(char* word) {
    unsigned int hash = 0;
    for(int i = 0; word[i] != '\0'; i++) 
        hash = 31 * hash + word[i];
    
    return hash % htsize;
}

HTNODE *new_hashnode(char *name, int value) {
    HTNODE *node = (HTNODE *) malloc(sizeof(HTNODE));
    strcpy(node->name, name);
    node->value = value;
    node->next = NULL;

    return node;
}

HASHTABLE *new_hashtable(int size) {
    HASHTABLE *table = (HASHTABLE *) malloc(sizeof(HASHTABLE));
    table->size = size;
    table->count = 0;
    table->hnp = (HTNODE **) malloc(sizeof(HTNODE **) * size);

    for(int i = 0; i < size; i++)
        *(table->hnp + i) = NULL;

    return table;
}


HTNODE *search(HASHTABLE *table, char *name) { 
    int index = hash(name);
    HTNODE *node = table->hnp[index];
    while(node) {
        if(strcmp(node->name, name) == 0)
            return node;

        node = node->next;

    }

    return NULL;
}

int insert(HASHTABLE *table, HTNODE *node) {
    int index = hash(node->name);
    HTNODE *prev = NULL;
    HTNODE *curr = table->hnp[index];
    if(curr != NULL) {
        while(curr && strcmp(curr->name, node->name) != 0) {
            prev = curr;
            curr = curr->next;

        } 

        if(strcmp(curr->name, node->name) != 0) {
            if(prev) 
                prev->next = node;

            node->next = curr;
            table->count += 1;
            return 1;

        } else 
            curr->value = node->value;

    } else {
        table->hnp[index] = node;
        table->count += 1;
        return 1;

    }

    return 0;
}

int delete(HASHTABLE *table, char *name) {
    int index = hash(name);
    HTNODE *prev = NULL;
    HTNODE *curr = table->hnp[index];
    if(curr) {
        int i = 0;
        while(curr && strcmp(curr->name, name) != 0) {
            prev = curr;
            curr = curr->next;
            i++;

        }

        // Checks to see if the loop above didn't just stop because its at the end of the list.
        if(strcmp(curr->name, name) == 0) {
            if(prev)
                prev->next = curr->next;
            
            table->hnp[index + i] = NULL;
            free(table->hnp[index + i]);
            table->count -= 1;
            return 1;

        }

    // Value doesn't exist.
    } else
        return 0;
    
}


void clean_hash(HASHTABLE **htp) {
    if(*htp == NULL)
        return;
    
    HASHTABLE *ht = *htp;
    HTNODE *sp = ht->hnp[0], *p, *temp;
    for(int i = 0; i < ht->size; i++) {
        p = ht->hnp[i];
        while(p) {
            temp = p;  
            p = p->next;
            free(temp);
        
        }

        ht->hnp[i] = NULL;
    }

    free(ht->hnp);
    ht->hnp = NULL;
    *htp = NULL;

}

void display_hashtable(HASHTABLE *ht, int option) {
    HTNODE *p;
    if(option == 0) {
        printf("size:  %d\n", ht->size);
        printf("count: %d\n", ht->count);
        printf("hash data:\nindex: list of the data elements");
        for(int i = 0; i < ht->size; i++) {
            p = *(ht->hnp + i);
            if(p)
                printf("\n%2d: ", i);
            
            while(p) {
                printf("(%s, %d) ", p->name, p->value);
                p = p->next;
            
            }
        }

        printf("\n");
    
    } else {
        for(int i = 0; i < ht->size; i++) {
            p = *(ht->hnp + i);
            while(p) {
                printf("%s=%d\n", p->name, p->value);
                p = p->next;

            }
        }
    }
}
