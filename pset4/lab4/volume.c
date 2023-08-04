// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
const int SAMPLE_SIZE = 2;
typedef int16_t WAVE;

void error_check (char valueCheck[10]);

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

    size_t inputwave = fread(buffer, sizeof(WAVE),HEADER_SIZE, input);
    if (inputwave != HEADER_SIZE)
            {
                error_check ("inputwave");
            }
    fseek(output, 0, SEEK_END);
    size_t outputwave = fwrite(buffer, sizeof(WAVE),HEADER_SIZE, output);
    if (outputwave != HEADER_SIZE)
            {
                error_check ("outputwave");
            }

    // Read samples from input file and write updated data to output file
    do{
        buffer[SAMPLE_SIZE];

        inputwave = fread(buffer, sizeof(WAVE),SAMPLE_SIZE, input);
        if (inputwave != SAMPLE_SIZE)
                {
                    error_check ("inputwave");
                }
        fseek(output, 0, SEEK_END);
        outputwave = fwrite(buffer, sizeof(WAVE),SAMPLE_SIZE, output);
        if (outputwave != SAMPLE_SIZE)
                {
                    error_check ("outputwave");
                }

    }
    while(inputwave == SAMPLE_SIZE);

    // Close files
    fclose(input);
    fclose(output);
}

void error_check (char valueCheck[10])
{
    if(valueCheck[0] == "i")
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
