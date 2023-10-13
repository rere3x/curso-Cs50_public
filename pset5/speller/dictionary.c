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

    node *cursor = malloc(sizeof(node));
        if (cursor == NULL)
        {
            printf("Erro ao alocar memória para o novo nó.\n");
            free(cursor);
            return false;
        }
    cursor = table[index];
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
        fclose(file);
        return false;
    }

    // ler as strings do arquivo uma por uma
    char buffer[42];
    while (fscanf(file, "%s", buffer) != EOF)
    {
        sizeCount++;
        size(sizeCount);

        node *tempNode = malloc(sizeof(node));
        if (tempNode == NULL)
        {
            printf("Erro ao alocar memória para o novo nó.\n");
            free(tempNode);
            return false;
        }
        strcpy(tempNode->word, buffer);
        tempNode->next = NULL;

        unsigned int index = hash(buffer);
        tempNode->next = table[index];
        table[index] = tempNode;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(int countValue)
{
    // TODO
    
    return countValue;

}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
