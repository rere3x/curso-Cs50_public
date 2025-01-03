#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"
#include <strings.h>
#include <string.h>
#include <ctype.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
#define N 52

// Hash table
node *table[N];
unsigned int sizeCount = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    if (strlen(word) == 0)
    {
        return true;
    }

    unsigned int index = hash(word);

    node *cursor = table[index];
    while (cursor != NULL)
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
    unsigned int hash = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash = (hash * 31) + tolower(word[i]); // Converta para minúsculas antes de calcular o hash
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return false;
    }

    char buffer[LENGTH];
    while (fscanf(file, "%s", buffer) != EOF)
    {
        if (strlen(buffer) > 0)
        {
            sizeCount++;

            node *tempNode = malloc(sizeof(node));
            if (tempNode == NULL)
            {
                printf("Erro ao alocar memória para o novo nó.\n");
                fclose(file);
                return false;
            }

            strncpy(tempNode->word, buffer, LENGTH);
            tempNode->word[LENGTH] = '\0';

            unsigned int index = hash(buffer);
            tempNode->next = table[index];
            table[index] = tempNode;
        }
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return sizeCount;
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
        table[i] = NULL;
    }

    return true;
}
