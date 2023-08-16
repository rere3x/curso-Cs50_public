// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO

    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //abrir o arquivo dictionary
    FILE *file = fopen(dictionary, "r")
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return false;
    }

    // ler as strings do arquivo uma por uma
    while (fscanf(file, "%s", word) != EOF)
    {

        node *newNode = malloc(sizeof(node))
        if (newNode == NULL)
        {
            printf("Erro ao alocar memória para o novo nó.\n");
            fclose(file);
            return false;
        }
        strcpy(newNode->word, word);
        newNode->next = NULL;
        unsigned int index = hash(word);

        newNode->next = table[index];
        table[index] = newNode;
    }


    //usar o hash na palavra para ter um valor hash pra ela
    //colocar o node na tabela hash no local certo
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
