#include <stdlib.h>
#include "main.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: old size of the memory block
 * @new_size: new size of the memory block
 *
 * Return: pointer to the new memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *clone, *relloc;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	clone = ptr;
	relloc = malloc(new_size);

	if (relloc == NULL)
		return (NULL);

	for (i = 0; i < old_size && i < new_size; i++)
		relloc[i] = clone[i];

	free(ptr);

	return (relloc);
}
