#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check if de file exist
    if(argv[1] == NULL)
    {
    printf("Coloque o nome do arquivo a ser recuperado Ex. /recover card.raw");
    return 1;
    }


    BYTE buffer [512];

    //open the file
    FILE *f = fopen(argv[1], "r");
    int i = 0;
    size_t sucessul_read;

    do{
        size_t sucessul_read = fread(buffer, sizeof(BYTE), 512, f);

        if (sucessul_read != 512)
        {
        printf("Erro ao ler a memoria do arquivo.\n");
        return 2;
        }

        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0 )
        {
            if(i != 0)
            {
                fclose(img);
            }
            char image[10];
            sprintf(image, "%03i.jpg", i);
            FILE *img = fopen(image, "w");
            BYTE sucessul_write = fwrite (buffer, sizeof(BYTE), 512, img);

            if (sucessul_read != sucessul_write)
                {
                    printf("Erro ao gravar no arquivo de saída.\n");
                    fclose(inputFile);
                    fclose(outputFile);
                    return 1;
                }
        }
        else
        {
            fwrite (buffer, sizeof(BYTE), 512, img);
            i--;
        }
            i++;


    }while (sucessul_read == 512);



    fclose(img);
    fclose(f);

    return 0;
}