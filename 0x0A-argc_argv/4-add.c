#include <stdio.h>
#include <stdlib.h>

/**
 * is_number - check if a string is a number
 * @s: string to check
 *
 * Return: 1 if string is a number, 0 otherwise
 */
int is_number(char *s)
{
    int i = 0;

    if (s[i] == '-')
        i++;

    for (; s[i] != '\0'; i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return (0);
    }

    return (1);
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of argument strings
 *
 * Return: 0 if successful, 1 if error
 */
int main(int argc, char *argv[])
{
    int i, sum = 0;

    if (argc < 2)
    {
        printf("0\n");
        return (0);
    }

    for (i = 1; i < argc; i++)
    {
        if (!is_number(argv[i]))
        {
            printf("Error\n");
            return (1);
        }

        sum += atoi(argv[i]);
    }

    printf("%d\n", sum);
    return (0);
}
