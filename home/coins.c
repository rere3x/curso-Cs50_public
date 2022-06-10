#include<stdio.h>
#include<cs50.h>


float get_money();
float troco(float v, float m);

int main(void)
{
    float valoritem = get_float("Qual valor do item? ");
    float valorDinheiro = get_money();
    float t = troco (valoritem,valorDinheiro);


    int coin25 = 0;
    int coin10 = 0;
    int coin05 = 0;
    int coin01 = 0;
    float resultado;


    if (trocoInt >= 25)
    {
        coin25  = trocoInt / 25;
        trocoInt = trocoInt % 25 ;

    }

    if (trocoInt >= 10)
    {
        coin10 = trocoInt / 10;
        trocoInt = trocoInt % 10 ;
    }


    if  (trocoInt >= 5)
    {
        coin05 = trocoInt / 5;
        trocoInt = trocoInt % 5 ;

    }

    if  (trocoInt >= 1)
    {
        coin01 = 1;
    }

    printf("de o troco em %i moedas de 25, %i moedas de 10, %i moedas de 5, %i moedas de 1\n", coin25,coin10,coin05,coin01);


}





float troco(float vI, float vD)
{

    //converte valor para positivo
    float resultado = vI - vD;
    if(resultado < 0)
    {resultado *= -1;}

    //coverte pra centavos
    float newResultado = (int)resultado
    resultado = resultado - newResultado;
    resultado *= 100.00;



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








