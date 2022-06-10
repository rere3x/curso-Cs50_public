#include<stdio.h>
#include<cs50.h>

int main(void)
{

   long cartao = get_long("Teste seu cartão de credito: \n");


   //remender test

    long remender = cartao % 100000000000;
    printf("remender = %li\n", remender);

}
