#include "main.h"

/**
 * infinite_add - Adds two numbers
 *
 * @n1: The first number to add
 * @n2: The second number to add
 * @r: The buffer to store the result in
 * @size_r: The size of the buffer
 *
 * Return: A pointer to the result, or 0 if it cannot be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len1 = 0, len2 = 0, carry = 0, sum = 0;
    int i, j;

    while (n1[len1] != '\0')
        len1++;
    while (n2[len2] != '\0')
        len2++;

    if (len1 + 2 > size_r || len2 + 2 > size_r)
        return (0);

    for (i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0 || carry == 1; i--, j--)
    {
        sum = carry;
        if (i >= 0)
            sum += n1[i] - '0';
        if (j >= 0)
            sum += n2[j] - '0';
        carry = sum / 10;
        r[i + j + 1] = (sum % 10) + '0';
    }
    r[i + j + 2] = '\0';

    for (i = 0, j = len1 + len2 - 1; i < j; i++, j--)
    {
        char tmp = r[i];
        r[i] = r[j];
        r[j] = tmp;
    }

    return (r);
}
