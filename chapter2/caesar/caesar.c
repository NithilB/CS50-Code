#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[]) {
    int k = 0;
    string word = "";
    int c = 0;
    string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower = "abcdefghijklmnopqrstuvwxyz";
    int count = 0;
    string argument = " ";


    if (argc != 2) {
        
        return 1;
        
    } else {
        
        argument = argv[1];
        for (int t = 0; t < strlen(argv[1]); t++){
            if(isdigit(argument[t]) == 0){
                count++;
            }
        }
        
        if(count > 0){
        
            return 1;
        
        } else {

            word = get_string("plaintext: ");
            char w[strlen(word)+1];
        
            k = atoi(argv[1]);

            for (int i = 0; i < strlen(word); i++){
                for (int n = 0; n < 26; n++){
                    if(isalpha(word[i]) != 0){
                        if (upper[n] == word[i]){
                            if ((n+k) >= 26){
                                c = (n + k) % 26;
                                w[i] = upper[c];
                            } else {
                                w[i] = upper[n+k];
                            }
                        } else if (lower[n] == word[i]){
                            if ((n+k) >= 26){
                                c = (n + k) % 26;
                                w[i] = lower[c];
                            } else {
                                w[i] = lower[n+k];
                            }
                        }
                    }
                }
        
                if(isalpha(word[i]) == 0){
                    w[i] = word[i];
                }
            
            }
            
            w[strlen(word)] = '\0'; // (Searched up output not valid ASCII text) https://stackoverflow.com/questions/62089955/cs50-pset2-substitution-output-not-valid-ascii-text 
            printf("ciphertext: %s\n", w);
    
        }
    }
    
    
}