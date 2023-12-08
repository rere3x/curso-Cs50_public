
from cs50 import get_string

number = get_string("Card number: ")
while number.len != 15:
    number= get_string("Card number: ")
