
from cs50 import get_string

number = get_string("Card number: ")
while len(number) != 15:
    number= get_string("Card number: ")

if number[0] == '3':
    print("AMERICAN EXPRESS")
elif number[0] == '5':
    print("MASTERCAD")
elif number[0] == '4':
    print("VISA")
else
    print("INVALID")


