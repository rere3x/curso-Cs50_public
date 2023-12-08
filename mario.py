from cs50 import get_int

altura = get_int("indique a altura: ")
i = 1
while True:
    print (" " * (altura - 1))
    print ("#" * i)
    altura -= 1
    i      += 1
