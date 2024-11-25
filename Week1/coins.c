#include<stdio.h>
#include<cs50.h>
#include<math.h>

float get_money();
int troco(float vI, float vD);
float positive_int(void);

int main(void)
{
    float valoritem     = positive_int();
    float valorDinheiro = get_money();
    int   trocoInt      = troco (valoritem,valorDinheiro);


    int coin25 = 0;
    int coin10 = 0;
    int coin05 = 0;
    int coin01 = 0;
    float resultado;


    if (trocoInt >= 25)
    {
        coin25  = trocoInt / 25;
    printf("test r = %i\n", trocoInt);
    printf("test c = %i\n", coin25);
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

        printf("test t = %i\n", trocoInt);
    if  (trocoInt >= 1)
    {
        coin01 = trocoInt / 1;

    }

    printf("de o troco em %i moedas de 25, %i moedas de 10, %i moedas de 5, %i moedas de 1\n", coin25,coin10,coin05,coin01);


}


int troco(float vI, float vD)
{

    float resultado = vD - vI;


    //coverte pra centavos

    resultado -= (int)resultado;
    int coin = round(resultado * 100);


    return coin;

}


float get_money(get_string)
{
    float n;
    do
    {
        n = get_float("Coloque o valor do pagamento\n");
    }
        while(n < 0.009);
        return n;
}

float positive_int(void)
{
    float n;
    do
    {
        n = get_float("Qual valor do item: \n");
    }
    while (n < 1);
    return n;
}






