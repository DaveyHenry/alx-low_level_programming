#include "main.h"

/**
 * main - prints the name of the program
 * @argc: number of arguments
 * @argv: array of pointers to arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
    _puts(argv[0]);
    return (0);
}

/**
 * _puts - prints a string to stdout
 * @str: string to print
 *
 * Return: number of characters printed
 */
int _puts(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        _putchar(str[i]);

    return (i);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}
