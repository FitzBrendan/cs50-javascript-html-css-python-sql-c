#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // prompt for change - variable cents, verify 1 - 99, repeat if not 1 - 99
    int cents;
    do
    {
        cents = get_int("please provide change due, 0 - 99 cents  ");
    }
    while (cents < 0 || cents > 99);
    return cents;
}

int calculate_quarters(int cents)
{
    // calculate max quarters within provided parameter cents
    // cents / 25,           return only integer value
    int quarters = cents / 25;
    return quarters;
}

int calculate_dimes(int cents)
{
    // calculate max dimes,
    // do not need to account for quarters as cents reset following quarter funcion
    // cents - quarters * 25 / 10         return only integer value
    int dimes = cents / 10;
    return dimes;
}

int calculate_nickels(int cents)
{
    // calculate max nickels
    // do not need to account for quarters or dimes, cents reset after each function
    int nickels = cents / 5;
    return nickels;
}

int calculate_pennies(int cents)
{
    // calculate max pennies
    // do not need to account for other coins, cents reset after all coin functions
    int pennies = cents;
    return pennies;
}
