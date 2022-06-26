#include<stdio.h>
#include<cs50.h>
#include<math.h>

int yearsToLimit(int population,int endSize);
int positive_int(string s);

int population = 8;


int main(void)
{



    population = positive_int("Qual tamanho inicial da população: \n");

    int endSize = positive_int("Qual tamanho final da população: \n");

    int years = yearsToLimit(population , endSize);

    printf("Years: %i\n", years);
    
}




int positive_int(string s)
{

    int n;
    do
    {
        n = get_float("%s", s);
    }
    while (n < population);
    return n;
}

int yearsToLimit(int n, int b)
{

    int years = 0;
    int newPopulation = n + (n/3) - (n/4);

    if (n == b) return years = 0;


    do
    {
        newPopulation = ceil( newPopulation + (newPopulation/3) - (newPopulation/4) );
        years++;
        if(newPopulation > b)
        years++;
    }
    while (newPopulation < b );

    return years;

}