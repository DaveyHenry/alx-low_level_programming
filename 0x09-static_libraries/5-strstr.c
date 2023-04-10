#include "main.h"
#include <stddef.h>

/**
 * _strstr - locate and return pointer to first occurrence of substring
 * @haystack: string to search
 * @needle: target substring to search for
 * Return: pointer to index of string at first occurrence of whole substring
 */
char *_strstr(char *haystack, char *needle)
{
	int i = 0, j = 0, x;

	if (needle[0] == '\0')
		return (haystack);

	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			x = i, j = 0;
			while (needle[j] != '\0' && haystack[x] == needle[j])
				x++, j++;
			if (needle[j] == '\0')
				return (haystack + i);
		}
		i++;
	}

	return (NULL);
}
