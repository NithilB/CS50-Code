from cs50 import get_string

text = get_string("Text: ");

letters = 0
sentences = 0
words = 0
L = 0
S = 0
    
for i in range(len(text)):
    if (text[i].isalpha() != 0): 
        letters += 1
        
    if (text[i] == '.' or text [i] == '?' or text [i] == '!'):
        sentences += 1


for n in range(len(text)):
    if ((text[n].isalpha() != 0) and (text[n+1] == ' ' or text[n+1] == '.' or text[n+1] == ',' or text[n+1] == ';' or text [n+1] == ':'or text [n+1] == '?' or text [n+1] == '!')):
        words += 1

    
c = 100.0 / words
L =  c * letters
S = c * sentences
grade = (0.0588 * L) - (0.296 * S) - 15.8

if(round(grade, 1) < 1):
    print("Before Grade 1")
elif (round(grade, 1) > 16):
    print("Grade 16+")
else:
    print("Grade",round(grade))
