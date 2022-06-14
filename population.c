#include<stdio.h>
#include<cs50.h>

int main(void)
{
   /* Start size: 100
    End size: 200
    Years: 9
    */

   int n = positive_int();
   int b = positive_int();


}


int positive_int(void)
{
    float n;
    do
    {
        n = get_float("Qual tamanho inicial da população: \n");
    }
    while (n < 1);
    return n;
}