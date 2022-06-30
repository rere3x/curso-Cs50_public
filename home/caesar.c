#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int validKey (int length, string t[]);
char ciperText(int length, string s, int ciper);

int main(int arg, string argv[])
{

    if (validKey(strlen( argv[1]), argv) == 1 && argv[1])
    {

        string text = get_string("Text: \n");
        printf("ciphertext: %c", ciperText(strlen(text), text, atoi(argv[1])));

    }
    //print a comand line showing that the key is not valid
    else
    {
    printf("Usage: ./caesar Key\n");
    return 1;
    }

 return 0;
}


// the function thats valid the key
int validKey (int length, string t[])
{
    for (int i = 0; i < length; i++)
    {

        int digt = isdigit(t[1][i]);
        int space = isspace(t[1][i]);
   if (digt == 0 || space != 0 )
   return 0;

    }


return 1;

}

char ciperText(int length, string s, int ciper)
{

        //ciper the text

        for (int i = 0; i < length; i++)
{




            if (isupper(s[i]) && isalpha(s[i]))
                return(((s[i] - 65)  + ciper) % 26) + 65;

            else if (islower(s[i]) && isalpha(s[i]))
                 return(((s[i] - 97) + ciper) % 26) + 97;

            else
                return s[i];
}

printf("\n");
}

