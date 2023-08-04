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
    BYTE buffer[BUFFER_SIZE];

    //open the file
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Erro ao abrir o arquivo. \n");
    }

    FILE *img = NULL;

    int count = 0;
    int offsetcount = 1;
    size_t sucessul_read = 0;




    do{
        sucessul_read = fread(buffer, sizeof(BYTE), BUFFER_SIZE, f);//le o bloco de dados do arquivo "f"
        if (sucessul_read == 0) // Se não houver mais dados para ler
        {
            break; // Sai do loop
        }


        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0 )
        {
            if(img != NULL){
            fclose(img);
            }

            char image[10];
            sprintf(image, "%03d.jpg", count);
            img = fopen(image, "w");
            size_t sucessul_write = fwrite (buffer, sizeof(BYTE), BUFFER_SIZE, img);

            offsetcount++;
            count++;

        }else if (img != NULL)
        {
            size_t sucessul_write = fwrite (buffer, sizeof(BYTE), BUFFER_SIZE, img);

            if (sucessul_write != BUFFER_SIZE)
                {
                    if (feof(img))
                    {
                        printf("Alcançou o fim do arquivo. \n");
                        break;
                        return 1;
                    } else if (ferror(img))
                    {
                        perror("Erro ao ler o arquivo.");
                        break;
                        return 1;
                    }

                }
            fseek(img, (BUFFER_SIZE * offsetcount), SEEK_SET);
            offsetcount++;
        }
        fseek(f, (BUFFER_SIZE * offsetcount), SEEK_SET);

        }while (sucessul_read == BUFFER_SIZE);




    fclose(f);

    return 0;
}