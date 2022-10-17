#include <cs50.h>
#include <stdio.h>

int main (void) {
    int n = 0;
    
    do {
        
        n = get_int("Height: ");
        
    } while (n < 1 || n > 8);
    
    
    for (int r = 0; r < n; r++){
        
        for(int c = n; c > 0; c--){
            
            if (c > r + 1){
                printf(" ");
            } else {
                printf("#");
            }
        }
        
        printf("  ");
        
        for(int a = 0; a < (r+1); a++){
            
                printf("#");
            
        }
        
      printf("\n");
        
    }
    
}