from cs50 import get_int

n = 0

while (n < 1) or (n > 8):
    n = get_int("Height: ")
        
cnt = n    
x = n
        
for r in range(n):
    cnt = n 
    for c in range(n):
        if (cnt > r + 1):
            print(" ",end = "")
        else: 
            print("#",end = "")
        cnt -= 1    
            
    print("  ",end = "")
    
    
    for a in range(r+1):
        print("#",end = "")
    print("")