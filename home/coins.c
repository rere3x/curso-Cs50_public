#include<stdio.h>
#include<cs50.h>


float get_money();
float troco(float v, float m);

int main(void)
{
    float valorItem = get_float("Qual valor do item? ");
    float valorDinheiro = get_money();
    float t = troco (valorDinheiro,valorItem);

    int coin25;
    int coin10;
    int coin05;
    int coin01;
    float resultado;

    t = t*100;
    int trocoInt = (int)t;

 if (trocoInt >= 25)
    {
        coin25 = trocoInt / 25;
        trocoInt = trocoInt % 25;
    }
     if (trocoInt >= 10)
    {
        coin10 = trocoInt / 10;
        trocoInt = trocoInt % 10 ;
    }
     if (trocoInt >= 5)
    {
        coin05 = trocoInt / 5;
        trocoInt = trocoInt % 5 ;
    }
     if (trocoInt >= 1)
    {
        coin01 = trocoInt / 1;
    }

    printf("de o troco em %i moedas de 25, %i moedas de 10, %i moedas de 5,%i moedas de 1", coin25,coin10,coin05,coin01);


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








