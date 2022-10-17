#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>

int main(int argc, char *argv[])
{

    if(argc != 2){
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output;
    uint8_t buffer[512];
    //string filename = "";
    char filename[8];
    int count = 0;

    while (fread(buffer, sizeof(uint8_t), 512, input)){

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
            //if(output != NULL){
            //    fclose(output);
            //}
            sprintf(filename, "%03i.jpg", count);
            output = fopen(filename, "w");
            count++;
        }
        
        if(output != NULL){
            fwrite(buffer, sizeof(uint8_t), 512, output);
        }
        
    }

    fclose(output);
    fclose(input);

    return 0;
}