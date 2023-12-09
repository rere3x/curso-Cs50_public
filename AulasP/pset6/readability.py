from cs50 import get_string
import string

text        = get_string("Digite seu texto: ")
letters    = 0
words       = 0
sentenses   = 0

for i in range(len(text)):
    if str.isalpha(text[i]):
        letters +=1
for i in range(len(text)):
    if str.isspace(text[i]):
        words +=1
for i in range(len(text)):
    if str.find(string.punctuation) in text:
        sentenses +=1

letters = letters/words
print(letters)

print((0.0588 * letters) - (0.296 * sentenses) - 15.8)
