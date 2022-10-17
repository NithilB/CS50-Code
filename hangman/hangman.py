from cs50 import get_string
import random


Wordbank = ["article", "feeling", "exemption", "principle", "muggy", "ethnic", "mechanical", "chimpanzee", "circle", "highlight", "miserable", "reaction", "enthusiasm", "quarter", "cutting", "injury",
"shaft", "deadly", "attract", "motivation", "ceremony", "addition", "snake", "delivery", "observation", "imposter", "commemorate", "chicken", "salesperson", "sphere", "finish", "impress", "marriage", "family",
"deputy", "normal", "fossil", "stake", "follow", "leash", "helpless", "asset", "handy", "poison", "adventure", "valley", "obstacle", "transparent", "margin", "process"]

used = [] 
alphabet = "abcdefghijklmnopqrstuvwxyz"
word=""
wrongcounter = 0
gamestate=False
blank = []

def charcorrect(letter):
    global wrongcounter
    global blank
    global word
    global used
    vcheck = False
    
    for x in range(len(word)):
        if word[x] == letter:
            blank[x] = letter
            vcheck=True
            
    if vcheck == False:
        wrongcounter += 1
        used.append(letter)
        return False
        
    used.append(letter)
    return True;

def wordcorrect(guess):
    global wrongcounter
    global blank
    global word
    global used
    if guess == word:
        for y in range(len(word)):
            blank[y]=word[y] 
        used.append(guess)
        return True
    else:
        wrongcounter += 1
        used.append(guess)
        return False
        
def isused(guess):
    global used
    global wrongcounter
    for f in range(len(used)):
        if(guess==used[f]):
            return True
    return False
    
    

def drawman(num):
    global gamestate
    if(num==1):
        print("-----")
        print("    |")
        print("    |")
        print("    |\n")
    elif(num==2):
        print("-----")
        print("    |")
        print("    |")
        print("    |")
        print("    O\n")
    elif(num==3):
        print("-----")
        print("    |")
        print("    |")
        print("    |")
        print("    O")
        print("    |")
        print("    |\n")
    elif(num==4):
        print("-----")
        print("    |")
        print("    |")
        print("    |")
        print("    O")
        print("   \|")
        print("    |\n")
    elif(num==5):
        print("-----")
        print("    |")
        print("    |")
        print("    |")
        print("    O")
        print("   \|/")
        print("    |\n")
    elif(num==6):
        print("-----")
        print("    |")
        print("    |")
        print("    |")
        print("    O")
        print("   \|/")
        print("    |")
        print("   /\n")
    elif(num >= 7):
        print("-----")
        print("    |")
        print("    |")
        print("    |")
        print("    O")
        print("   \|/")
        print("    |")
        print("   / \ \n")
        
        print("YOU LOST")
        print("The correct word is", word)
        gamestate=False

def didwin():
    global blank
    counter=0
    for w in range(len(blank)):
        if(blank[w] == "_"):
            counter += 1
    
    if counter >= 1:
        return False
    
    return True


def main():
    global gamestate
    start = ""
    while (not start == "start"):
        start = get_string("Start Hangman, type start \n")
        
    if(start == "start"):
        gamestate = True
    
    global word    
        
    word = random.choice(Wordbank)
    
    global blank
    for i in range(len(word)):
        blank += "_"
    
    print(blank, "\n\n")
    
    global wrongcounter
    while (wrongcounter <= 6):
        letter = ""
        
        while(letter.isalpha() == False):
            print("used: ",used, "\n")
            letter = get_string("input a letter or word: ")
            
            while(isused(letter)==True):
                letter = get_string("You used the same word. Please input a new letter/word: ")

        if (len(letter) == 1):
            charcorrect(letter)
        else:
            wordcorrect(letter)
                
        drawman(wrongcounter)
        
        if(didwin()):
            print("Congratulations!!! You Won!")
            print("The word was:", word)
            gamestate = False
            break;
        
        elif (wrongcounter <= 6):
            
            print(blank, "\n\n")
            
main()