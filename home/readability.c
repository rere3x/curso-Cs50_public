#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
    /*
    ask for a text
    get the text
    pass the formula
    give de result as grade X
    */

   string text = get_string("Text: ");
   int grade = textFormula(text);


   if(grade < 1)

    printf ("Before Grade 1");

    if else(Grade >= 16)

        printf ("Before Grade 1");

        else
        printf ("Grade %i", grade);

}



int grade = textFormula(string text)
{

    int words = 1;



    //walking char by char
    for (i=0, n = strlen(text); i < n; i++)
    {
        //checking blank spaces to cout words
        if(isspace(text[i]) == 1 )
            words++;

        if( == 1 )



    }
}