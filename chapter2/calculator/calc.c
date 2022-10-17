#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main (int argc, string argv[]){
    float ans = 0;
    int q = 0;
    
    if (argc != 4){
        return 1;
    }    

    float a = atof(argv[1]);
    float y = atof(argv[3]);
    
    char op = argv[2][0];
    
    switch(op){
        case '+':
            ans = a + y;
            printf("%f\n", ans);
            break;
            
        case '-':
            ans = a - y;
            printf("%f\n", ans);
            break;
        
        case '/':
            ans = a / y;
            printf("%f\n", ans);
            break;
        
        case 'x':
            ans = a * y;
            printf("%f\n", ans);
            break;
        
        case '%':
            q = (int)(a / y);
            ans = a - (y*q);
            printf("%f\n", ans);
            break;
            
        default:
            return 1;
    }
    
    
    
}