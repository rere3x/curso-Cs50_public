from cs50 import get_string

text = get_string("Digite seu texto: ")

print (text)
sentenses = 0
words = 0
for  in text:
    sentenses += 1
    print(sentenses)
y = " "
for y in text:
    words += 1
    print(words)

letters = len(text) - (sentenses + words)
print(letters)

letters = letters/words
print(letters)

print((0.0588 * letters) - (0.296 * sentenses) - 15.8)
