from cs50 import get_float

answer = get_float("Your cash: ")
while answer < 0.00001:
    answer = get_float("Your cash: ")

change = coins(answer)

def coins(answer)
    x = int(answer * 100)
    x / 25 > 0

