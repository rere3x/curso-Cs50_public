from cs50 import get_float

answer = get_float("Your cash: ")
while answer < 0.00001:
    answer = get_float("Your cash: ")

change = coins(answer)

def coins(answer)
    coins = 0
    x = int(answer * 100)
    if (x/25) > 0:
        coins = coins + (x/25)
        

