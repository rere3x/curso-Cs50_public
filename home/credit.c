#include<stdio.h>
#include<cs50.h>
#include<math.h>


    int lastdigit;
    int digit;
    int trackNumber = 0;


    get_validcard();
    bool validCheck(int n);
    int numbercheck(long cartao);
    showflag();

int main(void)
{

    long cartao = get_validcard();
    int numberchecked = numbercheck(cartao);
    bool valid = validCheck(numberchecked);

    if(valid == 1)
    {
        showflag();
    }


        printf("testtrack = %i\n", valid);

}

showflag()
{
    if (digit == 12 || digit == 16 && lastdigit == 4 )
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

long positive_int(void)
{
    long n;
    do
    {
        n = get_long("Escolha um numero de cartão de credito valido: \n");
    }
    while (n < 1000000000000);
    return n;

    n = round (n / 1000000000000);
    if (n > 9999)
}