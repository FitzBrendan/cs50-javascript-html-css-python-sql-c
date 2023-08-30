from cs50 import get_string

text = get_string("Please enter text: ")

# declare vars for letters, words (1 ie. words == " " + 1), sentences
letters = 0
words = 1
sentences = 0

for char in text:
    if char.isalpha():
        letters += 1
    elif char == " ":
        words += 1
    elif char == "." or char == "!" or char == "?":
        sentences += 1

# calculate Coleman-Liau index, 0.0588 * L - 0.296 * S - 15.8
# L is avg letters per 100 words, S is avg sentences per 100 words
avg100 = 100 / words
L = letters * avg100
S = sentences * avg100
index = round(0.0588 * L - 0.296 * S - 15.8)

# print grade level per index
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
