#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix
 * @a: the square matrix
 * @size: size of the matrix
 */
void print_diagsums(int *a, int size)
{
	int i, j;
	int sum1 = 0, sum2 = 0;

	for (i = 0; i < size; i++)
	{
		/* add elements of the first diagonal */
		sum1 += *(a + i * size + i);

		/* add elements of the second diagonal */
		j = size - 1 - i;
		sum2 += *(a + i * size + j);
	}

	printf("%d, %d\n", sum1, sum2);
}
