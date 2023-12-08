from cs50 import get_float

def main ():

    answer = get_float("Your cash: ")
    while answer < 0.00001:
        answer = get_float("Your cash: ")

    change = coins(answer)

    def coins(value):
        coins = 0

        newValue = int(value * 100)
        if (x/25) > 0:
            coins = coins + (x/25)
            x = x%25
        if (x/10) > 0:
            coins = coins + (x/10)
            x = x%10
        if (x/5) > 0:
            coins = coins + (x/5)
            x = x%5
        if (x/1) > 0:
            coins = coins + (x/1)

        print("Coins owed: "+coins)

        return coins

main ()
