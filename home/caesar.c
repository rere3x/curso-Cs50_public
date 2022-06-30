#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int validKey (int length, string t[]);

int main(int arg, string argv[])
{

    if (                validKey       (       strlen( argv[1])    , argv) == 1          )

        printf("valid\n");






    //print a comand line showing that the key is not valid
    else
    printf("Usage: ./caesar Key\n");


}


// the function thats valid the key
int validKey (int length, string t[])
{
    for (int i = 0; i < length; i++)
    {
        printf ("%i\n", !isspace(t[3][i]));

   // if (isdigit(t[1][i]) == 0 || isspace(t[1][i]))
   // return 0;

    }


return 1;

}

/*void ciperText(string s)
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
*/