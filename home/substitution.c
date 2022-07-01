#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int main (int arg, string argv[])
{


    //ler a chave e confirmar se é valida
    if ( validKey(strlen( argv[1]), argv ) == 1 )


    else
    return 1;
    //pegar o texto
    //encripitar o texto
    //imprimir o texto encripitado




}


// the function thats valid the key
int validKey (int length, string t[])
{
    if (length > 26)
    {
        printf
        return 0;
    }
    for (int i = 0; i < length; i++)
    {



    }

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