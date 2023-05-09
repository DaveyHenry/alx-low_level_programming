#include "main.h"

/**
 * create_file - creates a file and adds permission to it
 * @filename: The name of the file to be created
 * @text_content: content to be placed in the created file
 * Return: 1 if successfull and -1 on error
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor = 0, bytes_written = 0, i = 0;

	if (!filename)
		return (-1);

	if (!text_content)
		text_content = "";

	file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 00600);
	if (file_descriptor < 0)
		return (-1);

	while (text_content[i])
		i++;

	bytes_written = write(file_descriptor, text_content, i);
	if (bytes_written < 0)
	{
		close(file_descriptor);
		return (-1);
	}

	close(file_descriptor);
	return (1);
}
