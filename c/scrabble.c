#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// declaring/**prototyping** with includes inputs types function compute_score
int compute_score(string word);

int main(void)
{

    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

}
// define Function compute_score, Compute and return score for string
// POINTS[] arrary stores points for each alph char
// upper and lower case alph char have equal points for that character
// non alph char receive no points

int compute_score(string word)                          // compute scrabble score for prompted word passed to function
{
    int sum_score = 0;                                      // variable sum_score to return points sum of word

    for (int i = 0; i < strlen(word); i++)              // variable i to cylcle through word to eval each letter for points
    {
        if (isalpha(word[i]))                       // checking for alpha, only alpha characters receive points
        {
            int a = toupper(word[i]) - 65;          // var a = upper ASCII - 65 for points index number, A/65-65=0
            sum_score += POINTS[a];                 // continue sum for each letter in word
        }
    }
    return sum_score;

}
