#include<stdio.h>
#include<cs50.h>

int main(void)
{

   long cartao = get_int("Teste seu cartão de credito: \n");

   //remender test

    int remender = cartao % 10;
    printf("remender = %i", remender);
}