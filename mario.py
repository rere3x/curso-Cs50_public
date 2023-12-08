from cs50 import get_int

altura = get_int("indique a altura: ")
bloco = 1
for i in range(altura + 1):
    print ("_" * altura, end="pinto")
    print ("#" * bloco, end="")
    print (" ", end="")
    print ("#" * bloco, end="")
    print()
    altura -= 1
    bloco += 1
