# import function get_float from cs50
from cs50 import get_float

# prompt user for positive number continuously until pos num received for change
changeDue = 0
while changeDue <= 0:
    changeDue = get_float("Please provide change due ")

# create dictionary for coin values
coinValues = {

    "quarter": 0.25,
    "dime": 0.10,
    "nickel": 0.05,
    "penny": 0.01
}

# define function to return min number of coins to make change


def coinsForChange(change):

    # declare var for total num of coins to make change
    coinCount = 0

    # loop thru each coin value, add coins needed to coinCount, subtract value from change
    for coin, cents in coinValues.items():
        coins = int(change / cents)
        coinCount += coins
        change = round(change - (coins * cents), 2)

    print(coinCount)


coinsForChange(changeDue)
