from cs50 import get_int

altura = get_int("indique a altura: ")
bloco = 1
for i in range(altura + 1):
    altura -= 1
    print ("_" * altura, end="")
    print ("#" * bloco, end="")
    bloco += 1
