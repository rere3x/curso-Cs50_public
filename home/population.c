#include<stdio.h>
#include<cs50.h>

int yearsToLimit(int population,int endSize);
int positive_int(string s);


int population;
int endSize;

int main(void)
{
   /* Start size: 100
    End size: 200
    Years: 9
    */

    population = positive_int("Qual tamanho inicial da população: \n");
    endSize = positive_int("Qual tamanho final da população: \n");
    int years = yearsToLimit(population , endSize);
    printf("%i\n", years);
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

int yearsToLimit(int n, int b)
{



    int years = 0;
    int newPopulation;

    do
    {
        newPopulation = n + (n/3) - (n/4) ;
        
        years++;
    }
    while (newPopulation == endSize);

    return years;
}