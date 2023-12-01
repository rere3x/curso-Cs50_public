// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"
#include <strings.h>
#include <string.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 52;

// Hash table
node *table[N];
unsigned int sizeCount = 0;


// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int index = hash(word);

    node *cursor = table[index];
    while (cursor != NULL)
    {
        if(strcasecmp(cursor->word, word) == 0)
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
    unsigned int long hash = 5381;
    int c;

    while((c = *word++))
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //abrir o arquivo dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return false;
    }

    // ler as strings do arquivo uma por uma
    char buffer[45];
    while (fscanf(file, "%s", buffer) != EOF)
    {
        sizeCount++;

        node *tempNode = malloc(sizeof(node));
        strncpy(tempNode->word, buffer, LENGTH);
        tempNode->word[LENGTH] = '\0';
        tempNode->next = NULL;

        if (tempNode == NULL)
        {
            printf("Erro ao alocar memória para o novo nó.\n");
            return false;
        }
        unsigned int index = hash(buffer);
        tempNode->next = table[index];
        table[index] = tempNode;
    }

    unsigned int count = size();
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO

    if(sizeCount != 0)
    {
        return sizeCount;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
        return true;
}
