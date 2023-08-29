import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("input not valid")
        sys.exit(1)

    databaseInput = sys.argv[1]
    sequenceInput = sys.argv[2]

    database = []
    STRs = []
    lenSTRs = 0
    sequence = []

    # Read database csv file into a variable
    with open(databaseInput, "r") as file:
        reader = csv.DictReader(file)
        database = list(reader)
        STRs = list(database[0].keys())[1:]
        lenSTRs = len(STRs)

    # Read DNA sequence txt file into a variable
    with open(sequenceInput, "r") as file:
        sequence = file.read()

    # Find longest match of each STR in DNA sequence
    STRsLongest = {}
    for STR in STRs:
        STRsLongest[STR] = longest_match(sequence, STR)

    # Check database for matching profiles
    for person in database:
        matches = 0
        for STR in STRs:
            if int(person[STR]) == STRsLongest[STR]:
                matches += 1

                # if all STRs match, matches will equal lenSTRs
                if matches == lenSTRs:
                    print(person["name"])
                    sys.exit(0)

    print("No match")
    sys.exit(0)


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
