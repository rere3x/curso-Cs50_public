#include<stdio.h>
#include<cs50.h>
#include<math.h>


    int trackNumber = 0;
    int digit;
    bool validCheck(int n);
    int numbercheck(long cartao);
    showflag();

int main(void)
{

    long cartao = get_long("Teste seu cartão de credito: ");
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
