#include<stdio.h>
#include<cs50.h>


float get_money();
int troco(double v, double m);

int main(void)
{
    double valoritem = get_float("Qual valor do item? ");
    double valorDinheiro = get_money();
    int trocoInt = troco (valoritem,valorDinheiro);


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





int troco(double vI, double vD)
{

    //converte valor para positivo
    double resultado = vI - vD;
    if(resultado < 0.00)
    {resultado *= -1.00;}

    //coverte pra centavos


    int newResultado =  (int)resultado;
    resultado -= (float)newResultado;
    resultado *=100.00;
    int calcResultado =  (int)resultado;

    printf("test = %i\n", calcResultado);
    printf("test = %.2f\n", resultado);

    return newResultado;

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








