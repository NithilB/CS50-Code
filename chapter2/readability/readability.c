#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main (void){
    
    //input text
    string text = get_string("Text: ");
    
    //declared variables
    int letters = 0;
    int sentences = 0;
    int words = 0;
    float L = 0;
    float S = 0;
    
    //finding num of letters and sentences
    for (int i = 0; i < strlen(text); i++){
        if (isalpha(text[i]) != 0){
            letters++;
        }    
        if (text[i] == '.' || text [i] == '?' || text [i] == '!'){
            sentences++;
        }
    }
    
    //finding number of words
    for (int n = 0; n < strlen(text); n++){
        if ((isalpha(text[n]) != 0) && (text[n+1] == ' ' || text[n+1] == '.' || text[n+1] == ',' || text[n+1] == ';' || text [n+1] == ':'|| text [n+1] == '?' || text [n+1] == '!')){
            words++;
        }
    }
    
    printf("%i\n", letters);
    printf("%i\n", sentences);
    printf("%i\n", words);
    
    //math calculations
    float c = 100.0 / words;
    L =  c * letters;
    S = c * sentences;
    float grade = (0.0588 * L) - (0.296 * S) - 15.8;
    
    printf("%f\n", grade);

    //print statements
    if(round(grade) < 1){
        printf("Before Grade 1\n");
    } else if (round(grade) > 16){
        printf("Grade 16+\n");
    } else {
        printf("Grade %i\n", (int)round(grade)); 
    }
    
}