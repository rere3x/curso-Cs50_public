
from cs50 import get_int

number = get_int("Card number: ")
while len(number) != 15:
    number= get_int("Card number: ")

if number[0] == 3:
    print("MASTERCAD")


