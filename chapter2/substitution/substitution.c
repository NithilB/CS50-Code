#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main (int argc, string argv[]){
    string key = " ";
    key = argv[1];
    int count = 0;
    
    if (argc != 2 || strlen(key) != 26){ 
        return 1;
    } 

    for(int a = 0; a < strlen(argv[1]); a++){
        for(int b = a; b < 26; b++){
            if(key[a] == key[b+1]){
                count++;
            }
        }
        
        if(isalpha(key[a]) == 0){
            count++;
        }
    }    
    
    if(count > 0){
        return 1;
    } 

    string plaintext = get_string("plaintext: ");
    char p[strlen(plaintext)+1];
    
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";
    
    for (int i = 0; i < strlen(plaintext); i++){
        for (int n = 0; n < 26; n++){
            if(isalpha(plaintext[i]) != 0){
                if(plaintext[i] == upper[n]){
                   p[i] = toupper(key[n]);
                   //printf("%s\n", p);
                } else if (plaintext[i] == lower[n]){
                   p[i] = tolower(key[n]);
                   //printf("%s\n", p);
                }
            } 
        }
        
        if (isalpha(plaintext[i]) == 0){
                p[i] = plaintext[i];
        } 
    }
    
    p[strlen(plaintext)] = '\0';
    printf("ciphertext: %s\n", p);
    
    
}