// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
const int SAMPLE_SIZE = 2;
typedef int16_t WAVE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    //Copy header from input file to output file
    WAVE buffer[HEADER_SIZE];

    size_t inputwave fread(buffer, sizeof(WAVE),HEADER_SIZE, input);
    if (inputwave != HEADER_SIZE)
            {
                perror("Erro ao ler o arquivo.");
                fclose(input);
                fclose(output);
                return 1;
            }
    fseek(output, 0, SEEK_END);
    size_t outputwave fwrite(buffer, sizeof(WAVE),HEADER_SIZE, output);
    if (outputwave != HEADER_SIZE)
            {
                perror("Erro ao escrever no arquivo.");
                fclose(input);
                fclose(output);
                return 1;
            }


    // Read samples from input file and write updated data to output file
    do{
        WAVE buffer[SAMPLE_SIZE];

    size_t inputwave fread(buffer, sizeof(WAVE),SAMPLE_SIZE, input);
    if (inputwave != SAMPLE_SIZE)
            {
                error_check (inputwave)
            }
    fseek(output, 0, SEEK_END);
    size_t outputwave fwrite(buffer, sizeof(WAVE),SAMPLE_SIZE, output);
    if (outputwave != SAMPLE_SIZE)
            {
                error_check (outputwave)
            }
    }

    // Close files
    fclose(input);
    fclose(output);
}

void error_check (valueCheck)
{
    if(valueCheck == 44)
    {
    perror("Erro ao ler o arquivo.");
                fclose(input);
                fclose(output);
                return 1;
    }else
    perror("Erro ao escrever no arquivo.");
                fclose(input);
                fclose(output);
                return 1;

}
