from cs50 import get_string
import string

text        = get_string("Digite seu texto: ")
letters    = 0
words       = 1
sentenses   = 0


for i in range(len(text)):
    if str.isalpha(text[i]):
        letters +=1

for i in range(len(text)):
    if str.isspace(text[i]):
        words +=1

for i in range(len(text)):
    if  text[i] in ['!', '?', '.']:
        sentenses +=1

letters = round((letters / words) * 100, 2)
sentenses = round((sentenses / words) * 100, 2)

result = round((0.0588 * letters) - (0.296 * sentenses) - 15.8)
print(result)

if result in range (1, 17):
    print("Grade: " + str(result))
elif result < 1:
    print ("Before Grade 1.")
else:
    print("Grade 16+")

