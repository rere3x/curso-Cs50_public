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
    int tLargura = n - 1;
    int jlargura = 0;

    for(int i = 0; i < largura; i++)
    {

        for(int j = jlargura; j < largura; j++)
        {
            printf(" ");
        }

        for(int l = tLargura ; l < largura; l++)
        {
            printf("#");
        }
        tLargura--;
        jlargura++;
        printf("  ");
        for(int l = tLargura + 1; l < largura; l++)
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
