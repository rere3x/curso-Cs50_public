#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Verifica se o nome do arquivo foi passado como argumento
    if (argc != 2)
    {
        printf("Uso: %s arquivo\n", argv[0]);
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
    size_t successful_read = 0;

    do
    {
        // Lê o bloco de dados do arquivo "f"
        successful_read = fread(buffer, sizeof(BYTE), BUFFER_SIZE, f);

        if (successful_read == 0) // Se não houver mais dados para ler
        {
            break; // Sai do loop
        }

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }

            char image[10];
            sprintf(image, "%03d.jpg", count);
            img = fopen(image, "w");
            size_t successful_write = fwrite(buffer, sizeof(BYTE), successful_read, img);

            count++;
        }
        else if (img != NULL)
        {
            fseek(img, 0, SEEK_END); // Move o ponteiro para o final do arquivo img
            size_t successful_write = fwrite(buffer, sizeof(BYTE), successful_read, img);

            if (successful_write != successful_read)
            {
                perror("Erro ao escrever no arquivo.");
                fclose(img);
                fclose(f);
                return 1;
            }
        }
    } while (successful_read == BUFFER_SIZE);

    fclose(img);
    fclose(f);

    return 0;
}