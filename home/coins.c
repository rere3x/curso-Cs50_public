#include<stdio.h>
#include<cs50.h>


float get_money();
float troco(float v, float m);

int main(void)
{
    float p = get_float("Qual valor do item? ");
    float i = get_money();
    float t = troco (p,i);

    int coin25;
    int coin10;
    int coin05;
    int coin01;
    float resultado;

    t = t*100;

 if (t >= 25)
    {
        coin25 = t / 25;
        t = t % 25;
        printf("coin25 = %i e t = %.2f\n", coin25,t);
    }
/*
        coin25 = t / 0.25;
    t = t % 0.25;
    if(t > 0.10)
    {
       coin10 = t / 0.10;

    }
    if(t > 0.05)
    {
        coin05 = t / 0.05;

    }
    if(t > 0.01)
    {
        coin01 = t / 0.01;

    }
    printf("de o troco em %i moedas de 25, %i moedas de 10, %i moedas de 5,%i moedas de 1", coin25,coin10,coin05,coin01);
    printf("quantidade de moeda 25 %i e valor de T %f", coin25,t);
*/
}





float troco(float v, float m)
{

    //converte valor para positivo
    float resultado = v - m;
    if(resultado < 0)
    {resultado *= -1;}

    //coverte pra centavos
    resultado = resultado - (int)resultado;

    return resultado;

}




float get_money(get_string)
{
    float n;
    do
    {
        n = get_float("Coloque o valor do troco\n");
    }
        while(n < 0.009);
        return n;
}








