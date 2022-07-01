#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int validKey (int length, string t[], int arg);
void ciperText(int length, string s, string ciper);

int main (int arg, string argv[])

{

        //check if there is a key
        if(arg == 2)
        {


                //valid a key and star to encriptate the text
            if ( validKey(strlen( argv[1]), argv, arg ) == 1 )
            {


                    string text = get_string("Text: ");
                    printf("ciphertext:  ");
                    ciperText(text[1], text, argv[1]);


            }
            else
            return 1;
        }
        else
        {
            printf("muitos inputs\n");
            return 1;
        }





return 0;

}


// the function thats valid the key
int validKey (int length, string t[], int arg)
{

    if (length > 26)
        {
            printf("Chave maior que 26\n");
            return 0;
        }




    for (int i = 0; i < length; i++)
    {
        if(isdigit(t[1][i]))
        {

        printf("%s\n", t[i]);
        return 0;
        }
    }
        for (int i = 0; i < length; i++)

    {
        for (int j = 1 + i; j < length; j++)
        {
            char currentLocation = t[1][i];
            char nextLocation = t[1][j];

            if (currentLocation == nextLocation)
            {

            printf("Digitos repetido não sao aceitos\n");
            return 0;
            }
        }
    }

 return 1;
}


void ciperText(int length, string s, string ciper)
{

        //ciper the text


        for (int i = 0; i < length; i++)
{

            if (isupper(s[i]) && isalpha(s[i]))
                
                printf("%c", ciper[(s[i] % 'A')]);

            else if (islower(s[i]) && isalpha(s[i]))
                printf("%c", ciper[(s[i] % 'a')]);

            else
                printf("%c", s[i]);
}
printf("\n");
}
