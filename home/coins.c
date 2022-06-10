#include<stdio.h>
#include<cs50.h>


float get_money();
float troco(float v, float m);

int main(void)
{
    float valorItem = get_float("Qual valor do item? ");
    float valorDinheiro = get_money();
    float troco = troco (valorItem,valorDinheiro);

    int coin25;
    int coin10;
    int coin05;
    int coin01;
    float resultado;

    /*t = t*100;
*/
    float sacodocarai = troco;
 if (sacodocarai >= 0.25)
    {
        coin25 = sacodocarai / 0.25;
        sacodocarai = sacodocarai % 0.25 ;

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

*/
}





float troco(float valorItem, float valorDinheiro)
{

    //converte valor para positivo
    float resultado = valorItem - valorDinheiro;
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








