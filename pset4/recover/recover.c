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
        // Lê o bloco de dados do arquivo "f" e armazena no "buffer"
        sucessul_read = fread(buffer, sizeof(BYTE), BUFFER_SIZE, f);

        // Se não houver mais dados para ler, sai do loop
        if (sucessul_read == 0)
        {
            break;
        }

        // Verifica se o bloco de dados no "buffer" representa o início de um novo arquivo JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Confere se é o primeiro arquivo, e se não for ele é fechado
            if (img != NULL)
            {
                fclose(img);
                img = NULL;
            }

            char image[10]; // Cria um nome para o novo arquivo JPEG baseado no valor atual de "count"
            sprintf(image, "%03d.jpg", count);

            img = fopen(image, "w"); // Abre um novo arquivo JPEG com o nome "image" no modo de escrita ("w")
            size_t sucessul_write = fwrite(buffer, sizeof(BYTE), BUFFER_SIZE, img); // Escreve o bloco de dados no novo arquivo JPEG

            count++; // Incrementa o valor de "count" para representar um novo arquivo criado
        }
        else if (img != NULL)
        {
            fseek(img, 0, SEEK_END); // Move o ponteiro do arquivo "img" para o final do arquivo existente

            size_t sucessul_write = fwrite(buffer, sizeof(BYTE), BUFFER_SIZE, img); // Escreve o bloco de dados no arquivo JPEG existente

            // Verifica se todos os bytes foram gravados corretamente
            if (sucessul_write != BUFFER_SIZE)
            {
                perror("Erro ao escrever no arquivo.");
                fclose(img);
                fclose(f);
                return 1;
            }
        }
    }
    // Continua o loop enquanto houver dados a serem lidos do arquivo "f"
    while (sucessul_read == BUFFER_SIZE);

    // Fecha o arquivo "img" e "f"
    fclose(img);
    fclose(f);

    return 0;
}