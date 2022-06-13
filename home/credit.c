#include<stdio.h>
#include<cs50.h>
#include<math.h>


    int digitCount;
    int lastdigit = 0;
    int trackNumber = 0;


    long get_validcard();
    bool validCheck(int n);
    int numbercheck(long cartao);
    void showflag();


int main(void)
{

    long cartao = get_validcard();
    int numberchecked = numbercheck(cartao);
    bool valid = validCheck(numberchecked);

    if(valid == 1)
    {
        void showflag();

    }




}

void showflag(void)
{
    if ((digitCount == 13 || digitCount == 16) && lastdigit == 4)
    {
        printf("É um cartão Visa");
    }
    if (digitCount == 16 && lastdigit == 5)
    {
        printf("É um cartão MasterCard");
    }
    if (digitCount == 15 && lastdigit == 3)
    {
        printf("É um cartão visa");
    }
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

    for (int i = 0; i < digitCount; i++)
    {
        long cardnumber = cartao % rstnumber;
        rstnumber *= 10;
        cardnumber /= antRstNumber;
        antRstNumber *= 10;
        int digit = round(cardnumber * 1);
        lastdigit = digit;
        


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

long get_validcard(void)
{
    long n;
    do
    {
        n = get_long("Escolha um numero de cartão de credito valido: \n");
    }
    while (n < 1000000000000);

    int testN = round (n / 1000000000000);
    if (n < 10)
    {
        digitCount = 13;
    }
    if (n > 10 && n < 100)
    {
        digitCount = 14;
    }
    if (n > 100 && n < 1000)
    {
        digitCount = 15;
    }
    if (n > 1000)
    {
        digitCount = 16;
    }

    return n;

}