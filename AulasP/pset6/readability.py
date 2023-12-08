from cs50 import get_string

text = get_string("Digite seu texto: ")

x = {'?', '!', '.'}
sentenses = 1
words = 0
for x in text:
    sentenses += 1
y = " "
for y in text:
    words += 1

letters = len(text) - (senteses + words)

letters = letters/words

print((0.0588 * letters) - (0.296 * senteses) - 15.8)
