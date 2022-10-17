#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    double gray = 0;
    for(int r = 0; r < height; r++){
        for(int c = 0; c < width; c++){
            gray = image[r][c].rgbtBlue + image[r][c].rgbtRed + image[r][c].rgbtGreen;
            gray /= 3.0;
            image[r][c].rgbtBlue = round(gray);
            image[r][c].rgbtRed = round(gray);
            image[r][c].rgbtGreen = round(gray);
            //avg the red/green/blue values out. Then set the pixel with each rgb with the same value. 
        }
    }
    
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //sepiared = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
    //sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    //sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
    double sepiared = 0;
    double sepiablue = 0;
    double sepiagreen = 0;

    for(int r = 0; r < height; r++){
        for(int c = 0; c < width; c++){
            sepiared = (.393 * image[r][c].rgbtRed) + (.769 * image[r][c].rgbtGreen) + (.189 * image[r][c].rgbtBlue);
            sepiagreen = (.349 * image[r][c].rgbtRed) + (.686 * image[r][c].rgbtGreen) + (.168 * image[r][c].rgbtBlue);
            sepiablue = (.272 * image[r][c].rgbtRed) + (.534 * image[r][c].rgbtGreen) + (.131 * image[r][c].rgbtBlue);
            
            if(sepiared > 255){
                sepiared = 255;
            }
            if(sepiagreen > 255){
                sepiagreen = 255;
            }
            if(sepiablue > 255){
                sepiablue = 255;
            }
            
            image[r][c].rgbtRed = round(sepiared);
            image[r][c].rgbtGreen = round(sepiagreen);
            image[r][c].rgbtBlue = round(sepiablue);
        }
    }

    
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //For each row, you're switching each column. For example column 1 is switched with column 10. 
    int count = width - 1;
    double w = width - 1;
    for(int r = 0; r < height; r++){ //[10, 1 , 2, 3, 4, 5, 6, 7, 8, 9, 0]
        for(int c = 0; c < round(w / 2); c++){
            RGBTRIPLE x = image[r][c];
            image[r][c] = image[r][count];
            image[r][count] = x;
            count--;
        }
        count = width - 1;
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    
    for(int a = 0; a < height; a++){
        for(int b = 0; b < width; b++){
            temp[a][b] = image[a][b];
        }
    }
    
    int x = 0;
    int y = 0;
    
    for(int r = 0; r < height; r++){
        for(int c = 0; c < width; c++){
            if(r == 0 && c == 0){
                
                image[r][c].rgbtRed = round((temp[r][c].rgbtRed + temp[r][c+1].rgbtRed + temp[r+1][c].rgbtRed + temp[r+1][c+1].rgbtRed) / 4.0);
                image[r][c].rgbtBlue = round((temp[r][c].rgbtBlue + temp[r][c+1].rgbtBlue + temp[r+1][c].rgbtBlue + temp[r+1][c+1].rgbtBlue) / 4.0);
                image[r][c].rgbtGreen = round((temp[r][c].rgbtGreen + temp[r][c+1].rgbtGreen + temp[r+1][c].rgbtGreen + temp[r+1][c+1].rgbtGreen) / 4.0);
                
            } else if (r == height-1 && c == width-1){
             
                image[r][c].rgbtRed = round((temp[r-1][c-1].rgbtRed + temp[r-1][c].rgbtRed + temp[r][c-1].rgbtRed + temp[r][c].rgbtRed) / 4.0);
                image[r][c].rgbtBlue = round((temp[r-1][c-1].rgbtBlue + temp[r-1][c].rgbtBlue + temp[r][c-1].rgbtBlue + temp[r][c].rgbtBlue) / 4.0);
                image[r][c].rgbtGreen = round((temp[r-1][c-1].rgbtGreen + temp[r-1][c].rgbtGreen + temp[r][c-1].rgbtGreen + temp[r][c].rgbtGreen) / 4.0);
            
            } else if (r == 0 && c == width -1){
                
                image[r][c].rgbtRed = round((temp[r][c-1].rgbtRed + temp[r][c].rgbtRed + temp[r+1][c-1].rgbtRed + temp[r+1][c].rgbtRed) / 4.0);
                image[r][c].rgbtBlue = round((temp[r][c-1].rgbtBlue + temp[r][c].rgbtBlue + temp[r+1][c-1].rgbtBlue + temp[r+1][c].rgbtBlue) / 4.0);
                image[r][c].rgbtGreen = round((temp[r][c-1].rgbtGreen + temp[r][c].rgbtGreen + temp[r+1][c-1].rgbtGreen + temp[r+1][c].rgbtGreen) / 4.0);
                
            } else if (r == height-1 && c == 0){
            
                image[r][c].rgbtRed = round((temp[r-1][c].rgbtRed + temp[r-1][c+1].rgbtRed + temp[r][c].rgbtRed + temp[r][c+1].rgbtRed) / 4.0);
                image[r][c].rgbtBlue = round((temp[r-1][c].rgbtBlue + temp[r-1][c+1].rgbtBlue + temp[r][c].rgbtBlue + temp[r][c+1].rgbtBlue) / 4.0);
                image[r][c].rgbtGreen = round((temp[r-1][c].rgbtGreen + temp[r-1][c+1].rgbtGreen + temp[r][c].rgbtGreen + temp[r][c+1].rgbtGreen) / 4.0);
                
            } else if (r == 0){
                
                image[r][c].rgbtRed = round((temp[r][c-1].rgbtRed + temp[r][c].rgbtRed + temp[r][c+1].rgbtRed + temp[r+1][c-1].rgbtRed + temp[r+1][c].rgbtRed + temp[r+1][c+1].rgbtRed) / 6.0);
                image[r][c].rgbtBlue = round((temp[r][c-1].rgbtBlue + temp[r][c].rgbtBlue + temp[r][c+1].rgbtBlue + temp[r+1][c-1].rgbtBlue + temp[r+1][c].rgbtBlue + temp[r+1][c+1].rgbtBlue) / 6.0);
                image[r][c].rgbtGreen = round((temp[r][c-1].rgbtGreen + temp[r][c].rgbtGreen + temp[r][c+1].rgbtGreen + temp[r+1][c-1].rgbtGreen + temp[r+1][c].rgbtGreen + temp[r+1][c+1].rgbtGreen) / 6.0);

            } else if (c == 0){
                
                image[r][c].rgbtRed = round((temp[r-1][c].rgbtRed + temp[r-1][c+1].rgbtRed + temp[r][c].rgbtRed + temp[r][c+1].rgbtRed + temp[r+1][c].rgbtRed + temp[r+1][c+1].rgbtRed) / 6.0);
                image[r][c].rgbtBlue = round((temp[r-1][c].rgbtBlue + temp[r-1][c+1].rgbtBlue + temp[r][c].rgbtBlue + temp[r][c+1].rgbtBlue + temp[r+1][c].rgbtBlue + temp[r+1][c+1].rgbtBlue) / 6.0);
                image[r][c].rgbtGreen = round((temp[r-1][c].rgbtGreen + temp[r-1][c+1].rgbtGreen + temp[r][c].rgbtGreen + temp[r][c+1].rgbtGreen + temp[r+1][c].rgbtGreen + temp[r+1][c+1].rgbtGreen) / 6.0);
        
                
            } else if (r == height -1){ //still need to do
                
                image[r][c].rgbtRed = round((temp[r-1][c-1].rgbtRed + temp[r-1][c].rgbtRed + temp[r-1][c+1].rgbtRed + temp[r][c-1].rgbtRed + temp[r][c].rgbtRed + temp[r][c+1].rgbtRed) / 6.0);
                image[r][c].rgbtBlue = round((temp[r-1][c-1].rgbtBlue + temp[r-1][c].rgbtBlue + temp[r-1][c+1].rgbtBlue + temp[r][c-1].rgbtBlue + temp[r][c].rgbtBlue + temp[r][c+1].rgbtBlue) / 6.0);
                image[r][c].rgbtGreen = round((temp[r-1][c-1].rgbtGreen + temp[r-1][c].rgbtGreen + temp[r-1][c+1].rgbtGreen + temp[r][c-1].rgbtGreen + temp[r][c].rgbtGreen + temp[r][c+1].rgbtGreen) / 6.0);
        
                
            } else if (c == width-1){
                
                image[r][c].rgbtRed = round((temp[r-1][c-1].rgbtRed + temp[r-1][c].rgbtRed + temp[r][c-1].rgbtRed + temp[r][c].rgbtRed + temp[r+1][c-1].rgbtRed + temp[r+1][c].rgbtRed) / 6.0);
                image[r][c].rgbtBlue = round((temp[r-1][c-1].rgbtBlue + temp[r-1][c].rgbtBlue + temp[r][c-1].rgbtBlue + temp[r][c].rgbtBlue + temp[r+1][c-1].rgbtBlue + temp[r+1][c].rgbtBlue) / 6.0);
                image[r][c].rgbtGreen = round((temp[r-1][c-1].rgbtGreen + temp[r-1][c].rgbtGreen + temp[r][c-1].rgbtGreen + temp[r][c].rgbtGreen + temp[r+1][c-1].rgbtGreen + temp[r+1][c].rgbtGreen) / 6.0);

                
            } else {
            
                image[r][c].rgbtRed = round((temp[r-1][c-1].rgbtRed + temp[r-1][c].rgbtRed + temp[r-1][c+1].rgbtRed + temp[r][c-1].rgbtRed + temp[r][c].rgbtRed + temp[r][c+1].rgbtRed + temp[r+1][c-1].rgbtRed + temp[r+1][c].rgbtRed + temp[r+1][c+1].rgbtRed) / 9.0);
                image[r][c].rgbtBlue = round((temp[r-1][c-1].rgbtBlue + temp[r-1][c].rgbtBlue + temp[r-1][c+1].rgbtBlue + temp[r][c-1].rgbtBlue + temp[r][c].rgbtBlue + temp[r][c+1].rgbtBlue + temp[r+1][c-1].rgbtBlue + temp[r+1][c].rgbtBlue + temp[r+1][c+1].rgbtBlue) / 9.0);
                image[r][c].rgbtGreen = round((temp[r-1][c-1].rgbtGreen + temp[r-1][c].rgbtGreen + temp[r-1][c+1].rgbtGreen + temp[r][c-1].rgbtGreen + temp[r][c].rgbtGreen + temp[r][c+1].rgbtGreen + temp[r+1][c-1].rgbtGreen + temp[r+1][c].rgbtGreen + temp[r+1][c+1].rgbtGreen) / 9.0);
            
            }
            // temp[r-1][c-1] temp[r-1][c] temp[r-1][c+1]
            // temp[r][c-1]   temp[r][c]   temp[r][c+1]
            // temp[r+1][c-1] temp[r+1][c] temp[r+1][c+1]
            
        }
    }
    
    return;
}
