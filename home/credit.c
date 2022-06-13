#include<stdio.h>
#include<cs50.h>
#include<math.h>

int numbercheck(long cartao);


int main(void)
{

    long cartao = get_long("Teste seu cartão de credito: ");
    int numerchecked = numbercheck(cartao);



}

int numbercheck(long cartao)
{
    int trackNumber = 0;
    long rstnumber = 10;
    long antRstNumber = 1;
    int parVariable;
    int imparVariable;

    for (int i = 0; i < 16; i++)
    {
        long cardnumber = cartao % rstnumber;
        rstnumber *= 10;
        cardnumber /= antRstNumber;
        antRstNumber *= 10;
        int digit = round(cardnumber * 1);

        printf("testtrack = %i\n", digit);


        trackNumber++;
        if(trackNumber % 2 == 0)
        {
            digit *= 2;
            if(digit > 10)
            {
                digit 
            }

        }
        else
        {

        }


    }
    return 0;

}
