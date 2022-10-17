#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main (void){
    float change = 0;
    do {
        change = get_float("How much change you have left");
    } while (change <= 0);
   // printf("%f\n", change);
    int dollar = round(change*100);
   // printf("%i\n",dollar);
    int quarter = 0;
    int dime = 0;
    int nickel = 0;
    int penny = 0;
   
        quarter = dollar / 25;
        dollar -= quarter * 25;
    //    printf("%i\n", dollar);
    //    printf("%i\n", quarter);
    

        dime = dollar / 10;
        dollar -= dime * 10;
    //    printf("%i\n", dollar);
    //    printf("%i\n", dime);
    

        nickel = dollar / 5;
        dollar -= nickel * 5;
    //    printf("%i\n", dollar);
    //    printf("%i\n", nickel);

        penny = dollar / 1;
        dollar -= penny * 1;
    //    printf("%i\n", dollar);
    //    printf("%i\n", penny);
        
    int total = quarter + dime + nickel + penny;

    printf("%i\n", total);
}