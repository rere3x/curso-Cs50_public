#include <stdio.h>
#include <cs50.h>

int alturaDosBlocos(int n);
int main(void)
{

    int n = get_int("escolha a altura \n");


    alturaDosBlocos(n);

}

void alturaDosBlocos(int n)
{
    int largura = n;

    for(int i = 1; i < largura; i++)
    {
        printf(" ");
    }
    for(int i = largura; i > 0; i--)
    {
        printf("#");
    }
    
}
