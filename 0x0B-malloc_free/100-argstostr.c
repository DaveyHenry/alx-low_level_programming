#include "main.h"

/**
 * argstostr - concatenates all arguments of the program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to new string containing concatenated args
 */
char *argstostr(int ac, char **av)
{
	char *str;
	int count = 0, a, b, c = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (a = 0; a < ac; a++)
	{
		for (b = 0; av[a][b] != '\0'; b++)
			count++;
		count++;
	}

	str = malloc(sizeof(char) * count);
	if (str == NULL)
		return (NULL);

	for (a = 0; a < ac; a++)
	{
		for (b = 0; av[a][b] != '\0'; b++)
		{
			str[c] = av[a][b];
			c++;
		}
		str[c] = '\n';
		c++;
	}

	return (str);
}
