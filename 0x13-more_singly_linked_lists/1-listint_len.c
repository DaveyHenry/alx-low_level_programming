#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked list
 * @h: pointer to the first node of the linked list
 *
 * Return: number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t nodenum = 0;

	while (h != NULL)
	{
		nodenum++;
		h = h->next;
	}

	return (nodenum);
}
