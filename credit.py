
from cs50 import get_string
from sys import exit

number = get_string("Card number: ")
while len(number) < 15:
    print("INVALID")
    exit()

if number[0] == '3':
    print("AMEX")
elif number[0] == '5':
    print("MASTERCARD")
elif number[0] == '4':
    print("VISA")
else:
    print("INVALID")


