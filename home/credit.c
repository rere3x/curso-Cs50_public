#include<stdio.h>
#include<cs50.h>

int numbercheck(long cartao);


int main(void)
{

    long cartao = get_long("Teste seu cartão de credito: ");
    int numerchecked = numbercheck(cartao);



}

int numbercheck(long cartao)
{
    int calc;
    long rstnumber = 10;
    long antRstNumber = 1;
    for (int i = 0; i < 16; i++)
    {
        long cardnumber = cartao % rstnumber;
        rstnumber *= 10;
        cardnumber /= antRstNumber;
        antRstNumber *= 10;

        int tracknumber = 1;
        tracknumber++;
        printf("testtrack = %li\n", cardnumber);

        if(tracknumber % 2 == 0)
        {
            calc = cardnumber * 2;
            if(calc >= 10)
            {
                calc %= 10;
                calc++;
            }else{return calc;}

        }


    }
    return 0;

}
