#include <stdio.h>
#include <cs50.h>

void alturaDosBlocos(int n);
int positive_int(void);


int main(void)
{

    int i = positive_int();



    alturaDosBlocos(i);
}

void alturaDosBlocos(int n)
{
    int largura = n;


    for(int i = 0; i < largura; i++)
    {
/*
        for(int j = 1; j < largura; j++)
        {
            printf("  ");
        }
*/
        for(int l = largura--; l < largura; l++)
        {
            printf("#");
        }
        printf("\n");

    }
}


int positive_int(void)
{
    int n;
    do
    {
        n = get_int("Escolha um numero positivo: \n");
    }
    while (n < 1);
    return n;
}
