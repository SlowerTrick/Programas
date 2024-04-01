#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int vermelho = image[i][j].rgbtRed;
            int azul = image[i][j].rgbtBlue;
            int verde = image[i][j].rgbtGreen;

            int media = (vermelho + azul + verde) / 3;

            image[i][j].rgbtRed = media;
            image[i][j].rgbtBlue = media;
            image[i][j].rgbtGreen = media;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int vermelho1 = image[i][j].rgbtRed;
            int azul1 = image[i][j].rgbtBlue;
            int verde1 = image[i][j].rgbtGreen;

            int vermelho2 = image[i][width - j].rgbtRed;
            int azul2 = image[i][width - j].rgbtBlue;
            int verde2 = image[i][width - j].rgbtGreen;

            image[i][j].rgbtRed = vermelho2;
            image[i][j].rgbtBlue = azul2;
            image[i][j].rgbtGreen = verde2;

            image[i][width - j].rgbtRed = vermelho1;
            image[i][width - j].rgbtBlue = azul1;
            image[i][width - j].rgbtGreen = verde1;
        }
    }
    return;
}

// Blur image

void blur(int height, int width, RGBTRIPLE image[height][width])
{
        for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0)
            {
                int vermelho = (image[0][0].rgbtRed + image[0][1].rgbtRed + image[1][0].rgbtRed + image[1][1].rgbtRed) / 4;
                int azul = (image[0][0].rgbtBlue + image[0][1].rgbtBlue + image[1][0].rgbtBlue + image[1][1].rgbtBlue) / 4;
                int verde = (image[0][0].rgbtGreen + image[0][1].rgbtGreen + image[1][0].rgbtGreen + image[1][1].rgbtGreen) / 4;

                image[0][0].rgbtRed = vermelho;
                image[0][0].rgbtBlue = azul;
                image[0][0].rgbtGreen = verde;
            }

            else if (i == 0 && j == width - 1)

            {
                int vermelho = (image[0][width - 1].rgbtRed + image[0][width - 2].rgbtRed + image[1][width - 2].rgbtRed + image[1][width - 1].rgbtRed) / 4;
                int azul = (image[0][width - 1].rgbtBlue + image[0][width - 2].rgbtBlue + image[1][width - 2].rgbtBlue + image[1][width - 1].rgbtBlue) / 4;
                int verde = (image[0][width - 1].rgbtGreen + image[0][width - 2].rgbtGreen + image[1][width - 2].rgbtGreen + image[1][width - 1].rgbtGreen) / 4;

                image[0][width - 1].rgbtRed = vermelho;
                image[0][width - 1].rgbtBlue = azul;
                image[0][width - 1].rgbtGreen = verde;
            }

            else if (i == height - 1 && j == 0)

            {
                int vermelho = (image[height - 1][0].rgbtRed + image[height - 2][0].rgbtRed + image[height - 2][1].rgbtRed + image[height - 1][1].rgbtRed) / 4;
                int azul = (image[height - 1][0].rgbtBlue + image[height - 2][0].rgbtBlue + image[height - 2][1].rgbtBlue + image[height - 1][1].rgbtBlue) / 4;
                int verde = (image[height - 1][0].rgbtGreen + image[height - 2][0].rgbtGreen + image[height - 2][1].rgbtGreen + image[height - 1][1].rgbtGreen) / 4;

                image[height - 1][0].rgbtRed = vermelho;
                image[height - 1][0].rgbtBlue = azul;
                image[height - 1][0].rgbtGreen = verde;
            }

            else if (i == height - 1 && j == width - 1)
            {
                int vermelho = (image[height - 1][width - 1].rgbtRed + image[height - 2][width - 1].rgbtRed + image[height - 2][width - 2].rgbtRed + image[height - 1][width - 2].rgbtRed) / 4;
                int azul = (image[height - 1][width - 1].rgbtBlue + image[height - 2][width - 1].rgbtBlue + image[height - 2][width - 2].rgbtBlue + image[height - 1][width - 2].rgbtBlue) / 4;
                int verde = (image[height - 1][width - 1].rgbtGreen + image[height - 2][width - 1].rgbtGreen + image[height - 2][width - 2].rgbtGreen + image[height - 1][width - 2].rgbtGreen) / 4;

                image[height - 1][width - 1].rgbtRed = vermelho;
                image[height - 1][width - 1].rgbtBlue = azul;
                image[height - 1][width - 1].rgbtGreen = verde;
            }
            else if ((i == 0 && j > 0 && j < width - 1) || (i == height - 1 && j > 0 && j < width - 1) || (i > 0 && i < height - 1 && j == 0) || (i > 0 && i < height - 1 && j == width - 1))
            {
                if (i == 0)
                {
                    int vermelho = (image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j+1].rgbtRed) / 6;
                    int azul = (image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j+1].rgbtBlue) / 6;
                    int verde = (image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j+1].rgbtGreen) / 6;

                    image[i][j].rgbtRed = vermelho;
                    image[i][j].rgbtBlue = azul;
                    image[i][j].rgbtGreen = verde;
                }

                if (i == height - 1)
                {
                    int vermelho = (image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j+1].rgbtRed) / 6;
                    int azul = (image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j+1].rgbtBlue) / 6;
                    int verde = (image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j+1].rgbtGreen) / 6;

                    image[i][j].rgbtRed = vermelho;
                    image[i][j].rgbtBlue = azul;
                    image[i][j].rgbtGreen = verde;
                }

                if (j == 0)
                {
                    int vermelho = (image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed) / 6;
                    int azul = (image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / 6;
                    int verde = (image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen) / 6;

                    image[i][j].rgbtRed = vermelho;
                    image[i][j].rgbtBlue = azul;
                    image[i][j].rgbtGreen = verde;
                }
                if (j == width - 1)
                {
                    int vermelho = (image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed) / 6;
                    int azul = (image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue) / 6;
                    int verde = (image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen) / 6;

                    image[i][j].rgbtRed = vermelho;
                    image[i][j].rgbtBlue = azul;
                    image[i][j].rgbtGreen = verde;
                }
            }
            else
            {
                int vermelho = (image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j+1].rgbtRed + image[i-1][j+1].rgbtRed) / 9;
                int azul = (image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i-1][j+1].rgbtBlue) / 9;
                int verde = (image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i-1][j+1].rgbtGreen) / 9;

                image[i][j].rgbtRed = vermelho;
                image[i][j].rgbtBlue = azul;
                image[i][j].rgbtGreen = verde;
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
       //temp image
    RGBTRIPLE temp[height][width];

    //gx and gy kernels
    int gxarr[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int gyarr[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

    //copying image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++) //
        {
            temp[i][j] = image[i][j];
        }
    }

    //iterating through image
    for (int i = 0; i < height; i++)    //
    {
        for (int j = 0; j < width; j++)
        {
            //setting all gx and gy values to 0
            int gxred = 0;
            int gyred = 0;

            int gxblue = 0;
            int gyblue = 0;

            int gxgreen = 0;
            int gygreen = 0; //

            int countx = 0;
            int county = 0;

            //indexing through 3x3 grid surrounding pixel
            for (int k = i - 1; k < i + 2; k++)
            {
                for (int l = j - 1; l < j + 2; l++)
                {
                    //not counting pixels that arent in the boundary
                    if (k < 0 || l < 0 || k > height - 1 || l > width - 1)
                    {
                        countx++;
                        county++;
                        continue;
                    }

                    //updating gx and gy values according to  3x3 pixel
                    gxred += (gxarr[countx] * temp[k][l].rgbtRed);
                    gxblue += (gxarr[countx] * temp[k][l].rgbtBlue);
                    gxgreen += (gxarr[countx] * temp[k][l].rgbtGreen);

                    gyred += (gyarr[county] * temp[k][l].rgbtRed);
                    gyblue += (gyarr[county] * temp[k][l].rgbtBlue);        //
                    gygreen += (gyarr[county] * temp[k][l].rgbtGreen);

                    //index of gx gy kernel
                    countx++;
                    county++;

                }
            }

            //calculating gx and gy
            int gred = round(sqrt(pow(gxred, 2) + pow(gyred, 2)));
            int gblue = round(sqrt(pow(gxblue, 2) + pow(gyblue, 2)));   //
            int ggreen = round(sqrt(pow(gxgreen, 2) + pow(gygreen, 2)));

            //condition for gx or gy being above 255
            gred = gred > 255 ? 255 : gred;
            gblue = gblue > 255 ? 255 : gblue;
            ggreen = ggreen > 255 ? 255 : ggreen;

            //updating colour of pixel
            image[i][j].rgbtRed = gred;
            image[i][j].rgbtBlue = gblue;
            image[i][j].rgbtGreen = ggreen;

        }
    }
    return;
}
/*
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0)
            {}
            else if (i == 0 && j == width - 1)
            {}
            else if (i == height - 1 && j == 0)
            {}
            else if (i == height - 1 && j == width - 1)
            {}
            else if ((i == 0 && j > 0 && j < width - 1) || (i == height - 1 && j > 0 && j < width - 1) || (i > 0 && i < height - 1 && j == 0) || (i > 0 && i < height - 1 && j == width - 1))
            {}

            else
            {
                int vermelhogx = ((image[i][j].rgbtRed * 0) + (image[i][j-1].rgbtRed * -2) + (image[i-1][j].rgbtRed * 0) + (image[i-1][j-1].rgbtRed * -1) + (image[i+1][j].rgbtRed * 0) + (image[i+1][j-1].rgbtRed * -1) + (image[i][j+1].rgbtRed * 2) + (image[i+1][j+1].rgbtRed * 1)  + (image[i-1][j+1].rgbtRed * 1));
                int azulgx = ((image[i][j].rgbtBlue * 0) + (image[i][j-1].rgbtBlue * -2) + (image[i-1][j].rgbtBlue * 0)  + (image[i-1][j-1].rgbtBlue * -1) + (image[i+1][j].rgbtBlue * 0) + (image[i+1][j-1].rgbtBlue * -1) + (image[i][j+1].rgbtBlue * 2) + (image[i+1][j+1].rgbtBlue * 1) + (image[i-1][j+1].rgbtBlue * 1));
                int verdegx = ((image[i][j].rgbtGreen * 0) + (image[i][j-1].rgbtGreen * -2) + (image[i-1][j].rgbtGreen * 0) + (image[i-1][j-1].rgbtGreen * -1) + (image[i+1][j].rgbtGreen * 0) + (image[i+1][j-1].rgbtGreen * -1) + (image[i][j+1].rgbtGreen * 2) + (image[i+1][j+1].rgbtGreen * 1) + (image[i-1][j+1].rgbtGreen * 1));

                int vermelhogy = ((image[i][j].rgbtRed * 0) + (image[i][j-1].rgbtRed * 0) + (image[i-1][j].rgbtRed * -2) + (image[i-1][j-1].rgbtRed * -1) + (image[i+1][j].rgbtRed * 2) + (image[i+1][j-1].rgbtRed * 1) + (image[i][j+1].rgbtRed * 0) + (image[i+1][j+1].rgbtRed * 1)  + (image[i-1][j+1].rgbtRed * -1));
                int azulgy = ((image[i][j].rgbtBlue * 0) + (image[i][j-1].rgbtBlue * 0) + (image[i-1][j].rgbtBlue * -2)  + (image[i-1][j-1].rgbtBlue * -1) + (image[i+1][j].rgbtBlue * 2) + (image[i+1][j-1].rgbtBlue * 1) + (image[i][j+1].rgbtBlue * 0) + (image[i+1][j+1].rgbtBlue * 1) + (image[i-1][j+1].rgbtBlue * -1));
                int verdegy = ((image[i][j].rgbtGreen * 0) + (image[i][j-1].rgbtGreen * 0) + (image[i-1][j].rgbtGreen * -2) + (image[i-1][j-1].rgbtGreen * -1) + (image[i+1][j].rgbtGreen * 2) + (image[i+1][j-1].rgbtGreen * 1) + (image[i][j+1].rgbtGreen * 0) + (image[i+1][j+1].rgbtGreen * 1) + (image[i-1][j+1].rgbtGreen * -1));

                float magnitude_vermelho = sqrt((float)(vermelhogx * vermelhogx) + (float)(vermelhogy * vermelhogy));
                float magnitude_azul = sqrt((float)(azulgx * azulgx) + (float)(azulgy * azulgy));
                float magnitude_verde = sqrt((float)(verdegx * verdegx) + (float)(verdegy * verdegy));

                // Limitar valores de magnitude
                if (magnitude_vermelho > 255)
                {
                    magnitude_vermelho = 255;
                }
                if (magnitude_azul > 255)
                {
                    magnitude_azul = 255;
                }
                if (magnitude_verde > 255)
                {
                    magnitude_verde = 255;
                }

                // Atualizar valores de pixel
                image[i][j].rgbtRed = (int)magnitude_vermelho;
                image[i][j].rgbtBlue = (int)magnitude_azul;
                image[i][j].rgbtGreen = (int)magnitude_verde;
            }
        }
    }
}
*/
