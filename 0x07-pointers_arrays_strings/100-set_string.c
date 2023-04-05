#include "main.h"

/**
 * set_string - Sets the value of a pointer to a char.
 * @s: A pointer to a pointer to a char.
 * @to: The value to be set.
 */

void set_string(char **s, char *to)
{
	*s = to;
}
