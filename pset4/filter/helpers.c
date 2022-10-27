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
        for (int j = 0; j <= width; j++)
        {
            tempImage [i][j] = image[i][j];
        }
    }
    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            int sepiaRed    =  round(.393 * tempImage[i][j].rgbtRed
                            +  .769 * tempImage[i][j].rgbtGreen
                            +  .769 * tempImage[i][j].rgbtBlue);

            int sepiaGreen  =  round(.349 * tempImage[i][j].rgbtRed
                            +  .686 * tempImage[i][j].rgbtGreen
                            +  .168 * tempImage[i][j].rgbtBlue);

            int sepiaBlue   =  round(.272 * tempImage[i][j].rgbtRed
                            +  .534 * tempImage[i][j].rgbtGreen
                            +  .131 * tempImage[i][j].rgbtBlue);

            if(sepiaRed > 255) image[i][j].rgbtRed = 255;
            else image[i][j].rgbtRed = sepiaRed;

            if(sepiaGreen > 255) image[i][j].rgbtGreen = 255;
            else image[i][j].rgbtRed = sepiaGreen;

            if(sepiaBlue > 255) image[i][j].rgbtBlue = 255;
            else image[i][j].rgbtRed = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
