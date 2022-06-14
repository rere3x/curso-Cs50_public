#include<stdio.h>
#include<cs50.h>


int positive_int(string s);

int main(void)
{
   /* Start size: 100
    End size: 200
    Years: 9
    */

   int n = positive_int("Qual tamanho inicial da população: \n");
   int b = positive_int("Qual tamanho final da população: \n");


}


int positive_int(string s)
{

    int n;
    do
    {
        n = get_float("%s", s);
    }
    while (n < 1);
    return n;
}