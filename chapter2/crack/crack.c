#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <crypt.h>

int main (int argc, string argv[]){
    
    if (argc != 2) {
        
        return 1;
        
    } else {
        
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        char salt[3] = {argv[1][0], argv[1][1]};
        string hash = argv[1];
        
        //printf("%s\n", crypt("at", salt));
        //return 0;
        
        
        char key4[2];
        key4[1] = '\0';
        
        for(int a = 0; a < 26; a++){
                
                key4[0] = alphabet[a];
                if (strcmp(crypt(key4, salt), hash) == 0){
                    printf("%s\n", crypt(key4, salt));
                    printf("%s\n", key4);
                    return 0;
                }
                
        }
        
        char key3[3];
        key3[2] = '\0';
        
        for(int a = 0; a < 26; a++){
            
            key3[0] = alphabet[a];
            
            for(int b = 0; b < 26; b++){
                
                key3[1] = alphabet[b];
                if (strcmp(crypt(key3, salt), hash) == 0){
                    printf("%s\n", crypt(key3, salt));
                    printf("%s\n", key3);
                    return 0;
                }
                
            }    
        }
        
        char key2[4];
        key2[3] = '\0';

        for(int a = 0; a < 26; a++){
            
            key2[0] = alphabet[a];
            
            for(int b = 0; b < 26; b++){
                
                key2[1] = alphabet[b];
                
                for(int c = 0; c < 26; c++){
                    
                    key2[2] = alphabet[c];
                    if (strcmp(crypt(key2, salt), hash) == 0){
                        printf("%s\n", crypt(key2, salt));
                        printf("%s\n", key2);
                        return 0;
                    }
                    
                }
            }    
        }
        
        char key1[5];
        key1[4] = '\0';

        for(int a = 0; a < 26; a++){
            
            key1[0] = alphabet[a];
            
            for(int b = 0; b < 26; b++){
                
                key1[1] = alphabet[b];
                
                for(int c = 0; c < 26; c++){
                    
                    key1[2] = alphabet[c];
                    
                    for(int d = 0; d < 26; d++){
                        
                        key1[3] = alphabet[d];
                        if (strcmp(crypt(key1, salt), hash) == 0){
                            printf("%s\n", crypt(key1, salt));
                            printf("%s\n", key1);
                            return 0;
                        }
                        
                    }
                }
            }    
        }
 
        char key[6]; 
        key[5] = '\0';

        for(int a = 0; a < 26; a++){
            
            key[0] = alphabet[a];
            
            
            for(int b = 0; b < 26; b++){
                
                key[1] = alphabet[b];
               
                
                for(int c = 0; c < 26; c++){
                    
                    key[2] = alphabet[c];
                   
                    
                    for(int d = 0; d < 26; d++){
                        
                        key[3] = alphabet[d];
                        
                        
                        for(int e = 0; e < 26; e++){
                            
                            key[4] = alphabet[e];
                            if (strcmp(crypt(key, salt), hash) == 0){
                                printf("%s\n", crypt(key, salt));
                                printf("%s\n", key);
                                return 0;
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
    
        }
        
 
    }
    
}