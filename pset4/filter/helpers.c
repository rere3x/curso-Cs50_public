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

    // copy the data to a temp image
    RGBTRIPLE tempImage[height][width];
      for (int i = 0; i < height; i++)
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
                    if((l >= 0 && t >=0) && (l <= height-1 && t <= width-1))
                    {
                    count++;

                    somaRed += tempImage [l][t].rgbtRed;
                    somaGreen += tempImage [l][t].rgbtGreen;
                    somaBlue += tempImage [l][t].rgbtBlue;

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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    // copy the data to a temp image
    RGBTRIPLE tempImage[height][width];
      for (int i = 0; i < height; i++)
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
            float Gx[2] = 0.0;
            float Gy[2] = 0.0;


            for (int l = i-1; l <= i+1; l++)
            {
                int gcolum = 1;

                for (int t = j-1; t <= j+1; t++)
                {
                    int gline = -1;

                    if((l >= 0 || t >=0) || (l <= height-1 || t <= width-1))
                    {

                        tempImage [l][t].rgbtRed = 0;
                        tempImage [l][t].rgbtGreen = 0;
                        tempImage [l][t].rgbtBlue = 0;

                        int gxMultiplayer = gline * gcolum;
                        Gx += tempImage [l][t].rgbtRed * gxMultiplayer;
                        gline++;

                    }else
                    {
                        int gxMultiplayer = gline * gcolum;
                        Gx[0] += tempImage [l][t].rgbtRed * gxMultiplayer;
                        Gx[1] += tempImage [l][t].rgbtGreen * gxMultiplayer;
                        Gx[2] += tempImage [l][t].rgbtBlue * gxMultiplayer;
                        gline++;
                    }
                        //l = 1 /2 / 3 x t -1 / 0 / 1
                }

                        gcolum++;
                        if(gcolum < 3)
                        gcolum = 1;


            }

            for (int l = i-1; l <= i+1; l++)
            {
                int gcolum = 1;

                for (int t = j-1; t <= j+1; t++)
                {
                    int gline = -1;

                    if((l >= 0 || t >=0) || (l <= height-1 || t <= width-1))
                    {

                        tempImage [l][t].rgbtRed = 0;
                        tempImage [l][t].rgbtGreen = 0;
                        tempImage [l][t].rgbtBlue = 0;

                        int gxMultiplayer = gline * gcolum;
                        Gy += tempImage [l][t].rgbtRed * gxMultiplayer;
                        gcolum++;

                    }else
                    {
                        int gxMultiplayer = gline * gcolum;
                        Gy[0] += tempImage [l][t].rgbtRed * gxMultiplayer;
                        Gy[1] += tempImage [l][t].rgbtGreen * gxMultiplayer;
                        Gy[2] += tempImage [l][t].rgbtBlue * gxMultiplayer;
                        gcolum++;
                    }
                        //l = 1 /2 / 3 x t -1 / 0 / 1
                }

                        gline++;
                        if(gline < 3)
                        gline = 1;


            }

            image[i][j].rgbtRed = sqrt( (Gx[0] * Gx[0]) + (Gy[0] * Gy[0]);
            image[i][j].rgbtGreen = sqrt( (Gx[1] * Gx[1]) + (Gy[1] * Gy[1]);
            image[i][j].rgbtBlue = sqrt( (Gx[2] * Gx[2]) + (Gy[2] * Gy[2]);

            }
        }

    return;
}
