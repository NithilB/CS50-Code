from cs50 import get_int

credit = 0
even = 0
e = 0
odd = 0
total = 0
count = 0

credit = get_int("Number: ")
c = credit
cc = credit

while (c > 0):
    c //= 10
    count += 1

for r in range(count):
    odd += credit % 10
    credit //= 10
    e = credit % 10
    e *= 2
    
    if (e >= 10):
        even += (e % 10)
        e //= 10
        even += e
    else: 
        even += e
    
    credit //= 10
    
    
total = even + odd

if (total % 10 == 0):
    if (count == 15 and ((cc // 10000000000000) == 34 or (cc // 10000000000000) == 37)): 
        print("AMEX")
    elif ((count == 13 and (cc // 1000000000000) == 4) or ((count == 16 and (cc // 1000000000000000) == 4))):
        print("VISA")
    elif (count == 16 and ((cc // 100000000000000) >= 51 and (cc // 100000000000000) <= 55)):
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")


    