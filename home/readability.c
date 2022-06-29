#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int textFormula(string text);

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

    printf ("\nBefore Grade 1\n");

    else if(grade >= 16)

        printf ("\nBefore Grade 1\n");

        else
        printf ("\nGrade %i\n", grade);

}



int textFormula(string text)
{
    string t = text;
    int words = 1;
    int letters = 0;
    int sentenses = 0;
    float grade = 0;


    //walking char by char
    for (int i = 0 , n = strlen(t); i < n; i++)
    {
        printf ("%c", t[i]);

        //checking for blank spaces
        if(isspace(t[i]) == 1 )
        printf("\ntrue\n");
            words++;

        //checking for lettlers
        if(isalpha(t[i]) == 1 )
            letters++;

        //checking for non-lettlers like ". , ? :"
        if(isalpha(t[i]) == 0 )
            sentenses++;
    }

    grade = (0.0588 * letters) - (0.296 * sentenses) - 15.8;

    return grade;
}