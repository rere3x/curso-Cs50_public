#include<stdio.h>
#include<cs50.h>

int numbercheck(long cartao);


int main(void)
{

    long cartao = get_long("Teste seu cartão de credito: \n");
    int numerchecked = numbercheck(cartao);

   //remender test

    long remender = cartao % 10000000000000000;
    printf("remender = %li\n", remender);

}

int numbercheck(long cartao)
{
    int test = 0;
    long rstnumber = 10;
    for (int i = 0; i < 16; i++)
    {
        long cardnumber = cartao % rstnumber;
        
        rstnumber *= 10;
        if(cardnumber == cardnumberCheck)
        {


        }
    }
    return test;

}
