#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * array_range - creates an array of integers
 * @min: minimum
 * @max: maximum
 * Return: array
 */
int *array_range(int min, int max)
{
	int *arr, i = 0;
	long int size = max - min + 1;

	if (min > max)
		return (NULL);

	if (size > INT_MAX)
		return (NULL);

	arr = malloc(size * sizeof(int));

	if (!arr)
		return (NULL);

	while (i < size)
	{
		arr[i] = min++;
		i++;
	}

	return (arr);
}
