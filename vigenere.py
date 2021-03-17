import string
import itertools
from string import ascii_lowercase
from string import ascii_uppercase
import time

def encryptVigenere(text, key):
    #remember what chars are uppercase
    uppers = [id for id in range(len(text)) if text[id].isupper()]
    #remove spaces from text and go all lowercase
    text = text.replace(" ","")
    text = text.lower()
    key = key.lower()
    keyLen = len(key)

    #dictionaries for num/letter conversions
    letterToNum = {letter: index for index, letter in enumerate(ascii_lowercase)}
    numToLetter = {index: letter for index, letter in enumerate(ascii_lowercase)}

    encryptedText = ""
    for iterator,letter in enumerate(text):
        encryptedText += numToLetter[(letterToNum[letter] + letterToNum[key[iterator % keyLen]]) % 26]

    #replace upperase letters
    for iterator,letter in enumerate(encryptedText):
        if(iterator in uppers):
            encryptedText = encryptedText[:iterator] + encryptedText[iterator].upper() + encryptedText[iterator+1:]
    return encryptedText


def decryptVigenere(cipherText, keyLength, firstWordLength):
    #load dictionary into memory as a set
    theDict = set(line.strip() for line in open('dict.txt'))

    #convert cipherText to uppercase since we will want to check it against uppercase dictionary
    cipherText = cipherText.upper()

    #get first word's ciphertext
    firstWordCT = cipherText[:firstWordLength]

    #dictionaries for num/letter conversions
    letterToNum = {letter: index for index, letter in enumerate(ascii_uppercase)}
    numToLetter = {index: letter for index, letter in enumerate(ascii_uppercase)}

    #letter list for generating keys
    letterList = list(ascii_uppercase)

    #test all possible keys of keyLength
    for item in itertools.product(letterList,repeat=keyLength):
        #form candidate key
        candidate = ("".join(item))

        #generate plaintext of firstWordCT using candidate as key
        tempPT = ""
        for iterator,letter in enumerate(firstWordCT):
            tempPT += numToLetter[(letterToNum[letter] - letterToNum[candidate[iterator % keyLength]]) % 26]

        #check dict for key
        if(tempPT in theDict):
            #if in dictionary, generate full plaintext and display
            tempPT = ""
            for iterator,letter in enumerate(cipherText):
                tempPT += numToLetter[(letterToNum[letter] - letterToNum[candidate[iterator % keyLength]]) % 26]
            print("Plaintext candidate: ", tempPT, " with key: ", candidate)

t0 = time.time()
#print(encryptVigenere("HeLloO","key"))
#decryptVigenere("LDWMEKPOPSWNOAVBIDHIPCEWAETYRVOAUPSINOVDIEDHCDSELHCCPVHRPOHZUSERSFS", 6, 9)
t1 = time.time()
print("Total time of execution: ", t1-t0)
