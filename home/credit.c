#include<stdio.h>
#include<cs50.h>

int main(void)
{

   long cartao = get_long("Teste seu cartão de credito: \n");

   //remender test

    int remender = cartao % 100;
    printf("remender = %i\n", remender);
}