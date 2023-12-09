from cs50 import get_string
import _string

text = get_string("Digite seu texto: ")


sentenses = punctuation(text)
words = text.whitespace
letters = text.ascii_letters

print(letters)

letters = letters/words
print(letters)

print((0.0588 * letters) - (0.296 * sentenses) - 15.8)
