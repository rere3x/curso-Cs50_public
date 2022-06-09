#include<stdio.h>
#include<cs50.h>


float get_money();
float troco(float v, float m);

int main(void)
{
    float p = get_float("Qual valor do item? ");
    float i = get_money();
    float t = troco(p,i);
    printf("A sobra é: %f", t);

}


float troco(float v, float m)
{
    
    float resultado = v - m;

    //converte valor para positivo
    if(resultado < 0){resultado *= -1;}
    return resultado;

}



float get_money(void)
{
    float n;
    do
    {
        n = get_float("Coloque o valor do troco\n");
    }
        while(n < 0.009);
        return n;
}


