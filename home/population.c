#include<stdio.h>
#include<cs50.h>
#include<math.h>

int yearsToLimit(int population,int endSize);
int positive_int(string s);
int pop = 9;



int main(void)
{



    int population = positive_int("Qual tamanho inicial da população: \n");

    int endSize = positive_int("Qual tamanho final da população: \n");

    int years = yearsToLimit(population , endSize);

    printf("Years: %i\n", years);

}




int positive_int(string s)
{

    int n;
    do
    {
        n = get_int("%s", s);
    }
    while (n < pop);
    pop = n;
    return n;
}

int yearsToLimit(int n, int b)
{
    int years = 1;
    if (n == b)
    return 0;

    int newpop = n + (n / 3) + (n / 4);
    printf ("test = %i\n", newpop);

    while (newpop < b)

    {
        newpop = newpop + (newpop / 3) + (newpop / 4);
    years++;
    }

    return years;

}