#include<stdio.h>
#include<cs50.h>
#include<math.h>


    int lastdigit;
    int digit;
    int trackNumber = 0;


    long get_validcard();
    bool validCheck(int n);
    int numbercheck(long cartao);


int main(void)
{

    long cartao = get_validcard();
    int numberchecked = numbercheck(cartao);
    bool valid = validCheck(numberchecked);

    if(valid == 1)
    {
        printf("valido\n");
    }



}
/*
void showflag()
{
    if (digit == 12 || digit == 16 && lastdigit == 4 )
    {
        printf("É um cartão visa");
    }
}
*/
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

    for (int i = 0; i < lastdigit; i++)
    {
        long cardnumber = cartao % rstnumber;
        rstnumber *= 10;
        cardnumber /= antRstNumber;
        antRstNumber *= 10;
        digit = round(cardnumber * 1);



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
    return n;

    n = round (n / 1000000000000);
    if (n < 10)
    {
        lastdigit = 13;
    }
    if (n > 10 && n < 100)
    {
        lastdigit = 14;
    }
    if (n > 100 && n < 1000)
    {
        lastdigit = 15;
    }
    if (n > 1000 && n < 10000)
    {
        lastdigit = 16;
    }

        printf("testtrack = %li\n", n);

}