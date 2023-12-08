
from cs50 import get_string

number = get_int("Card number: ")
while len(number) != 15:
    number= get_string("Card number: ")

if number[0] == 3:
    print("MASTERCAD")


