#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer for result
 * @size_r: buffer size
 *
 * Return: address of r or 0
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k, l, m, n;

	/* Find lengths of n1 and n2 */
	for (i = 0; n1[i]; i++)
		;
	for (j = 0; n2[j]; j++)
		;

	/* Check if the sum can fit in r */
	if (i > size_r - 1 || j > size_r - 1)
		return (0);

	/* Initialize variables */
	m = 0;
	k = 0;
	i--;
	j--;

	/* Calculate the sum of the numbers */
	while (i >= 0 || j >= 0 || m)
	{
		n = m;
		if (i >= 0)
			n += n1[i--] - '0';
		if (j >= 0)
			n += n2[j--] - '0';

		r[k++] = (n % 10) + '0';
		m = n / 10;
	}

	/* If r is full but there is still a carry, return 0 */
	if (k == size_r && m)
		return (0);

	/* Reverse r */
	for (l = 0, k--; l < k; k--, l++)
	{
		m = r[k];
		r[k] = r[l];
		r[l] = m;
	}

	return (r);
}
