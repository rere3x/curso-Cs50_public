#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int validKey (void);

int main(int arg, string argv[])
{

    if ( validKey() && argv[2] == '\0' )

        //get the text to ciper
        string plantext = get_string("Text to ciper: ");

        //convert each lettler to a ciper lettler

        





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
        int ciper = (argv[1][i] + int atoi (argv[1])) % 26;