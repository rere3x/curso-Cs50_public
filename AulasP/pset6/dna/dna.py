import csv
from sys import argv, exit



def main()
    if argv != 3:
        print(f" Usage: python {argv[0]} data.csv sequence.txt")
        exit(0)

        _,data_file, sequence_file = agrv



def read_csv(path):
    with open(path) as csvfile:
        reader = csv.DictReader(csvfile)
        return {"columns": reader.fieldnames, "data": list(reader)}
main()



