#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int validKey (string t[]);
void ciperText(string s);

int main(int arg, string argv[])
{

        string plantext = get_string("Text: ");
    if ( validKey(argv[]) )

        //get the text to ciper

        //convert each lettler to a ciper lettler
        ciperText(plantext);




    //print a comand line showing that the key is not valid
    else
    printf("Usage: ./caesar key\n");


}


// the function thats valid the key
int validKey (string t[])
{
    for (int i = 0, n = strlen(t[1]); i < n; i++)

        if (!isdigit(t[1][i]))
            return false;
        else
            return true;
}

void ciperText(string s)
{

        //ciper the text

        for (int i = 0, n = strlen(plantext); i < n ; i++)

            if (isupper(s[i]) && isalphas(s[i]))
                printf("%c", (( s[i] + int atoi (argv[1])) % 26) + 65);

            else if (islower(s[i]) && isalphas(s[i]))
                 printf("%c", (( s[i] + int atoi (argv[1])) % 26) + 97);

            else
                printf("%c", s[i])


}