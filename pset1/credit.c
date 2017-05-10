// Implement a program that determines whether a provided credit card number is valid according to Luhn’s algorithm.

// $ ./credit
// Number: 378282246310005
// AMEX

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_len (long long value);
int get_first_digit (long long value);
int credit_card_result(long long cc_copy);
int check_credit_card(long long cc_num);

int main(void)
{
    long long cc_num = 1;
   
    while (true)
    {
        printf ("Number: ");
        cc_num = get_long_long();    
        
        check_credit_card(cc_num);
        break;
    }
}

int check_credit_card(long long cc_num)
{   
    int switcher = 1;
    int sum = 0;
    int sum1 = 0;
    long long cc_copy = cc_num;
    
    while (cc_num > 0) {
    int digit = cc_num % 10;
    
    if (switcher == 1 )
    {
        sum += digit;
    } else 
    {
        switch (get_len(digit*2)) {
            case 1:
                sum1 += digit * 2;
                break;
            case 2:
                sum1 += (digit * 2) % 10;
                sum1 += 1;
        }
    }
    
        switcher = 1 - switcher;
        cc_num /= 10;
    }
    
    if ((sum + sum1) % 10 == 0) 
    {
        credit_card_result(cc_copy);
    } else 
    {
        printf("INVALID\n");
    }
    
    return 0;
}

int credit_card_result(long long cc_copy)
{
    int first = get_first_digit(cc_copy);
    
    switch (first)
    {
        case 3:
            printf ("AMEX\n");
            break;
        case 4:
            printf ("VISA\n");
            break;
        case 5:
            printf ("MASTERCARD\n");
            break;
    }
    
    return 0;
}

int get_len (long long value) 
{
    int l=1;
    while (value > 9) 
    { 
        l++; value/=10; 
    }
    
    return l;
}

int get_first_digit (long long cc_num1)
{   
    return cc_num1 / pow(10, (get_len(cc_num1) - 1));
}