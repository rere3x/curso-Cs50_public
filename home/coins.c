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

 if(t > 0.25)
    {
        resultado /= 0.25;


    }
    if(t > 0.10)
    {
        resultado /= 0.10;

    }
    if(t > 0.05)
    {
        resultado /= 0.05;

    }
    if(t > 0.01)
    {
        resultado /= 0.01;

    }



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








