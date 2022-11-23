#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //check if de file exist
    if(argv[1] == NULL)
    {
    printf("Coloque o nome do arquivo a ser recuperado Ex. /recover card.raw")
    return 1;
    }
    //open the file
    FILE *f = fopen(agrv[1], "r");


    int buffer[511];

    fread(buffer, 4, 512, *f)
    if( buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)

    sprintf(filename, "%03i.jpg", 2);
    FILE *image = fopen(filename, "w");
    




    fclose(f)
    return 0;
}