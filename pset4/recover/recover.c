#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Verifica se o nome do arquivo foi passado como argumento
    if (argv[1] == NULL)
    {
        printf("Coloque o nome do arquivo a ser recuperado. Ex.: ./recover card.raw\n");
        return 1;
    }

    const int BUFFER_SIZE = 512;
    BYTE buffer[BUFFER_SIZE];

    // Abre o arquivo "f"
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Erro ao abrir o arquivo. \n");
        return 1;
    }

    FILE *img = NULL;

    int count = 0;
    int offsetcount = 1;
    size_t sucessul_read = 0;

    do
    {
        // Le o bloco de dados do arquivo "f"
        sucessul_read = fread(buffer, sizeof(BYTE), BUFFER_SIZE, f);

        if (sucessul_read == 0) // Se não houver mais dados para ler
        {
            break; // Sai do loop
        }

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
                img = NULL; // Define img como NULL para indicar que não há arquivo aberto
            }

            char image[10];
            sprintf(image, "%03d.jpg", count);
            img = fopen(image, "w");
            size_t sucessul_write = fwrite(buffer, sizeof(BYTE), BUFFER_SIZE, img);

            offsetcount++;
            count++;
        }
        else if (img != NULL)
        {
            size_t sucessul_write = fwrite(buffer, sizeof(BYTE), BUFFER_SIZE, img);

            if (sucessul_write != BUFFER_SIZE)
            {
                perror("Erro ao escrever no arquivo.");
                fclose(img);
                fclose(f);
                return 1;
            }
            fseek(img, (BUFFER_SIZE * offsetcount), SEEK_SET);
            offsetcount++;
        }
    } while (sucessul_read == BUFFER_SIZE);

    fclose(f);
    if (img != NULL)
    {
        fclose(img);
    }

    return 0;
}