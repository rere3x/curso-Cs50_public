import csv
import sys


if len(sys.argv) < 3:
    print("Usage: python dna.py data.csv sequence.txt")
    sys.exit(1)

with open(sys.argv[1], 'r') as database:
    database_reader = csv.reader(database)
    database_data = [row for row in database_reader]

with open(sys.argv[2], 'r') as sequence_file:
    sequence = sequence_file.read()

for i in range(len(sequence)):
    match_found = False
    for j in range(len(database_data[0]) - 1):
        for l in range(len(database_data[0][j + 1])):
            if database_data[0][j + 1][l] != sequence[i]:
                match_found = True
                break
            if match_found:
                print("N")
            else:
                print("S")



