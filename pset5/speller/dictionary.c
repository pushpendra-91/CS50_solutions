// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <cs50.h>
#include <ctype.h>

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
int total_words = 0;
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);

    node *cursor = table[index];
    while(cursor)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int sum = 0;
    for(int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }
    return (sum % N);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Loads dictionary
    FILE *file = fopen(dictionary, "r");
    if(!file)
    {
        return false;
    }
    //read a word from file
    char word[LENGTH + 1];
    while(fscanf(file, "%s", word) != EOF)
    {
        //creating a new node
        node *new_node = malloc(sizeof(node));
        if(!new_node)
        {
            return false;
        }
        strcpy(new_node->word, word);
        new_node->next = NULL;

        //obtain index for hashing
        int index = hash(word);
        if(!table[index])
        {
            table[index] = new_node;
        }
        else
        {
            new_node->next = table[index];
            table[index] = new_node;
        }
        total_words++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return total_words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for( int i = 0; i < N; i++)
    {
        node *head = table[i];
        node *cursor = head;
        node *tmp = head;
        while(cursor)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
