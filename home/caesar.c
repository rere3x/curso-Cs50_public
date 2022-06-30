#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int validKey (void);

int main(int arg, string argv[])
{

    if ( validKey() )

        //get the text to ciper
        string plantext = get_string("Text to ciper: ");

        //convert each lettler to a ciper lettler
        ciperText(plantext);




    //print a comand line showing that the key is not valid
    else
    printf("Usage: ./caesar key\n");


}


// the function thats valid the key
int validKey (void)
{
    for (int i = 0, n = strlen(argv[1]); i < n; i++)

        if (!isdigit(argv[1][i]))
            return false;
        else
            return true;
}

ciperText(string s)
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