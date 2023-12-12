import csv
import sys


if len(sys.argv) < 3:
    print("Usage: python dna.py data.csv sequence.txt")
    sys.exit(1)

with open(sys.argv[1], 'r') as database:
    database_reader = csv.reader(database)
    database_data = [row for row in database_reader]

with open(sys.argv[2], 'r') as sequence:
    sequence_reader = sequence.read(sequence)
