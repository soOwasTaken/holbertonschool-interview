#include "palindrome.h"

/**
 * is_palindrome - Check if a given unsigned integer is a palindrome.
 * @n: Number to be checked.
 * 
 * Return: 1 if n is a palindrome, and 0 otherwise.
 */

int is_palindrome(unsigned long n)
{
    unsigned long reversed = 0, original = n, remainder;

    while (n != 0)
    {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    if (original == reversed)
        return (1);
    else
        return (0);
}
