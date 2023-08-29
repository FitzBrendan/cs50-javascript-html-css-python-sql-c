# import cs50 function get_string, re for Python regex, and exit from sys
from cs50 import get_string
import re
from sys import exit


# define main and call at end
def main():

    # prompt user for credit card (cc) number
    cc = get_string("Please provide Credit Card Number ")

    # return AMEX if 15 digits, starting with 34 or 37, and checksum Luhn function true
    if re.search("^(34|37)\d{13}$", cc):
        if luhnChecksum(cc):
            print("AMEX")
            exit()

    # return MASTERCARD if 16 digits, starting with 51-55 inclusive, and checksum Luhn function true
    if re.search("^5[1-5]\d{14}$", cc):
        if luhnChecksum(cc):
            print("MASTERCARD")
            exit()

    # return VISA if 13 or 16 digits, starting with 4, and checksum Luhn function true
    if re.search("^4\d{12}$|^4\d{15}$", cc):
        if luhnChecksum(cc):
            print("VISA")
            exit()

    # if all checks fail
    print("INVALID")
    exit()


# define Luhn function for checksum
def luhnChecksum(num):

    sumDoubles = 0
    sumSingles = 0
    # starting with 2nd to last digit, sum all digits of every other number multipied by 2
    # for even number of digits of cc, start at first digit, for odd cc amounts, start at 2nd
    # sumTotal is sum of all digits from *2 plus sum of remaining digits
    if len(num) % 2 == 0:
        x = 0
        y = 1
    else:
        x = 1
        y = 0

    for digitString in num[x::2]:
        Doubled = str(int(digitString) * 2)

        for doubledString in Doubled:
            sumDoubles += int(doubledString)

    for digitString in num[y::2]:
        sumSingles += int(digitString)

    sumTotal = sumDoubles + sumSingles

    # return True if last digit is 0, total % 10 = 0
    if sumTotal % 10 == 0:
        return True
    else:
        return False


if __name__ == "__main__":
    main()
