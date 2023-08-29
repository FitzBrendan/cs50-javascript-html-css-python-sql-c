#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//CAESAR cs50

// argument count = number of command line argumrnts, inputs/strings, count includes file name sting
// argument vector = inputs in array of strings, numbers entered in strings(chars in order), not integers
// in stdlib.h the atoi funcion converts a sting into a number
// use arguments in main() to get command line arguments in c

// first check that only one number is provided for the key, ie. argc should be 2, file name plus one number
// if no number (string) provided or more than one provided, print error message and return from main value of 1

// check that input for key is numeric only, decimal digit only
// if decimal digit check fails, print message "Usage: ./caesar key", and return from main value of 1

// for validated key, prompt user for plaintext: with 2 spaces, not new line, get_string
// encipher Plaintext string, shift by key, preserve case, non-alpha characters pass through inchanged
// in ctype.h, isalpha, isupper, islower    in string.h, strlen
// c = (p + k) % 26, for alph index where A = 0, B = 1, Z = 26, ASCII - 65, A 65-65=0, B 66-65=0
// Print ciphertext: with 1 space, no new line, convert c back to ASCII, c + 65 = ASCII
// after outputting ciphertexts print new line and exit by returning 0 from main

int main(int argc, string argv[])
{

// get single command line input, positive integer only

// if no arguments executed  or >one arguments, printf error code of choice and return 1 from main

    if (argc != 2)                                          // 2 strings to inlcude file name and 1 string for key
    {
        printf("key provided not a single string\n");
        return 1;
    }

// if argument is not decicmal digit, printf "Usage: ./caesear key", and return from main a value of 1
// cycle through each character in argv[1] array and verify for int-decimal digit, argv[0] is the file name

    string key_s = argv[1];
    int key_i = atoi(key_s);
    for (int i = 0, n = strlen(key_s); i < n;  i++)         //cycle through each char of string, i<n does not iclude the null
    {
        if (isdigit(key_s[i]) == 0)                         // isdigit returns 0 if not decimal digit
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    }

// for validated key, prompt user for plaintext: with 2 spaces, not new line, get_string

    string plaintext = get_string("plaintext:  ");

// encipher Plaintext string, shift by key, preserve case, non-alpha characters pass through inchanged
// in ctype.h, isalpha, isupper, islower    in string.h, strlen
// c = (p + k) % 26, for alph index where A = 0, B = 1, Z = 26, ASCII - 65, A 65-65=0, B 66-65=0

    printf("ciphertext: ");                                 // print 'ciphertext' before the encoded text

    for (int i = 0, n = strlen(plaintext); i < n; i++)      // cycle through each char of sting plaintext not including null
    {
        if (isalpha(plaintext[i]) != 0)                     // check for alph char to cipher, isalpha 0 for not alpha, if not alph pass unchanged
        {
            int ai;                                                         // ai alpha int to index ASCII A 65 to 0, a 97 to 0
            if (isupper(plaintext[i]) != 0)                                 // isupper 0 for not uppercase
            {
                ai = 65;                                                    // ai alpha indexing ASCII uppercases by A 65
            }
            else
            {
                ai = 97;                                                    // indexing ASCII lowercase by a 97
            }
            printf("%c", ((((plaintext[i] - ai) + key_i) % 26) + ai));      // print ciphered alpha char
        }
        else                                                                // just pass through non alph char preserved as given
        {
            printf("%c", plaintext[i]);                                     // print non decimal digit just pass through unchanged
        }

    }
    printf("\n");
    return 0;

}
