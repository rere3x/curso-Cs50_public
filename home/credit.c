#include<stdio.h>
#include<cs50.h>

int numbercheck(long cartao);


int main(void)
{

    long cartao = get_long("Teste seu cartão de credito: \n");
    int numerchecked = numbercheck(cartao);

   //remender test

    long remender = cartao % 10000000000000000;
    

}

int numbercheck(long cartao)
{
    int test = 0;
    long rstnumber = 10;
    long antRstNumber = 1;
    for (int i = 0; i < 16; i++)
    {
        long cardnumber = cartao % rstnumber;
        rstnumber *= 10;
        cardnumber /= antRstNumber;
        antRstNumber *= 10;

        int tracknumber = 0;
        tracknumber++;

        if(tracknumber % 2 == 0)
        {
            int r = cardnumber * 2;
            if(r >= 10)
            {
                r %= 10;
                r++;
            }

        printf("testttt = %i\n", r);
        }


    }
    return test;

}
