from cs50 import get_float

change = 0;

while (change <= 0):
    change = get_float("Change owed: ");

dollar = round(change*100);
quarter = 0;
dime = 0;
nickel = 0;
penny = 0;
   
quarter = dollar // 25;
dollar -= quarter * 25;


dime = dollar // 10;
dollar -= dime * 10;


nickel = dollar // 5;
dollar -= nickel * 5;


penny = dollar // 1;
dollar -= penny * 1;

total = quarter + dime + nickel + penny;

print(total);
