#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

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
    FILE *img = NULL;
    int count = 0;
    size_t sucessul_read = 0;

    // Abre o arquivo "f"
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Erro ao abrir o arquivo. \n");
        return 1;
    }
    // Loop para ler e recuperar blocos de dados do arquivo "f"
    do
    {
        // Lê o bloco de dados do arquivo "f" e armazena em "buffer"
        sucessul_read = fread(buffer, sizeof(BYTE), BUFFER_SIZE, f);

        if (sucessul_read == 0) // Se não houver mais dados para ler, sai do loop
        {
            break;
        }
        // Verifica se o bloco de dados no "buffer" representa o início de um novo arquivo JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //Confere se é o primeiro arquivo e se não for ele é fechado
            if (img != NULL)
            {
                fclose(img);
                img = NULL;
            }

            char image[10];
            sprintf(image, "%03d.jpg", count);
            img = fopen(image, "w");
            size_t sucessul_write = fwrite(buffer, sizeof(BYTE), BUFFER_SIZE, img);

            count++;
        }
        else if (img != NULL)
        {
            fseek(img, 0, SEEK_END);

            size_t sucessul_write = fwrite(buffer, sizeof(BYTE), BUFFER_SIZE, img);
            if (sucessul_write != BUFFER_SIZE)
            {
                perror("Erro ao escrever no arquivo.");
                fclose(img);
                fclose(f);
                return 1;
            }
        }
    }
    while (sucessul_read == BUFFER_SIZE);
    fclose(img);
    fclose(f);

    return 0;
}