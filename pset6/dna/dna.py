import sys
import csv

# checks for no of command-line arguments
if len(sys.argv) != 3:
    sys.exit("Usage: python dna.py data.csv sequence.txt")

database = sys.argv[1]
sequence = sys.argv[2]

dna_strs = []
strands = []
data = {}

# opens file database and creating a sequence
with open(database, newline='') as d_file:
    d_read = csv.DictReader(d_file)
    list_strs = d_read.fieldnames[1:]

# reads the sequences from txt files
with open(sequence, "r") as seq_file:
    read_seq = seq_file.read()

# counts the maximum consecutive STRs
for str in list_strs:
    i = 0
    while str*(i+1) in read_seq:
        i += 1
    dna_strs.append(i)

# enumrate function adds counter to the csv data file
with open(database, "r") as data_file:
    for index, row in enumerate(data_file):
        if index == 0:
            strands = [strand for strand in row.strip().split(',')][1:]
        else:
            curr_row = row.strip().split(',')
            data[curr_row[0]] = [int(x) for x in curr_row[1:]]

# matches the STR counts with Persons data
# prints the name of person if match found

for name, f_data in data.items():
    if(f_data == dna_strs):
        print(name)
# if match found exits the program
        sys.exit(0)

print("No match")