from cs50 import get_float

answer = get_float("Your cash: ")
while answer < -1:
    print("wrong value")
    answer = get_float("Your cash: ")




