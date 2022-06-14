#include<stdio.h>
#include<cs50.h>
#include<math.h>

int yearsToLimit(int population,int endSize);
int positive_int(string s);

int population = 9;


int main(void)
{
   /* Start size: 100
    End size: 200
    Years: 9
    */

    population = positive_int("Qual tamanho inicial da população: \n");
    int endSize = positive_int("Qual tamanho final da população: \n");
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
    while (n < population);
    return n;
}

int yearsToLimit(int n, int b)
{



    int years = 0;
    int newPopulation = n + (n/3) - (n/4);


    while (newPopulation < b )
    {


        newPopulation = newPopulation + (newPopulation/3) - (newPopulation/4) ;
        years++;
    }

    return years;

}