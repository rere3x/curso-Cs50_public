from cs50 import get_float

def main():

    answer = get_float("Your cash: ")
    while answer < 0.01:
        answer = get_float("Your cash: ")

    print(coins(answer))



def coins(value):

    coins = 0

    newValue = int(value * 100)
    print(newValue)
    if (newValue/25) > 0:
        coins = coins + (newValue/25)
        newValue = newValue%25
        print(f"new {newValue}")
        print (f"coins {coins}")

    if (newValue/10) > 0:
        coins = coins + (newValue/10)
        newValue = newValue%10
        print(f"new {newValue}")
        print (f"coins {coins}")

    if (newValue/5) > 0:
        coins = coins + (newValue/5)
        newValue = newValue%5
        print(f"new {newValue}")
        print (f"coins {coins}")

    if (newValue/1) > 0:
        coins = coins + (newValue/1)
        print(f"new {newValue}")
        print (f"coins {coins}")
    return coins

main()

