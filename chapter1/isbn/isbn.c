#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void){
    long isbn = 0;
    
  //  do {
    isbn = get_long("ISBN: ");
  //  } while ()
    
    int count = 0;
    int total = 0;
    int tenth = isbn % 10;
    isbn = isbn / 10;
    for (int i = 0; i <= 9; i++){
        for (int n = 9; n >= 0; n--){
            count = isbn % 10;
            isbn = isbn / 10;
            total += count*n;
        }
    }

    if ((total % 11) == tenth){
        
        total += tenth*10;
        printf("YES\n");
        
    } else {

        printf("NO\n");
    }

}