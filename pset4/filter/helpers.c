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

    int Gx[3][3]  =  {{-1, 0, 1},
                      {-2, 0, 0},
                      {-1, 0, 1}};
    float somaGx[3] = 0;

    int Gy[3][3]  =  {{-1,-2,-1},
                      {0, 0, 0},
                      {1, 2, 1}};

    float somaGy[3] = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int l = i-1; l <= i+1; l++)
            {
                int colum = 0;
                for (int t = j-1; t <= j+1; t++)
                {
                    int line = 0;
                    if((l >= 0 && t >=0) && (l <= height-1 && t <= width-1))
                    {
                        somaGx[0] += tempImage [l][t].rgbtRed * Gx[colum][line];
                        somaGx[1] += tempImage [l][t].rgbtGreen * Gx[colum][line];
                        somaGx[2] += tempImage [l][t].rgbtBlue * Gx[colum][line];

                        somaGy[0] += tempImage [l][t].rgbtRed * Gx[colum][line];
                        somaGy[1] += tempImage [l][t].rgbtGreen * Gx[colum][line];
                        somaGy[2] += tempImage [l][t].rgbtBlue * Gx[colum][line];


                    }
                }
            }
            
        }

/*
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float Gx[3]= {0, 0, 0};
            float Gy[3] = {0, 0, 0};

            int gxcolum = 1;
            int gycolum = -1;

            for (int l = i-1; l <= i+1; l++)
            {

                int gxline = -1;
                if(gxcolum == 3)
                gxcolum = 1;

                for (int t = j-1; t <= j+1; t++)
                {

                    if((l >= 0 && t >=0) && (l <= height-1 && t <= width-1))
                    {
                        count++;
                        int gMultiplayer = gxline * gxcolum;
                        Gx[0] += tempImage [l][t].rgbtRed * gMultiplayer;
                        Gx[1] += tempImage [l][t].rgbtGreen * gMultiplayer;
                        Gx[2] += tempImage [l][t].rgbtBlue * gMultiplayer;
                        gxline++;
                    }else
                    {
                        count++;
                        Gx[0] += 0;
                        Gx[1] += 0;
                        Gx[2] += 0;
                        gxline++;
                    }

                        //gcolum = 1 /2 / 3 x gline -1 / 0 / 1
                }
                        gxcolum++;

            }

            for (int l = i-1; l <= i+1; l++)
            {

                int gyline = 1;

                for (int t = j-1; t <= j+1; t++)
                {

                    if((l >= 0 && t >=0) && (l <= height-1 && t <= width-1))
                    {
                        if(gyline == 3)
                        gyline = 1;
                        count++;
                        int gMultiplayer = gyline * gycolum;
                        Gy[0] += tempImage [l][t].rgbtRed * gMultiplayer;
                        Gy[1] += tempImage [l][t].rgbtGreen * gMultiplayer;
                        Gy[2] += tempImage [l][t].rgbtBlue * gMultiplayer;
                        gyline++;
                    }else
                    {
                        count++;
                        Gy[0] += 0;
                        Gy[1] += 0;
                        Gy[2] += 0;
                        gyline++;

                    }

                        //gcolum = -1 /0 / 1 x gline 1 / 2 / 3
                }
                        gycolum++;

            }
            if(sqrt( pow(Gx[0],2) + pow(Gy[0],2)) > 255.00)
                image[i][j].rgbtRed = 255;
                else
                image[i][j].rgbtRed = (int)round(sqrt( pow(Gx[0],2) + pow(Gy[0],2)));

            if(sqrt( pow(Gx[1],2) + pow(Gy[1],2)) > 255.00)
                image[i][j].rgbtGreen = 255;
                else
                image[i][j].rgbtGreen = (int)round(sqrt( pow(Gx[1],2) + pow(Gy[1],2)));

            if(sqrt( pow(Gx[2],2) + pow(Gy[2],2)) > 255.00)
                image[i][j].rgbtBlue = 255;
                else
                image[i][j].rgbtBlue = (int)round(sqrt( pow(Gx[2],2) + pow(Gy[2],2)));



            }
        }
*/
    return;
}
