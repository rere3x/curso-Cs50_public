#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int main (int arg, string argv[])
{

    //ler a chave e confirmar se é valida
    //


}







void ciperText(int length, string s, int ciper)
{

        //ciper the text


        for (int i = 0; i < length; i++)
{



            if (isupper(s[i]) && isalpha(s[i]))
                printf("%c", (((s[i] - 'A')  + ciper) % 26) + 'A');

            else if (islower(s[i]) && isalpha(s[i]))
                printf("%c", (((s[i] - 'a')  + ciper) % 26) + 'a');

            else
                printf("%c", s[i]);
}
printf("\n");
}