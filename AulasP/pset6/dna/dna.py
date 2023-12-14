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

def Max_consecutive_reps(substring,strig)
    total_reps = len(string)
    while (substring * total_reps) not in string and total_reps > 0:
        total_reps -= 1
    return total_reps


def read_dna_sequence(path, sequences)
    with open(path) as file:
        dna_seq = file.read()
        return {seq: str(max_consecutive_reps(seq, dna_seq)) for seq in sequences}
main()



