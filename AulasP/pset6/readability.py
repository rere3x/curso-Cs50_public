from cs50 import get_string
from 

text = get_string("Digite seu texto: ")

sentenses = 0
for i in range(len(text)):
    if isalpha(text[i]):
        sentenses +=1
        print(sentenses)








#letters = letters/words
#print(letters)

#print((0.0588 * letters) - (0.296 * sentenses) - 15.8)
