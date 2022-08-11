// Implements a dictionary's functionality

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int hash_number;
    // Get hash value of the word
    hash_number = hash(word);
    node *trav = NULL;
    trav = table[hash_number]->next;
    while (trav != NULL)
    {
        if (strcasecmp(trav->word, word) == 0)
        {
            return true;
        }
        trav = trav->next;
    }
    
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open dictionary file
    FILE *fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        return false;
    }
    
    char *buffer = NULL;
    
    // Read words from dictionary
    while (fscanf(fp, "%s", buffer) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        // Copy words into nodes
        strcpy(n->word, buffer);

        // Load word into hash table
        // Get hash code
        unsigned int hash_number;
        hash_number = hash(n->word);

        // Insert a new node
        n->next = table[hash_number]->next;
        table[hash_number]->next = n;
    }

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int word_counter = 0;
    node *trav = NULL;
    for (int i = 0; i < N; i++)
    {
        trav = table[i];
        while (trav->next != NULL)
        {
            word_counter++;
            trav = table[i]->next->next;
        }
    }
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
