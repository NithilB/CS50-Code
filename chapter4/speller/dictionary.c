// Implements a dictionary's functionality

// Suchi and Aryaman were my partners

#include <stdbool.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *table[N];

// count the number of loaded words in dictionary
int cnt = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    char temp[strlen(word) + 1];
    temp[strlen(word)] = '\0';
    
    for(int r = 0; r < strlen(word); r++){
        temp[r] = toupper(word[r]);
    }
    
    
    int h = hash(temp);
    node *x = table[h];
    
    if(x == NULL) {    
        return false;
    }

    while(x != NULL){
       if(strcasecmp(x->word, temp) == 0){
           return true;
        }
        x = x->next;
    }
    
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    //https://stackoverflow.com/questions/7666509/hash-function-for-string

    unsigned long hash = 5381;
    int c = 0;
    while (c == *word++) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % N; 
    
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE *f = fopen(dictionary, "r");
    if(f == NULL){
        return false;
    }
    
    char w[LENGTH + 1];
    while(fscanf(f, "%s", w) != EOF){
        node *n = malloc(sizeof(node));
        
        if(n == NULL){
            fclose(f);
            return false;
        }
        
        strcpy(n->word, w);
        n->next = NULL;
        unsigned int i = hash(w);
        n->next = table[i];
        table[i] = n;
        cnt++;
    }
    
    fclose(f);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return cnt;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    //bool check = true;
    for(int x = 0; x < N; x++){
        node *t = table[x];
        while(true){
            if(t == NULL){
                break;
            } 
            node *y = t;
            t = t->next;
            free(y);
        }
        
    }
    
    return true;
}
