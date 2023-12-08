from cs50 import get_int

altura = get_int("indique a altura: ")
espaco = 1
for i in range(altura + 1):
    print (" " * (altura - 1))
    print ("#" * i)
    altura -= 1
    espaco += 1
