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

dna_count = [0] * (len(database_data[0]) - 1)

for i in range(len(sequence)):

    for j in range(len(database_data[0]) - 1):
        test_count = 0

        for l in range(len(database_data[0][j + 1])):
            if (l + i) >= len(sequence):
                break
            elif database_data[0][j + 1][l] != sequence[l + i]:
                test_count = 0
                break
            else:
                test_count += 1

            if len(database_data[0][j + 1]) == test_count:

                dna_count[j] += 1

for i in range(len(database_data) - 1):
    for j in range(len(database_data[i + 1]) - 1):
        print(dna_count[j])
        print(database_data[i + 1][j + 1])
        if dna_count[j] != database_data[i + 1][j + 1]:
            break
        else:
            print(database_data[i + 1][0])


