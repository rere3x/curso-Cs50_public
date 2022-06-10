#include<stdio.h>
#include<cs50.h>


float get_money();
float troco(float v, float m);

int main(void)
{
    float p = get_float("Qual valor do item? ");
    float i = get_money();
    float t = troco (p,i);

    int coin25 = 0;
    int coin10 = 0;
    int coin05 = 0;
    int coin01 = 0;
    float resultado;

    t = t*100;
    int sacodocarai = (int)t;

 if (sacodocarai >= 25)
    {
        coin25 = sacodocarai / 25;
        sacodocarai = sacodocarai % 25 ;
        if(sacodocarai == 1){sacodocarai = 0;}
    }

    else if (sacodocarai >= 10)
    {
        coin10 = sacodocarai / 10;
        sacodocarai = sacodocarai % 10 ;
        if(sacodocarai == 1){sacodocarai = 0;}
    }

    else if  (sacodocarai >= 5)
    {
     printf(" test = %i\n", sacodocarai);
        coin05 = sacodocarai / 5;
        sacodocarai = sacodocarai % 5 ;
        if(sacodocarai == 1){sacodocarai = 0;}
    }

    else if  (sacodocarai >= 1)
    {
        coin10 = 1;
    }

    printf("de o troco em %i moedas de 25, %i moedas de 10, %i moedas de 5, %i moedas de 1\n", coin25,coin10,coin05,coin01);


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








