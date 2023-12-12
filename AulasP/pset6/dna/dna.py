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

    for j in range(len(database_data[0]) - 1):

        for l in range(len(database_data[0][j + 1])):

            test_match[l] = sequence[l]

