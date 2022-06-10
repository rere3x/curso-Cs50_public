#include<stdio.h>
#include<cs50.h>


float get_money();
float troco(float v, float m);

int main(void)
{
    float p = get_float("Qual valor do item? ");
    float i = get_money("Quanto voce tem? ");
    float t = troco(p,i);
    printf("A sobra é: %f", t);

}



float troco(float v, float m)
{

    //converte valor para positivo
    float resultado = v - m;

    if(resultado < 0)
    {resultado *= -1;}

    //coverte pra centavos
    resultado 


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


