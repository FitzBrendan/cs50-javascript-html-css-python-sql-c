#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Prompt user for text
    string text = get_string("Please type in text: ");

    // counts for letters, words, sentences
    float letters = 0;
    float words = 1;      // start with 1 to account for last word
    float sentences = 0;

    // Loop for counting
    for (int i = 0; i < strlen(text); i++)
    {
        // Counting letters, isalpha returns non 0 for alphabetical
        char c = text[i];

        if (isalpha(c) != 0)
        {
            letters++;
        }
        // Counting words, chars after spaces count as words
        if (c == ' ')
        {
            words++;
        }
        // Counting Sentences, any punctuation that ends a sentence
        if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
    }

    // Calculation, Coleman-Liau Index = 0.0588 * L - 0.296 * S - 15.8
    // per 100 words in text, L is avg num of letters, S is avg num of sentances

    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
