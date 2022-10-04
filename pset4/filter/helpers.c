#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j <= width; j++)
        {

            float soma    = image[i][j].rgbtGreen + image[i][j].rgbtRed + image[i][j].rgbtBlue;
            int average = (int)round(soma / 3);

            image[i][j].rgbtGreen   = average;
            image[i][j].rgbtBlue    = average;
            image[i][j].rgbtRed     = average;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int hafWidth = 0;

    if (width == 1)
        hafWidth = 0;
    else if (width == 2)
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
    int average = 9;
    RGBTRIPLE tempImage[height][width];
      for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tempImage [i][j] = image[i][j];
        }
    }

     for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if(i < 0 || i >= width && j < 0 || j >= height)
                average -= 5;
            if else(i < 0 || i >= width || j < 0 || j >= height)
                average -= 3;


                RGBTRIPLE Average[i][j]  =
                tempImage [i - 1][j - 1].rgbtRed  +
                tempImage [i - 1][j].rgbtRed      +
                tempImage [i - 1][j + 1].rgbtRed  +
                tempImage [i][j - 1].rgbtRed      +
                tempImage [i][j].rgbtRed          +
                tempImage [i][j + 1].rgbtRed      +
                tempImage [i + 1][j - 1].rgbtRed  +
                tempImage [i + 1][j].rgbtRed      +
                tempImage [i + 1][j + 1].rgbtRed  ;
            RGBTRIPLE Image [i][j];
        }
    }



    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
