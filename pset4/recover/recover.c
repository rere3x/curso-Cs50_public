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


    fread()
    int buffer[511];


    fclose(f)
    return 0;
}