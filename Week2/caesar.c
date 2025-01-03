#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int validKey (int length, string t[]);
void ciperText(int length, string s, int ciper);

int main(int arg, string argv[])
{

    if (arg == 2 &&  validKey(strlen( argv[1]), argv) == 1 )
    {

        string text = get_string("Text: \n");
        printf("ciphertext:  ");
        ciperText(strlen(text), text, atoi(argv[1]));
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

