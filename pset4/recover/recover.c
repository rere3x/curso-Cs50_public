#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    //check if de file exist
    if(argv[1] == NULL)
    {
    printf("Coloque o nome do arquivo a ser recuperado Ex. /recover card.raw");
    return 1;
    }

    char filename[] = "argv[1]";
    typedef uint8_t BYTE;

    BYTE buffer [512];

    //open the file
    FILE *f = fopen(argv[1], "r");


    fread ( ,512,512,*f)

    // separar em blocos do tamanho FAT(512) usando fread

    //criar um meio de ler se os 4 primeiros bits do bloco são o começo de um jpg e retornar V ou F

    fclose(f)
    return 0;
}