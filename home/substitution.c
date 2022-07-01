#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int validKey (int length, string t[], int arg);

int main (int arg, string argv[])

{

        //check if there is a key
        if(arg != 2)
        {
            printf("muitos inputs\n");
            return 1;
        }


            //valid a key and star to encriptate the text
        if ( validKey(strlen( argv[1]), argv, arg ) == 1 )
        {
                string text = get_string("Text: ");


        }
        else
        return 1;

    //encripitar o texto
    //imprimir o texto encripitado


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
        printf("Digitos não são aceitos\n");
        return 0;
    }
        for (int i = 0; i < length; i++)
    {
        for (int j = 1; j < length; i++)
        {

        if (t[1][i] == t[1][j])
        printf("Digitos repetido não sao aceitos\n");
        return 0;
        }
    }

 return 1;
}


void ciperText(int length, string s, int ciper)
{

        //ciper the text


        for (int i = 0; i < length; i++)
{



            if (isupper(s[i]) && isalpha(s[i]))


            else if (islower(s[i]) && isalpha(s[i]))


            else
                printf("%c", s[i]);
}
printf("\n");
}
