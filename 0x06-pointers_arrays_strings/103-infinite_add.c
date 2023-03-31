#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer to store result
 * @size_r: buffer size
 *
 * Return: pointer to result, or 0 if result cannot be stored in buffer
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0, i, j, k = 0, sum, carry = 0;

	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;
	if (len1 + 2 > size_r || len2 + 2 > size_r)
		return (0);
	i = len1 - 1;
	j = len2 - 1;
	while (i >= 0 || j >= 0)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i] - '0';
		if (j >= 0)
			sum += n2[j] - '0';
		if (k + 1 > size_r)
			return (0);
		r[k++] = sum % 10 + '0';
		carry = sum / 10;
		i--;
		j--;
	}
	if (carry && k + 1 <= size_r)
		r[k++] = carry + '0';
	if (k + 1 > size_r)
		return (0);
	r[k] = '\0';
	for (i = 0, j = k - 1; i < j; i++, j--)
	{
		char tmp = r[i];
		r[i] = r[j];
		r[j] = tmp;
	}
	return (r);
}
