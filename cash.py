from cs50 import get_float

answer = get_float("Your cash: ")
while answer < 0.00001:
    answer = get_float("Your cash: ")




