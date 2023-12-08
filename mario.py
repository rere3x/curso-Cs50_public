from cs50 import get_int

altura = get_int("indique a altura: ")

while True:
    print(" "*(altura - 1))
    print("#" * altura)
