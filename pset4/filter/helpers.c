#include "helpers.h"
#include<cs50.h>
#include<stdio.h>
#include<math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int average = round((pixel.rgbtRed + pixel.rgbtBlue + pixel.rgbtGreen) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
}

//caps the value at 255
int cap(int value)
{
    return value > 255 ? 255 : value;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int ored = pixel.rgbtRed;
            int ogreen = pixel.rgbtGreen;
            int oblue = pixel.rgbtBlue;
            image[i][j].rgbtRed = cap(round(0.393 * ored + 0.769 * ogreen + 0.189 * oblue));
            image[i][j].rgbtGreen = cap(round(0.349 * ored + 0.686 * ogreen + 0.168 * oblue));
            image[i][j].rgbtBlue = cap(round(0.272 * ored + 0.534 * ogreen + 0.131 * oblue));
        }
    }
}

//swaps the pixels for reflection
void swap(RGBTRIPLE *pixel1, RGBTRIPLE *pixel2)
{
    RGBTRIPLE temp = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = temp;
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap(&image[i][j], &image[i][width - 1 - j]);
        }
    }
}

//check for valid pixel of image
bool is_pixel(int i, int j, int height, int width)
{
    return i >= 0 && i < height && j >= 0 && j < width;
}

//get the blurred pixel
RGBTRIPLE get_blurred(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int rvalue = 0, bvalue = 0, gvalue = 0;
    int num_val_pixel = 0;
    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            int new_ip = i + di;
            int new_jp = j + dj;
            if (is_pixel(new_ip, new_jp, height, width))
            {
                num_val_pixel++;
                rvalue += image[new_ip][new_jp].rgbtRed;
                bvalue += image[new_ip][new_jp].rgbtBlue;
                gvalue += image[new_ip][new_jp].rgbtGreen;
            }
        }
    }
    RGBTRIPLE blurred_pixel;
    blurred_pixel.rgbtRed = round((float)rvalue / num_val_pixel);
    blurred_pixel.rgbtBlue = round((float)bvalue / num_val_pixel);
    blurred_pixel.rgbtGreen = round((float)gvalue / num_val_pixel);
    return blurred_pixel;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            new_image[i][j] = get_blurred(i, j, height, width, image);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j]; //copies new image to original image
        }
    }
}
