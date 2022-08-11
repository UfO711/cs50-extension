// Implements a dictionary's functionality

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
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

// Initiallize word counter
unsigned int word_counter = 0;

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
    
    char buffer[LENGTH + 1];
    
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
        if (table[hash_number] == NULL)
        {
            table[hash_number] = n;
            n->next = NULL;
            word_counter++;
        }
        else
        {
            n->next = table[hash_number];
            table[hash_number] = n;
            word_counter++;
        }
    }
    fclose(fp);
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *trav = NULL;  
    node *temp = NULL;  
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            trav = table[i];  
            do
            {
                temp = trav;
                trav = trav->next;
                free(temp);
            } while (trav != NULL);
        }
    }
    // How do I know if it is successful
    return true;
}
