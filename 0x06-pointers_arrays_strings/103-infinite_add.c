#include "main.h"
#include <stdio.h>

/**
 * infinite_add - Adds two numbers stored as strings
 * @n1: First number to add
 * @n2: Second number to add
 * @r: Buffer to store the result
 * @size_r: Size of the buffer
 * Return: Pointer to the result, or 0 if the result can't be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len1 = 0, len2 = 0, len_res = 0, carry = 0;
    int i = 0, j = 0;
    char tmp;

    while (n1[len1] != '\0')
        len1++;
    while (n2[len2] != '\0')
        len2++;

    len_res = (len1 > len2 ? len1 : len2) + 1;

    if (len_res >= size_r)
        return (0);

    r[len_res] = '\0';
    len_res--;

    while (len1 > 0 || len2 > 0)
    {
        tmp = carry;
        if (len1 > 0)
            tmp += n1[--len1] - '0';
        if (len2 > 0)
            tmp += n2[--len2] - '0';
        carry = tmp / 10;
        r[len_res--] = (tmp % 10) + '0';
    }

    if (carry)
        r[len_res--] = carry + '0';

    if (len_res < 0)
        return (0);

    return (r + len_res + 1);
}
