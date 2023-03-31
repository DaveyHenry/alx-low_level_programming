#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints the content of a buffer
 * @b: pointer to the buffer to print
 * @size: size of the buffer
 */
void print_buffer(char *b, int size)
{
    int i, j;
    unsigned char c;

    if (size <= 0)
    {
        printf("\n");
        return;
    }

    for (i = 0; i < size; i += 10)
    {
        printf("%08x: ", i);

        for (j = i; j < i + 10; j++)
        {
            if (j < size)
            {
                printf("%02x", b[j]);
            }
            else
            {
                printf("  ");
            }

            if (j % 2)
            {
                printf(" ");
            }
        }

        for (j = i; j < i + 10; j++)
        {
            if (j >= size)
            {
                printf(" ");
            }
            else
            {
                c = b[j];
                if (c < 32 || c > 126)
                {
                    c = '.';
                }
                printf("%c", c);
            }
        }

        printf("\n");
    }
}
