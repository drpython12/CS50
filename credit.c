#include <stdio.h>
#include <string.h>
#include <math.h>

int length(long long number);
int luhn(long long number);
int type(long long number);

int main(void)
{
    long long card_number;
    // Prompts the user to enter a card number > 0
    printf("Card number: ");
    scanf("%lld", &card_number);
    // Checks if card is valid through Luhn's algorithm
    if (luhn(card_number) == 0) 
    {
        int card_length = length(card_number);
        // Cards of 15 digits are AMEX
        if (card_length == 15)
        {
            printf("Valid AMEX card\n");
        }
        // Cards of 13 digits are Visa
        else if (card_length == 13)
        {
            printf("Valid VISA card\n");
        }
        // Cards of 16 digits are either Visa or Mastercard
        else if (card_length == 16)
        {
            int card_type = type(card_number);
            if (card_type == 0)
            {
                printf("Valid VISA card\n");
            }
            else if (card_type == 1)
            {
                printf("Valid MASTERCARD\n");
            }
            else
            {
                printf("Invalid card number!\n");
            }
        }
    }
    else
    {
        printf("Invalid card number!");
    }
}

int length(long long number)
{
    // Takes the log base 10 of the number, rounds it down and adds 1 to find length
    int length = floor(log10(number)) + 1;
    return length;
}

int luhn(long long number)
{ 
    long long ccnumber = number;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;
    int final = 0;
    // Starting with last digit, add every alternate digit of card number
    while (ccnumber > 0)
    {
        int last_digit = ccnumber % 10;
        sum1 = sum1 + last_digit;
        ccnumber = ccnumber / 100;
    }
    // Starting with second last digit, add every alternate digit of card number multiplied by 2
    ccnumber = number / 10;
    while (ccnumber > 0)
    {
        int last = ccnumber % 10;
        int last_times_two = last * 2;
        if (last_times_two >= 10)
        {
            sum2 += (last_times_two % 10) + (last_times_two / 10);
        }
        else
        {
            sum2 += last_times_two;
        }
        ccnumber = ccnumber / 100;
    }
    sum3 = sum1 + sum2;
    final = sum3 % 10;
    return final;
}

int type(long long number)
{
    long long ccnumber = number;
    int first_digit = ccnumber / 1000000000000000;
    int pair_digits = ccnumber / 100000000000000;
    if (first_digit == 4)
    {
        return 0;
    }
    else if (pair_digits == 51 || pair_digits == 52 || pair_digits == 53 || pair_digits == 54 || pair_digits == 55)
    {
        return 1;
    }
}