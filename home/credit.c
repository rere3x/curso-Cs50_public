#include<stdio.h>
#include<cs50.h>
#include<math.h>


    int trackNumber = 0;
    int validCheck(int n);
    int numbercheck(long cartao);


int main(void)
{

    long cartao = get_long("Teste seu cartão de credito: ");
    int numberchecked = numbercheck(cartao);
    int valid = validCheck(numberchecked);

        printf("testtrack = %i", valid);

}

bool validCheck(int n)
{
    n %= 10;
    if(n == 0)
    {
        return true;
    }
    else{return false;}

}


int numbercheck(long cartao)
{
    long rstnumber = 10;
    long antRstNumber = 1;
    int parVariable = 0;
    int imparVariable = 0;

    for (int i = 0; i < 16; i++)
    {
        long cardnumber = cartao % rstnumber;
        rstnumber *= 10;
        cardnumber /= antRstNumber;
        antRstNumber *= 10;
        int digit = round(cardnumber * 1);



        trackNumber++;
        if(trackNumber % 2 == 0)
        {
            digit *= 2;
            if(digit > 10)
            {
                digit %= 10;
                digit++;
            }
            parVariable += digit;
        }
        else
        {
            imparVariable += digit;
        }


    }
    return parVariable + imparVariable;

}
