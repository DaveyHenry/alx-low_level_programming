#include "main.h"

/**
 * infinite_add - Adds two numbers
 * @n1: First number to add
 * @n2: Second number to add
 * @r: Buffer to store the result
 * @size_r: Size of the buffer
 *
 * Return: Pointer to the result or 0 if it can not be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0, i = 0, j = 0, sum = 0, carry = 0;

	/* Calculate the length of n1 and n2 */
	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;

	/* Check if the sum of n1 and n2 fits in r */
	if (len1 + 1 > size_r || len2 + 1 > size_r)
		return (0);

	/* Add digits from right to left */
	for (i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; i--, j--)
	{
		sum = carry;

		if (i >= 0)
			sum += n1[i] - '0';

		if (j >= 0)
			sum += n2[j] - '0';

		if (sum >= 10)
		{
			carry = 1;
			sum -= 10;
		}
		else
			carry = 0;

		r[i + j + 1] = sum + '0';
	}

	/* Check if there is a carry left */
	if (carry != 0)
	{
		if (len1 + len2 + 1 > size_r)
			return (0);
		r[0] = carry + '0';
		return (r);
	}

	/* Remove leading zeros */
	for (i = 0; r[i] != '\0'; i++)
	{
		if (r[i] != '0')
			break;
	}

	/* Move the digits to the beginning of the buffer */
	for (j = 0; r[i] != '\0'; i++, j++)
		r[j] = r[i];

	r[j] = '\0';

	return (r);
}
