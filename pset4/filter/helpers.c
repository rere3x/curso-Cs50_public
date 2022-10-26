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

    int Gx[2][2]  =  {{-1, 0, 1},
                      {-2, 0, 2},
                      {-1, 0, 1}};

    float somaGx[3] = {0, 0, 0};

    int Gy[2][2]  =  {{-1,-2,-1},
                      {0, 0, 0},
                      {1, 2, 1}};

    float somaGy[3] = {0, 0, 0};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {int count = 0;
            int colum = 0;
            for (int l = i-1; l <= i+1; l++)
            {
                int line = 0;
                for (int t = j-1; t <= j+1; t++)
                {
                    if((l >= 0 && t >=0) && (l <= height-1 && t <= width-1))
                    {
                        somaGx[0] += tempImage [l][t].rgbtRed * Gx[colum][line];
                        somaGx[1] += tempImage [l][t].rgbtGreen * Gx[colum][line];
                        somaGx[2] += tempImage [l][t].rgbtBlue * Gx[colum][line];

                        somaGy[0] += tempImage [l][t].rgbtRed * Gy[colum][line];
                        somaGy[1] += tempImage [l][t].rgbtGreen * Gy[colum][line];
                        somaGy[2] += tempImage [l][t].rgbtBlue * Gy[colum][line];
                        line++;

                    }else
                    {
                        somaGx[0] += 0;
                        somaGx[1] += 0;
                        somaGx[2] += 0;

                        somaGy[0] += 0;
                        somaGy[1] += 0;
                        somaGy[2] += 0;
                        line++;
                    }
                    count++;
                }
                colum++;
            }

            if((sqrt( pow(somaGx[0],2) + pow(somaGy[0],2))) > 255.00) image[i][j].rgbtRed = 255;
            else
            image[i][j].rgbtRed = (int)round(sqrt( pow(somaGx[0],2) + pow(somaGy[0],2)));

            if((sqrt( pow(somaGx[1],2) + pow(somaGy[1],2))) > 255.00) image[i][j].rgbtGreen = 255;
            else
            image[i][j].rgbtGreen = (int)round(sqrt( pow(somaGx[1],2) + pow(somaGy[1],2)));

            if((sqrt( pow(somaGx[2],2) + pow(somaGy[2],2))) > 255.00) image[i][j].rgbtBlue = 255;
            else
            image[i][j].rgbtBlue = (int)round(sqrt( pow(somaGx[2],2) + pow(somaGy[2],2)));

            }

            }
    return;
}


