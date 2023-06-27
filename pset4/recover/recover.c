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

    typedef uint8_t BYTE;

    BYTE buffer [512];

    //open the file
    FILE *f = fopen(argv[1], "r");
    int i = 0;

    do{


    fread sucessul_read(buffer, BYTE, 512, *f);
    if (sucessul_read != 512)
    {
    printf("Erro ao ler a memoria do arquivo.\n");
    }
    return 2;

    if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0 )
    {
        
    }
    else
    {
        i--;
    }

        sprintf(image, "%03i.jpg", i);
        FILE *img = fopen(image, w);
        fwrite (buffer, BYTE, 512, *img);

        i++;
    } while (sucessul_read == 512);



    // separar em blocos do tamanho FAT(512) usando fread

    //criar um meio de ler se os 4 primeiros bits do bloco são o começo de um jpg e retornar V ou F

    fclose(f)

    return 0;
}