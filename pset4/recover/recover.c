//check
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check if the file exist and return a mesage if not
    if(argv[1] == NULL)
    {
    printf("Coloque o nome do arquivo a ser recuperado Ex. /recover card.raw");
    return 1;
    }

    const int BUFFER_SIZE = 512;
    BYTE buffer [BUFFER_SIZE];

    //open the file
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Erro ao abrir o arquivo. \n");
    }

    int i = 0;
    size_t sucessul_read;

    do{
        size_t sucessul_read = fread(buffer, sizeof(BYTE), BUFFER_SIZE, f);

        if (sucessul_read != BUFFER_SIZE)
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
            BYTE sucessul_write = fwrite (buffer, sizeof(BYTE), BUFFER_SIZE, img);

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
            fwrite (buffer, sizeof(BYTE), BUFFER_SIZE, img);
            i--;
        }
            i++;


    }while (sucessul_read == BUFFER_SIZE);



    fclose(img);
    fclose(f);

    return 0;
}