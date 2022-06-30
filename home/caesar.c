#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int validKey (void);

int main(int arg, string argv[])
{

    if ( validKey() && argv[2] == \0 )

        



    else
    printf("Usage: ./caesar key\n");


}

int validKey (void)
{
    for (int i = 0, n = strlen(argv[1]); i < n; i++)

        if (!isdigit(argv[1][i]))
            return false;
        else
            return true;
}