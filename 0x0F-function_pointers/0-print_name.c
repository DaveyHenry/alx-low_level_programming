#include "function_pointers.h"

/**
 * print_name - function that prints a name passed to it
 * @name: the name to print
 * @f: pointer to the printing function to use
 */
void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;

	f(name);
}
