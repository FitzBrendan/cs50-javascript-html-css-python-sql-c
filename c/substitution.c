#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Substition - cmd line arg for 26 letters for alphabet cipher index key, no letters repeat, case insensitive
// cipher alphabet char's only, maintain case of input to be deciphered, pass through all others preserved

int main(int argc, string argv[])
{
    string key = argv[1];
    string error_message = "Key must contain 26 characters";


// first check that a sting key was provided and only one provided

    if (argc != 2)                                       // argc is count of strings, file name accounts for first string
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }


// validity checks for entered key, 26 alpabet char upper/lower, no repeated letters (case not sensitive)

    if (strlen(key) != 26)                               // validate key string provided is 26 char's
    {
        printf("%s\n", error_message);
        return 1;
    }


//cycle through string key to validate all alphabetical and no char repeated

    for (int i = 0, n = strlen(key); i < n; i++)        // loop to check each char in string for alphabetical
    {
        if (isalpha(key[i]) == 0)                       // isalpha returns non-zero for alphabetical letters
        {
            printf("%s\n", error_message);
            return 1;
        }
        for (int j = i + 1; j < n; j++)                 // cylcle through each char to compare to char[i] to validate no repeats
        {
            if (key[i] == key[j])                       // if ==, error for key provided contains repeated char
            {
                printf("%s\n", error_message);
                return 1;
            }
        }
    }


// prompt user for strings to be ciphered

    string plaintext = get_string("plaintext:  ");


// process decipher with key[] changing plaintext to ciphertext
// maintain case of plaintext, preserve non-alphabetical char's

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)          // cycle through each char of provided plaintext string
    {
        if (isalpha(plaintext[i]))                              // isalpha != 0 true for alphabetical char
        {
            if (isupper(plaintext[i]))                          // isupper != 0 true for upper case
            {
                int ciphu = plaintext[i] - 65;                  // index letter A to O, etc to get key char in first/A index[0]
                printf("%c", toupper(key[ciphu]));              // print char key[i] as uppercase to match plaintext upper case
            }
            else
            {
                int ciphl = plaintext[i] - 97;                  // index letter a to 0, etc to get key char in first/a index[0]
                printf("%c", tolower(key[ciphl]));              // print char key[i] at lower case to match plaintext lower case
            }
        }
        else
        {
            printf("%c", plaintext[i]);                         // pass through all no alphabetcal char unchanged and print
        }
    }

    printf("\n");
    return 0;
}
