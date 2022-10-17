#include <cs50.h>
#include <stdio.h>

int main(void){
    
    long credit = 0;
    int even = 0;
    int e = 0;
    int odd = 0;
    int total = 0;
    int count = 0;
    
    credit = get_long("Number: ");
    long c = credit;
    long cc = credit;
    
    while (c > 0){
        c /= 10;
        count++;
    }
    

    for (int i = 0; i < count; i++){
        odd += credit % 10;
        credit /= 10;
        e = credit % 10;
        e *= 2;
        if (e >= 10){
            even += (e % 10);
            e /= 10;
            even += e;
        } else {
            even += e;
        }
        credit /= 10;
    }
    
    total = even + odd;

    if (total % 10 == 0){
        if (count == 15 && ((cc / 10000000000000) == 34 || (cc / 10000000000000) == 37)){
            printf("AMEX\n");
        } else if ((count == 13 && (cc / 1000000000000) == 4) || ((count == 16 && (cc / 1000000000000000) == 4))){
            printf("VISA\n");
        } else if (count == 16 && ((cc / 100000000000000) >= 51 && (cc / 100000000000000) <= 55)){
            printf("MASTERCARD\n");
        } else {
            printf("INVALID\n");
        }
    } else {
        printf("INVALID\n");
    }

    
}