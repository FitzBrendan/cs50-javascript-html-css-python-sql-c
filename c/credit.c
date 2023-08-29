#include <cs50.h>
#include <stdio.h>

int main(void)
{

// global variables
    long cc;                // cc = credit card entered
    int dig = 0;            // cc number of digits
    string inv = "INVALID";             // varibale to print when any check fails

// code to check validity of credit cart number promted for
// if all checks pass, cc number sent to back servers
// valid cc numbers contain 13, 15 or 16 digits
// valid cc numbers satisiy ending 0 for luhn checksum
// valid VISA cc numbers are 13 or 16 digits, with starting number 4
// valid AMEX cc numbers are 15 digits, with starting numbers 34 or 37
// valid MASTERCARD cc numbes are 16 digits, with staring numbers 51 - 55

// start with prompting user for credit card number, variable cc

    do
    {
        cc = get_long("please provide credit card number  ");
    }
    while (cc < 1);

//// diagnostics    printf("\ncredit card entered, %ld\n", cc);     print cc credit card number

//calculate digits in credit card number cc

    for (long cc_dig = cc; cc_dig > 0; dig++)           // local var cc_dig to truncate cc in loop to calculate number of digits of cc
    {
        cc_dig = cc_dig / 10;
    }

////    diagnostics     printf("digits in card entered,  %i\n", dig);       print calculated number of digits in cc

// verify digits valid, 13, 15 or 16  all others return INVALID

    if (dig != 13 && dig != 15 && dig != 16)
    {
        printf("%s\n", inv);        // invalid number if dig is not 13, 15 or 16 digits
        return 0;
    }

// checksum luhn

// variables for checksumc luhn
    long cc_luhn1 = cc;     // variable for truncated credit card number first digit & every other
    long cc_luhn2 = cc;     // variable for truncatred cc number, 2nd digit & every other *2
    int sum1 = 0;           // sum of digits not processed
    int sum2 = 0;           // sum of digits multiplied by 2
    int sumluhn = 0;        // sum for lugn check, sum = sum1 + sum2
    int dig1;               // variable for not processed digits to sum
    int dig2;               // variable for digits to be multiplied by 2
    int dig2_tens;          // variable for tens for sum2 digits that are > 9
    int dig2_ones;          // variable for ones for sum2 digits that are > 9

// determine second digit from right of cc (tens) and then every other digit
// each digit * 2, sum of digits (not sum of numbers)

    cc_luhn2 = cc_luhn2 / 10;                 // intial setup to get rid of first (ones) digit
    while (cc_luhn2 > 0)
    {
        dig2 = cc_luhn2 % 10;                   // call out first digit, was cc second digit
        dig2_tens = dig2 * 2 / 10;              // separate out tens digit if *2 > 9, zero added to single digit product
        dig2_ones = dig2 * 2 % 10;               // separate out ones digit after *2
        sum2 = sum2 + dig2_tens + dig2_ones;    // sum of every other digit after *2
        cc_luhn2 = cc_luhn2 / 100;               // incrementing to skip 2 digits, for every other digit, rid worked on and next
    }

// determine first digit on cc (ones) and sum every other digit

    while (cc_luhn1 > 0)
    {
        dig1 = cc_luhn1 % 10;                // call out first digit of cc (ones)
        sum1 = sum1 + dig1;                 // sum of every othe digit of cc start at (ones)
        cc_luhn1 = cc_luhn1 / 100;          // for every other digit, rid worked on and next
    }

//// diagnostics    printf("\n this is sum2 %i\n", sum2);   print sum2
//// diagnostics    printf("\n this is sum1 %i\n", sum1);   print sum1

// calc sumluhn = sum1 + sum2, validate last digit (ones) is zero (0)

    sumluhn = sum1 + sum2;
    if (sumluhn % 10 != 0)          // verify last digit is 0 for cc validity check
    {
        printf("%s\n", inv);        // invalid luhn checksum failed
        return 0;
    }

// checking digits and starting number for validation, AMEX, MC, VISA
// dig  and  cc     use existing global variables for digits provided and cc number
// 13 digits VISA, 15 digits AMEX, 16 digits VISA and MC
// starting numbers  AMEX 34, 37   - MC 51-55    VISA 4

// checking for VISA with 13 digits and starting digit = 4

    if (dig == 13)
    {
        long cc_13 = cc;        // declare variable for truncated 13 digit cc number
        while (cc_13 >= 10)     // truncate number down to single digit
        {
            cc_13 = cc_13 / 10;
        }
//// diagnostics    printf("this is the first digit of 13 digit cc number %ld\n", cc_13);   check first digits of 13
        if (cc_13 == 4)
        {
            printf("VISA\n");          // all checks for 13 digit VISA validated
            return 0;
        }
        else
        {
            printf("%s\n", inv);
            return 0;
        }
    }

// checking for AMEX 15 digits and starting with 34 or 37

    if (dig == 15)
    {
        long cc_15 = cc;            // declare variable for tuncated 15 digit cc number
        while (cc_15 >= 100)
        {
            cc_15 = cc_15 / 10;
        }

//// diagnostics    printf("this is the first 2 digits of 15 digit cc number %ld\n", cc_15);    check first 2 digits of 15

        if (cc_15 == 34 || cc_15 == 37)
        {
            printf("AMEX\n");
            return 0;
        }
        else
        {
            printf("%s\n", inv);
            return 0;
        }
    }

// checking for VISA or MC 16 digits, VISA starts with 4, MC starts with 51-55

    if (dig == 16)
    {
        long cc_16 = cc;        // declare variable for truncated 16 digit cc number
        while (cc_16 >= 100)
        {
            cc_16 = cc_16 / 10;
        }

//// diagnostics    printf("this is the first 2 digits of 16 digit cc number %ld\n", cc_16);    check first 2 digits of 16

        if (cc_16 / 10 == 4)
        {
            printf("VISA\n");
            return 0;
        }
        else if (cc_16 >= 51 && cc_16 <= 55)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else
        {
            printf("%s\n", inv);       // return INVALID if all 16 digit first number checks failes
        }
    }

    return 0;

}
