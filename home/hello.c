#include <stdio.h>
#include <cs50.h>

int alturaDosBlocos(int n);
int positive_int(void);


int main(void)
{

    int i = positive_int();


    alturaDosBlocos(i);

}

void alturaDosBlocos(int n)
{
    int largura = n;

    for(int i = 1; i < largura; i++)
    {
        printf(" ");
    }
    for(int i = largura--; i < largura; i++)
    {
        printf("#");
    }

}

int positive_int(void)
{
    int n;
    do
    {
        n = get_int("Escolha um numero positivo: "\n);
    }
    while (n < 1);
    return n;
}
