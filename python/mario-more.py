# get function get_int from cs50
from cs50 import get_int

# prompt user for pyramid size 1-8, keep prompting until num 1-8 provided
blocksSize = 0
while blocksSize < 1 or blocksSize > 8:
    blocksSize = get_int("How many blocks? ")

# print blocksSize amount of rows, with spaces, blocks, const 2 spaces, blocks
for i in range(blocksSize):
    spaces = blocksSize - 1 - i
    blocks = i + 1
    print(" " * spaces + "#" * blocks + " " * 2 + "#" * blocks)
