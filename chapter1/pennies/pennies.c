#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main(void){
    int days = 0;
    double total = 0;
    long first = 0;
    long long pennies = 0;

    do {
        days = get_int("Days in Month: ");
    } while (days < 28 || days > 31);

    do {
        first = get_long("Pennies on the first day: ");
    } while (first < 1);

    for (int i = 0; i < days; i++){
        pennies = first * pow(2,i);
        total += pennies;
    }

    total /= 100;

    printf("$%.2f\n", total);
}