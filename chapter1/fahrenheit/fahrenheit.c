#include <cs50.h>
#include <stdio.h>
int main (void) {
    float degrees = get_float("Enter the Degrees in Celcius ");
    
    degrees = (((degrees*9)/5)) + 32;
    
    printf("%.1f\n", degrees);
}