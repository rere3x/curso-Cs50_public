#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j <= width; j++)
        {

            float soma = image[i][j].rgbtGreen + image[i][j].rgbtRed + image[i][j].rgbtBlue;
            int average = (int)round(soma / 3);

            image[i][j].rgbtGreen   = average;
            image[i][j].rgbtBlue    = average;
            image[i][j].rgbtRed     = average;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tempImage[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int sepiaRed =     round(.393 * tempImage[i][j].rgbtRed
                                +  .769 * tempImage[i][j].rgbtGreen
                                +  .189 * tempImage[i][j].rgbtBlue);

            int sepiaGreen  =  round(.349 * tempImage[i][j].rgbtRed
                            +  .686 * tempImage[i][j].rgbtGreen
                            +  .168 * tempImage[i][j].rgbtBlue);

            int sepiaBlue   =  round(.272 * tempImage[i][j].rgbtRed
                            +  .534 * tempImage[i][j].rgbtGreen
                            +  .131 * tempImage[i][j].rgbtBlue);


            if(sepiaRed > 255) image[i][j].rgbtRed = 255;
            else image[i][j].rgbtRed = sepiaRed;

            if(sepiaGreen > 255) image[i][j].rgbtGreen = 255;
            else image[i][j].rgbtGreen = sepiaGreen;

            if(sepiaBlue > 255) image[i][j].rgbtBlue = 255;
            else image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int hafWidth = 0;

    if (width < 2)
        hafWidth = 0;
    else if(width % 2 == 0)
        hafWidth = (width / 2) - 1;
    else
        hafWidth = (width / 2) - 0.5;


     for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j <= hafWidth; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][(width - 1) - j];
            image[i][(width - 1) - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // copy the data to a temp image
    RGBTRIPLE tempImage[height][width];
    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            tempImage [i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            float somaRed = 0;
            float somaGreen = 0;
            float somaBlue = 0;

            for (int l = i-1; l <= i+1; l++)
            {
                for (int t = j-1; t <= j+1; t++)
                {
                    if((l >= 0 && t >=0) && (l < height && t < width))
                    {
                    count++;

                    somaRed += tempImage[l][t].rgbtRed;
                    somaGreen += tempImage[l][t].rgbtGreen;
                    somaBlue += tempImage[l][t].rgbtBlue;
                    }
                }
            }
            image[i][j].rgbtRed = (int)round(somaRed / count);
            image[i][j].rgbtGreen = (int)round(somaGreen / count);
            image[i][j].rgbtBlue = (int)round(somaBlue / count);
            }
        }

    return;
}
