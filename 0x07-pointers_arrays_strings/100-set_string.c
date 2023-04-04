#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix of integers.
 * @a: pointer to int representing the square matrix
 * @size: size of the square matrix
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
        int sum1 = 0, sum2 = 0, i, j;

        for (i = 0; i < size; i++)
        {
                sum1 += a[i * size + i];
                sum2 += a[(i + 1) * (size - 1)];
        }

        printf("%d, %d\n", sum1, sum2);
}
