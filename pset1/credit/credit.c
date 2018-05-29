#include <stdio.h>
#include <cs50.h>
#include <math.h>

long long getUserCredit(void);
int getNthDigit(long long dividend, double n);
int checkCreditNumValidity(long long creditNum);
void printCardType(long long creditNum);

int main(void)
{
    long long userCredit = getUserCredit();
    printCardType(userCredit);
    return 0;
}

/**
 * Prints out the type of a card using the given credit card number. Possible types are Amex, Master Card, Visa, and Invalid.
 */
void printCardType(long long creditNum)
{
    if (checkCreditNumValidity(creditNum) == 0)
    {
        int creditNumLen = (int)ceil(log10(creditNum));
        int firstTwoDigits = getNthDigit(creditNum, (double)creditNumLen) * 10 + getNthDigit(creditNum, (double)(creditNumLen-1));
        if (creditNumLen == 15 && \
        (firstTwoDigits == 34 || firstTwoDigits == 37))
        {
            printf("AMEX\n");
        }
        else if (creditNumLen == 16 && \
        (firstTwoDigits == 51 || firstTwoDigits == 52 || firstTwoDigits == 53 || firstTwoDigits == 54 || firstTwoDigits == 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((creditNumLen == 14 || creditNumLen == 16) && \
        (int)(firstTwoDigits / 10) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }
}

/**
 * Determine validity of userCredit by multiplying every other digit by 2, starting with the
 * number’s second-to-last digit, and then add those products' digits together (Luhn's Algorithm)
 */
int checkCreditNumValidity(long long creditNum)
{
    int creditNumLen = (int)ceil(log10(creditNum)); // (https://www.quora.com/How-can-I-find-the-length-of-a-long-number-in-C)
    int luhnNum = 0;
    for (int i = 0; i < creditNumLen; i++)
    {
        int digit = getNthDigit(creditNum, i+1);

        if (i % 2 != 0)
        {
            // nth digit where n is even
            luhnNum += ((digit * 2) % 10) + (int)((digit * 2) / 10);
        }
        else
        {
            // nth digit where n is odd
            luhnNum += digit;
        }
    }

    if (luhnNum % 10 == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/**
 * Fetches a long long user input of credit number.
 */
long long getUserCredit(void)
{
    long long userCredit;
    do
    {
        userCredit = get_long_long("Number: ");
    }
    while(userCredit <= 0);

    return userCredit;
}

/**
 * Returns the nth digit of a positive long long.
 */
int getNthDigit(long long dividend, double n)
{
    // power function in C (https://stackoverflow.com/questions/213042/how-do-you-do-exponentiation-in-c)
    long long divisor = (long long) pow(10.0, n); // (dividend = quotient * divisor + remainder)
    return (int)(dividend % divisor / (divisor / 10));
}
