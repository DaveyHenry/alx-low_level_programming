#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 if incorrect number of arguments, 2 if negative bytes
 */
int main(int argc, char **argv)
{
	char *opc = (char *) main;
	int i, nbytes;

	if (argc != 2)
	{
		fprintf(stderr, "Error: incorrect number of arguments\n");
		return (1);
	}

	nbytes = atoi(argv[1]);

	if (nbytes < 0)
	{
		fprintf(stderr, "Error: negative number of bytes\n");
		return (2);
	}

	for (i = 0; i < nbytes; i++)
	{
		printf("%02x", opc[i] & 0xFF);
		if (i != nbytes - 1)
			printf(" ");
	}

	printf("\n");
	return (0);
}
